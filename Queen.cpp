#include "Queen.h"


Queen::Queen(char colour){
    this->colour = colour;
    this->name = "Queen";
    this->symbol = (colour == 'w') ? "Q" : "q";
}

std::vector<std::string> Queen::calculatePossibleMoves(){
    return std::vector<std::string>();
}
