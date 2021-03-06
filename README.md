# Byte Packing

This is a byte packing program wrote in C++11 which illustrates how to manually pack data into different data types and structures through the use of bit shifting.

Program demonstrates basic byte packing from an uint64_t array to uint8_t and then back to uint64_t. The program illustrates how the data is represented during all stages of packing.

Main use case for byte packing is to reduce memory footprint of applications that deal with large data sets that often hit memory limits or for memory constrained systems such as embedded systems or kernels.

## Build and Run

```bash
git clone https://github.com/efriel94/byte-packing.git
g++ -Wall main.cpp -o main
./main
```
