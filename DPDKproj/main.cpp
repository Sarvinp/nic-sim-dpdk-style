#include "rte_mbuf.h"
#include "nic_simulator.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>
#include <atomic>

std::atomic<bool> keep_running(true);

void signal_handler(int) {
    keep_running = false;
    std::cout << "\nStopping packet simulation..." << std::endl;
}

int main() {
    std::signal(SIGINT, signal_handler);

    rte_ring ring;
    NicSimulator nic;
    int packet_count = 0;

    while (keep_running) {
        rte_mbuf* rx_packet = nic.receive_packet(packet_count);
        std::cout << "[RX] Received: " << rx_packet->data << std::endl;

        ring.enqueue(rx_packet);
        rte_mbuf* tx_packet = ring.dequeue();

        if (tx_packet) {
            nic.transmit_packet(tx_packet);
        }

        ++packet_count;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "Total packets simulated: " << packet_count << std::endl;
    return 0;
}
