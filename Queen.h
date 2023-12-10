#pragma once
#ifndef QUEEN_H
#define QUEEN_H

#endif // QUEEN_H


#include "Piece.h"


class Queen: public Piece{
public:
    Queen(char colour);
    std::vector<std::string> calculatePossibleMoves() override;
protected:

};
