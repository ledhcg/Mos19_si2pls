#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{	
	cout << "\t   S.r.(1 + r)^n \t\t\t  p" << endl;
	cout << "m = ";
	cout << setfill('-');
	cout << setw(30) <<"-";
	cout << " where r = ";
	cout << setw(12) << "-" << endl;
	cout << "\t 12.((1 + r)^n - 1) \t\t\t 100" <<endl;
	cout << setfill('/');
	cout << setw(65) << "/" << endl;
	cout << "Enter information:" << endl;
	double s, p, n, r, i, k;
	cout << "S (rup) = ";
	cin >> s;
	cout << "p = "; 
	cin >> p;
	cout << "n = ";
	cin >> n;
	r = p / 100;
	i = s * r * pow((1 + r), n);
	k = 12 * (pow((1 + r), n) - 1);
	if (k != 0)
		cout << "Answer: m = " << i / k << endl;
	else
		cout << "Math ERROR" << endl;

	system("pause");
	return 0;
}