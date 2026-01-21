#include "Evaluation.h"
#include "Utils.h"
#include "Moves.h"
#include<bits/stdc++.h>
using namespace std;

const double PawnsEV[64] = {
    1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,
    1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,
    1.0 ,1.0 ,1.1 ,1.0 ,1.0 ,1.1 ,1.0 ,1.0 ,
    1.0 ,1.0 ,1.1 ,1.2 ,1.2 ,1.1 ,1.0 ,1.0 ,
    1.0 ,1.0 ,1.0 ,1.2 ,1.2 ,1.0 ,1.0 ,1.0 ,
    1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,
    1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,
    1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 ,1.0 
};
const double KnightsEV[64] = {
    
    2.8 ,2.9 ,2.9 ,2.9 ,2.9 ,2.9 ,2.9 ,2.8 ,
    3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,2.9 ,
    3.0 ,3.0 ,3.1 ,3.0 ,3.0 ,3.1 ,3.0 ,3.0 ,
    3.0 ,3.1 ,3.2 ,3.1 ,3.2 ,3.1 ,3.0 ,2.9 ,
    3.0 ,3.1 ,3.1 ,3.1 ,3.1 ,3.1 ,3.0 ,2.9 ,
    2.9 ,3.0 ,3.1 ,3.0 ,3.0 ,3.1 ,3.0 ,2.9 ,
    2.9 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,2.9 ,
    2.9 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,2.9 
};
const double QueensEV[64] = {
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,
    9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 ,9.0 
};
const double RooksEV[64] = {
    5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0,
    5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,
    5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,
    5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,
    5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,
    5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,5.0 ,
    5.2 ,5.2 ,5.2 ,5.2 ,5.2 ,5.2 ,5.2 ,5.2 ,
    5.0 ,5.1 ,5.1 ,5.1 ,5.1 ,5.1 ,5.1 ,5.1 
};
const double BishopsEV[64] = {
    2.9, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9,
    3.0 ,3.1 ,3.0 ,3.0 ,3.0 ,3.0 ,3.1 ,3.0 ,
    3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0,
    3.1, 3.1 ,3.1 ,3.0 ,3.0 ,3.1 ,3.1 ,3.1,
    3.1 ,3.1 ,3.0 ,3.0 ,3.0 ,3.0 ,3.1 ,3.1,
    3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0,
    3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0,
    3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0 ,3.0
};
int countKnightMoves(int rank, int file,  const Pos &pos) {
    ull own   = pos.IsWhiteMove ? (pos.white.Pawn|pos.white.Rook|pos.white.Knight|
                         pos.white.Bishop|pos.white.Queen|pos.white.King)
                      : (pos.black.Pawn|pos.black.Rook|pos.black.Knight|
                         pos.black.Bishop|pos.black.Queen|pos.black.King);    
                         
        static const int dr[8] = {-2,-2,-1,-1, 1, 1, 2, 2};
    static const int df[8] = {-1, 1,-2, 2,-2, 2,-1, 1};

    int cnt = 0;
    for(int i = 0; i < 8; i++){
        int r = rank + dr[i];
        int f = file + df[i];
        if(r < 0 || r >= 8 || f < 0 || f >= 8) continue;
        if(!getBit(own, r, f)) cnt++;
    }
    return cnt;
}
int countBishopMoves(int rank, int file, const Pos &pos) {
     ull own   = pos.IsWhiteMove ? (pos.white.Pawn|pos.white.Rook|pos.white.Knight|
                         pos.white.Bishop|pos.white.Queen|pos.white.King)
                      : (pos.black.Pawn|pos.black.Rook|pos.black.Knight|
                         pos.black.Bishop|pos.black.Queen|pos.black.King);

    ull enemy = pos.IsWhiteMove ? (pos.black.Pawn|pos.black.Rook|pos.black.Knight|
                         pos.black.Bishop|pos.black.Queen|pos.black.King)
                      : (pos.white.Pawn|pos.white.Rook|pos.white.Knight|
                         pos.white.Bishop|pos.white.Queen|pos.white.King);
    int cnt = 0;

    const int dr[4] = {-1,-1, 1, 1};
    const int df[4] = {-1, 1,-1, 1};

    for(int d = 0; d < 4; d++){
        int r = rank + dr[d];
        int f = file + df[d];

        while(r >= 0 && r < 8 && f >= 0 && f < 8){
            if(getBit(own, r, f)) break;   // blok własny
            cnt++;                         // pole legalne
            if(getBit(enemy, r, f)) break; // bicie kończy promień
            r += dr[d];
            f += df[d];
        }
    }
    return cnt;
}
int countKnightsMoves(const Pos& pos, bool white) {
    ull knights = white ? pos.white.Knight : pos.black.Knight;
    int res = 0;
    while (knights) {
        int sq = __builtin_ctzll(knights);
        knights &= knights - 1;
        int rank = sq / 8;
        int file = sq % 8;
        res += countKnightMoves(rank, file, pos);
    }       
    return res;
}
int countBishopsMoves(const Pos& pos, bool white) {
    ull bishops = white ? pos.white.Bishop : pos.black.Bishop;
    int res = 0;

    while (bishops) {
        int sq = __builtin_ctzll(bishops);
        bishops &= bishops - 1;

        int rank = sq / 8;
        int file = sq % 8;

        res += countBishopMoves(rank, file,pos);
    }

    return res;
}

bool EndOfTheGame(Pos L){
    if(!L.black.King && !L.white.King)assert(0);//shouldnt happen
    if(!L.black.King || !L.white.King)return true;
    return false;
}
double Evaluate(Pos L){
    auto E = [](Board A){
        double res = 0;
        for(int i = 0; i < 64; i++){
            if(A.Pawn & (1ULL << i)) res += PawnsEV[i];
            else if(A.Bishop & (1ULL << i)) res += BishopsEV[i];
            else if(A.Rook & (1ULL << i))res += RooksEV[i];
            else if(A.Knight & (1ULL << i))res += KnightsEV[i];
            else if(A.Queen & (1ULL << i))res += QueensEV[i];
        }
        return res;
    };
    
    double res =  E(L.white) - E(reverseBoard(L.black));

    // res += 0.01 * (countKnightsMoves(L,L.IsWhiteMove) 
    // - countKnightsMoves(L, !L.IsWhiteMove));
    res += 0.008 * (countBishopsMoves(L,L.IsWhiteMove) 
    - countBishopsMoves(L, !L.IsWhiteMove));

    if(!L.IsWhiteMove)res = -res;
    return res;
}
