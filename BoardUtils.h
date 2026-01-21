#ifndef BOARDUTILS_H
#define BOARDUTILS_H

#include "DataTypes.h"
#include <vector>
#include <string>

void setBit(ull &bitboard, int rank, int file);
bool getBit(ull bitboard, int rank, int file);
Pos InBoard(const std::vector<std::string> &boardStrings, bool whiteMove);
std::vector<std::string> outBoard(const Pos& pos);

#endif // BOARDUTILS_H
