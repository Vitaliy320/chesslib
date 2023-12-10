#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#endif // SQUARE_H

#include <iostream>
#include "Piece.h"
#include <memory>

class Square{
public:
    Square(std::pair<char, char> coordinates);
    std::pair<char, char> getCoordinates();
    std::shared_ptr<Piece> getPiece();
    void setPiece(std::shared_ptr<Piece> piece);
    void removePiece();
    void capturePiece(std::shared_ptr<Piece> capturingPiece);

private:
    std::pair<char, char> _coordinates;
    std::shared_ptr<Piece> _piece;
};
