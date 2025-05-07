#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Piece.hpp"
#include "ChessBoard.hpp"
#include <cmath>

class Queen : public Piece {
public:
    Queen(std::string color) : Piece("Queen", color) {}

    std::string getSymbol() const override {
        return color[0] + std::string("Q");
    }

    bool isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const override;
};

#endif
