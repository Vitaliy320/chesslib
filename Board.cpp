#include "Board.h"
#include <sstream>


Board::Board(){}

Board::Board(char* columns, int numberOfColumns, char* rows, int numberOfRows, std::string fen){
    this->columns = columns;
    this->rows = rows;
    this->numberOfColumns = numberOfColumns;
    this->numberOfRows = numberOfRows;
    this->boardFEN = fen;
    this->_position = std::make_shared<Position>(Position(columns, numberOfColumns, rows, numberOfRows, fen));

    Board::initialiseBoard();
    Board::updateBoard(this->boardFEN);
}

void Board::initialiseBoard(){
    std::string coordinatesString;
    //    "a1", "a2"

    //    for (auto coordinates : bishop.getPossibleMoves()){
    //        newCoordinates = std::make_pair<char, char>(square.getCoordinates()[0] + coordinates[0], square.getCoordinates()[1] + coordinates[1])
    //            <'a', '1'>
    //            squares["a1"]
    //        }

    char column;
    char row;

    std::map<std::string, std::shared_ptr<Square>> squares;

    for (int i = 0; i < numberOfColumns; i++){
        column = columns[i];
        for (int j = 0; j < numberOfRows; j++){
            row = rows[j];

            coordinatesString = std::string(1, column) + std::string(1, row);
            squares[coordinatesString] = std::make_shared<Square>(Square(std::make_pair(column, row)));
        }
    }

    _position->setSquares(squares);
}

void Board::updateBoard(std::string fen){
    _position->positionFromFEN(fen);
}

void Board::makeMove(std::pair<char, char> moveFrom, std::pair<char, char> moveTo){
    _position->makeMove(moveFrom, moveTo);
}

void Board::makeMoveStr(std::string moveFrom, std::string moveTo){
    _position->makeMove(std::make_pair(moveFrom[0], moveFrom[1]), std::make_pair(moveTo[0], moveTo[1]));
}

void Board::createBoardRows(std::map<std::string, std::shared_ptr<Square>> squares){
    std::string coordinatesString;
    std::shared_ptr<Square> square;

    char column;
    char row;

    std::vector<std::shared_ptr<Square>> currentRow;
    std::vector<std::vector<std::shared_ptr<Square>>> allRows;

    for (int j = numberOfRows - 1; j >= 0; j--){
        currentRow = std::vector<std::shared_ptr<Square>>();
        for (int i = 0; i < numberOfColumns; i++){
            currentRow.push_back(_position->getSquareByCoordinates(std::make_pair(columns[i], rows[j])));
        }
        allRows.push_back(currentRow);
    }

    _boardRows = allRows;
}


std::vector<std::string> Board::boardToString(){
    Board::createBoardRows(_position->getSquares());

    std::vector<std::string> rowsVector;

    rowsVector.push_back("  A B C D E F G H ");
    rowsVector.push_back("                  ");

    std::string currentRow;
    std::stringstream ss;
    std::vector<std::shared_ptr<Square>> row;

    for (int i = 0; i < _boardRows.size(); i++){
        ss.str("");
        ss << 8 - i;
        currentRow += ss.str() + " ";

        row = _boardRows[i];
        for (std::shared_ptr<Square> square: row){
            if (square->getPiece() == nullptr){
                currentRow += "  ";
            }
            else{
                currentRow += square->getPiece()->getSymbol() + " ";
            }
        }

        rowsVector.push_back(currentRow);
        currentRow = "";

    }
    return rowsVector;
}
