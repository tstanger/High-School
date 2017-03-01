#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

int main()
{
	char playAgain = 'Y';
	int firstTime = 1, f = 0;
	while (playAgain == 'Y' || playAgain == 'y')
	{
		stringstream guessedLettersSS;
		string alphabet[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
		string alreadyGuessed[26] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
		srand(time(0));
		system("CLS");
		string input, guess, guessedLetters = "", plural = "es", pluralW = "";
		int randomInt, g = 0;
		cout << "\n\n\tEnter a word, or type \"random\" for a random word: ";
		if (firstTime != 1)
			cin.ignore();
		getline(cin, input);
		string random[145] = { "acres", "adult", "advice", "arrangement", "attempt", "August", "autumn", "border", "breeze", "brick", "buff", "buzz", "calm", "canal", "casey", "cast", "chose", "claws", "coach", "constantly", "contrast", "cookies", "customs", "damage", "danny", "deeply", "depth", "discussion", "dizzy", "doll", "donkey", "egypt", "ellen", "essential", "exchange", "exist", "explanation", "facing", "fax", "film", "finest", "fireplace", "fizz", "fuzz", "floating", "folks", "fort", "fox", "garage", "grabbed", "grandmother", "habit", "happily", "harry", "heading", "hunter", "huff", "illinois", "image", "independent", "instant", "january", "jazz", "jinx", "junk", "kids", "label", "lax", "lee", "lungs", "manufacturing", "martin", "mathematics", "melted", "memory", "mill", "mission", "monkey", "mount", "mysterious", "neighborhood", "norway", "nuts", "occasionally", "official", "ourselves", "palace", "pennsylvania", "philadelphia", "plates", "poetry", "policeman", "positive", "possibly", "practical", "pride", "promised", "puff", "quiz", "recall", "relationship", "remarkable", "require", "rhyme", "rhythm", "rocky", "rubbed", "rush", "sale", "satellites", "satisfied", "scared", "selection", "shake", "shaking", "shallow", "shout", "silly", "simplest", "slight", "slip", "slope", "soap", "solar", "species", "sphynx", "spin", "stiff", "swung", "tales", "thumb", "tobacco", "toy", "trap", "treated", "tune", "university", "vapor", "vessels", "wealth", "wolf", "zap", "zephyr", "zit", "zoo" };
		if (input == "random")
		{
			randomInt = rand() % 146;
			input = random[randomInt];
		}
		int x = input.length(), n = 0, guesses = 0, a = 0;
		int y = x;
		bool solved = 0, lose = 0;
		string * word = new string[x];
		while (x--)
		{
			word[n] = input.substr(n, 1);
			n++;
		}
		x = y, n = 0;
		string * hidden = new string[x];
		while (x--)
		{
			if (word[n] != " ")
				hidden[n] = "?";
			else
			{
				hidden[n] = " ";
				pluralW = "s";
			}
			n++;
		}
		x = y, n = 0;
		while (solved != 1)
		{
			system("CLS");
			cout << "\n\n\t";
			while (x--)
			{
				cout << hidden[n];
				n++;
			}
			x = y, n = 0;
			if (guesses == 0)
			{
				cout << "\n\tGuess a letter: ";
				cin >> guess;
			}
			else if (guesses == 1)
			{
				cout << "\n\t(You have guessed " << guesses << " time)\n\tAlready guessed letter: " << guessedLetters << "\n\tGuess a letter, or solve the word: ";
				cin >> guess;
			}
			else if (guesses < 14 && guesses > 1)
			{
				cout << "\n\t(You have guessed " << guesses << " times)\n\tAlready guessed letters: " << guessedLetters << "\n\tGuess a letter, or solve the word: ";
				cin >> guess;
			}
			else if (guesses >= 14 && guesses < 27)
			{
				g = guessedLetters.length() - 28;
				cout << "\n\t(You have guessed " << guesses << " times)\n\tAlready guessed letters: " << guessedLetters.substr(0, 33) << "\n\t " << guessedLetters.substr(33, g) << "\n\tGuess a letter, or solve the word: ";
				cin >> guess;
			}
			else if (guesses >= 27)
			{
				x = y, n = 0;
				while (x--)
				{
					hidden[n] = word[n];
					n++;
				}
				solved = 1;
				lose = 1;
			}
			x = y, n = 0;
			while (x--)
			{
				if (guess.length() == 1)
				{
					if (guess.substr(0, 1) == word[n])
						hidden[n] = guess.substr(0, 1);
					n++;
				}
				else
				{
					if (guess == input)
					{
						x = 0;
						solved = 1;
					}
				}
			}
			guesses++;
			x = y, n = 0;
			while (x--)
			{
				if (hidden[n] != "?")
					a++;
				if (a == input.length())
				{
					solved = 1;
					x = 0;
				}
				n++;
			}
			x = y, n = 0, a = 0;
			if (guess.length() == 1)
			{
				if (guesses == 1 || guessedLetters == "")
					guessedLettersSS << guess.substr(0, 1);
				else
					guessedLettersSS << ", " << guess.substr(0, 1);
				guessedLetters = guessedLettersSS.str();
			}
		}
		system("CLS");
		if (guesses == 1)
			plural = "";
		else
			plural = "es";
		if (lose == 0)
			cout << "\n\n\tYou solved the word" << pluralW << " \"" << input << "\" in " << guesses << " guess" << plural << ".\n\tWould you like to play again? (Y/N) >> ";
		else if (lose == 1)
			cout << "\n\n\tYou failed to solve the word" << pluralW << " \"" << input << ".\"\n\tWould you like to play again? (Y/N) >> ";
		cin >> playAgain;
		firstTime = 0;
	}
	system("CLS");
	cout << "\n\n\n\t\t\t\t";
	return 0;
}