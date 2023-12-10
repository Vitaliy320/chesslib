#include "Bishop.h"


Bishop::Bishop(char colour){
    this->colour = colour;
    this->name = "Bishop";
    this->symbol = (colour == 'w') ? "B" : "b";
}

std::vector<std::string> Bishop::calculatePossibleMoves(){
    return std::vector<std::string>();
}
