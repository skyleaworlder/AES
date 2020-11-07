#include "SubBytes.hpp"

vector<byte> SubBytes(
    vector<byte> input
) {
    assert(input.size() == 16);
    vector<byte> ret;
    for (byte elem : input) {
        size_t col_index = (elem & byte(0x0F)).to_ulong();
        size_t row_index = (elem & byte(0xF0)).to_ulong() >> 4;
        ret.push_back(s_box[row_index * 16 + col_index]);
    }
    return ret;
}