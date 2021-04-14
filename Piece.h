#pragma once
#ifndef DEF_Piece
#define DEF_Piece
#include "Board.h"


class Piece : public Board
{

public:
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);
	bool isMoved();
	bool playGame();



};





















#endif // !DEF_Piece

