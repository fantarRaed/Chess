#include "Piece.h"

bool Piece::movePawn(Square* thisPawn, Square* thatSpace) {

	using namespace std;
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();


	if (thisPawn->getColor() == WHITE)
	{

		if (pawnY == thatY && thatX == pawnX - 1 && thatSpace->getColor() == NONE || pawnX == 6 && pawnY == thatY && thatX == pawnX - 2 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
		}
		else
			if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX - 1 == thatX && thatSpace->getColor() == BLACK)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				return false;

	}
	else
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnY == thatY && thatX == pawnX + 1 && thatSpace->getColor() == NONE || pawnX == 1 && pawnY == thatY && thatX == pawnX + 2)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX + 1 == thatX && thatSpace->getColor() == WHITE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					return true;
				}
				else
					return false;
		}
		else
			return false;
}

bool Piece::moveKnight(Square* thisKnight, Square* thatSpace)
{

	int knightX = thisKnight->getX();
	int knightY = thisKnight->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
	{
		thatSpace->setSpace(thisKnight);
		thisKnight->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}
bool Piece::moveRook(Square* thisRook, Square* thatSpace)
{
    int RookX = thisRook->getX();
	int rookY = thisRook->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	if (RookX==thatX || rookY==thatY)
    {
       thatSpace->setSpace(thisRook);
		thisRook->setEmpty();
		return true;
    }
	else
	{
		return false;
	}
}
 bool Piece::moveKing(Square* thisKing, Square* thatSpace)
{
    int kingX = thisKing->getX();
	int KingY = thisKing->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	thatSpace->setSpace(thisKing);
		thisKing->setEmpty();
		return true;

  }
     bool Piece::moveQueen(Square* thisQueen, Square* thatSpace)
     {
    int QueenX = thisQueen->getX();
	int QueenY = thisQueen->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	thatSpace->setSpace(thisQueen);
		thisQueen->setEmpty();
		return true;

     }
     bool Piece::moveBishop(Square* thisBishop, Square* thatSpace)
     {
    int BishopX = thisBishop->getX();
	int BishopXY = thisBishop->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	thatSpace->setSpace(thisBishop);
		thisBishop->setEmpty();
		return true;

     }

bool  Piece::makeMove(int x1, int y1, int x2, int y2) {
	using namespace std;

	Square* from = getSquare(x1, y1);
	Square* to = getSquare(x2, y2);
	if (from->getColor() == to->getColor() && to->getColor() != NONE)
	{
		cout << "You have a piece right there " << endl;
		return false;

	}



	switch (from->getPiece())
	{

	case PAWN: return movePawn(from, to);
		break;
	case KNIGHT: return moveKnight(from, to);
		break;
		case ROOK: return moveRook(from,to);
		break;
	case KING: return moveKing(from,  to);
		break;
		case BISHOP : return moveBishop(from,to);
		break;
		case QUEEN : return moveQueen(from,to);
		break;

	case EMPTY: cout << "You do not have a piece there" << endl;  return false;
		break;
	default: cout << "Something went wrong in the switch statement in makeMove()" << endl;
		break;
	}
	return false;
}
bool Piece::isMoved() {
	using namespace std;
	string move;
	int x1, x2, y1, y2;
	bool stop = false;


	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move with 4 numbers. Type in first the Line(L) in each pair." << endl << "Example: 7655 means you want to move your piece from 76 position to 55 position " << endl;
		cin >> move;
		x1 = move[0] - 48;
		y1 = move[1] - 48;
		x2 = move[2] - 48;
		y2 = move[3] - 48;


		if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>8)
		{
			cout << "One of your numbers is not acceptable" << endl;

		}

		else if (getSquare(x1, y1)->getColor() == turn)

			{
				if (makeMove(x1, y1, x2, y2) == false)
				{
					cout << "Invalid move, try again." << endl;
				}
				else
					stop = true;
			}
		else if (getSquare(x1, y1)->getPiece() == EMPTY)
		{
			cout << "You do not have a piece there" << endl;
		}

		else
				cout << "That's not your piece. Try again." << endl;






	}



	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;

	return true;

}

bool Piece::playGame()
{
	system("cls");
	printBoard();
	return isMoved();

}


