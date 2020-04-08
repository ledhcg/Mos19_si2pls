#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	
	cout << "\t\t x^2 - 2x + 2" << endl;
	cout << "Calculate y = ";
	cout << setfill('-');
	cout << setw(20) << "-" << endl;
	cout << "\t\t    x - 1" << endl;
	cout << "x = [-4;4] and step = 0,5" << endl;
	cout << setfill('.');
	cout << setw(40) << "." << endl;

	for (double x = -4; x <= 4; x += 0.5)
	{
		double h = pow(x, 2) - 2 * x + 2;
		double k = x - 1;
		if (k != 0)
		{
			cout << "Answer y = " << h / k << endl;
			cout << "\t if x = " << x << endl;
			cout << endl;
		}
		else
		{
			cout << "Math ERROR" << endl;
			cout << "\t if x = " << x << endl;
			cout << endl;
		}
	}
	system("pause");
	return 0;
}