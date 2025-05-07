#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

class ChessBoard;  // forward declaration

class Piece {
public:
    Piece(std::string type, std::string color);
    virtual ~Piece() = default;

    std::string getType() const;
    std::string getColor() const;
    virtual std::string getSymbol() const;

    // 🔥 Taş sınıfları bunu override edecek
    virtual bool isMoveValid(int fromX, int fromY, int toX, int toY, const ChessBoard& board) const = 0;

protected:
    std::string type;
    std::string color;
};

#endif
