#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
	char front[9] = { 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' }, up[9] = { 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R' }, left[9] = { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' }, right[9] = { 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G' }, down[9] = { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' }, back[9] = { 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y' };
	char holder1 = '?', holder2 = '?', holder3 = '?';
	int playing = 1, valid = 0, moves = -50, playerFinish = 0, quit = 0, scrambler = 0, random;
	string move, plural = "s";
	srand(time(NULL));

	cout << "\n\n\n\n\tInstructions:\n\tTurn the cube by inputting one of the following:\n\tU, L, F, R, D, B, U', L', F', R', D', B'\n\tU rotates the top layer of the cube.\n\tL rotates the left layer of the cube.\n\tF rotates the front layer of the cube.\n\tR rotates the right layer of the cube.\n\tD rotates the bottom layer of the cube.\n\tB rotates the back layer of the cube.\n\tLetters by themselves will rotate the layer clockwise.\n\tAdding a ' to your input will rotate the layer counter-clockwise.\n\tStuck? Enter the word \"SOLVE\" to finish the puzzle.\n\tGive up? Enter the word \"QUIT\" to quit.\n\tEnter the word \"HELP\" at any time to return here.\n\n\t";
	system("PAUSE");
	system("CLS");
	while (playing == 1)
	{
		cout << "\n\n\n\n\t      " << up[0] << " " << up[1] << " " << up[2] << endl;
		cout << "\t      " << up[3] << " " << up[4] << " " << up[5] << endl;
		cout << "\t      " << up[6] << " " << up[7] << " " << up[8] << endl;
		cout << "\t" << left[0] << " " << left[1] << " " << left[2] << " " << front[0] << " " << front[1] << " " << front[2] << " " << right[0] << " " << right[1] << " " << right[2] << " " << back[0] << " " << back[1] << " " << back[2] << endl;
		cout << "\t" << left[3] << " " << left[4] << " " << left[5] << " " << front[3] << " " << front[4] << " " << front[5] << " " << right[3] << " " << right[4] << " " << right[5] << " " << back[3] << " " << back[4] << " " << back[5] << endl;
		cout << "\t" << left[6] << " " << left[7] << " " << left[8] << " " << front[6] << " " << front[7] << " " << front[8] << " " << right[6] << " " << right[7] << " " << right[8] << " " << back[6] << " " << back[7] << " " << back[8] << endl;
		cout << "\t      " << down[0] << " " << down[1] << " " << down[2] << endl;
		cout << "\t      " << down[3] << " " << down[4] << " " << down[5] << endl;
		cout << "\t      " << down[6] << " " << down[7] << " " << down[8] << endl;

		if (scrambler > 50)
		{
			cout << "\n\tEnter move: ";
			cin >> move;
		}
		else
		{
			random = (((rand() % 10) * (rand())) % 12) + 1;
			switch (random)
			{
			case 1:
				move = "R";
				break;
			case 2:
				move = "L";
				break;
			case 3:
				move = "U";
				break;
			case 4:
				move = "D";
				break;
			case 5:
				move = "F";
				break;
			case 6:
				move = "B";
				break;
			case 7:
				move = "R'";
				break;
			case 8:
				move = "L'";
				break;
			case 9:
				move = "U'";
				break;
			case 10:
				move = "D'";
				break;
			case 11:
				move = "F'";
				break;
			case 12:
				move = "B'";
				break;
			}
			scrambler++;
		}

		if (move == "r" || move == "l" || move == "u" || move == "d" || move == "b" || move == "f" || move == "r'" || move == "l'" || move == "u'" || move == "d'" || move == "b'" || move == "f'" || move == "R" || move == "L" || move == "U" || move == "D" || move == "B" || move == "F" || move == "R'" || move == "L'" || move == "U'" || move == "D'" || move == "B'" || move == "F'" || move == "help" || move == "Help" || move == "hElp" || move == "heLp" || move == "helP" || move == "HElp" || move == "HeLp" || move == "HelP" || move == "hELp" || move == "hElP" || move == "heLP" || move == "HELp" || move == "HElP" || move == "HeLP" || move == "hELP" || move == "HELP" || move == "solve" || move == "Solve" || move == "sOlve" || move == "soLve" || move == "solVe" || move == "solvE" || move == "SOlve" || move == "SoLve" || move == "SolVe" || move == "SolvE" || move == "sOLve" || move == "sOlVe" || move == "sOlvE" || move == "soLVe" || move == "soLvE" || move == "solVE" || move == "SOLve" || move == "SOlVe" || move == "SOlvE" || move == "SoLVe" || move == "SoLvE" || move == "SolVE" || move == "sOLVe" || move == "sOLvE" || move == "sOlVE" || move == "soLVE" || move == "SOLVe" || move == "SOLvE" || move == "SOlVE" || move == "SoLVE" || move == "sOLVE" || move == "SOLVE" || move == "quit" || move == "Quit" || move == "quit" || move == "quIt" || move == "quiT" || move == "QUit" || move == "QuIt" || move == "QuiT" || move == "qUIt" || move == "qUiT" || move == "quIT" || move == "QUIt" || move == "QUiT" || move == "QuIT" || move == "qUIT" || move == "QUIT")
			valid = 1;
		else
			valid = 0;

		while (valid == 0)
		{
			cout << "\tInvalid move. Try again, or enter \"HELP\": ";
			cin >> move;
			if (move == "r" || move == "l" || move == "u" || move == "d" || move == "b" || move == "f" || move == "r'" || move == "l'" || move == "u'" || move == "d'" || move == "b'" || move == "f'" || move == "R" || move == "L" || move == "U" || move == "D" || move == "B" || move == "F" || move == "R'" || move == "L'" || move == "U'" || move == "D'" || move == "B'" || move == "F'" || move == "help" || move == "Help" || move == "hElp" || move == "heLp" || move == "helP" || move == "HElp" || move == "HeLp" || move == "HelP" || move == "hELp" || move == "hElP" || move == "heLP" || move == "HELp" || move == "HElP" || move == "HeLP" || move == "hELP" || move == "HELP" || move == "solve" || move == "Solve" || move == "sOlve" || move == "soLve" || move == "solVe" || move == "solvE" || move == "SOlve" || move == "SoLve" || move == "SolVe" || move == "SolvE" || move == "sOLve" || move == "sOlVe" || move == "sOlvE" || move == "soLVe" || move == "soLvE" || move == "solVE" || move == "SOLve" || move == "SOlVe" || move == "SOlvE" || move == "SoLVe" || move == "SoLvE" || move == "SolVE" || move == "sOLVe" || move == "sOLvE" || move == "sOlVE" || move == "soLVE" || move == "SOLVe" || move == "SOLvE" || move == "SOlVE" || move == "SoLVE" || move == "sOLVE" || move == "SOLVE" || move == "quit" || move == "Quit" || move == "quit" || move == "quIt" || move == "quiT" || move == "QUit" || move == "QuIt" || move == "QuiT" || move == "qUIt" || move == "qUiT" || move == "quIT" || move == "QUIt" || move == "QUiT" || move == "QuIT" || move == "qUIT" || move == "QUIT")
				valid = 1;
			else
				valid = 0;
		}

		if (move == "R" || move == "r")
		{
			holder1 = front[2];
			holder2 = front[5];
			holder3 = front[8];
			front[2] = down[2];
			front[5] = down[5];
			front[8] = down[8];
			down[2] = back[6];
			down[5] = back[3];
			down[8] = back[0];
			back[6] = up[2];
			back[3] = up[5];
			back[0] = up[8];
			up[2] = holder1;
			up[5] = holder2;
			up[8] = holder3;
			holder1 = right[0];
			holder2 = right[1];
			right[0] = right[6];
			right[6] = right[8];
			right[8] = right[2];
			right[2] = holder1;
			right[1] = right[3];
			right[3] = right[7];
			right[7] = right[5];
			right[5] = holder2;
			moves++;
		}
		else if (move == "R'" || move == "r'")
		{
			holder1 = front[2];
			holder2 = front[5];
			holder3 = front[8];
			front[2] = up[2];
			front[5] = up[5];
			front[8] = up[8];
			up[2] = back[6];
			up[5] = back[3];
			up[8] = back[0];
			back[6] = down[2];
			back[3] = down[5];
			back[0] = down[8];
			down[2] = holder1;
			down[5] = holder2;
			down[8] = holder3;
			holder1 = right[0];
			holder2 = right[1];
			right[0] = right[2];
			right[2] = right[8];
			right[8] = right[6];
			right[6] = holder1;
			right[1] = right[5];
			right[5] = right[7];
			right[7] = right[3];
			right[3] = holder2;
			moves++;
		}
		else if (move == "L" || move == "l")
		{
			holder1 = front[0];
			holder2 = front[3];
			holder3 = front[6];
			front[0] = up[0];
			front[3] = up[3];
			front[6] = up[6];
			up[0] = back[8];
			up[3] = back[5];
			up[6] = back[2];
			back[8] = down[0];
			back[5] = down[3];
			back[2] = down[6];
			down[0] = holder1;
			down[3] = holder2;
			down[6] = holder3;
			holder1 = left[0];
			holder2 = left[1];
			left[0] = left[6];
			left[6] = left[8];
			left[8] = left[2];
			left[2] = holder1;
			left[1] = left[3];
			left[3] = left[7];
			left[7] = left[5];
			left[5] = holder2;
			moves++;
		}
		else if (move == "L'" || move == "l'")
		{
			holder1 = front[0];
			holder2 = front[3];
			holder3 = front[6];
			front[0] = down[0];
			front[3] = down[3];
			front[6] = down[6];
			down[0] = back[8];
			down[3] = back[5];
			down[6] = back[2];
			back[8] = up[0];
			back[5] = up[3];
			back[2] = up[6];
			up[0] = holder1;
			up[3] = holder2;
			up[6] = holder3;
			holder1 = left[0];
			holder2 = left[1];
			left[0] = left[2];
			left[2] = left[8];
			left[8] = left[6];
			left[6] = holder1;
			left[1] = left[5];
			left[5] = left[7];
			left[7] = left[3];
			left[3] = holder2;
			moves++;
		}
		else if (move == "U" || move == "u")
		{
			holder1 = front[0];
			holder2 = front[1];
			holder3 = front[2];
			front[0] = right[0];
			front[1] = right[1];
			front[2] = right[2];
			right[0] = back[0];
			right[1] = back[1];
			right[2] = back[2];
			back[0] = left[0];
			back[1] = left[1];
			back[2] = left[2];
			left[0] = holder1;
			left[1] = holder2;
			left[2] = holder3;
			holder1 = up[0];
			holder2 = up[1];
			up[0] = up[6];
			up[6] = up[8];
			up[8] = up[2];
			up[2] = holder1;
			up[1] = up[3];
			up[3] = up[7];
			up[7] = up[5];
			up[5] = holder2;
			moves++;
		}
		else if (move == "U'" || move == "u'")
		{
			holder1 = front[0];
			holder2 = front[1];
			holder3 = front[2];
			front[0] = left[0];
			front[1] = left[1];
			front[2] = left[2];
			left[0] = back[0];
			left[1] = back[1];
			left[2] = back[2];
			back[0] = right[0];
			back[1] = right[1];
			back[2] = right[2];
			right[0] = holder1;
			right[1] = holder2;
			right[2] = holder3;
			holder1 = up[0];
			holder2 = up[1];
			up[0] = up[2];
			up[2] = up[8];
			up[8] = up[6];
			up[6] = holder1;
			up[1] = up[5];
			up[5] = up[7];
			up[7] = up[3];
			up[3] = holder2;
			moves++;
		}
		else if (move == "D" || move == "d")
		{
			holder1 = front[6];
			holder2 = front[7];
			holder3 = front[8];
			front[6] = left[6];
			front[7] = left[7];
			front[8] = left[8];
			left[6] = back[6];
			left[7] = back[7];
			left[8] = back[8];
			back[6] = right[6];
			back[7] = right[7];
			back[8] = right[8];
			right[6] = holder1;
			right[7] = holder2;
			right[8] = holder3;
			holder1 = down[0];
			holder2 = down[1];
			down[0] = down[6];
			down[6] = down[8];
			down[8] = down[2];
			down[2] = holder1;
			down[1] = down[3];
			down[3] = down[7];
			down[7] = down[5];
			down[5] = holder2;
			moves++;
		}
		else if (move == "D'" || move == "d'")
		{
			holder1 = front[6];
			holder2 = front[7];
			holder3 = front[8];
			front[6] = right[6];
			front[7] = right[7];
			front[8] = right[8];
			right[6] = back[6];
			right[7] = back[7];
			right[8] = back[8];
			back[6] = left[6];
			back[7] = left[7];
			back[8] = left[8];
			left[6] = holder1;
			left[7] = holder2;
			left[8] = holder3;
			holder1 = down[0];
			holder2 = down[1];
			down[0] = down[2];
			down[2] = down[8];
			down[8] = down[6];
			down[6] = holder1;
			down[1] = down[5];
			down[5] = down[7];
			down[7] = down[3];
			down[3] = holder2;
			moves++;
		}
		else if (move == "F" || move == "f")
		{
			holder1 = up[6];
			holder2 = up[7];
			holder3 = up[8];
			up[6] = left[8];
			up[7] = left[5];
			up[8] = left[2];
			left[8] = down[2];
			left[5] = down[1];
			left[2] = down[0];
			down[2] = right[0];
			down[1] = right[3];
			down[0] = right[6];
			right[0] = holder1;
			right[3] = holder2;
			right[6] = holder3;
			holder1 = front[0];
			holder2 = front[1];
			front[0] = front[6];
			front[6] = front[8];
			front[8] = front[2];
			front[2] = holder1;
			front[1] = front[3];
			front[3] = front[7];
			front[7] = front[5];
			front[5] = holder2;
			moves++;
		}
		else if (move == "F'" || move == "f'")
		{
			holder1 = up[6];
			holder2 = up[7];
			holder3 = up[8];
			up[6] = right[0];
			up[7] = right[3];
			up[8] = right[6];
			right[0] = down[2];
			right[3] = down[1];
			right[6] = down[0];
			down[2] = left[8];
			down[1] = left[5];
			down[0] = left[2];
			left[8] = holder1;
			left[5] = holder2;
			left[2] = holder3;
			holder1 = front[0];
			holder2 = front[1];
			front[0] = front[2];
			front[2] = front[8];
			front[8] = front[6];
			front[6] = holder1;
			front[1] = front[5];
			front[5] = front[7];
			front[7] = front[3];
			front[3] = holder2;
			moves++;
		}
		else if (move == "B" || move == "b")
		{
			holder1 = up[0];
			holder2 = up[1];
			holder3 = up[2];
			up[0] = right[2];
			up[1] = right[5];
			up[2] = right[8];
			right[2] = down[8];
			right[5] = down[7];
			right[8] = down[6];
			down[8] = left[6];
			down[7] = left[3];
			down[6] = left[0];
			left[6] = holder1;
			left[3] = holder2;
			left[0] = holder3;
			holder1 = back[0];
			holder2 = back[1];
			back[0] = back[6];
			back[6] = back[8];
			back[8] = back[2];
			back[2] = holder1;
			back[1] = back[3];
			back[3] = back[7];
			back[7] = back[5];
			back[5] = holder2;
			moves++;
		}
		else if (move == "B'" || move == "b'")
		{
			holder1 = up[0];
			holder2 = up[1];
			holder3 = up[2];
			up[0] = left[6];
			up[1] = left[3];
			up[2] = left[0];
			left[6] = down[8];
			left[3] = down[7];
			left[0] = down[6];
			down[6] = right[8];
			down[7] = right[5];
			down[8] = right[2];
			right[2] = holder1;
			right[5] = holder2;
			right[8] = holder3;
			holder1 = back[0];
			holder2 = back[1];
			back[0] = back[2];
			back[2] = back[8];
			back[8] = back[6];
			back[6] = holder1;
			back[1] = back[5];
			back[5] = back[7];
			back[7] = back[3];
			back[3] = holder2;
			moves++;
		}
		else if (move == "help" || move == "Help" || move == "hElp" || move == "heLp" || move == "helP" || move == "HElp" || move == "HeLp" || move == "HelP" || move == "hELp" || move == "hElP" || move == "heLP" || move == "HELp" || move == "HElP" || move == "HeLP" || move == "hELP" || move == "HELP")
		{
			system("CLS");
			cout << "\n\n\n\n\tInstructions:\n\tTurn the cube by inputting one of the following:\n\tU, L, F, R, D, B, U', L', F', R', D', B'\n\tU rotates the top layer of the cube.\n\tL rotates the left layer of the cube.\n\tF rotates the front layer of the cube.\n\tR rotates the right layer of the cube.\n\tD rotates the bottom layer of the cube.\n\tB rotates the back layer of the cube.\n\tLetters by themselves will rotate the layer clockwise.\n\tAdding a ' to your input will rotate the layer counter-clockwise.\n\tStuck? Enter the word \"SOLVE\" to finish the puzzle.\n\tGive up? Enter the word \"QUIT\" to quit.\n\tEnter the word \"HELP\" at any time to return here.\n\n\t";
			system("PAUSE");
		}
		else if (move == "solve" || move == "Solve" || move == "sOlve" || move == "soLve" || move == "solVe" || move == "solvE" || move == "SOlve" || move == "SoLve" || move == "SolVe" || move == "SolvE" || move == "sOLve" || move == "sOlVe" || move == "sOlvE" || move == "soLVe" || move == "soLvE" || move == "solVE" || move == "SOLve" || move == "SOlVe" || move == "SOlvE" || move == "SoLVe" || move == "SoLvE" || move == "SolVE" || move == "sOLVe" || move == "sOLvE" || move == "sOlVE" || move == "soLVE" || move == "SOLVe" || move == "SOLvE" || move == "SOlVE" || move == "SoLVE" || move == "sOLVE" || move == "SOLVE")
		{
			for (int i = 0; i < 9; i++)
				front[i] = 'W';
			for (int i = 0; i < 9; i++)
				up[i] = 'R';
			for (int i = 0; i < 9; i++)
				left[i] = 'B';
			for (int i = 0; i < 9; i++)
				right[i] = 'G';
			for (int i = 0; i < 9; i++)
				down[i] = 'O';
			for (int i = 0; i < 9; i++)
				back[i] = 'Y';
			playing = 0;
			playerFinish = 0;
		}
		else if (move == "quit" || move == "Quit" || move == "quit" || move == "quIt" || move == "quiT" || move == "QUit" || move == "QuIt" || move == "QuiT" || move == "qUIt" || move == "qUiT" || move == "quIT" || move == "QUIt" || move == "QUiT" || move == "QuIT" || move == "qUIT" || move == "QUIT")
		{
			playing = 0;
			quit = 1;
		}
		else
		{
			cout << "An error has occurred.";
			playing = 0;
		}
		if (front[4] == front[0] && front[4] == front[1] && front[4] == front[2] && front[4] == front[3] && front[4] == front[5] && front[4] == front[6] && front[4] == front[7] && front[4] == front[8]
			&& back[4] == back[0] && back[4] == back[1] && back[4] == back[2] && back[4] == back[3] && back[4] == back[5] && back[4] == back[6] && back[4] == back[7] && back[4] == back[8]
			&& up[4] == up[0] && up[4] == up[1] && up[4] == up[2] && up[4] == up[3] && up[4] == up[5] && up[4] == up[6] && up[4] == up[7] && up[4] == up[8]
			&& down[4] == down[0] && down[4] == down[1] && down[4] == down[2] && down[4] == down[3] && down[4] == down[5] && down[4] == down[6] && down[4] == down[7] && down[4] == down[8]
			&& left[4] == left[0] && left[4] == left[1] && left[4] == left[2] && left[4] == left[3] && left[4] == left[5] && left[4] == left[6] && left[4] == left[7] && left[4] == left[8]
			&& right[4] == right[0] && right[4] == right[1] && right[4] == right[2] && right[4] == right[3] && right[4] == right[5] && right[4] == right[6] && right[4] == right[7] && right[4] == right[8] && moves > 0 && !(move == "solve" || move == "Solve" || move == "sOlve" || move == "soLve" || move == "solVe" || move == "solvE" || move == "SOlve" || move == "SoLve" || move == "SolVe" || move == "SolvE" || move == "sOLve" || move == "sOlVe" || move == "sOlvE" || move == "soLVe" || move == "soLvE" || move == "solVE" || move == "SOLve" || move == "SOlVe" || move == "SOlvE" || move == "SoLVe" || move == "SoLvE" || move == "SolVE" || move == "sOLVe" || move == "sOLvE" || move == "sOlVE" || move == "soLVE" || move == "SOLVe" || move == "SOLvE" || move == "SOlVE" || move == "SoLVE" || move == "sOLVE" || move == "SOLVE"))
		{
			playing = 0;
			playerFinish = 1;
		}
		Sleep(200);
		system("CLS");
	}
	if (quit == 0)
	{
		cout << "\n\n\n\n\t      " << up[0] << " " << up[1] << " " << up[2] << endl;
		cout << "\t      " << up[3] << " " << up[4] << " " << up[5] << endl;
		cout << "\t      " << up[6] << " " << up[7] << " " << up[8] << endl;
		cout << "\t" << left[0] << " " << left[1] << " " << left[2] << " " << front[0] << " " << front[1] << " " << front[2] << " " << right[0] << " " << right[1] << " " << right[2] << " " << back[0] << " " << back[1] << " " << back[2] << endl;
		cout << "\t" << left[3] << " " << left[4] << " " << left[5] << " " << front[3] << " " << front[4] << " " << front[5] << " " << right[3] << " " << right[4] << " " << right[5] << " " << back[3] << " " << back[4] << " " << back[5] << endl;
		cout << "\t" << left[6] << " " << left[7] << " " << left[8] << " " << front[6] << " " << front[7] << " " << front[8] << " " << right[6] << " " << right[7] << " " << right[8] << " " << back[6] << " " << back[7] << " " << back[8] << endl;
		cout << "\t      " << down[0] << " " << down[1] << " " << down[2] << endl;
		cout << "\t      " << down[3] << " " << down[4] << " " << down[5] << endl;
		cout << "\t      " << down[6] << " " << down[7] << " " << down[8] << endl;
		if (moves == 1)
			plural = "";
		if (playerFinish == 0)
			cout << "\n\tThe puzzle has been solved.\n\n\n\t";
		else
			cout << "\n\tYou solved the puzzle!\n\tIt took you " << moves << " move" << plural << ".\n\n\n\t";
	}
	else
		cout << "\n\n\n\t";
	return 0;
}