#include "Utils.h"

ull reverseBits(ull n) {
    ull result = 0;
    for (int i = 0; i < 64; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}
Board reverseBoard(Board A){
    A.Pawn   = reverseBits(A.Pawn);
    A.Rook   = reverseBits(A.Rook);
    A.Knight = reverseBits(A.Knight);
    A.Bishop = reverseBits(A.Bishop);
    A.Queen  = reverseBits(A.Queen);
    A.King   = reverseBits(A.King);
    return A;
}
