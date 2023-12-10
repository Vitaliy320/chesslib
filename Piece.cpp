#include "Piece.h"


char Piece::getColour(){
    return colour;
}

std::vector<std::string> Piece::getPossibleMoves(){
    return possibleMoves;
}

void Piece::setPossibleMoves(std::vector<std::string> moves){
    possibleMoves = moves;
}

std::vector<std::string> Piece::calculatePossibleMoves(){
    return std::vector<std::string>();
}

std::string Piece::getSymbol(){
    return symbol;
}
