#pragma once
#ifndef KING_H
#define KING_H

#endif // KING_H


#include "Piece.h"


class King: public Piece{
public:
    King(char colour);
    std::vector<std::string> calculatePossibleMoves() override;
    bool getInCheck();
    void setInCheck(bool inCheck);
protected:
private:
    bool _inCheck;
};
