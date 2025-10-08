cmake_minimum_required(VERSION 3.26)

project(DPDKproj)

set(CMAKE_CXX_STANDARD 17)


include_directories(${DPDK_DIR}/include)

# Link DPDK libraries
link_directories(${DPDK_DIR}/lib)

add_executable(DPDKproj main.cpp
        rte_mbuf.cpp
        nic_simulator.cpp)

target_include_directories(DPDKproj PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
