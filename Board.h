#pragma once
#ifndef BOARD_H
#define BOARD_H

#endif // BOARD_H

#include <iostream>
#include <vector>
#include <map>
//#include "Square.h"
#include <tuple>
#include <map>
#include "Position.h"


class Board{
public:
    Board();
    Board(char* columns, int numberOfColumns, char* rows, int numberOfRows, std::string fen);
    void updateBoard(std::string fen);
    virtual void initialiseBoard();
//    std::map<std::string, std::shared_ptr<Square>> getSquares();

//    Position fenToPosition();
    void makeMove(std::pair<char, char> moveFrom, std::pair<char, char> moveTo);
    void makeMoveStr(std::string moveFrom, std::string moveTo);
    void createBoardRows(std::map<std::string, std::shared_ptr<Square>> squares);
    std::vector<std::string> boardToString();

protected:
    int numberOfColumns;
    int numberOfRows;

    std::string boardFEN;
    char* columns;
    char* rows;

private:
    std::shared_ptr<Position> _position;
    std::vector<std::vector<std::shared_ptr<Square>>> _boardRows;
};
