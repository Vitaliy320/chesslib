#include "Knight.h"


Knight::Knight(char colour){
    this->colour = colour;
    this->name = "Knight";
    this->symbol = (colour == 'w') ? "N" : "n";
}

std::vector<std::string> Knight::calculatePossibleMoves(){
    return std::vector<std::string>();
}
