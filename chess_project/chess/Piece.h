#pragma once
#include <iostream>
#include "Board.h"
#include <math.h>
using namespace std;

class Board;

class Piece
{
public:
	virtual int move(string dest) = 0;
	virtual int isValid(string dest) const = 0;
protected:
	char type;
	string place;
	Board* _board;
};