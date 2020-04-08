#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	float a, x;
	cout << "w = a.ln|x| if |x| < 1" << endl;
	cout << "w = sqrt(a - x^2) if |x| >= 1" << endl;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "Input a, x" << endl;
	cout << "a = ";
	cin >> a;
	cout << "x = ";
	cin >> x;
	//cout << x;
	float w;
	if (x > -1 && x < 1)
	{
		if (x != 0)
		{
			if (x < 0)
			{
				w = a * log(-x);
				cout << "w = " << w << endl;
			}
			else
			{
				w = a * log(x);
				cout << "w = " << w << endl;
			}

		}
		else
		{

			cout << "Math ERROR" << endl;
		}

	}
	else
	{
		float k = a - pow(x, 2);
		if (k >= 0)
		{
			w = sqrt(k);
			cout << "w = " << w << endl;
		}
		else
		cout << "Math ERROR" << endl;
	}

	system("pause");
	return 0;
}