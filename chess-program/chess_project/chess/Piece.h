#pragma once
#include <iostream>
#include <math.h>
#include "string.h"
using namespace std;

class Board;

class Piece
{
public:
	Piece(string type = "", string place = "", Board* board = nullptr, string color = "");
	~Piece();
	virtual int isMoveValid(string dest) const = 0;

	void setPlace(string place);

	string getColor() const;
	string returnType() const;
	string getType() const;
protected:
	string _color;
	string _type;
	string _place;
	Board* _board;
};