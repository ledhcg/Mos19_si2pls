#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	cout << "\t   S.r.(1 + r)^n \t\t\t  p" << endl;
	cout << "m = ";
	cout << setfill('-');
	cout << setw(30) << "-";
	cout << " where r = ";
	cout << setw(12) << "-" << endl;
	cout << "\t 12.((1 + r)^n - 1) \t\t\t 100" << endl;
	cout << setfill('/');
	cout << setw(65) << "/" << endl;
	cout << "Enter information:" << endl;
	double s, m, n, i, k;
	double p = 0;
	cout << "S (rup) = ";
	cin >> s;
	cout << "m = ";
	cin >> m;
	cout << "n = ";
	cin >> n;
	for ( p = 0.0001; p <= 100; p +=0.001)
	{	
		double r = double(p) / 100;
		i = s * r * pow((1 + r), n);
		k = 12 * (pow((1 + r), n) - 1);
		double m0 = i / k;
		if (m < m0)
			break;
	} 
	cout << "Answer: p = " << p << endl;
	
	system("pause");
	return 0;
}