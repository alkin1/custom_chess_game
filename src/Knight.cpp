#include "Knight.hpp"
#include "ChessBoard.hpp"
#include <cmath>

bool Knight::isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const {
    int dx = std::abs(toX - fromX);
    int dy = std::abs(toY - fromY);

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
        auto target = board.getPiece(toX, toY);
        return !target || target->getColor() != this->getColor();
    }

    return false;
}
