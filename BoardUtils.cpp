#include "BoardUtils.h"
#include <iostream>

void setBit(ull &bitboard, int rank, int file) {
    bitboard |= (1ULL << (rank * 8 + file));
}

bool getBit(ull bitboard, int rank, int file) {
    return (bitboard >> (rank * 8 + file)) & 1;
}

Pos InBoard(const std::vector<std::string> &boardStrings, bool whiteMove) {

    Pos pos;
    pos.IsWhiteMove = whiteMove;
    pos.white = {0,0,0,0,0,0};
    pos.black = {0,0,0,0,0,0};

    for(int rank = 0; rank < 8; rank++) {
        for(int file = 0; file < 8; file++) {
            char c = boardStrings[rank][file];
            switch(c) {
                case 'P': setBit(pos.white.Pawn, rank, file); break;
                case 'R': setBit(pos.white.Rook, rank, file); break;
                case 'N': setBit(pos.white.Knight, rank, file); break;
                case 'B': setBit(pos.white.Bishop, rank, file); break;
                case 'Q': setBit(pos.white.Queen, rank, file); break;
                case 'K': setBit(pos.white.King, rank, file); break;
                case 'p': setBit(pos.black.Pawn, rank, file); break;
                case 'r': setBit(pos.black.Rook, rank, file); break;
                case 'n': setBit(pos.black.Knight, rank, file); break;
                case 'b': setBit(pos.black.Bishop, rank, file); break;
                case 'q': setBit(pos.black.Queen, rank, file); break;
                case 'k': setBit(pos.black.King, rank   , file); break;
                case '.': break; // puste pole
                default: std::cerr << "Nieznany znak: " << c << std::endl;
            }
        }
    }

    
    return pos;
}
std::vector<std::string> outBoard(const Pos& pos) {
    std::vector<std::string> boardStrings(8, std::string(8, '.'));

    for(int rank = 7; rank >= 0; rank--) {
        for(int file = 0; file < 8; file++) {
            if(getBit(pos.white.Pawn, rank, file)) boardStrings[rank][file] = 'P';
            else if(getBit(pos.white.Rook, rank, file)) boardStrings[rank][file] = 'R';
            else if(getBit(pos.white.Knight, rank, file)) boardStrings[rank][file] = 'N';
            else if(getBit(pos.white.Bishop, rank, file)) boardStrings[rank][file] = 'B';
            else if(getBit(pos.white.Queen, rank, file)) boardStrings[rank][file] = 'Q';
            else if(getBit(pos.white.King, rank, file)) boardStrings[rank][file] = 'K';
            else if(getBit(pos.black.Pawn, rank, file)) boardStrings[rank][file] = 'p';
            else if(getBit(pos.black.Rook, rank, file)) boardStrings[rank][file] = 'r';
            else if(getBit(pos.black.Knight, rank, file)) boardStrings[rank][file] = 'n';
            else if(getBit(pos.black.Bishop, rank, file)) boardStrings[rank][file] = 'b';
            else if(getBit(pos.black.Queen, rank, file)) boardStrings[rank][file] = 'q';
            else if(getBit(pos.black.King, rank, file)) boardStrings[rank][file] = 'k';
        }
    }
    return boardStrings;
}
