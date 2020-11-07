#include "Misc.hpp"

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

vector<vector<byte>> vector_to_2_vector(vector<byte> input) {
    assert(input.size() == 16);
    return vector<vector<byte>> {
        vector<byte> { input[0], input[1], input[2], input[3] },
        vector<byte> { input[4], input[5], input[6], input[7] },
        vector<byte> { input[8], input[9], input[10], input[11] },
        vector<byte> { input[12], input[13], input[14], input[15] },
    };
}