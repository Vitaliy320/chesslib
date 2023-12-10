#include "Pawn.h"


Pawn::Pawn(char colour){
    this->colour = colour;
    this->name = "Pawn";
    this->symbol = (colour == 'w') ? "P" : "p";
}

std::vector<std::string> Pawn::calculatePossibleMoves(){
    return std::vector<std::string>();
}
