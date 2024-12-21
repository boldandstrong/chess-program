#pragma once
#include <iostream>
#include "Board.h"
#include <math.h>
#include "string.h"
using namespace std;

class Board;

class Piece
{
public:
	Piece(string type = "", string place = "", Board* board = nullptr, string color = "");
	~Piece();
	virtual int move(string dest) = 0;
	virtual int isValid(string dest) const = 0;
	string getColor() const;

	string returnType() const ;

protected:
	string _color;
	string _type;
	string _place;
	Board* _board;
};