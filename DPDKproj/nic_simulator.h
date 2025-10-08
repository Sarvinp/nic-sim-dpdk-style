#pragma once
#include "rte_mbuf.h"
#include <string>

class NicSimulator {
public:
    NicSimulator();
    rte_mbuf* receive_packet(int packet_id);
    void transmit_packet(rte_mbuf* mbuf);
    void print_packet_hex(const rte_mbuf* mbuf);

private:
    std::string get_timestamp();
};
