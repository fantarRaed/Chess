#include "Mouvement.h"
#include <vector>
#include <algorithm>
#include <assert.h>

bool Mouvement::movePawn(Square* thisPawn, Square* thatSpace) {

	using namespace std;
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	char a;



	if (thisPawn->getColor() == WHITE)
	{

		if (pawnY == thatY && thatX == pawnX - 1 && thatSpace->getColor() == NONE
			|| pawnX == 6 && pawnY == thatY && thatX == pawnX - 2 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			if (thatX == 0) {
				cout << "You want to promote your pawn to? Enter a character: Q stands for Queen, H for Knight ..";
				cin >> a;
				pawnPromote(thatX, thatY, a);
			}
			return true;
		}
		else
			if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX - 1 == thatX && thatSpace->getColor() == BLACK)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				if (thatX == 0) {
					cout << "You want to promote your pawn to? Enter a character: Q stands for Queen, H for Knight ..";
					cin >> a;
					pawnPromote(thatX, thatY, a);
				}
				return true;
			}

		else
				return false;




	}
	else
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnY == thatY && thatX == pawnX + 1 && thatSpace->getColor() == NONE
				|| pawnX == 1 && pawnY == thatY && thatX == pawnX + 2)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();

				if (thatX == 7) {
					cout << "You want to promote your pawn to? Enter a character: Q stands for Queen, H for Knight ..";
					cin >> a;
					pawnPromote(thatX, thatY, a);
					}
				return true;
			}
			else
				if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX + 1 == thatX && thatSpace->getColor() == WHITE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
				    if (thatX == 7) {
					      cout << "You want to promote your pawn to? Enter a character: Q stands for Queen, H for Knight ..";
					      cin >> a;
					      pawnPromote(thatX, thatY, a);
				    }
					return true;
				}

				else
					return false;
		}
	else
		return false;
}


bool Mouvement::softMovePawn(Square* thisPawn, Square* thatSpace)
{
	using namespace std;
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();



	if (thisPawn->getColor() == WHITE)
	{

		if (pawnY == thatY && thatX == pawnX - 1 && thatSpace->getColor() == NONE
			|| pawnX == 6 && pawnY == thatY && thatX == pawnX - 2 && thatSpace->getColor() == NONE)
		{

			return true;
		}
		else
			if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX - 1 == thatX && thatSpace->getColor() == BLACK)
			{

				return true;
			}
			else
				return false;

	}
	else
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnY == thatY && thatX == pawnX + 1 && thatSpace->getColor() == NONE
				|| pawnX == 1 && pawnY == thatY && thatX == pawnX + 2)
			{

				return true;
			}
			else
				if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX + 1 == thatX && thatSpace->getColor() == WHITE)
				{

					return true;
				}
				else
					return false;
		}
		else
			return false;
}

void Mouvement::reculePawn(Square* thisPawn, Square* thatSpace)
{
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	if (thisPawn->getColor() == WHITE)
	{

		if (pawnY == thatY && thatX == pawnX + 1 && thatSpace->getColor() == NONE
			|| pawnX == 4 && pawnY == thatY && thatX == pawnX + 2 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();

		}
		else
			if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX + 1 == thatX && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
			}


	}
}

bool Mouvement::moveKnight(Square* thisKnight, Square* thatSpace)
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
bool Mouvement::softMoveKnight(Square* thisKnight, Square* thatSpace)
{
	int knightX = thisKnight->getX();
	int knightY = thisKnight->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
	{

		return true;
	}
	else
	{
		return false;
	}
}
bool Mouvement::moveBishop(Square* thisBishop, Square* thatSpace) {
	int bishopX = thisBishop->getX();
	int bishopY = thisBishop->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	using namespace std;

	if (abs(bishopX - thatX) == abs(bishopY - thatY)) {

		int j = abs(thatX - bishopX ) - 1  ; // number of squares that might block the bihsopMove
		int i = 0;
		while (i != j) {

				int xx = (thatX - bishopX) / (abs(thatX - bishopX));
				int yy = (thatY - bishopY) / (abs(thatY - bishopY));
				if (square[bishopX + xx * (i+1)][bishopY + yy * (i+1)].getColor() != NONE) {
					cout << "Theres a piece stopping your bishop to move further" << endl;
					return false;
				}

				else {
					i = i + 1;
				}

		}


		thatSpace->setSpace(thisBishop);
		thisBishop->setEmpty();
		return true;
	}
	else {
		return false;
	}



}
bool Mouvement::softMoveBishop(Square* thisBishop, Square* thatSpace)
{
	int bishopX = thisBishop->getX();
	int bishopY = thisBishop->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	using namespace std;
	//if (thatX == bishopX && thatY == bishopY) return false;


	if (abs(bishopX - thatX) == abs(bishopY - thatY)) {

		int j = abs(thatX - bishopX) - 1; // number of squares that might block the bihsopMove
		int i = 0;
		while (i != j) {

			if (thatX != bishopX && thatY != bishopY)
			{

			        int xx = (thatX - bishopX) / (abs(thatX - bishopX));
			        int yy = (thatY - bishopY) / (abs(thatY - bishopY));
			        if (square[bishopX + xx * (i + 1)][bishopY + yy * (i + 1)].getColor() != NONE)
					{
				                //cout << "Theres a piece stopping your bishop to move further" << endl;
				                 return false;
			        }

			        else
					{
				           i = i + 1;
			        }
		    }
			/*else if (thatX == bishopX || thatY == bishopY) {
				for (int s = 0; s < 8; s++) {
						if (square[s][s].getColor() != NONE)
						{
							//cout << "Theres a piece stopping your bishop to move further" << endl;
							return false;
						}

				}
			}*/

		}
		return true;


	 }
	else {
		return false;
	}
}
bool Mouvement::moveQueen(Square* thisQueen, Square* thatSpace) {

	int queenX = thisQueen->getX();
	int queenY = thisQueen->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	int yy;
	int xx;
	bool invalid = false;


	if (queenX != thatX || queenY != thatY)
	{

		if (queenX == thatX)
		{
			yy = (thatY - queenY) / (abs(thatY - queenY));
			for (int i = queenY + yy; i != thatY; i += yy)
			{

				if (square[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else if (queenY == thatY)
			{

				xx = (thatX - queenX) / (abs(thatX - queenX));
				for (int i = queenX + xx; i != thatX; i += xx)
				{
					if (square[i][thatY].getColor() != NONE)
						return false;
				}
			}
		else if (abs(queenX - thatX) == abs(queenY - thatY))

				{
					xx = (thatX - queenX) / (abs(thatX - queenX));
					yy = (thatY - queenY) / (abs(thatY - queenY));

					for (int i = 1; i < abs(queenX - thatX); i++)
					{
						if (square[queenX + xx * i][queenY + yy * i].getColor() != NONE)
							return false;

					}
				}
		else
			 return false;

	}



	if (invalid == false)
	{
		thatSpace->setSpace(thisQueen);
		thisQueen->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}
bool Mouvement::softMoveQueen(Square* thisQueen, Square* thatSpace)
{
	int queenX = thisQueen->getX();
	int queenY = thisQueen->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	int yy;
	int xx;
	bool invalid = false;
	if (queenX != thatX || queenY != thatY)
	{

		if (queenX == thatX)
		{
			yy = (thatY - queenY) / (abs(thatY - queenY));
			for (int i = queenY + yy; i != thatY; i += yy)
			{

				if (square[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else if (queenY == thatY)
		{

			xx = (thatX - queenX) / (abs(thatX - queenX));
			for (int i = queenX + xx; i != thatX; i += xx)
			{
				if (square[i][thatY].getColor() != NONE)
					return false;
			}
		}
		else if (abs(queenX - thatX) == abs(queenY - thatY))

		{
			xx = (thatX - queenX) / (abs(thatX - queenX));
			yy = (thatY - queenY) / (abs(thatY - queenY));

			for (int i = 1; i < abs(queenX - thatX); i++)
			{

				if (square[queenX + xx * i][queenY + yy * i].getColor() != NONE)
					return false;

			}
		}
		else
			return false;

	}



	if (invalid == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Mouvement::moveKing(Square* thisKing, Square* thatSpace)
{
	if (thatSpace->getX() == 7 && thatSpace->getY() == 6 || thatSpace->getX() == 7 && thatSpace->getY() == 2
		|| thatSpace->getX() == 0 && thatSpace->getY() == 6 || thatSpace->getX() == 0 && thatSpace->getY() == 2) {


		return kingCastle(thisKing,thatSpace);


	}

	if (abs(thatSpace->getX() - thisKing->getX()) == 1 || abs(thatSpace->getX() - thisKing->getX()) == 0)
		if (abs(thatSpace->getY() - thisKing->getY()) == 1 || abs(thatSpace->getY() - thisKing->getY()) == 0)
		{
			thatSpace->setSpace(thisKing);
			thisKing->setEmpty();
			return true;
		}

		else return false;
	else return false;

}

bool Mouvement::softMoveKing(Square* thisKing, Square* thatSpace)
{
	if (abs(thatSpace->getX() - thisKing->getX()) == 1 || abs(thatSpace->getX() - thisKing->getX()) == 0)
		if (abs(thatSpace->getY() - thisKing->getY()) == 1 || abs(thatSpace->getY() - thisKing->getY()) == 0)
		{

			return true;
		}

		else return false;
	else return false;
}

bool Mouvement::kingCastle(Square* thisKing,Square* thatSpace)
{

	if (thisKing->getColor() == WHITE ) {

		if (thatSpace->getX() == 7 && thatSpace->getY() == 6 ) {
			if (whiteShortCastle) {
				if (square[7][5].getPiece() == EMPTY && square[7][6].getPiece() == EMPTY && !whiteIsChecked(7, 6) && !whiteIsChecked(7, 5)) {
					square[7][7].setEmpty();
					square[7][4].setEmpty();
					square[7][5].setPieceAndColor(ROOK, WHITE);
					square[7][6].setPieceAndColor(KING, WHITE);
					whiteShortCastle = false;
					return true;
				}
				else return false;
			}
			else return false;
		}
		else if (thatSpace->getX() == 7 && thatSpace->getY() == 2 ) {
			if (whiteLongCastle) {
				if (square[7][3].getPiece() == EMPTY && square[7][2].getPiece() == EMPTY && square[7][1].getPiece() == EMPTY
					&& !whiteIsChecked(7, 3) && !whiteIsChecked(7, 2) && !whiteIsChecked(7, 1)) {
					square[7][0].setEmpty();
					square[7][4].setEmpty();
					square[7][3].setPieceAndColor(ROOK, WHITE);
					square[7][2].setPieceAndColor(KING, WHITE);
					whiteLongCastle = false;
					return true;
				}
				else return false;
			}
			else return false;
		}

		}
		else if (thisKing->getColor() == BLACK) {
		if (thatSpace->getX() == 0 && thatSpace->getY() == 6 ) {
			if (blackShortCastle) {
				if (square[0][5].getPiece() == EMPTY && square[0][6].getPiece() == EMPTY && !blackIsChecked(0, 6) && !blackIsChecked(0, 5)) {

					square[0][7].setEmpty();
					square[0][4].setEmpty();
					square[0][5].setPieceAndColor(ROOK, BLACK);
					square[0][6].setPieceAndColor(KING, BLACK);
					blackShortCastle = false;
					return true;
				}
				else return false;
			}
			else return false;

		}
		else if (thatSpace->getX() == 0 && thatSpace->getY() == 2 ) {
			if (blackLongCastle) {
				if (square[0][3].getPiece() == EMPTY && square[0][2].getPiece() == EMPTY && square[0][1].getPiece() == EMPTY
					&& !blackIsChecked(0, 3) && !blackIsChecked(0, 2) && !blackIsChecked(0, 1)) {
					square[0][0].setEmpty();
					square[0][4].setEmpty();
					square[0][3].setPieceAndColor(ROOK, BLACK);
					square[0][2].setPieceAndColor(KING, BLACK);
					blackLongCastle = false;
					return true;
				}
				else return false;
			}
			else return false;
		}

		}



}


bool Mouvement::moveRook(Square* thisRook, Square* thatSpace)
{
	int RookX = thisRook->getX();
	int rookY = thisRook->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	int test = 1;
	int test1 = 1;
	int x = RookX;
	int x1 = thatX;
	int y = rookY;
	int y1 = thatY;
	if (x > x1)
	{
		while (test == 1 && x > x1)
		{
			x = x - 1;
			Square* nvS = getSquare(x, rookY);
			if (nvS->getColor() == NONE) test = 1; else test = 0;
		}
	}
	if (x < x1)
	{
		while (test == 1 && x < x1)
		{
			x = x + 1; ;
			Square* nvS = getSquare(x, rookY);
			if (nvS->getColor() == NONE) test = 1; else test = 0;
		}

	}
	if (y > y1)
	{
		while (test1 == 1 && y > y1)
		{
			y = y - 1;
			Square* nvS = getSquare(RookX, y);
			if (nvS->getColor() == NONE) test1 = 1; else test1 = 0;
		}
	}
	if (y < y1)
	{
		while (test1 == 1 && y < y1)
		{
			y = y + 1; ;
			Square* nvS = getSquare(RookX, y);
			if (nvS->getColor() == NONE) test1 = 1; else test1 = 0;
		}

	}
	if ((RookX == thatX && test == 1 || rookY == thatY && test == 1) && (RookX == thatX && test1 == 1 || rookY == thatY && test1 == 1))
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



bool  Mouvement::makeMove(int x1, int y1, int x2, int y2) {
	using namespace std;

	Square* from = getSquare(x1, y1);
	Square* to = getSquare(x2, y2);


	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7)
	{
		return false;

	}
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
	case ROOK: return moveRook(from, to);
		break;
	case BISHOP: return moveBishop(from, to);
		break;
	case QUEEN: return moveQueen(from, to);
		break;
	case KING: return moveKing(from, to);
		break;
	case EMPTY: cout << "You do not have a piece there" << endl;  return false;
		break;
	default: cout << "Theres somehow an error in switch statment in makeMove()" << endl;
		break;
	}
	return false;
}

bool Mouvement::makeMoveWithoutOutputs(int x1, int y1, int x2, int y2)
{
	using namespace std;

	Square* from = getSquare(x1, y1);
	Square* to = getSquare(x2, y2);


	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7)
	{
		return false;

	}
	if (from->getColor() == to->getColor() && to->getColor() != NONE)
	{
		return false;

	}




	switch (from->getPiece())
	{

	case PAWN: return movePawn(from, to);
		break;
	case KNIGHT: return moveKnight(from, to);
		break;
	case ROOK: return moveRook(from, to);
		break;
	case BISHOP: return moveBishop(from, to);
		break;
	case QUEEN: return moveQueen(from, to);
		break;
	case KING: return moveKing(from, to);
		break;
	case EMPTY:  return false;
		break;
	default: cout << "Theres somehow an error in switch statment in makeMove()" << endl;
		break;
	}
	return false;
}

bool Mouvement::softMakeMove(int x1, int y1, int x2, int y2)
{
	using namespace std;

	Square * from = getSquare(x1, y1);
	Square* to = getSquare(x2, y2);
	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7)
	{
		return false;

	}
	if (from->getColor() == to->getColor() && to->getColor() != NONE)
	{
		//cout << "You have a piece right there " << endl;
		return false;

	}




	switch (from->getPiece())
	{

	/*case PAWN: return softMovePawn(from, to);
		break;*/
	case KNIGHT: return softMoveKnight(from, to);
		break;
	case BISHOP: return softMoveBishop(from, to);
		break;
	case KING: return softMoveKing(from, to);
		break;
	case QUEEN: return softMoveQueen(from, to);
		break;
	default: return false;



	}
	return false;


}


bool Mouvement::isMoved() {
	using namespace std;
	string move;
	int x1, x2, y1, y2;
	bool stop = false;
	char a;
	Mouvement mv;
//m = getSquare(7, 4)->getX();
     while (!stop)
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == WHITE)
					kingWhiteX = i;}}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == WHITE)
					kingWhiteY = j;}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == BLACK)
					kingBlackX = i;}}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == BLACK)
					kingBlackY = j;}}

		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move with 4 numbers. Type in first the Row(R) in each pair." << endl << "Example: 7655 means you want to move your piece from 76 position to 55 position " << endl;
		cout << checked << "    " << whiteShortCastle << "  " << "   " << "l=" << l << "             " << "s= " << s << "w= " << w << "kingWhiteX=  " << kingWhiteX << " kingWhiteY= " << kingWhiteY
			<< "        " << "f= " << f << "    " << "m=" << m << "kingBlackX= " << kingBlackX << " KingBlackY= " << kingBlackY << endl;
		cin >> move;
		x1 = move[0] - 48;
		y1 = move[1] - 48;
		x2 = move[2] - 48;
		y2 = move[3] - 48;
        if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7)
		{ cout << "One of your numbers is not acceptable, try again." << endl;}

		else if (getSquare(x1, y1)->getColor() == turn)
		{
			if (checked == false)
			{
				if (makeMove(x1, y1, x2, y2) == false)
				{ cout << "Invalid move, try again." << endl;}
				else {

					if ((whiteIsChecked(kingWhiteX, kingWhiteY) && turn != BLACK) || blackIsChecked(kingBlackX, kingBlackY) && turn != WHITE)
					{

						cout << "Your Piece is Pinned" << endl;
						if (getSquare(x2, y2)->getPiece() == PAWN)
						{
							reculePawn(getSquare(x2, y2), getSquare(x1, y1));
						}
						else
							makeMove(x2, y2, x1, y1);
					}
					else {

						stop = true;
					}



				}




			}
			else {
				if (makeMove(x1, y1, x2, y2) == true)
				{
					if (getSquare(x2, y2)->getPiece() == KING && getSquare(x2, y2)->getColor() == WHITE) {
						kingWhiteX = x2;
						kingWhiteY = y2;
				    }
					if ((whiteIsChecked(kingWhiteX, kingWhiteY) ) || blackIsChecked(kingBlackX, kingBlackY))
					{
						cout << "Your Piece is Checked" << endl;
						if (getSquare(x2, y2)->getPiece() == PAWN)
						{
							reculePawn(getSquare(x2, y2), getSquare(x1, y1));
						}
						else
							s = s + 1;
							makeMove(x2, y2, x1, y1);
					}


					/*if (whiteIsChecked(kingWhiteX, kingWhiteY)  || blackIsChecked(kingBlackX,kingBlackY))
					{
						cout << "Your King is Checked" << endl;
						if (getSquare(x2, y2)->getPiece() == PAWN)
						{
							reculePawn(getSquare(x2, y2), getSquare(x1, y1));
						}
						else
							makeMove(x2, y2, x1, y1);
					}*/

					else {

						stop = true;
					}




				}
			}


		}
		else if (getSquare(x1, y1)->getPiece() == EMPTY)
		{
			cout << "You do not have a piece there" << endl;
		}


		else
			cout << "That's not your piece. Try again." << endl;
	}

	if (getSquare(7, 7)->getPiece() != ROOK) {
		whiteShortCastle = false;
	}
	if (getSquare(7, 0)->getPiece() != ROOK) {
		whiteLongCastle = false;
	}
	if (getSquare(0, 7)->getPiece() != ROOK) {
		blackShortCastle = false;
	}
	if (getSquare(0, 0)->getPiece() != ROOK) {
		blackLongCastle = false;
	}


	if (whiteIsChecked(kingWhiteX,kingWhiteY) || blackIsChecked(kingBlackX, kingBlackY))/*&& getSquare(x2,y2)->getColor() != WHITE && getSquare(x2,y2)->getPiece() != KING)*/ {
		//cout << "CHEEEEEEEEECK";
		checked = true;

	}
	else
		checked = false;
	if (whiteIsCheckMated()) {

		return false;
	}







	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;


	return true;

}

bool Mouvement::playGame()
{
	system("cls");
	printBoard();
	return isMoved();

}

bool Mouvement::whiteIsChecked(int x1, int y1)

{
	using namespace std;
	vector <Square*> vWhite,vBlack;
	vector <Square*> ::iterator iter;
	vWhite = {};
	vBlack = {};

	f = 0;



	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8 ; j++) {
			if (square[i][j].getPiece() != EMPTY && square[i][j].getColor() == BLACK)
			{

				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						if (softMakeMove(i, j, k, q)) {
							vBlack.push_back(&square[k][q]);
							f = vBlack.size();
							for (int a = 0; a < vBlack.size(); a++) {
								if ((vBlack[a] == (getSquare(x1, y1)))) {
									l = l + 1;
									//s = i;
									//w = j;
									return true;
								}
							}



						}


					}
				}
			}

		}






		}

	return false;


	}

bool Mouvement::blackIsChecked(int x1, int y1)
{
	using namespace std;
	vector <Square*> vWhite, vBlack;
	vector <Square*> ::iterator iter;
	vWhite = {};
	vBlack = {};

	m = 0;



	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (square[i][j].getPiece() != EMPTY && square[i][j].getColor() == WHITE)
			{

				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						if (softMakeMove(i, j, k, q)) {
							vWhite.push_back(&square[k][q]);
							m = vWhite.size();
							for (int a = 0; a < vWhite.size(); a++) {
								if ((vWhite[a] == (getSquare(x1, y1)))) {
									l = l + 1;
									s = i;
									w = j;
									return true;
								}
							}



						}


					}
				}
			}
		}
	}
}

bool Mouvement::whiteIsCheckMated()
{
	bool valid = false;
	Square* s;
	if (whiteIsChecked(kingWhiteX,kingWhiteY)) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() != EMPTY && square[i][j].getColor() == WHITE) {
					for (int k = 0; k < 8; k++) {
						for (int q = 0; q < 8; q++) {

							if (makeMoveWithoutOutputs(i,j,k,q) ){
								s = (getSquare(i, j));

								if (whiteIsChecked(kingWhiteX, kingWhiteY)) {

									if (getSquare(k, q)->getPiece() == PAWN)
									{
										reculePawn(getSquare(k, q), getSquare(i,j));
									}
									else
										makeMove(k, q, i,j);
									getSquare(i,j)->setPieceAndColor(s->getPiece(), s->getColor());

								}
								else {
									valid = true;
									if (getSquare(k, q)->getPiece() == PAWN)
									{
										reculePawn(getSquare(k, q), getSquare(i,j));
									}
									else
										makeMove(k, q, i, j);
									getSquare(i,j)->setPieceAndColor(s->getPiece(), s->getColor());



								}


							}
						}
					}
				}


			}
		}

		if (valid == false) return true;
		else return false;


	}
	else return false;
}


/*bool Piece::validMove(int a, int b, int c, int d)
{

		if (isChecked(a, b, c, d)) {
			return false;
		}
		else return true;
}*/

void Mouvement::pawnPromote(int a , int b , char x)
{
	if (getSquare(a, b)->getColor() == WHITE) {


		switch (x)
		{
		case 'q': square[a][b].setPieceAndColor(QUEEN, WHITE);
			break;

		case 'Q': square[a][b].setPieceAndColor(QUEEN, WHITE);
			break;
		case 'h': square[a][b].setPieceAndColor(KNIGHT, WHITE);
			break;
		case 'b': square[a][b].setPieceAndColor(BISHOP, WHITE);
			break;
		case 'B': square[a][b].setPieceAndColor(BISHOP, WHITE);
			break;
		case 'r': square[a][b].setPieceAndColor(ROOK, WHITE);
			break;
		case 'R': square[a][b].setPieceAndColor(ROOK, WHITE);
			break;
		default:
			break;
		}
	}
	else if (getSquare(a, b)->getColor() == BLACK) {

		switch (x)
		{
		case 'q': square[a][b].setPieceAndColor(QUEEN, BLACK);
			break;

		case 'Q': square[a][b].setPieceAndColor(QUEEN, BLACK);
			break;
		case 'h': square[a][b].setPieceAndColor(KNIGHT, BLACK);
			break;
		case 'b': square[a][b].setPieceAndColor(BISHOP, BLACK);
			break;
		case 'B': square[a][b].setPieceAndColor(BISHOP, BLACK);
			break;
		case 'r': square[a][b].setPieceAndColor(ROOK, BLACK);
			break;
		case 'R': square[a][b].setPieceAndColor(ROOK, BLACK);
			break;
		default:
			break;
		}




	}
}












