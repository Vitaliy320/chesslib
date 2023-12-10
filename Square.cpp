#include "Square.h"

Square::Square(std::pair<char, char> coordinates){
    _coordinates = coordinates;
}

std::shared_ptr<Piece> Square::getPiece(){
    return _piece;
}

void Square::setPiece(std::shared_ptr<Piece> piece){
    _piece = piece;
}

void Square::removePiece(){
    _piece = nullptr;
}

void Square::capturePiece(std::shared_ptr<Piece> capturingPiece){
    _piece = capturingPiece;
}
