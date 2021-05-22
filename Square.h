#pragma once


enum Name { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };
class Square
{
	Name piece;
	Color color;
	int x, y;
public:
	Square();
	Name getPiece();
	Color getColor();
	int getX() { return x; }
	int getY() { return y; }
	void setX(int a) { x = a; }
	void setY(int b) { y = b; }
	void setSpace(Square*);
	void setEmpty();
	void setPieceAndColor(Name, Color);
	bool operator== (const Square& s);
	Square(const Square& s);






};
