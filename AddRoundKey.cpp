#include "AddRoundKey.hpp"

vector<byte> AddRoundKey(
    vector<byte> input,
    vector<byte> round_key
) {
    assert(input.size() == 16 && round_key.size() == 16);
    vector<byte> ret;
    for (size_t index = 0; index < input.size(); ++index)
        ret.push_back(input[index] ^ round_key[index]);
    return ret;
}