#include <iostream>
#include <iomanip>
using namespace std;

int UCLN(int a, int b)
{
	if (b == 0)
		return a;
	else
		return UCLN(b, a % b);
}
int main()
{

	int a, b;
	cout << "Enter any 2 natural numbers" << endl;
	cout << "(for finding the greatest common divisor of 2 natural numbers)" << endl;
	cout << "N1 = ";
	cin >> a;
	cout << "N2 = ";
	cin >> b;
	int k;
	k = UCLN(a, b);
	cout << "UCLN = " << k << endl;
	return 0;
}