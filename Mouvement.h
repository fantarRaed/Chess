#pragma once
#ifndef DEF_Piece
#define DEF_Piece
#include "Board.h"


class Mouvement : public Board
{
    int m = 0, l = 0, n = 0, r = 0, k = 0, f = 0, j = 0, s = 0, w = 0;
    int kingWhiteX = 0, kingWhiteY = 0, kingBlackX = 0, kingBlackY = 0;
    bool checked = false;
    bool whiteShortCastle = true, whiteLongCastle = true, blackShortCastle = true, blackLongCastle = true;

public:

    bool movePawn(Square* thisPawn, Square* thatSpace);
    bool softMovePawn(Square* thisPawn, Square* thatSpace);
    void reculePawn(Square* thisPawn, Square* thatSpace);

    bool moveKnight(Square* thisKnight, Square* thatSpace);
    bool softMoveKnight(Square* thisKnight, Square* thatSpace);

    bool moveRook(Square* thisKnight, Square* thatSpace);
    bool moveBishop(Square* thisBishop, Square* thatSpace);
    bool softMoveBishop(Square*thisBishop, Square* thatSpace);

    bool moveQueen(Square* thisQueen, Square* thatSpace);
    bool softMoveQueen(Square* thisQueen, Square* thatSpace);


    bool moveKing(Square* thisKing, Square* thatSpace);
    bool softMoveKing(Square* thisKing, Square* thatSpace);
    bool kingCastle(Square* thisKing, Square* thatSpace);
    bool makeMove(int x1, int y1, int x2, int y2);
    bool makeMoveWithoutOutputs(int x1, int y1, int x2, int y2);
    bool softMakeMove(int x1, int y1, int x2, int y2);

    bool isMoved();
    bool playGame();
    bool whiteIsChecked(int x1, int y1);
    bool blackIsChecked(int, int);
    bool whiteIsCheckMated();
    bool validMove(int x1, int y1, int x2, int y2);
    bool validValidMove();
    void pawnPromote(int a, int b, char x);
};





















#endif // !DEF_Piece

