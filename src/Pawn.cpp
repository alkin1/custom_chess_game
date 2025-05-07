#include "../include/Pawn.hpp"

bool Pawn::isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const {
    int direction = (color == "white") ? 1 : -1;

    // 1 kare ileri
    if (toX == fromX && toY == fromY + direction && board.getPiece(toX, toY) == nullptr) {
        return true;
    }

    // 2 kare ileri (başlangıçta)
    if (toX == fromX && toY == fromY + 2 * direction &&
        ((color == "white" && fromY == 1) || (color == "black" && fromY == 6)) &&
        board.getPiece(toX, toY) == nullptr &&
        board.getPiece(toX, fromY + direction) == nullptr) {
        return true;
    }

    // Şimdilik çapraz yeme desteklenmiyor

    return false;
}
