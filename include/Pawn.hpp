#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"
#include "ChessBoard.hpp"
#include <cmath>

class Pawn : public Piece {
public:
    Pawn(std::string color) : Piece("Pawn", color) {}

    std::string getSymbol() const override {
        return color[0] + std::string("P");
    }

    bool isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const override;
};

#endif
