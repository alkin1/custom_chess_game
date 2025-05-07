#include "../include/Piece.hpp"

Piece::Piece(std::string type, std::string color)
    : type(std::move(type)), color(std::move(color)) {}

std::string Piece::getType() const {
    return type;
}

std::string Piece::getColor() const {
    return color;
}

std::string Piece::getSymbol() const {
    return color[0] + type.substr(0, 1); // örn: "wK"
}
