#pragma once
#include <cstdint>
#include <queue>

// Simulated DPDK mbuf
struct rte_mbuf {
    char data[2048];
    uint16_t data_len;
    uint16_t pkt_len;
};

// Allocation and deallocation
rte_mbuf* rte_pktmbuf_alloc();
void rte_pktmbuf_free(rte_mbuf* mbuf);

// Simulated NIC I/O
rte_mbuf* simulate_nic_rx();
void simulate_nic_tx(rte_mbuf* mbuf);

// Simulated DPDK ring
class rte_ring {
public:
    int enqueue(rte_mbuf* mbuf);
    rte_mbuf* dequeue();

private:
    std::queue<rte_mbuf*> q;
};
