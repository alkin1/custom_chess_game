#include "../include/Queen.hpp"

bool Queen::isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const {
    int dx = std::abs(fromX - toX);
    int dy = std::abs(fromY - toY);

    if (dx == dy || fromX == toX || fromY == toY) {
        // Rook veya Bishop gibi hareket edebilir, yol kontrolü yok — isteğe bağlı eklenebilir
        auto target = board.getPiece(toX, toY);
        return !target || target->getColor() != this->getColor();
    }

    return false;
}
