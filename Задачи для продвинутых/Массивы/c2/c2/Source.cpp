#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.1415

int main()
{
	int n;
	cout << "Enter number: ";
	cin >> n;
	if (n < 0)
	{
		cout << "y = " << -n + 1 << endl;
	}
	else
		if (n == 0)
			cout << "y = 1" << endl;
		else
			cout << "y = " << pow((sin(2 * n * PI / 180)), 2) << endl;
	return 0;
}