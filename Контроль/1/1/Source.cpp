#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 2000000000
int main()
{
	int a, b, c, n;
	cout << "Cost of spinner: A + B.N(number of blades) <= C" << endl;
	cout << "Cost of spinner base: A = ";
	cin >> a;
	cout << "Cost of one blade: B = ";
	cin >> b;
	cout << "The maximum cost of the entire spinner: C = ";
	cin >> c;
	if (a >= MAX || b >= MAX || c >= MAX)
	{
		cout << "! The number input >= 2.10^9!" << endl;
		
	}
	else
	{
		if (a > c)
		{
			cout << "Cost of spinner base > The maximum cost of the entire spinner!" << endl;
		}
		else
		/*{
			n = (c - a) / b;
			cout << "The maximum number of spinner blades: N = " << n << endl;

		}*/
		{
		n = 0;
		while ((a + b * n) <= c)
		{
			n += 1;
		}
		cout << "The maximum number of spinner blades: N = " << n-1 << endl;
	}
	}
	return 0;

	

}