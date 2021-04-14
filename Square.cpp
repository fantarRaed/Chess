#include "Square.h"
Square::Square()
{
	piece = EMPTY;
	color=NONE;
}
Name Square::getPiece()
{
	return piece;
}

Color Square::getColor()
{
	return color;
}

void Square::setSpace(Square* space)
{
	color = space->getColor();
	piece = space->getPiece();
}

void Square::setEmpty()
{
	color = NONE;
	piece = EMPTY;
}


void Square::setPieceAndColor(Name p, Color c)
{
	piece = p;
	color = c;

}


