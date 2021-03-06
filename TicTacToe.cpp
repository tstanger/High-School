#include <iostream>
#include <string>
using namespace std;

int main()
{
	string square[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	bool playing = 1, valid = 0;
	string location, winnerLetter = " ";
	short player = 1, winner = 0;
	while (playing == 1)
	{
		cout << "\n\n\t";
		cout << square[0] << "\xB3" << square[1] << "\xB3" << square[2] << "\n\t";
		cout << "\xC4\xC5\xC4\xC5\xC4\n\t";
		cout << square[3] << "\xB3" << square[4] << "\xB3" << square[5] << "\n\t";
		cout << "\xC4\xC5\xC4\xC5\xC4\n\t";
		cout << square[6] << "\xB3" << square[7] << "\xB3" << square[8] << "\n\n\n\t";
		cout << "Player " << player << ", enter a number: ";
		while (valid == 0)
		{
			cin >> location;
			if (location != "1" && location != "2" && location != "3" && location != "4" && location != "5" && location != "6" && location != "7" && location != "8" && location != "9")
			{
				valid = 0;
				cout << "\tInvalid input. Please try again: ";
			}
			else
				valid = 1;
		}
		valid = 0;
		if (player == 1)
			player++;
		else if (player == 2)
			player--;
		else
		{
			cout << "An error has occurred.";
			playing = 0;
		}
		for (int i = 0; i < 9; i += 0)
		{
			if (square[i] == location)
			{
				switch (player)
				{
				case 1:
					square[i] = "x";
					break;
				case 2:
					square[i] = "o";
					break;
				default:
					square[i] = "?";
				}
				i = 9;
			}
			else if (square[i] != location && i < 8)
				i++;
			else if (square[i] != location && i == 8)
			{
				cout << "\tThat location is already occupied. Please try again: ";
				while (valid == 0)
				{
					cin >> location;
					if (location != "1" && location != "2" && location != "3" && location != "4" && location != "5" && location != "6" && location != "7" && location != "8" && location != "9")
					{
						valid = 0;
						cout << "\tInvalid input. Please try again: ";
					}
					else
						valid = 1;
				}
				valid = 0;
				i = 0;
			}
		}
		if (square[0] == square[1] && square[0] == square[2] && square[1] == square[2])
		{
			winnerLetter = square[0];
			square[0] = "\xC4";
			square[1] = "\xC4";
			square[2] = "\xC4";
			playing = 0;
		}
		else if (square[3] == square[4] && square[3] == square[5] && square[4] == square[5])
		{
			winnerLetter = square[3];
			square[3] = "\xC4";
			square[4] = "\xC4";
			square[5] = "\xC4";
			playing = 0;
		}
		else if (square[6] == square[7] && square[6] == square[8] && square[7] == square[8])
		{
			winnerLetter = square[6];
			square[6] = "\xC4";
			square[7] = "\xC4";
			square[8] = "\xC4";
			playing = 0;
		}
		else if (square[0] == square[3] && square[0] == square[6] && square[3] == square[6])
		{
			winnerLetter = square[0];
			square[0] = "\xB3";
			square[3] = "\xB3";
			square[6] = "\xB3";
			playing = 0;
		}
		else if (square[1] == square[4] && square[1] == square[7] && square[4] == square[7])
		{
			winnerLetter = square[0];
			square[1] = "\xB3";
			square[4] = "\xB3";
			square[7] = "\xB3";
			playing = 0;
		}
		else if (square[2] == square[5] && square[2] == square[8] && square[5] == square[8])
		{
			winnerLetter = square[0];
			square[2] = "\xB3";
			square[5] = "\xB3";
			square[8] = "\xB3";
			playing = 0;
		}
		else if (square[0] == square[4] && square[0] == square[8] && square[4] == square[8])
		{
			winnerLetter = square[0];
			square[0] = "\x5C";
			square[4] = "\x5C";
			square[8] = "\x5C";
			playing = 0;
		}
		else if (square[2] == square[4] && square[2] == square[6] && square[4] == square[6])
		{
			winnerLetter = square[0];
			square[2] = "\x2F";
			square[4] = "\x2F";
			square[6] = "\x2F";
			playing = 0;
		}
		else if (square[0] != "1" && square[1] != "2" &&square[2] != "3" &&square[3] != "4" &&square[4] != "5" &&square[5] != "6" &&square[6] != "7" &&square[7] != "8" &&square[8] != "9")
		{
			playing = 0;
			winnerLetter = "t";
		}
		system("CLS");
	}
	cout << "\n\n\t";
	cout << square[0] << "\xB3" << square[1] << "\xB3" << square[2] << "\n\t";
	cout << "\xC4\xC5\xC4\xC5\xC4\n\t";
	cout << square[3] << "\xB3" << square[4] << "\xB3" << square[5] << "\n\t";
	cout << "\xC4\xC5\xC4\xC5\xC4\n\t";
	cout << square[6] << "\xB3" << square[7] << "\xB3" << square[8] << "\n\n\n\t";

	if (winnerLetter == "x")
		winner = 2;
	else if (winnerLetter == "o")
		winner = 1;
	else if (winnerLetter == "t")
		winner = 0;
	if (winner == 1 || winner == 2)
		cout << "Player " << winner << " wins!\n\n\t";
	else if (winner == 0)
		cout << "It's a tie.\n\n\t";
	else
		cout << "Error.\n\n\t";
	return 0;
}