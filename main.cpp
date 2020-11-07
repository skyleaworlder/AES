#include <iostream>
#include <string>
#include "Misc.hpp"
#include "KeyExpan.hpp"
#include "SubBytes.hpp"
#include "ShiftRows.hpp"
#include "MixColumns.hpp"
#include "AddRoundKey.hpp"

vector<byte> aes(
    std::bitset<128> input,
    std::bitset<128> key,
    size_t round
) {
    vector<vector<byte>> key_expan { Key_Expansion(byte_to_vector(key), round) };
    vector<byte> vec { byte_to_vector(input) };
    assert(key_expan.size() == round+1);

    vec = AddRoundKey(vec, key_expan[0]);

    size_t index;
    for (index = 1; index < round; ++index) {
        vec = SubBytes(vec);
        vec = ShiftRows(vec);
        vec = MixColumns(vec);
        vec = AddRoundKey(vec, key_expan[index]);
    }

    vec = SubBytes(vec);
    vec = ShiftRows(vec);
    vec = AddRoundKey(vec, key_expan[index]);
    return vec;
}

int main() {
    std::bitset<128> input(std::string("110010010000111111011010101000100010000101101000110000100011010011000100110001100110001010001011100000001101110000011100110100"));
    std::bitset<128> key(std::string("101011011111100001010100010110001010001010111011010010101001101010101111110111000101011000100000001001110011110100111100111100"));
    vector<byte> res { aes(input, key, 10) };
    for (byte elem : res)
        std::cout << elem << " ";
    std::cout << std::endl;
}