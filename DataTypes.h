#ifndef DATATYPES_H
#define DATATYPES_H

#include<bits/stdc++.h>

using ull = unsigned long long;
const double inf = 1e9;
const bool DEBUG = 0;
struct Board {
    ull Pawn, Rook, Queen, Knight, Bishop, King;
    bool operator==(const Board &other) const {
        return Pawn   == other.Pawn &&
               Rook   == other.Rook &&
               Knight == other.Knight &&
               Bishop == other.Bishop &&
               Queen  == other.Queen &&
               King   == other.King;
    }
};

struct Pos {
    bool IsWhiteMove;
    Board white, black;
    bool operator==(const Pos &other) const {
        return white == other.white &&
               black == other.black &&
               IsWhiteMove == other.IsWhiteMove;

    }
};

struct Move {
    int fromRank, fromFile, toRank, toFile;
    char promotion = '0';
    bool operator==(const Move &other) const {
        return fromRank == other.fromRank &&
               fromFile == other.fromFile &&
               toRank   == other.toRank &&
               toFile   == other.toFile &&
               promotion == other.promotion;
    }

};

struct Computed {
    int depth;
    double res;
    Move BestMove;
};
const double eps = 0.001;

const Move NO_MOVE = {-1,-1,-1,-1, '-'};
const Move END_OF_THE_TIME = {-2,-2,-2,-2, '-'};
#endif // DATATYPES_H
