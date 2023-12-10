#include "King.h"


King::King(char colour){
    this->colour = colour;
    this->name = "King";
    this->symbol = (colour == 'w') ? "K" : "k";
}

std::vector<std::string> King::calculatePossibleMoves(){
    return std::vector<std::string>();
}

bool King::getInCheck(){
    return _inCheck;
}

void King::setInCheck(bool inCheck){
    _inCheck = inCheck;
}
