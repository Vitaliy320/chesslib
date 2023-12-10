#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H

#endif // KNIGHT_H


#include "Piece.h"


class Knight: public Piece{
public:
    Knight(char colour);
    std::vector<std::string> calculatePossibleMoves() override;
protected:

};
