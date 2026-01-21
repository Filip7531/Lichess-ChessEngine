#include "Hash.h"
#include <random>
#include <chrono>

ull myHash(const Pos &P) {
    static ull Z[2][6][64]; 
    static ull ZMove;        
    static bool init = false;

    if(!init) {
        std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        for(int c = 0; c < 2; c++)
            for(int f = 0; f < 6; f++)
                for(int i = 0; i < 64; i++)
                    Z[c][f][i] = rng();
        ZMove = rng();
        init = true;
    }

    ull h = 0;
    auto E = [&](const Board &B, int color) {
        for(int i = 0; i < 64; i++) {
            if(B.Pawn   & (1ULL << i)) h ^= Z[color][0][i];
            if(B.Rook   & (1ULL << i)) h ^= Z[color][1][i];
            if(B.Queen  & (1ULL << i)) h ^= Z[color][2][i];
            if(B.Knight & (1ULL << i)) h ^= Z[color][3][i];
            if(B.Bishop & (1ULL << i)) h ^= Z[color][4][i];
            if(B.King   & (1ULL << i)) h ^= Z[color][5][i];
        }
    };

    E(P.white, 0);
    E(P.black, 1);

    if(P.IsWhiteMove) h ^= ZMove;

    return h;
}

size_t PosHash::operator()(const Pos &P) const {
    return myHash(P);
}
