# NIC Simulation with DPDK-style `rte_mbuf` and `rte_ring` in C++

This project simulates basic NIC packet flow using custom C++ implementations of `rte_mbuf` and `rte_ring`, inspired by [DPDK](https://www.dpdk.org/). It allows developers to experiment with packet allocation, queuing, and transmission logic without requiring kernel drivers or hardware support.

## 🧩 Features

- `rte_mbuf`: Simulated packet buffer structure with payload, length, and metadata
- `rte_ring`: FIFO queue for packet buffering and flow control
- `NicSimulator`: Encapsulated class for generating, transmitting, and inspecting packets
- Hex dump of packet payloads for debugging and analysis
- Continuous packet simulation with timestamps and graceful shutdown

## 📁 Project Structure

DPDKproj/ ├── CMakeLists.txt ├── main.cpp ├── rte_sim.h ├── rte_sim.cpp ├── nic_simulator.h └── nic_simulator.cpp


## 🚀 Getting Started

### Prerequisites

- CMake ≥ 3.10
- C++17-compatible compiler (MSVC, g++, clang++)
- Git (optional)

### Build Instructions
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
### Run
```bash
./DPDKproj
```
## 📦 Example Output
```bash
[RX] Received: Packet #42 at 2025-10-08 03:15:00
[TX] Transmitting: Packet #42 at 2025-10-08 03:15:00
[HEX] Payload (64 bytes):
0000: 50 61 63 6b 65 74 20 23 34 32 20 61 74 20 32 30  | Packet #42 at 20
0010: 32 35 2d 31 30 2d 30 38 20 30 33 3a 31 35 3a 30  | 25-10-08 03:15:0
...
```


## 🧠 Why This Project?
This simulation is ideal for:

Learning DPDK-style memory and queue management

Prototyping packet pipelines without hardware

Practicing systems-level design and modular architecture

## 🙋‍♂️ Author
Sarvnaz Nematpour 📧 sarv.np1200@gmail.com 🔗 LinkedIn
