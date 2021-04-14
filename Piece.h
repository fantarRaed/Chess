#pragma once
#ifndef DEF_Piece
#define DEF_Piece
#include "Board.h"


class Piece : public Board
{

public:
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
     bool moveRook(Square* thisKnight, Square* thatSpace);
     bool moveKing(Square* thisKing, Square* thatSpace);
     bool moveQueen(Square* thisQueen, Square* thatSpace);
     bool moveBishop(Square* thisBishop, Square* thatSpace);

	bool makeMove(int x1, int y1, int x2, int y2);
	bool isMoved();
	bool playGame();



};





















#endif // !DEF_Piece

