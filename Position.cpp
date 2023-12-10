#include "Position.h"
#include "Utils.h"
#include <algorithm>
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


Position::Position(){};

Position::Position(char columns[], int nOfColumns, char rows[], int nOfRows, std::string fen) {
    _fen = fen;
    _numberOfColumns = nOfColumns;
    _numberOfRows = nOfRows;
    _columns = columns;
    _rows = rows;
}

void Position::setSquares(std::map<std::string, std::shared_ptr<Square>> squares){
    _squares = squares;
}

std::map<std::string, std::shared_ptr<Square>> Position::getSquares(){
    return _squares;
}

std::shared_ptr<Piece> Position::_createPiece(char pieceSymbol){
    switch (pieceSymbol) {
    case 'r':
        return std::make_shared<Piece>(Rook('b'));
    case 'n':
        return std::make_shared<Piece>(Knight('b'));
    case 'b':
        return std::make_shared<Piece>(Bishop('b'));
    case 'q':
        return std::make_shared<Piece>(Queen('b'));
    case 'k':
        return std::make_shared<Piece>(King('b'));
    case 'p':
        return std::make_shared<Piece>(Pawn('b'));
    case 'R':
        return std::make_shared<Piece>(Rook('w'));
    case 'N':
        return std::make_shared<Piece>(Knight('w'));
    case 'B':
        return std::make_shared<Piece>(Bishop('w'));
    case 'Q':
        return std::make_shared<Piece>(Queen('w'));
    case 'K':
        return std::make_shared<Piece>(King('w'));
    case 'P':
        return std::make_shared<Piece>(Pawn('w'));

    default:
        return std::make_shared<Piece>(Piece());
    }
}

void Position::positionFromFEN(std::string fen) {
    std::vector<std::string> splitFEN = splitString(fen, ' ');
    auto boardFEN          = splitFEN[0];
    auto colourFEN         = splitFEN[1];
    auto castleFEN         = splitFEN[2];
    auto enPassantFEN      = splitFEN[3];
    auto halfMoveFEN       = splitFEN[4];
    auto fullMoveNumberFEN = splitFEN[5];

    _activeColour = colourFEN[0];
    _castleOptions = castleFEN;
    _enPassantSquare = enPassantFEN;
    _halfMoveClock = std::stoi(halfMoveFEN);
    _fullMoveNumber = std::stoi(fullMoveNumberFEN);

    std::vector<std::string> boardRows = splitString(boardFEN, '/');
    std::reverse(boardRows.begin(), boardRows.end());

    std::string row;
    std::shared_ptr<Piece> piece;
    int columnCounter;
    char columnCoordinate;
    char rowCoordinate;
    std::string squareCoordinates;
    int emptySquares;

    for (int j = 0; j < boardRows.size(); j++){
        row = boardRows[j];
        rowCoordinate = _rows[j];
        columnCounter = 0;

        for (char cellValue: row){
            if (std::isdigit(cellValue)){
                columnCounter += cellValue - '0';
            }
            else{
                piece = _createPiece(cellValue);
                columnCoordinate = _columns[columnCounter];

                getSquareByCoordinates(std::make_pair(columnCoordinate, rowCoordinate))->setPiece(piece);
                columnCounter++;
            }
        }
    }

}

std::shared_ptr<Square> Position::getSquareByCoordinates(std::pair<char, char> coordinates){
    std::string key = std::string(1, coordinates.first) + std::string(1, coordinates.second);
    return _squares.at(key);
}

void Position::makeMove(std::pair<char, char> moveFrom, std::pair<char, char> moveTo){
    std::shared_ptr<Square> fromSquare = getSquareByCoordinates(moveFrom);
    std::shared_ptr<Square> toSquare = getSquareByCoordinates(moveTo);

    std::shared_ptr<Piece> piece = fromSquare->getPiece();
    fromSquare->removePiece();
    toSquare->setPiece(piece);
}
