#include "Game.h"
#include <vector>
#include <algorithm>
#include <assert.h>









bool Game::movePawn(Square* thisPawn, Square* thatSpace) {

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


bool Game::fakeMovePawn(Square* thisPawn, Square* thatSpace)
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

void Game::reculePawn(Square* thisPawn, Square* thatSpace)
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
	else

		if (pawnY == thatY && thatX == pawnX - 1 && thatSpace->getColor() == NONE
			|| pawnX == 6 && pawnY == thatY && thatX == pawnX - 2 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();

		}
		else
			if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX - 1 == thatX && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
			}




}

bool Game::moveKnight(Square* thisKnight, Square* thatSpace)
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
bool Game::fakeMoveKnight(Square* thisKnight, Square* thatSpace)
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
bool Game::moveBishop(Square* thisBishop, Square* thatSpace) {

	int bishopX = thisBishop->getX();
	int bishopY = thisBishop->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	using namespace std;

	if (abs(bishopX - thatX) == abs(bishopY - thatY)) {

		int j = abs(thatX - bishopX) - 1; // number of squares that might block the bihsopMove
		int i = 0;
		while (i != j) {

			int xx = (thatX - bishopX) / (abs(thatX - bishopX));
			int yy = (thatY - bishopY) / (abs(thatY - bishopY));
			if (square[bishopX + xx * (i + 1)][bishopY + yy * (i + 1)].getColor() != NONE) {
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
bool Game::fakeMoveBishop(Square* thisBishop, Square* thatSpace)
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
bool Game::moveBishopWithoutOutputs(Square* thisBishop, Square* thatSpace)
{
	int bishopX = thisBishop->getX();
	int bishopY = thisBishop->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();

	using namespace std;

	if (abs(bishopX - thatX) == abs(bishopY - thatY)) {

		int j = abs(thatX - bishopX) - 1; // number of squares that might block the bihsopMove
		int i = 0;
		while (i != j) {

			int xx = (thatX - bishopX) / (abs(thatX - bishopX));
			int yy = (thatY - bishopY) / (abs(thatY - bishopY));
			if (square[bishopX + xx * (i + 1)][bishopY + yy * (i + 1)].getColor() != NONE) {
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
bool Game::moveQueen(Square* thisQueen, Square* thatSpace) {

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
bool Game::fakeMoveQueen(Square* thisQueen, Square* thatSpace)
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
bool Game::moveKing(Square* thisKing, Square* thatSpace)
{
	if (thatSpace->getX() == 7 && thatSpace->getY() == 6 || thatSpace->getX() == 7 && thatSpace->getY() == 2
		|| thatSpace->getX() == 0 && thatSpace->getY() == 6 || thatSpace->getX() == 0 && thatSpace->getY() == 2) {


		return kingCastle(thisKing, thatSpace);


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

bool Game::fakeMoveKing(Square* thisKing, Square* thatSpace)
{
	if (abs(thatSpace->getX() - thisKing->getX()) == 1 || abs(thatSpace->getX() - thisKing->getX()) == 0)
		if (abs(thatSpace->getY() - thisKing->getY()) == 1 || abs(thatSpace->getY() - thisKing->getY()) == 0)
		{

			return true;
		}

		else return false;
	else return false;
}

bool Game::kingCastle(Square* thisKing, Square* thatSpace)
{

	if (thisKing->getColor() == WHITE) {

		if (thatSpace->getX() == 7 && thatSpace->getY() == 6) {
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
		else if (thatSpace->getX() == 7 && thatSpace->getY() == 2) {
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
		if (thatSpace->getX() == 0 && thatSpace->getY() == 6) {
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
		else if (thatSpace->getX() == 0 && thatSpace->getY() == 2) {
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


bool Game::moveRook(Square* thisRook, Square* thatSpace)
{
	int rookX = thisRook->getX();
	int rookY = thisRook->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	bool invalid = false;
	if (rookX != thatX || rookY != thatY)
	{

		if (rookX == thatX)
		{
			int yy = (thatY - rookY) / (abs(thatY - rookY));
			for (int i = rookY + yy; i != thatY; i += yy)
			{

				if (square[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else
			if (rookY == thatY)
			{

				int xx = (thatX - rookX) / (abs(thatX - rookX));
				for (int i = rookX + xx; i != thatX; i += xx)
				{
					if (square[i][thatY].getColor() != NONE)
						return false;
				}
			}
			else
				return false;
	}
	if (invalid == false)
	{
		thatSpace->setSpace(thisRook);
		thisRook->setEmpty();
		return true;
	}
	else
	{
		std::cout << "That is an invalid move for rook";
		return false;
	}
}

bool Game::fakeMoveRook(Square* thisRook, Square* thatSpace)
{
	int rookX = thisRook->getX();
	int rookY = thisRook->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	bool invalid = false;
	if (rookX != thatX || rookY != thatY)
	{

		if (rookX == thatX)
		{
			int yy = (thatY - rookY) / (abs(thatY - rookY));
			for (int i = rookY + yy; i != thatY; i += yy)
			{

				if (square[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else
			if (rookY == thatY)
			{

				int xx = (thatX - rookX) / (abs(thatX - rookX));
				for (int i = rookX + xx; i != thatX; i += xx)
				{
					if (square[i][thatY].getColor() != NONE)
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



bool  Game::makeMove(int x1, int y1, int x2, int y2) {
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

bool Game::makeMoveWithoutOutputs(int x1, int y1, int x2, int y2)
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
	case BISHOP: return moveBishopWithoutOutputs(from, to);
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

bool Game::fakeMakeMove(int x1, int y1, int x2, int y2)
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
		//cout << "You have a piece right there " << endl;
		return false;

	}




	switch (from->getPiece())
	{

		/*case PAWN: return softMovePawn(from, to);
			break;*/
	case KNIGHT: return fakeMoveKnight(from, to);
		break;
	case BISHOP: return fakeMoveBishop(from, to);
		break;
	case KING: return fakeMoveKing(from, to);
		break;
	case QUEEN: return fakeMoveQueen(from, to);
		break;
	case ROOK: return fakeMoveRook(from, to);
		break;
	default: return false;



	}
	return false;


}


bool Game::isMoved() {
	using namespace std;
	string move;
	int x1, x2, y1, y2;
	bool stop = false;
	char a;
	Game p;


	while (!stop)
	{
		bool test = true;
		// whiteKing & blackKing Positions
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == WHITE)
					kingWhiteX = i;

			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == WHITE)
					kingWhiteY = j;

			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == BLACK)
					kingBlackX = i;

			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() == KING && square[i][j].getColor() == BLACK)
					kingBlackY = j;

			}
		}

		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move with 4 numbers. Type in first the Row(R) in each pair." << endl << "Example: 7655 means you want to move your piece from 76 position to 55 position " << endl;
		cout << checked << "    " << whiteShortCastle << "kingWhiteX=  " << kingWhiteX << " kingWhiteY= " << kingWhiteY
			<< "        " << "f= " << f << "    " << "m=" << m << "kingBlackX= " << kingBlackX << " KingBlackY= " << kingBlackY << endl;
		while (test) {
			cin >> move;
			if (move.length() == 4) {
				x1 = move[0] - 48;
				y1 = move[1] - 48;
				x2 = move[2] - 48;
				y2 = move[3] - 48;
				if (-1 < x1 < 8 && -1 < x2 < 8 && -1 < y1 < 8 && -1 < y2 < 8) {
					test = false;

				}
			}
			else cout << "Type in your move with 4 numbers! Try again!" << endl;


		}









		if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7)
		{
			cout << "One of your numbers is not acceptable, try again." << endl;

		}

		else if (getSquare(x1, y1)->getColor() == turn)
		{
			if (checked == false)
			{
				if (makeMove(x1, y1, x2, y2) == false)
				{
					cout << "Invalid move, try again." << endl;

				}
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
					if ((whiteIsChecked(kingWhiteX, kingWhiteY)) || blackIsChecked(kingBlackX, kingBlackY))
					{
						cout << "Your King is Checked" << endl;
						if (getSquare(x2, y2)->getPiece() == PAWN)
						{
							reculePawn(getSquare(x2, y2), getSquare(x1, y1));
						}
						else {

							makeMove(x2, y2, x1, y1);
						}
					}



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

	//For Castling Requirements
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


	if (whiteIsChecked(kingWhiteX, kingWhiteY) || blackIsChecked(kingBlackX, kingBlackY)) {
		checked = true;

	}
	else
		checked = false;
	if (whiteIsCheckMated()) {
		cout << "BLACK WON!" << endl;
		return false;
	}
	if (blackIsCheckMated()) {

		cout << "WHITE WON!" << endl;
		return false;

	}







	if (turn == BLACK) {
		turn = WHITE;

	}

	else
		turn = BLACK;



	return true;

}

bool Game::playGame()
{
	system("cls");
	printBoard();
	return isMoved();

}

bool Game::whiteIsChecked(int x1, int y1)

{
	using namespace std;
	vector <Square*> vWhite, vBlack;
	vector <Square*> ::iterator iter;
	vWhite = {};
	vBlack = {};

	f = 0;



	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (square[i][j].getPiece() != EMPTY && square[i][j].getColor() == BLACK)
			{

				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						if (fakeMakeMove(i, j, k, q)) {
							vBlack.push_back(&square[k][q]);
							f = vBlack.size();
							for (int a = 0; a < vBlack.size(); a++) {
								if ((vBlack[a] == (getSquare(x1, y1)))) {
									
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

bool Game::blackIsChecked(int x1, int y1)
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
						if (fakeMakeMove(i, j, k, q)) {
							vWhite.push_back(&square[k][q]);
							m = vWhite.size();
							for (int a = 0; a < vWhite.size(); a++) {
								if ((vWhite[a] == (getSquare(x1, y1)))) {
									
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

bool Game::whiteIsCheckMated()
{
	Game p;
	p = *this;
	int a = kingWhiteX;
	int b = kingWhiteY;
	bool valid = false;

	if (whiteIsChecked(kingWhiteX, kingWhiteY)) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() != EMPTY && square[i][j].getColor() == WHITE) {

					for (int k = 0; k < 8; k++) {
						for (int q = 0; q < 8; q++) {

							Square s = *(getSquare(k, q));




							if (makeMoveWithoutOutputs(i, j, k, q)) {


								if (getSquare(k, q)->getPiece() == KING && getSquare(k, q)->getColor() == WHITE) {
									kingWhiteX = k;
									kingWhiteY = q;
								}


								if ((whiteIsChecked(kingWhiteX, kingWhiteY)) == false) {

									valid = true;
							
								}

								if (getSquare(k, q)->getPiece() == PAWN)
								{
									reculePawn(getSquare(k, q), getSquare(i, j));
									getSquare(k, q)->setPieceAndColor(s.getPiece(), s.getColor());

								}
								else {
									makeMove(k, q, i, j);
									getSquare(k, q)->setPieceAndColor(s.getPiece(), s.getColor());

								}
								kingWhiteX = a;
								kingWhiteY = b;









							}



						}
					}
				}


			}
		}
		p.printBoard();

		if (valid == false) return true;
		else return false;


	}
	else return false;
}

bool Game::blackIsCheckMated()
{
	Game p;
	p = *this;
	int a = kingBlackX;
	int b = kingBlackY;
	bool valid = false;

	if (blackIsChecked(kingBlackX, kingBlackY)) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j].getPiece() != EMPTY && square[i][j].getColor() == BLACK) {

					for (int k = 0; k < 8; k++) {
						for (int q = 0; q < 8; q++) {

							Square s = *(getSquare(k, q));




							if (makeMoveWithoutOutputs(i, j, k, q)) {


								if (getSquare(k, q)->getPiece() == KING && getSquare(k, q)->getColor() == BLACK) {
									kingBlackX = k;
									kingBlackY = q;
								}


								if ((blackIsChecked(kingBlackX, kingBlackY)) == false) {

									valid = true;
							
								}

								if (getSquare(k, q)->getPiece() == PAWN)
								{
									reculePawn(getSquare(k, q), getSquare(i, j));
									getSquare(k, q)->setPieceAndColor(s.getPiece(), s.getColor());

								}
								else {
									makeMove(k, q, i, j);
									getSquare(k, q)->setPieceAndColor(s.getPiece(), s.getColor());

								}
								kingBlackX = a;
								kingBlackY = b;









							}



						}
					}
				}


			}
		}
		p.printBoard();

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

void Game::pawnPromote(int a, int b, char x)
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














