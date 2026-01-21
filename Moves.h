#ifndef MOVES_H
#define MOVES_H

#include "DataTypes.h"
#include <vector>
Pos makeMove(const Pos &pos, const Move &m);
std::vector<Move> generatePieceMoves(ull pieces, ull ownPieces, ull enemyPieces);

std::vector<Move> generateMoves(const Pos& pos);

std::vector<Move> generateQuietMoves(const Pos& pos);

std::vector<Move> generateLoudMoves(const Pos& pos);

#endif // MOVES_H
