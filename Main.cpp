#include <iostream>
#include <string>
#include "Mouvement.h"
using namespace std;
int main()
{
	Mouvement mv;
	string s;
	bool newgame = true;
	cout << "A chessGame by Fantar Raed & Dkhil Rihab & Nahdi Hiba " << endl;
	cout << "Enter any key to continue" << endl;
	cin >> s;

	while (newgame) {
		mv.setBoard();
		while (mv.playGame());
		mv.printBoard();
		cout << "Do you want to play again? (y stands for yes, anything else for no) ";
		cin >> s;
		if (s != "y" || s!= "Y")
			newgame = false;

	}


	return 0;
}
