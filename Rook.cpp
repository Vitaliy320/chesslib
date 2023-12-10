#include "Rook.h"


Rook::Rook(char colour){
    this->colour = colour;
    this->name = "Rook";
    this->symbol = (colour == 'w') ? "R" : "r";
}

std::vector<std::string> Rook::calculatePossibleMoves(){
    return std::vector<std::string>();
}
