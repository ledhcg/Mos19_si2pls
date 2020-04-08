
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
//#include "DOHOA.h"
using namespace std;
int main()
{
	int size = 91, height = 21;

	//textcolor(2);
	cout << "Graph of Sin(x)" << endl;
	cout << endl << endl;
	// Start with an empty chart (lots of spaces and a line in the middle)
	vector<string> chart(height, string(size, ' '));
	chart[height / 2] = string(size, '-');
	for (int i = 0; i < height; ++i)
	{
		chart[i][0] = '|';
		chart[height-1][0] = 'v';
	}
	// Then just put x-es where the function should be plotted
	for (int i = 0; i < size; ++i) {
		chart[static_cast<int>(round(10 * std::sin(i / 11.5) + 10))][i] = '+';
		chart[height / 2][size - 1] = '>';
		chart[height / 2 - 1][size - 2] = ')';
		chart[height / 2 - 1][size - 3] = 'x';
		chart[height / 2 - 1][size - 4] = '(';
		chart[height - 1][2] = 's';
		chart[height - 1][3] = 'i';
		chart[height - 1][4] = 'n';
		chart[height - 1][5] = '(';
		chart[height - 1][6] = 'x';
		chart[height - 1][7] = ')';

	}

	// and print the whole shebang
	//textcolor(4);
	for (auto&& s : chart) 
	{
		cout << s << '\n';
	}
	cout << endl << endl;
	//textcolor(3);
	system("pause");
	return 0;
}