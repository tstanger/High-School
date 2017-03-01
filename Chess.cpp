//Travis Stanger
#include <iostream>
#include <string>
using namespace std;
int main()
{
	// Initializes the chess board
	string board[8][8] = {
			{ "r", "n", "b", "q", "k", "b", "n", "r" },
			{ "p", "p", "p", "p", "p", "p", "p", "p" },
			{ " ", " ", " ", " ", " ", " ", " ", " " },
			{ " ", " ", " ", " ", " ", " ", " ", " " },
			{ " ", " ", " ", " ", " ", " ", " ", " " },
			{ " ", " ", " ", " ", " ", " ", " ", " " },
			{ "P", "P", "P", "P", "P", "P", "P", "P" },
			{ "R", "N", "B", "Q", "K", "B", "N", "R" } };
	// Initializes the inputs and creates the substrings
	string fromPosition = "A1", toPosition = "A1", fromPos1, fromPos2, toPos1, toPos2, playerStr = "?";
	// Starts the loop and initializes the values that the substrings will convert to; also sets up the player int, which is 1 or 2 depending on whose turn it is
	int playing = 1, valid = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, validMove = 0, player = 1, hasWon = 0;
	while (playing == 1)
	{
		// Displays the chess board
		cout << "\n   A B C D E F G H\n  \xDA\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xBF\n 1";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << "\xB3" << board[i][j];
			if (i < 7)
				cout << "\xB3\n  \xC3\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xB4\n " << i + 2;
			else if (i == 7)
				cout << "\xB3\n  \xC0\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xD9\n ";
		}
		// Input to try to move a piece
		while (validMove == 0)
		{
			cout << "\n\n\tMoving from position (Ex. B1): ";
			valid = 0;
			while (valid == 0)
			{
				cin >> fromPosition;
				fromPos1 = fromPosition.substr(0, 1);
				fromPos2 = fromPosition.substr(1, 1);
				if (fromPosition.length() == 2 && (fromPos1 == "A" || fromPos1 == "B" || fromPos1 == "C" || fromPos1 == "D" || fromPos1 == "E" || fromPos1 == "F" || fromPos1 == "G" || fromPos1 == "H" || fromPos1 == "a" || fromPos1 == "b" || fromPos1 == "c" || fromPos1 == "d" || fromPos1 == "e" || fromPos1 == "f" || fromPos1 == "g" || fromPos1 == "h") && (fromPos2 == "1" || fromPos2 == "2" || fromPos2 == "3" || fromPos2 == "4" || fromPos2 == "5" || fromPos2 == "6" || fromPos2 == "7" || fromPos2 == "8"))
					valid = 1;
				else
					cout << "Invalid input, please try again (Ex. B1): ";
			}
			valid = 0;
			cout << "\tMoving to position (Ex. C3): ";
			while (valid == 0)
			{
				cin >> toPosition;
				toPos1 = toPosition.substr(0, 1);
				toPos2 = toPosition.substr(1, 1);
				if (toPosition.length() == 2 && (toPos1 == "A" || toPos1 == "B" || toPos1 == "C" || toPos1 == "D" || toPos1 == "E" || toPos1 == "F" || toPos1 == "G" || toPos1 == "H" || toPos1 == "a" || toPos1 == "b" || toPos1 == "c" || toPos1 == "d" || toPos1 == "e" || toPos1 == "f" || toPos1 == "g" || toPos1 == "h") && (toPos2 == "1" || toPos2 == "2" || toPos2 == "3" || toPos2 == "4" || toPos2 == "5" || toPos2 == "6" || toPos2 == "7" || toPos2 == "8"))
					valid = 1;
				else
					cout << "Invalid input, please try again (Ex. C3): ";
			}
			// Converts substrings to integers
			if (fromPos2 == "1")
				x1 = 0;
			else if (fromPos2 == "2")
				x1 = 1;
			else if (fromPos2 == "3")
				x1 = 2;
			else if (fromPos2 == "4")
				x1 = 3;
			else if (fromPos2 == "5")
				x1 = 4;
			else if (fromPos2 == "6")
				x1 = 5;
			else if (fromPos2 == "7")
				x1 = 6;
			else if (fromPos2 == "8")
				x1 = 7;
			else
				x1 = 0;
			if (fromPos1 == "A" || fromPos1 == "a")
				y1 = 0;
			else if (fromPos1 == "B" || fromPos1 == "b")
				y1 = 1;
			else if (fromPos1 == "C" || fromPos1 == "c")
				y1 = 2;
			else if (fromPos1 == "D" || fromPos1 == "d")
				y1 = 3;
			else if (fromPos1 == "E" || fromPos1 == "e")
				y1 = 4;
			else if (fromPos1 == "F" || fromPos1 == "f")
				y1 = 5;
			else if (fromPos1 == "G" || fromPos1 == "g")
				y1 = 6;
			else if (fromPos1 == "H" || fromPos1 == "h")
				y1 = 7;
			if (toPos2 == "1")
				x2 = 0;
			else if (toPos2 == "2")
				x2 = 1;
			else if (toPos2 == "3")
				x2 = 2;
			else if (toPos2 == "4")
				x2 = 3;
			else if (toPos2 == "5")
				x2 = 4;
			else if (toPos2 == "6")
				x2 = 5;
			else if (toPos2 == "7")
				x2 = 6;
			else if (toPos2 == "8")
				x2 = 7;
			else
				x2 = 0;
			if (toPos1 == "A" || toPos1 == "a")
				y2 = 0;
			else if (toPos1 == "B" || toPos1 == "b")
				y2 = 1;
			else if (toPos1 == "C" || toPos1 == "c")
				y2 = 2;
			else if (toPos1 == "D" || toPos1 == "d")
				y2 = 3;
			else if (toPos1 == "E" || toPos1 == "e")
				y2 = 4;
			else if (toPos1 == "F" || toPos1 == "f")
				y2 = 5;
			else if (toPos1 == "G" || toPos1 == "g")
				y2 = 6;
			else if (toPos1 == "H" || toPos1 == "h")
				y2 = 7;
			// Uppercase Pawn
			if (board[x1][y1] == "P" && x1 == 6 && player == 1)
			{
				if ((((x2 == x1 - 1 || x2 == x1 - 2) && y2 == y1)) && (board[x2][y2] == " "))
					validMove = 1;
			}
			else if ((board[x1][y1] == "P" && x1 != 6) && (board[x2][y2] == " ") && player == 1)
			{
				if (x2 == x1 - 1 && y2 == y1)
					validMove = 1;
			}
			else if ((board[x1][y1] == "P" && x1 != 6) && (board[x2][y2] != " ") && player == 1)
			{
				if ((board[x2][y2] == "p" || board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k") && x2 == x1 - 1 && (y2 == y1 - 1 || y2 == y1 + 1))
					validMove = 1;
			}
			// Lowercase Pawn
			else if (board[x1][y1] == "p" && x1 == 1 && player == 2)
			{
				if ((((x2 == x1 + 1 || x2 == x1 + 2) && y2 == y1)) && (board[x2][y2] == " "))
					validMove = 1;
			}
			else if ((board[x1][y1] == "p" && x1 != 1) && (board[x2][y2] == " ") && player == 2)
			{
				if (x2 == x1 + 1 && y2 == y1)
					validMove = 1;
			}
			else if ((board[x1][y1] == "p" && x1 != 1) && (board[x2][y2] != " ") && player == 2)
			{
				if ((board[x2][y2] == "P" || board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K") && x2 == x1 + 1 && (y2 == y1 - 1 || y2 == y1 + 1))
					validMove = 1;
			}
			// Uppercase Knight
			else if (board[x1][y1] == "N" && player == 1)
			{
				if ((x2 == x1 - 1 && y2 == y1 + 2) || (x2 == x1 - 1 && y2 == y1 - 2) || (x2 == x1 + 1 && y2 == y1 + 2) || (x2 == x1 + 1 && y2 == y1 - 2) || (x2 == x1 - 2 && y2 == y1 - 1) || (x2 == x1 - 2 && y2 == y1 + 1) || (x2 == x1 + 2 && y2 == y1 - 1) || (x2 == x1 + 2 && y2 == y1 + 1))
				{
					if (board[x2][y2] == " " || board[x2][y2] == "p" || board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k")
						validMove = 1;
				}
			}
			// Lowercase Knight
			else if (board[x1][y1] == "n" && player == 2)
			{
				if ((x2 == x1 - 1 && y2 == y1 + 2) || (x2 == x1 - 1 && y2 == y1 - 2) || (x2 == x1 + 1 && y2 == y1 + 2) || (x2 == x1 + 1 && y2 == y1 - 2) || (x2 == x1 - 2 && y2 == y1 - 1) || (x2 == x1 - 2 && y2 == y1 + 1) || (x2 == x1 + 2 && y2 == y1 - 1) || (x2 == x1 + 2 && y2 == y1 + 1))
				{
					if (board[x2][y2] == " " || board[x2][y2] == "P" || board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K")
						validMove = 1;
				}
			}
			// Uppercase King
			else if (board[x1][y1] == "K" && player == 1)
			{
				if ((x2 == x1 + 1 || x2 == x1 - 1 || x2 == x1) && (y2 == y1 + 1 || y2 == y1 - 1 || y2 == y1) && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && !(x2 == x1 && y2 == y1))
					validMove = 1;
			}
			// Lowercase King
			else if (board[x1][y1] == "k" && player == 2)
			{
				if ((x2 == x1 + 1 || x2 == x1 - 1 || x2 == x1) && (y2 == y1 + 1 || y2 == y1 - 1 || y2 == y1) && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && !(x2 == x1 && y2 == y1))
					validMove = 1;
			}
			// Uppercase Rook
			else if (board[x1][y1] == "R" && player == 1)
			{
				if (x2 == x1 + 1 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (x2 == x1 + 2 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 3 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 4 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 5 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 6 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 7 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " " && board[x1 + 6][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 1 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (x2 == x1 - 2 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 3 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 4 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 5 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 6 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 7 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " " && board[x1 - 6][y1] == " ")
					validMove = 1;
				else if (y2 == y1 + 1 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (y2 == y1 + 2 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " ")
					validMove = 1;
				else if (y2 == y1 + 3 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " ")
					validMove = 1;
				else if (y2 == y1 + 4 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " ")
					validMove = 1;
				else if (y2 == y1 + 5 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " ")
					validMove = 1;
				else if (y2 == y1 + 6 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " ")
					validMove = 1;
				else if (y2 == y1 + 7 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " " && board[x1][y1 + 6] == " ")
					validMove = 1;
				else if (y2 == y1 - 1 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (y2 == y1 - 2 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " ")
					validMove = 1;
				else if (y2 == y1 - 3 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " ")
					validMove = 1;
				else if (y2 == y1 - 4 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " ")
					validMove = 1;
				else if (y2 == y1 - 5 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " ")
					validMove = 1;
				else if (y2 == y1 - 6 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " ")
					validMove = 1;
				else if (y2 == y1 - 7 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " " && board[x1][y1 - 6] == " ")
					validMove = 1;
			}
			// Lowercase Rook
			else if (board[x1][y1] == "r" && player == 2)
			{
				if (x2 == x1 + 1 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k")
					validMove = 1;
				else if (x2 == x1 + 2 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 3 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 4 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 5 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 6 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 7 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " " && board[x1 + 6][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 1 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k")
					validMove = 1;
				else if (x2 == x1 - 2 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 3 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 4 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 5 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 6 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 7 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " " && board[x1 - 6][y1] == " ")
					validMove = 1;
				else if (y2 == y1 + 1 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && (board[x1][y1 + 1] == " " || board[x1][y1 + 1] == "P" || board[x1][y1 + 1] == "R" || board[x1][y1 + 1] == "N" || board[x1][y1 + 1] == "B" || board[x1][y1 + 1] == "Q" || board[x1][y1 + 1] == "K"))
					validMove = 1;
				else if (y2 == y1 + 2 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && (board[x1][y1 + 2] == " " || board[x1][y1 + 2] == "P" || board[x1][y1 + 2] == "R" || board[x1][y1 + 2] == "N" || board[x1][y1 + 2] == "B" || board[x1][y1 + 2] == "Q" || board[x1][y1 + 2] == "K"))
					validMove = 1;
				else if (y2 == y1 + 3 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && (board[x1][y1 + 3] == " " || board[x1][y1 + 3] == "P" || board[x1][y1 + 3] == "R" || board[x1][y1 + 3] == "N" || board[x1][y1 + 3] == "B" || board[x1][y1 + 3] == "Q" || board[x1][y1 + 3] == "K"))
					validMove = 1;
				else if (y2 == y1 + 4 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && (board[x1][y1 + 4] == " " || board[x1][y1 + 4] == "P" || board[x1][y1 + 4] == "R" || board[x1][y1 + 4] == "N" || board[x1][y1 + 4] == "B" || board[x1][y1 + 4] == "Q" || board[x1][y1 + 4] == "K"))
					validMove = 1;
				else if (y2 == y1 + 5 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && (board[x1][y1 + 5] == " " || board[x1][y1 + 5] == "P" || board[x1][y1 + 5] == "R" || board[x1][y1 + 5] == "N" || board[x1][y1 + 5] == "B" || board[x1][y1 + 5] == "Q" || board[x1][y1 + 5] == "K"))
					validMove = 1;
				else if (y2 == y1 + 6 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " " && (board[x1][y1 + 6] == " " || board[x1][y1 + 6] == "P" || board[x1][y1 + 6] == "R" || board[x1][y1 + 6] == "N" || board[x1][y1 + 6] == "B" || board[x1][y1 + 6] == "Q" || board[x1][y1 + 6] == "K"))
					validMove = 1;
				else if (y2 == y1 + 7 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " " && board[x1][y1 + 6] == " " && (board[x1][y1 + 7] == " " || board[x1][y1 + 7] == "P" || board[x1][y1 + 7] == "R" || board[x1][y1 + 7] == "N" || board[x1][y1 + 7] == "B" || board[x1][y1 + 7] == "Q" || board[x1][y1 + 7] == "K"))
					validMove = 1;
				else if (y2 == y1 - 1 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && (board[x1][y1 - 1] == " " || board[x1][y1 - 1] == "P" || board[x1][y1 - 1] == "R" || board[x1][y1 - 1] == "N" || board[x1][y1 - 1] == "B" || board[x1][y1 - 1] == "Q" || board[x1][y1 - 1] == "K"))
					validMove = 1;
				else if (y2 == y1 - 2 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && (board[x1][y1 - 2] == " " || board[x1][y1 - 2] == "P" || board[x1][y1 - 2] == "R" || board[x1][y1 - 2] == "N" || board[x1][y1 - 2] == "B" || board[x1][y1 - 2] == "Q" || board[x1][y1 - 2] == "K"))
					validMove = 1;
				else if (y2 == y1 - 3 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && (board[x1][y1 - 3] == " " || board[x1][y1 - 3] == "P" || board[x1][y1 - 3] == "R" || board[x1][y1 - 3] == "N" || board[x1][y1 - 3] == "B" || board[x1][y1 - 3] == "Q" || board[x1][y1 - 3] == "K"))
					validMove = 1;
				else if (y2 == y1 - 4 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && (board[x1][y1 - 4] == " " || board[x1][y1 - 4] == "P" || board[x1][y1 - 4] == "R" || board[x1][y1 - 4] == "N" || board[x1][y1 - 4] == "B" || board[x1][y1 - 4] == "Q" || board[x1][y1 - 4] == "K"))
					validMove = 1;
				else if (y2 == y1 - 5 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && (board[x1][y1 - 5] == " " || board[x1][y1 - 5] == "P" || board[x1][y1 - 5] == "R" || board[x1][y1 - 5] == "N" || board[x1][y1 - 5] == "B" || board[x1][y1 - 5] == "Q" || board[x1][y1 - 5] == "K"))
					validMove = 1;
				else if (y2 == y1 - 6 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " " && (board[x1][y1 - 6] == " " || board[x1][y1 - 6] == "P" || board[x1][y1 - 6] == "R" || board[x1][y1 - 6] == "N" || board[x1][y1 - 6] == "B" || board[x1][y1 - 6] == "Q" || board[x1][y1 - 6] == "K"))
					validMove = 1;
				else if (y2 == y1 - 7 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " " && board[x1][y1 - 6] == " " && (board[x1][y1 - 7] == " " || board[x1][y1 - 7] == "P" || board[x1][y1 - 7] == "R" || board[x1][y1 - 7] == "N" || board[x1][y1 - 7] == "B" || board[x1][y1 - 7] == "Q" || board[x1][y1 - 7] == "K"))
					validMove = 1;
			}
			// Uppercase Bishop
			else if (board[x1][y1] == "B" && player == 1)
			{
				if (x2 == x1 + 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 + 2)
				{
					if (board[x1 + 1][y1 + 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 + 3)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 + 4)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 + 5)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 + 6)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 + 7)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && board[x1 + 6][y1 + 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 - 3)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 - 4)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 - 5)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 - 6)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 - 7)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && board[x1 - 6][y1 - 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 - 3)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 - 4)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 - 5)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 - 6)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 - 7)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && board[x1 + 6][y1 - 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 + 2)
				{
					if (board[x1 - 1][y1 + 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 + 3)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 + 4)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 + 5)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 + 6)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 + 7)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && board[x1 - 6][y1 + 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
			}
			// Lowercase Bishop
			else if (board[x1][y1] == "b" && player == 2)
			{
				if (x2 == x1 + 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 + 2)
				{
					if (board[x1 + 1][y1 + 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 + 3)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 + 4)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 + 5)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 + 6)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 + 7)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && board[x1 + 6][y1 + 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 - 3)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 - 4)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 - 5)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 - 6)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 - 7)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && board[x1 - 6][y1 - 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 - 3)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 - 4)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 - 5)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 - 6)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 - 7)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && board[x1 + 6][y1 - 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				if (x2 == x1 - 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 + 2)
				{
					if (board[x1 - 1][y1 + 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 + 3)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 + 4)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 + 5)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 + 6)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 + 7)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && board[x1 - 6][y1 + 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
			}
			// Uppercase Queen
			else if (board[x1][y1] == "Q" && player == 1)
			{
				if (x2 == x1 + 1 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (x2 == x1 + 2 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 3 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 4 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 5 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 6 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 7 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " " && board[x1 + 6][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 1 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (x2 == x1 - 2 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 3 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 4 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 5 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 6 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 7 && y2 == y1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " " && board[x1 - 6][y1] == " ")
					validMove = 1;
				else if (y2 == y1 + 1 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (y2 == y1 + 2 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " ")
					validMove = 1;
				else if (y2 == y1 + 3 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " ")
					validMove = 1;
				else if (y2 == y1 + 4 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " ")
					validMove = 1;
				else if (y2 == y1 + 5 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " ")
					validMove = 1;
				else if (y2 == y1 + 6 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " ")
					validMove = 1;
				else if (y2 == y1 + 7 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " " && board[x1][y1 + 6] == " ")
					validMove = 1;
				else if (y2 == y1 - 1 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K")
					validMove = 1;
				else if (y2 == y1 - 2 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " ")
					validMove = 1;
				else if (y2 == y1 - 3 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " ")
					validMove = 1;
				else if (y2 == y1 - 4 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " ")
					validMove = 1;
				else if (y2 == y1 - 5 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " ")
					validMove = 1;
				else if (y2 == y1 - 6 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " ")
					validMove = 1;
				else if (y2 == y1 - 7 && x2 == x1 && board[x2][y2] != "P" && board[x2][y2] != "R" && board[x2][y2] != "N" && board[x2][y2] != "B" && board[x2][y2] != "Q" && board[x2][y2] != "K" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " " && board[x1][y1 - 6] == " ")
					validMove = 1;
				else if (x2 == x1 + 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 + 2)
				{
					if (board[x1 + 1][y1 + 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 + 3)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 + 4)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 + 5)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 + 6)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 + 7)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && board[x1 + 6][y1 + 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 - 3)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 - 4)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 - 5)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 - 6)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 - 7)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && board[x1 - 6][y1 - 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 - 3)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 - 4)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 - 5)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 - 6)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 - 7)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && board[x1 + 6][y1 - 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 + 2)
				{
					if (board[x1 - 1][y1 + 1] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 + 3)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 + 4)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 + 5)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 + 6)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 + 7)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && board[x1 - 6][y1 + 6] == " " && (board[x2][y2] == "r" || board[x2][y2] == "n" || board[x2][y2] == "b" || board[x2][y2] == "q" || board[x2][y2] == "k" || board[x2][y2] == "p" || board[x2][y2] == " "))
						validMove = 1;
				}
			}
			// Lowercase Queen
			else if (board[x1][y1] == "q" && player == 2)
			{
				if (x2 == x1 + 1 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k")
					validMove = 1;
				else if (x2 == x1 + 2 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 3 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 4 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 5 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 6 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 + 7 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 + 1][y1] == " " && board[x1 + 2][y1] == " " && board[x1 + 3][y1] == " " && board[x1 + 4][y1] == " " && board[x1 + 5][y1] == " " && board[x1 + 6][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 1 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k")
					validMove = 1;
				else if (x2 == x1 - 2 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 3 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 4 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 5 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 6 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " ")
					validMove = 1;
				else if (x2 == x1 - 7 && y2 == y1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1 - 1][y1] == " " && board[x1 - 2][y1] == " " && board[x1 - 3][y1] == " " && board[x1 - 4][y1] == " " && board[x1 - 5][y1] == " " && board[x1 - 6][y1] == " ")
					validMove = 1;
				else if (y2 == y1 + 1 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && (board[x1][y1 + 1] == " " || board[x1][y1 + 1] == "P" || board[x1][y1 + 1] == "R" || board[x1][y1 + 1] == "N" || board[x1][y1 + 1] == "B" || board[x1][y1 + 1] == "Q" || board[x1][y1 + 1] == "K"))
					validMove = 1;
				else if (y2 == y1 + 2 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && (board[x1][y1 + 2] == " " || board[x1][y1 + 2] == "P" || board[x1][y1 + 2] == "R" || board[x1][y1 + 2] == "N" || board[x1][y1 + 2] == "B" || board[x1][y1 + 2] == "Q" || board[x1][y1 + 2] == "K"))
					validMove = 1;
				else if (y2 == y1 + 3 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && (board[x1][y1 + 3] == " " || board[x1][y1 + 3] == "P" || board[x1][y1 + 3] == "R" || board[x1][y1 + 3] == "N" || board[x1][y1 + 3] == "B" || board[x1][y1 + 3] == "Q" || board[x1][y1 + 3] == "K"))
					validMove = 1;
				else if (y2 == y1 + 4 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && (board[x1][y1 + 4] == " " || board[x1][y1 + 4] == "P" || board[x1][y1 + 4] == "R" || board[x1][y1 + 4] == "N" || board[x1][y1 + 4] == "B" || board[x1][y1 + 4] == "Q" || board[x1][y1 + 4] == "K"))
					validMove = 1;
				else if (y2 == y1 + 5 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && (board[x1][y1 + 5] == " " || board[x1][y1 + 5] == "P" || board[x1][y1 + 5] == "R" || board[x1][y1 + 5] == "N" || board[x1][y1 + 5] == "B" || board[x1][y1 + 5] == "Q" || board[x1][y1 + 5] == "K"))
					validMove = 1;
				else if (y2 == y1 + 6 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " " && (board[x1][y1 + 6] == " " || board[x1][y1 + 6] == "P" || board[x1][y1 + 6] == "R" || board[x1][y1 + 6] == "N" || board[x1][y1 + 6] == "B" || board[x1][y1 + 6] == "Q" || board[x1][y1 + 6] == "K"))
					validMove = 1;
				else if (y2 == y1 + 7 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 + 1] == " " && board[x1][y1 + 2] == " " && board[x1][y1 + 3] == " " && board[x1][y1 + 4] == " " && board[x1][y1 + 5] == " " && board[x1][y1 + 6] == " " && (board[x1][y1 + 7] == " " || board[x1][y1 + 7] == "P" || board[x1][y1 + 7] == "R" || board[x1][y1 + 7] == "N" || board[x1][y1 + 7] == "B" || board[x1][y1 + 7] == "Q" || board[x1][y1 + 7] == "K"))
					validMove = 1;
				else if (y2 == y1 - 1 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && (board[x1][y1 - 1] == " " || board[x1][y1 - 1] == "P" || board[x1][y1 - 1] == "R" || board[x1][y1 - 1] == "N" || board[x1][y1 - 1] == "B" || board[x1][y1 - 1] == "Q" || board[x1][y1 - 1] == "K"))
					validMove = 1;
				else if (y2 == y1 - 2 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && (board[x1][y1 - 2] == " " || board[x1][y1 - 2] == "P" || board[x1][y1 - 2] == "R" || board[x1][y1 - 2] == "N" || board[x1][y1 - 2] == "B" || board[x1][y1 - 2] == "Q" || board[x1][y1 - 2] == "K"))
					validMove = 1;
				else if (y2 == y1 - 3 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && (board[x1][y1 - 3] == " " || board[x1][y1 - 3] == "P" || board[x1][y1 - 3] == "R" || board[x1][y1 - 3] == "N" || board[x1][y1 - 3] == "B" || board[x1][y1 - 3] == "Q" || board[x1][y1 - 3] == "K"))
					validMove = 1;
				else if (y2 == y1 - 4 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && (board[x1][y1 - 4] == " " || board[x1][y1 - 4] == "P" || board[x1][y1 - 4] == "R" || board[x1][y1 - 4] == "N" || board[x1][y1 - 4] == "B" || board[x1][y1 - 4] == "Q" || board[x1][y1 - 4] == "K"))
					validMove = 1;
				else if (y2 == y1 - 5 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && (board[x1][y1 - 5] == " " || board[x1][y1 - 5] == "P" || board[x1][y1 - 5] == "R" || board[x1][y1 - 5] == "N" || board[x1][y1 - 5] == "B" || board[x1][y1 - 5] == "Q" || board[x1][y1 - 5] == "K"))
					validMove = 1;
				else if (y2 == y1 - 6 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " " && (board[x1][y1 - 6] == " " || board[x1][y1 - 6] == "P" || board[x1][y1 - 6] == "R" || board[x1][y1 - 6] == "N" || board[x1][y1 - 6] == "B" || board[x1][y1 - 6] == "Q" || board[x1][y1 - 6] == "K"))
					validMove = 1;
				else if (y2 == y1 - 7 && x2 == x1 && board[x2][y2] != "p" && board[x2][y2] != "r" && board[x2][y2] != "n" && board[x2][y2] != "b" && board[x2][y2] != "q" && board[x2][y2] != "k" && board[x1][y1 - 1] == " " && board[x1][y1 - 2] == " " && board[x1][y1 - 3] == " " && board[x1][y1 - 4] == " " && board[x1][y1 - 5] == " " && board[x1][y1 - 6] == " " && (board[x1][y1 - 7] == " " || board[x1][y1 - 7] == "P" || board[x1][y1 - 7] == "R" || board[x1][y1 - 7] == "N" || board[x1][y1 - 7] == "B" || board[x1][y1 - 7] == "Q" || board[x1][y1 - 7] == "K"))
					validMove = 1;
				else if (x2 == x1 + 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 + 2)
				{
					if (board[x1 + 1][y1 + 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 + 3)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 + 4)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 + 5)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 + 6)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 + 7)
				{
					if (board[x1 + 1][y1 + 1] == " " && board[x1 + 2][y1 + 2] == " " && board[x1 + 3][y1 + 3] == " " && board[x1 + 4][y1 + 4] == " " && board[x1 + 5][y1 + 5] == " " && board[x1 + 6][y1 + 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 - 3)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 - 4)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 - 5)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 - 6)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 - 7)
				{
					if (board[x1 - 1][y1 - 1] == " " && board[x1 - 2][y1 - 2] == " " && board[x1 - 3][y1 - 3] == " " && board[x1 - 4][y1 - 4] == " " && board[x1 - 5][y1 - 5] == " " && board[x1 - 6][y1 - 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 1 && y2 == y1 - 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 + 2 && y2 == y1 - 2)
				{
					if (board[x1 - 1][y1 - 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 3 && y2 == y1 - 3)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 4 && y2 == y1 - 4)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 5 && y2 == y1 - 5)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 6 && y2 == y1 - 6)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 + 7 && y2 == y1 - 7)
				{
					if (board[x1 + 1][y1 - 1] == " " && board[x1 + 2][y1 - 2] == " " && board[x1 + 3][y1 - 3] == " " && board[x1 + 4][y1 - 4] == " " && board[x1 + 5][y1 - 5] == " " && board[x1 + 6][y1 - 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				if (x2 == x1 - 1 && y2 == y1 + 1)
				{
					if (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " ")
						validMove = 1;
				}
				else if (x2 == x1 - 2 && y2 == y1 + 2)
				{
					if (board[x1 - 1][y1 + 1] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 3 && y2 == y1 + 3)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 4 && y2 == y1 + 4)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 5 && y2 == y1 + 5)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 6 && y2 == y1 + 6)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
				else if (x2 == x1 - 7 && y2 == y1 + 7)
				{
					if (board[x1 - 1][y1 + 1] == " " && board[x1 - 2][y1 + 2] == " " && board[x1 - 3][y1 + 3] == " " && board[x1 - 4][y1 + 4] == " " && board[x1 - 5][y1 + 5] == " " && board[x1 - 6][y1 + 6] == " " && (board[x2][y2] == "R" || board[x2][y2] == "N" || board[x2][y2] == "B" || board[x2][y2] == "Q" || board[x2][y2] == "K" || board[x2][y2] == "P" || board[x2][y2] == " "))
						validMove = 1;
				}
			}
			// Invalid Move
			else
				validMove = 0;
			// Promotes pawns to queens if they reach the other side
			if (board[x1][y1] == "p" && x2 == 7 && validMove == 1)
				board[x1][y1] = "q";
			else if (board[x1][y1] == "P" && x2 == 0 && validMove == 1)
				board[x1][y1] = "Q";
			// Updates board by overwriting location you move to and replacing the location you moved from with a space
			if (validMove == 1)
			{
				board[x2][y2] = board[x1][y1];
				board[x1][y1] = " ";
			}
			else
				cout << "Invalid move. Please try again: ";
		}
		validMove = 0;
		// Checks to see if someone has won the game
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == "K")
				{
					hasWon = 0;
					i = 8;
					j = 8;
				}
				else if (i == 7 && j == 7 && board[i][j] != "K")
					hasWon = 1;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == "k")
				{
					hasWon = 0;
					i = 8;
					j = 8;
				}
				else if (i == 7 && j == 7 && board[i][j] != "k")
					hasWon = 1;
			}
		}
		// Checks that the player is either 1 or 2, and switches to the other player so they can take their turn
		if (hasWon == 0)
		{
			if (player == 1)
				player++;
			else if (player == 2)
				player--;
			else
			{
				cout << "The game has encountered an error and needs to close.";
				playing = 0;
			}
		}
		// Refreshes the board
		system("CLS");
		if (hasWon == 1)
		{
			playing = 0;
			if (player == 1)
				playerStr = "1";
			else if (player == 2)
				playerStr = "2";
			else
				playerStr = "?";
			for (int i = 0; i < 8; i++)
			{
				board[0][i] = "\xDB";
				board[1][i] = "\xDB";
				board[2][i] = "\xDB";
				board[5][i] = "\xDB";
				board[6][i] = "\xDB";
				board[7][i] = "\xDB";
			}
			board[3][0] = "\xDB";
			board[3][1] = "P";
			board[3][2] = "L";
			board[3][3] = "A";
			board[3][4] = "Y";
			board[3][5] = "E";
			board[3][6] = "R";
			board[3][7] = "\xDB";
			board[4][0] = "\xDB";
			board[4][1] = playerStr;
			board[4][2] = " ";
			board[4][3] = "W";
			board[4][4] = "I";
			board[4][5] = "N";
			board[4][6] = "S";
			board[4][7] = "\xDB";
			cout << "\n   A B C D E F G H\n  \xDA\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xC2\xC4\xBF\n 1";
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
					cout << "\xB3" << board[i][j];
				if (i < 7)
					cout << "\xB3\n  \xC3\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xC5\xC4\xB4\n " << i + 2;
				else if (i == 7)
					cout << "\xB3\n  \xC0\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xC1\xC4\xD9\n ";
			}
		}
	}
	return 0;
}