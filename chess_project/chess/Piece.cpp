#include "Piece.h"

Piece::Piece(string type, string place, Board* board, string color)
{
    this->_type = type;
    this->_board = board;
    this->_place = place;
    this->_color = color;
}


Piece::~Piece()
{
    this->_type = " ";
    this->_board = nullptr;
    this->_place = " ";
}

string Piece::returnType() const
{
    return this->_type;
}

string Piece::getType() const
{
    return this->_type;
}

string Piece::getColor() const
{
    return this->_color;
}

void Piece::setPlace(string place)
{
    this->_place = place;
}