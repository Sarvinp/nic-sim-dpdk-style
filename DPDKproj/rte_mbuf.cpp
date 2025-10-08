#include "rte_mbuf.h"
#include <cstring>
#include <iostream>

rte_mbuf* rte_pktmbuf_alloc() {
    auto* mbuf = new rte_mbuf();
    mbuf->data_len = 0;
    mbuf->pkt_len = 0;
    return mbuf;
}

void rte_pktmbuf_free(rte_mbuf* mbuf) {
    delete mbuf;
}

rte_mbuf* simulate_nic_rx() {
    auto* mbuf = rte_pktmbuf_alloc();
    std::strcpy(mbuf->data, "Simulated incoming packet");
    mbuf->data_len = std::strlen(mbuf->data);
    mbuf->pkt_len = mbuf->data_len;
    return mbuf;
}

void simulate_nic_tx(rte_mbuf* mbuf) {
    std::cout << "Transmitting packet: " << mbuf->data << std::endl;
    rte_pktmbuf_free(mbuf);
}

int rte_ring::enqueue(rte_mbuf* mbuf) {
    q.push(mbuf);
    return 0;
}

rte_mbuf* rte_ring::dequeue() {
    if (q.empty()) return nullptr;
    auto* mbuf = q.front();
    q.pop();
    return mbuf;
}
