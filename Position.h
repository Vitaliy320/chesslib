#pragma once
#ifndef POSITION_H
#define POSITION_H

#endif // POSITION_H


#include <string>
#include <vector>
#include <map>
#include <memory>
#include <typeindex>
#include "Square.h"



class Position {
public:
    Position();
    Position(char columns[], int nOfColumns, char rows[], int nOfRows, std::string fen);
    void positionFromFEN(std::string fen);
    std::string getFEN();
    void setFEN(std::string fen);
    void setSquares(std::map<std::string, std::shared_ptr<Square>> squares);
    std::map<std::string, std::shared_ptr<Square>> getSquares();
    std::shared_ptr<Square> getSquareByCoordinates(std::pair<char, char> coordinates);
    void makeMove(std::pair<char, char> moveFrom, std::pair<char, char> moveTo);

private:
    std::string _fen;
    std::map<std::string, std::shared_ptr<Square>> _squares;
    char _activeColour;
    std::string _castleOptions;
    std::string _enPassantSquare;
    int _halfMoveClock;
    int _fullMoveNumber;
    int _numberOfColumns;
    int _numberOfRows;
    char* _columns;
    char* _rows;
    std::map<char, std::pair<std::type_index, char>> _pieces;
    std::shared_ptr<Piece> _createPiece(char pieceSymbol);
};
