#pragma once

#include "Piece.hpp"
class ChessBoard; // Forward declaration

class Rook : public Piece {
public:
    Rook(const std::string& color) : Piece("Rook", color) {}
    bool isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const override;
};
