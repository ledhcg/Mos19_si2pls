#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 2000000000
int main()
{
	int m;
	int sB4; // Spinner 4 blades
	int sB3; // Spinner 3 blades
	cout << "Enter positive integer: M = ";
	cin >> m;
	if (m >= MAX)
	{
		cout << "! The number input >= 2.10^9!" << endl;
	}
	else
	{
		sB4 = m % 3;
		sB3 = (m - 4 * sB4) / 3;
		if (sB3 >= 0)
		{
			cout << "Spinner 3 blades = " << sB3 << endl;
			cout << "Spinner 4 blades = " << sB4 << endl;
		}
		else
		{
			cout << "Spinner 3 blades = 0" << endl;
			cout << "Spinner 4 blades = 0" << endl;
		}
	}
	return 0;
}