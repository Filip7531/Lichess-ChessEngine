#ifndef UTILS_H
#define UTILS_H

#include "DataTypes.h"

ull reverseBits(ull x);
void setBit(ull &board, int rank, int file);
bool getBit(ull board, int rank, int file);
Board reverseBoard(Board A);
#endif // UTILS_H
