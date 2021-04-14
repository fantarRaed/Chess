#include "Board.h"
#include "Square.h"
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;


int main()
{
	Piece p;
	string s;
	bool newgame = true;
	cout << "A chessGame " << endl;
	cout << "Enter any key to continue" << endl;
	cin >> s;

	while (newgame) {
		p.setBoard();
		while (p.playGame());

	}


	return 0;
}
