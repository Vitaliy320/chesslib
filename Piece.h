#pragma once
#ifndef PIECE_H
#define PIECE_H

#endif // PIECE_H

#include <vector>
#include <string>


class Piece {
public:
    char getColour();
//    virtual ~Piece();
    std::vector<std::string> getPossibleMoves();
    void setPossibleMoves(std::vector<std::string> moves);
    virtual std::vector<std::string> calculatePossibleMoves();
    char colour;
    std::vector<std::string> possibleMoves;
    std::string getSymbol();

protected:
    std::string name;
    std::string symbol;
};
