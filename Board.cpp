#include "Board.h"
#include "Square.h"
Board::Board()
{

}
void Board::setBoard()
{
	square[7][7].setPieceAndColor(ROOK, WHITE);
	square[7][6].setPieceAndColor(KNIGHT, WHITE);
	square[7][5].setPieceAndColor(BISHOP, WHITE);
	square[7][4].setPieceAndColor(KING, WHITE);
	square[7][3].setPieceAndColor(QUEEN, WHITE);
	square[7][2].setPieceAndColor(BISHOP, WHITE);
	square[7][1].setPieceAndColor(KNIGHT, WHITE);
	square[7][0].setPieceAndColor(ROOK, WHITE);
	square[0][0].setPieceAndColor(ROOK, BLACK);
	square[0][1].setPieceAndColor(KNIGHT, BLACK);
	square[0][2].setPieceAndColor(BISHOP, BLACK);
	square[0][3].setPieceAndColor(QUEEN, BLACK);
	square[0][4].setPieceAndColor(KING, BLACK);
	square[0][5].setPieceAndColor(BISHOP, BLACK);
	square[0][6].setPieceAndColor(KNIGHT, BLACK);
	square[0][7].setPieceAndColor(ROOK, BLACK);

	for (int i = 0; i < 8; i++)
	{
		square[6][i].setPieceAndColor(PAWN, WHITE);
		square[1][i].setPieceAndColor(PAWN, BLACK);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			square[i][j].setPieceAndColor(Name::EMPTY, Color::NONE);

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			square[i][j].setX(i);
			square[i][j].setY(j);
		}

}
void Board::printBoard() {
	using namespace std;
	cout << "   C: 0  1  2  3  4  5  6  7 " << endl << "R:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
		{
			Name p = square[i][j].getPiece();
			Color c = square[i][j].getColor();

			switch (p)
			{
			case KING: (c == WHITE) ? cout << " K " : cout << " k ";
				break;
			case QUEEN: (c == WHITE) ? cout << " Q " : cout << " q ";
				break;
			case BISHOP:(c == WHITE) ? cout << " B " : cout << " b ";
				break;
			case KNIGHT:(c == WHITE) ? cout << " H " : cout << " h ";
				break;
			case ROOK: (c == WHITE) ? cout << " R " : cout << " r ";
				break;
			case PAWN: (c == WHITE) ? cout << " P " : cout << " p ";
				break;
			case EMPTY: cout << " " << "*" << " ";
				break;
			default: cout << "XXX";
				break;
			}

		}
		cout << endl;
	}

}

Board::Board(const Board& b)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			square[i][j] = b.square[i][j];
		}
	}
	turn = b.turn;
}







