#include "Piece.h"

bool Piece::movePawn(Square* thisPawn, Square* thatSpace) {
	
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
			if (pawnY == thatY && thatX == pawnX + 1 && thatSpace->getColor() == NONE 
				|| pawnX == 1 && pawnY == thatY && thatX == pawnX + 2)
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

bool Piece::softMovePawn(Square thisPawn, Square thatSpace)
{
	using namespace std;
	int pawnX = thisPawn.getX();
	int pawnY = thisPawn.getY();
	int thatX = thatSpace.getX();
	int thatY = thatSpace.getY();



	if (thisPawn.getColor() == WHITE)
	{

		if (pawnY == thatY && thatX == pawnX - 1 && thatSpace.getColor() == NONE
			|| pawnX == 6 && pawnY == thatY && thatX == pawnX - 2 && thatSpace.getColor() == NONE)
		{
		
			return true;
		}
		else
			if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX - 1 == thatX && thatSpace.getColor() == BLACK)
			{
				
				return true;
			}
			else
				return false;

	}
	else
		if (thisPawn.getColor() == BLACK)
		{
			if (pawnY == thatY && thatX == pawnX + 1 && thatSpace.getColor() == NONE
				|| pawnX == 1 && pawnY == thatY && thatX == pawnX + 2)
			{
				
				return true;
			}
			else
				if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX + 1 == thatX && thatSpace.getColor() == WHITE)
				{
					
					return true;
				}
				else
					return false;
		}
		else
			return false;
}

void Piece::reculePawn(Square* thisPawn, Square* thatSpace)
{
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();
	if (thisPawn->getColor() == WHITE)
	{

		if (pawnY == thatY && thatX == pawnX + 1 && thatSpace->getColor() == NONE
			|| pawnX == 6 && pawnY == thatY && thatX == pawnX + 2 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			
		}
		else
			if ((pawnY + 1 == thatY || pawnY - 1 == thatY) && pawnX + 1 == thatX && thatSpace->getColor() == WHITE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
			}
			

	}
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
bool Piece::softMoveKnight(Square thisKnight, Square thatSpace)
{
	int knightX = thisKnight.getX();
	int knightY = thisKnight.getY();
	int thatX = thatSpace.getX();
	int thatY = thatSpace.getY();

	if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
	{
		
		return true;
	}
	else
	{
		return false;
	}
}
bool Piece::moveBishop(Square* thisBishop, Square* thatSpace) { 
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
bool Piece::softMoveBishop(Square thisBishop, Square thatSpace)
{
	int bishopX = thisBishop.getX();
	int bishopY = thisBishop.getY();
	int thatX = thatSpace.getX();
	int thatY = thatSpace.getY();

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
		return true;

		
	}
	else {
		return false;
	}
}
bool Piece::moveQueen(Square* thisQueen, Square* thatSpace) { 

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
bool Piece::softMoveQueen(Square thisQueen, Square thatSpace)
{
	int queenX = thisQueen.getX();
	int queenY = thisQueen.getY();
	int thatX = thatSpace.getX();
	int thatY = thatSpace.getY();
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
bool Piece::moveKing(Square* thisKing, Square* thatSpace)
{
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

bool Piece::softMoveKing(Square thisKing, Square thatSpace)
{
	if (abs(thatSpace.getX() - thisKing.getX()) == 1)
		if (abs(thatSpace.getY() - thisKing.getY()) == 1)
		{
			
			return true;
		}
		else return false;
	else return false;
}

bool Piece::moveRook(Square* thisRook, Square* thatSpace)
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



bool  Piece::makeMove(int x1, int y1, int x2, int y2) {
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

bool Piece::softMakeMove(int x1, int y1, int x2, int y2)
{
	using namespace std;

	Square from = softGetSquare(x1, y1);
	Square to = softGetSquare(x2, y2);
	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7)
	{
		return false;

	}
	if (from.getColor() == to.getColor() && to.getColor() != NONE)
	{
		cout << "You have a piece right there " << endl;
		return false;

	}




	switch (from.getPiece())
	{

	case PAWN: return softMovePawn(from, to);
		break;
	case KNIGHT: return softMoveKnight(from, to);
		break;
	case BISHOP: return softMoveBishop(from, to);
		break;
	case KING: return softMoveKing(from, to);
		break;
	case QUEEN: return softMoveQueen(from, to);
		break;
	
	
	}
	
}


bool Piece::isMoved() {
	using namespace std;
	string move;
	int x1, x2, y1, y2;
	int kingWhiteX = 7;
	int kingWhiteY = 4;
	int kingBlackX = 0;
	int kingBlackY = 4;
	bool stop = false;
	char a;
	
	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move with 4 numbers. Type in first the Row(R) in each pair." << endl << "Example: 7655 means you want to move your piece from 76 position to 55 position " << endl;
		cout << checked << "    "  << "  " << l << "   " << p << "             " << m << endl;
		cin >> move;
		x1 = move[0] - 48;
		y1 = move[1] - 48;
		x2 = move[2] - 48;
		y2 = move[3] - 48;
		 
	  
	 
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
				else
					if (getSquare(x2, y2)->getPiece() == PAWN && x2 == 0 || getSquare(x2, y2)->getPiece() == PAWN && x2 == 7) {


						cout << "You want to promote your pawn to? Enter a character: Q stands for Queen, H for Knight ..";
						cin >> a;
						pawnPromote(x2, y2, a);
						stop = true;
					}

					else
						stop = true;

			}
			else {
				if (makeMove(x1, y1, x2, y2) == true)
				{
				

					if (isChecked(l, p, kingWhiteX, kingWhiteY) == true && getSquare(x2,y2)->getPiece() != KING)
					{
						cout << "Your King is Checked" << endl;
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
		
			
		}
		else if (getSquare(x1, y1)->getPiece() == EMPTY)
		{
			cout << "You do not have a piece there" << endl; 
		}
		

		else 
			cout << "That's not your piece. Try again." << endl;
	}

	
	

	
	if (isChecked(x2, y2, kingWhiteX, kingWhiteY) && getSquare(x2,y2)->getColor() != WHITE && getSquare(x2,y2)->getPiece() != KING) {
		cout << "CHEEEEEEEEECK";
		checked = true;
	//	m = x1;
		n = y1;
		l = x2;
		p = y2;
	}
	else
		checked = false;

	
		
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

bool Piece::isChecked(int x1, int y1, int x2, int y2)

{
	using namespace std;
	
	if (softMakeMove(x1, y1, x2, y2))
	{
		return true;
	}
	else
		return false;

	
	
}

bool Piece::validMove(int a, int b, int c, int d)
{
	
		if (isChecked(a, b, c, d)) {
			return false;
		}
		else return true;
}

void Piece::pawnPromote(int a , int b , char x)
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






		





