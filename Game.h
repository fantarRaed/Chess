#pragma once
#ifndef DEF_Piece
#define DEF_Piece
#include "Board.h"


class Game : public Board
{
	int m = 0, f = 0;
	int kingWhiteX = 0, kingWhiteY = 0, kingBlackX = 0, kingBlackY = 0;
	bool checked = false;
	bool whiteShortCastle = true, whiteLongCastle = true, blackShortCastle = true, blackLongCastle = true;

public:
	
	

	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool fakeMovePawn(Square* thisPawn, Square* thatSpace);
	void reculePawn(Square* thisPawn, Square* thatSpace);
	void pawnPromote(int a, int b, char x);

	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool fakeMoveKnight(Square* thisKnight, Square* thatSpace);

	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool fakeMoveBishop(Square* thisBishop, Square* thatSpace);
	bool moveBishopWithoutOutputs(Square* thisBishop, Square* thatSpace);

	bool moveRook(Square* thisKnight, Square* thatSpace);
	bool fakeMoveRook(Square* thisRook, Square* thatSpace);
	
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool fakeMoveQueen(Square* thisQueen, Square* thatSpace);

	bool moveKing(Square* thisKing, Square* thatSpace);
	bool fakeMoveKing(Square* thisKing, Square* thatSpace);
	bool kingCastle(Square* thisKing, Square* thatSpace);

	bool makeMove(int x1, int y1, int x2, int y2);
	bool fakeMakeMove(int x1, int y1, int x2, int y2);
	bool makeMoveWithoutOutputs(int x1, int y1, int x2, int y2);

	bool whiteIsChecked(int x1, int y1);
	bool blackIsChecked(int, int);
	bool whiteIsCheckMated();
	bool blackIsCheckMated();
	
	bool isMoved();
	bool playGame();
	
	

	



	



};





















#endif // !DEF_Piece

