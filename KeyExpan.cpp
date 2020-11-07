#include "KeyExpan.hpp"
#include <iostream>

vector<vector<byte>> Key_Expansion(
    vector<byte> input,
    size_t total_turn
) {
    vector<vector<byte>> ret { input };
    for (size_t index = 0; index < total_turn; ++index)
        ret.push_back(next_key(
            ret[index], index
        ));
    return ret;
}

vector<byte> next_key(
    vector<byte> former_key,
    size_t turn
) {
    assert(former_key.size() == 16);
    vector<byte> ret;

    vector<byte> former_key_last_word_after_rot {
        former_key[13], former_key[14],
        former_key[15], former_key[12]
    };
    size_t cnt = 0;
    for (byte elem : former_key_last_word_after_rot) {
        size_t col_index = (elem & byte(0x0F)).to_ulong();
        size_t row_index = (elem & byte(0xF0)).to_ulong() >> 4;
        byte res { former_key[cnt] ^ s_box[row_index * 16 + col_index] ^ rcon[turn*4+cnt]};
        ret.push_back(res);
        ++cnt;
    }

    for (size_t standard = 4; standard < 16; standard += 4) {
        ret.push_back(former_key[standard] ^ ret[standard-4]);
        ret.push_back(former_key[standard+1] ^ ret[standard-3]);
        ret.push_back(former_key[standard+2] ^ ret[standard-2]);
        ret.push_back(former_key[standard+3] ^ ret[standard-1]);
    }
    return ret;
}