#include <iostream>
#include <string>
#include "test.hpp"

vector<byte> byte_to_vector(std::bitset<128> input) {
    /* cos tmp is reverse */
    vector<byte> ret, tmp;
    for (size_t index = 0; index < 128 / 8; ++index) {
        tmp.push_back(std::bitset<8> {
            (input & std::bitset<128> { 0xFF }).to_ulong()
        });
        input >>= 8;
    }
    while (tmp.size()) {
        ret.push_back(tmp.back());
        tmp.pop_back();
    }
    return ret;
}

void test_KeyExpan() {
    std::bitset<128> tmp(std::string("101011011111100001010100010110001010001010111011010010101001101010101111110111000101011000100000001001110011110100111100111100"));
    std::cout << tmp << std::endl;
    vector<byte> vec { byte_to_vector(tmp) };
    for (byte elem : vec)
        std::cout << elem << std::endl;
    vector<vector<byte>> res = Key_Expansion(byte_to_vector(tmp), 10);
    for (vector<byte> elem1 : res) {
        for (byte elem2 : elem1)
            std::cout << elem2 << " ";
        std::cout << std::endl;
    }
}

vector<byte> test_SubBytes() {
    std::bitset<128> tmp2(std::string("11001001111011110001110111110101000001111010011100010001010111001101011000110100011010010101011101001111110000100100000001000"));
    vector<byte> vec = byte_to_vector(tmp2);
    vec = SubBytes(vec);
    for (byte elem1 : vec) {
        std::cout << elem1 << " ";
    }
    std::cout << std::endl;
    return vec;
}

vector<byte> test_ShiftRows(vector<byte> input) {
    vector<byte> vec = ShiftRows(input);
    for (byte elem1 : vec) {
        std::cout << elem1 << " ";
    }
    std::cout << std::endl;
    return vec;
}

int main() {
    // test_KeyExpan();
    vector<byte> vec = test_SubBytes();
    vec = test_ShiftRows(vec);
}