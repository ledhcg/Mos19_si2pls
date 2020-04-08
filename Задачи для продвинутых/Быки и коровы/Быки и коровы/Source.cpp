#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
bool contains_duplicates(string s)
{
	sort(s.begin(), s.end());
	return adjacent_find(s.begin(), s.end()) != s.end();
}

void game()
{
	typedef string::size_type index;

	string symbols = "0123456789";
	unsigned int const selection_length = 4;

	random_shuffle(symbols.begin(), symbols.end());
	string selection = symbols.substr(0, selection_length);
	string guess;
	while (cout << "Your guess? ", getline(cin, guess))
	{
		if (guess.length() != selection_length || guess.find_first_not_of(symbols) != string::npos || contains_duplicates(guess))
		{
			cout << guess << " is not a valid guess!";
			continue;
		}
		unsigned int bulls = 0;
		unsigned int cows = 0;
		for (index i = 0; i != selection_length; ++i)
		{
			index pos = selection.find(guess[i]);
			if (pos == i)
				++bulls;
			else if (pos != string::npos)
				++cows;
		}
		cout << bulls << " (+), " << cows << " (-).\n";  //bull = plus , cow = minut
		if (bulls == selection_length)
		{
			cout << "Congratulations! You have won!\n";
			return;
		}
	}
	cerr << "Oops! Something went wrong with input, or you've entered end-of-file!\nExiting ...\n";
	exit(EXIT_FAILURE);
}

int main()
{
	cout << "Welcome to bulls and cows!\nDo you want to play? ";
	string answer;
	while (true)
	{
		while (true)
		{
			if (!getline(std::cin, answer))
			{
				cout << "I can't get an answer. Exiting.\n";
				return EXIT_FAILURE;
			}
			if (answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y")
				break;
			if (answer == "no" || answer == "No" || answer == "n" || answer == "N")
			{
				cout << "Ok. Goodbye.\n";
				return EXIT_SUCCESS;
			}
			cout << "Please answer yes or no: ";
		}
		game();
		cout << "Another game? ";
	}
}