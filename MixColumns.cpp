#include "MixColumns.hpp"

byte FieldMult(byte input) {
    std::bitset<1> top { input[7] };
    byte tmp { input << 1 };
    if (top == 1)
        return tmp ^ byte(0x1b);
    else
        return tmp;
}

vector<byte> MixColumns(
    vector<byte> input
) {
    vector<byte> ret;
    vector<vector<byte>> total { vector_to_2_vector(input) };
    for (vector<byte> s : total) {
        byte x0 { s[0] }, x1 { s[1] }, x2 { s[2] }, x3 { s[3] };
        s[0] = x1 ^ x2 ^ x3;    s[1] = x0 ^ x2 ^ x3;
        s[2] = x0 ^ x1 ^ x3;    s[3] = x0 ^ x1 ^ x2;

        x0 = FieldMult(x0); x1 = FieldMult(x1);
        x2 = FieldMult(x2); x3 = FieldMult(x3);

        s[0] = s[0] ^ x0 ^ x1;  s[1] = s[1] ^ x1 ^ x2;
        s[2] = s[2] ^ x2 ^ x3;  s[3] = s[3] ^ x3 ^ x0;

        for (byte s_i : s)
            ret.push_back(s_i);
    }
    return ret;
}