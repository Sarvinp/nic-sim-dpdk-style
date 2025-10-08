#include "nic_simulator.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstring>
#include <chrono>

NicSimulator::NicSimulator() {}

std::string NicSimulator::get_timestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* tm_ptr = std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

rte_mbuf* NicSimulator::receive_packet(int packet_id) {
    auto* mbuf = rte_pktmbuf_alloc();
    std::string header = "Packet #" + std::to_string(packet_id) + " at " + get_timestamp();

    std::memset(mbuf->data, 0, sizeof(mbuf->data));
    std::memcpy(mbuf->data, header.c_str(), std::min(header.size(), sizeof(mbuf->data)));

    for (size_t i = header.size(); i < 64; ++i) {
        mbuf->data[i] = static_cast<char>(i);
    }

    mbuf->data_len = 64;
    mbuf->pkt_len = 64;
    return mbuf;
}

void NicSimulator::transmit_packet(rte_mbuf* mbuf) {
    std::cout << "[TX] Transmitting: " << mbuf->data << std::endl;
    print_packet_hex(mbuf);
    rte_pktmbuf_free(mbuf);
}

void NicSimulator::print_packet_hex(const rte_mbuf* mbuf) {
    std::cout << "[HEX] Payload (" << mbuf->data_len << " bytes):" << std::endl;

    for (size_t i = 0; i < mbuf->data_len; i += 16) {
        std::cout << std::hex << std::setw(4) << std::setfill('0') << i << ": ";

        for (size_t j = 0; j < 16; ++j) {
            if (i + j < mbuf->data_len) {
                std::cout << std::hex << std::setw(2) << std::setfill('0')
                          << static_cast<unsigned>(static_cast<unsigned char>(mbuf->data[i + j])) << " ";
            } else {
                std::cout << "   ";
            }
        }

        std::cout << " | ";
        for (size_t j = 0; j < 16 && i + j < mbuf->data_len; ++j) {
            char c = mbuf->data[i + j];
            std::cout << (std::isprint(c) ? c : '.');
        }

        std::cout << std::endl;
    }
}
