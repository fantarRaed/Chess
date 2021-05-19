#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "Square.h"


class Board
{
protected:
	Color turn = WHITE;
	Square square[8][8];

public:

	Board();
	Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	Square softGetSquare(int x, int y) {
		return square[x][y];
	}
	void setSquare(Square* s, int x, int y) {
		square[x][y] = *s;
	}
	void setBoard();
	void printBoard();
	Board(const Board& b);



};

