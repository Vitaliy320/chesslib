#pragma once
#ifndef CLASSICBOARD_H
#define CLASSICBOARD_H

#endif // CLASSICBOARD_H

#include "Board.h"


class ClassicBoard : public Board{
public:
    ClassicBoard(char* columns, int numberOfColumns, char* rows, int numberOfRows, std::string fen);

    void initialiseBoard() override;

};
