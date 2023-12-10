#pragma once
#ifndef ROOK_H
#define ROOK_H

#endif // ROOK_H


#include "Piece.h"


class Rook: public Piece{
public:
    Rook(char colour);
    std::vector<std::string> calculatePossibleMoves() override;
protected:

};
