#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int x, y, b;
	cout << "Calculate function: z = ln(b-y)*sqrt(b-x)" << endl;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "Enter information: " << endl;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "b = ";
	cin >> b;
	if ((b - y) > 0 && (b - x) >= 0)
	{
		double z = log(b - y) * sqrt(b - x);
		cout << "Answer: z = " << z << endl;
	}
	else
		cout << "Math ERROR!" << endl;
	system("pause");
	return 0;
}