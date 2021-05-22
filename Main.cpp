
#include <iostream>
#include <string>
#include "Game.h"
using namespace std;


int main()
{
	Game p;
	string s;
	bool newgame = true;
	cout << "A chessGame by Fantar Raed & Dkhil Rihab & Nahdi Hiba " << endl;
	cout << "Enter any key to continue" << endl;
	cin >> s;

	while (newgame) {
		p.setBoard();
		while (p.playGame());
		cout << "Do you want to play again? ( y stands for yes, anything else for no) ";
		cin >> s;
		if (s != "y" && s != "Y" ) {

			newgame = false;
		}
		else {
			Game p1;
			 p=p1;
		}


	}


	return 0;
}
