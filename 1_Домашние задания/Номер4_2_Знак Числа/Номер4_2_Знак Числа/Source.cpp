#include <iostream>
#include <iomanip>
using namespace std;

int main()
{		
		cout << "*if x > 0 => Sign x = 1." << endl;
		cout << "*if x = 0 => Sign x = 0." << endl;
		cout << "*if x > 0 => Sign x = -1." << endl;
		cout << setfill('-');
		cout << setw(25) << "-" << endl;
		cout << "Enter any x: ";
			float x;
		cin >> x;
		if (x >= 0)
		{
			if (x > 0)
				cout << "Sign x = 1." << endl;
			else
				cout << "Sign x = 0." << endl;
		}
		else
			cout << "Sign x = -1." << endl;
		system("pause");
		return 0;
}