#include "ShiftRows.hpp"

/*
 * 0  4  8  12      0  4  8  12
 * 1  5  9  13  --> 5  9  13 1
 * 2  6  10 14  --> 10 14 2  6
 * 3  7  11 15      15 3  7  11
 */
vector<byte> ShiftRows(
    vector<byte> input
) {
    return vector<byte> {
        input[0], input[5], input[10], input[15],
        input[4], input[9], input[14], input[3],
        input[8], input[13], input[2], input[7],
        input[12], input[1], input[6], input[11]
    };
}