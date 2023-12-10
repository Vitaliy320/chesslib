#pragma once
#ifndef PAWN_H
#define PAWN_H

#endif // PAWN_H


#include "Piece.h"


class Pawn: public Piece{
public:
    Pawn(char colour);
    std::vector<std::string> calculatePossibleMoves() override;
protected:

};
