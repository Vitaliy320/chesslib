#pragma once
#ifndef BISHOP_H
#define BISHOP_H

#endif // BISHOP_H


#include "Piece.h"


class Bishop: public Piece{
public:
    Bishop(char colour);
    std::vector<std::string> calculatePossibleMoves() override;
protected:

};
