#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "Square.h"


class Board
{


public:
	
	Color turn = WHITE;
	Square square[8][8];
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


};

