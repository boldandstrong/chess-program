#include "Player.h"


Player::Player(Board* board, string color, string king_loc)
{
	this->_king_place  = king_loc;
	this->_board = board;
	this->_color = color;
}

Player::~Player()
{
	this->_king_place = " ";
	this->_board = nullptr;
	this->_color = " ";
}