/********************************************
 *  
 * @file    byte_packing.cpp
 * @brief   Program demonstrates basic byte packing from an uint64_t array to uint8_t and then back to uint64_t.
 *          Illustrating how the data is represented during all stages of packing.
 * @author  Emmet Friel
 * @date    09/04/2021
 * 
 *******************************************/ 

#include <iostream>
#include <iomanip>
#include <array>

using std::array;
using std::cout;
using std::endl;
using std::hex;

void printArrayU8(array<uint8_t,16> arr);
void printArrayU64(array<uint64_t,2> arr);
void convertArrayU8toU64( array<uint8_t,16> &x, array<uint64_t,2> &y);
void convertArrayU64toU8( array<uint64_t,2> &x, array<uint8_t,16> &y);


int main(int argc, char const *argv[])
{
    cout << "Byte packing test!" << endl;

    array<uint8_t,16> x {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    array<uint64_t,2> y {};
    array<uint8_t,16> z {};
    
    cout << "x uint8_16 : ";
    printArrayU8(x);

    convertArrayU8toU64(x,y);
    cout << "y uint64_t : ";
    printArrayU64(y);

    convertArrayU64toU8(y,z);
    cout << "z uint8_t  : ";
    printArrayU8(z);
    
    

    return 0;
}

void printArrayU8(array<uint8_t,16> arr)
{
    for (size_t i = 0; i < arr.size(); i++) {
        cout << hex << std::setfill('0') << std::setw(2) << +arr.at(i);
    }
    std::cout << std::endl;
}

void printArrayU64(array<uint64_t,2> arr)
{
    for (size_t i = 0; i < arr.size(); i++) {
        cout << hex << std::setfill('0') << std::setw(16) << +arr.at(i);
    }
    std::cout << std::endl;
}

 
void convertArrayU8toU64( array<uint8_t,16> &x, array<uint64_t,2> &y)
{
    uint64_t i, j {}; // this is to remove warning [-Wsign-compare] where im comparing integers of different signedness
    int shift {};
    uint8_t value {};

    for (i = 0; i < y.size(); i++){
        y.at(i) = 0;
        for (j = 0; j < 8; j++){
            value = x[i*8 + j];   //current value
            shift = 8 * (7-j);    //byte0 is MSB word hence needs to be shifted the most
            y.at(i) += (static_cast<uint64_t>(value)) << shift;  //cast value before shift or else overflow occurs
        }
    }
}

void convertArrayU64toU8( array<uint64_t,2> &x, array<uint8_t,16> &y)
{
    uint64_t i,j {};   // this is to remove warning [-Wsign-compare] where im comparing integers of different signedness
    int shift {};
    uint64_t value {};

    for (i = 0; i < x.size(); i++) {
        for (j = 0; j < 8; j++) {
            shift = 8 * (7 - j);
            value = x.at(i) >> shift;
            y[i*8+j] = static_cast<uint8_t>(value & 0xff);
        }
    }
}