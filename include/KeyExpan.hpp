#include "const.hpp"

vector<vector<byte>> Key_Expansion(vector<byte> input, size_t total_turn);
vector<byte> next_key(vector<byte> former_key, size_t turn);