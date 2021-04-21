
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;


int main()
{
	Piece p;
	string s;
	bool newgame = true;
	cout << "A chessGame by Fantar Raed & Dkhil Rihab & Nahdi Hiba " << endl;
	cout << "Enter any key to continue" << endl;
	cin >> s;

	while (newgame) {
		p.setBoard();
		while (p.playGame());
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> s;
		if (s != "y")
			newgame = false;
		
	}


	return 0;
}
