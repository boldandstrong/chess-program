#include "Player.h"


Player::Player(Board* board, string color)
{
	this->_board = board;
	this->_color = color;
}

Player::~Player()
{
	this->_board = nullptr;
	this->_color = " ";
}