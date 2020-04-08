#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	float a, b, c;
	cout << "Input number 1 - a = ";
	cin >> a;
	cout << "Input number 2 - b = ";
	cin >> b;
	cout << "Input number 3 - c = ";
	cin >> c;
	cout << "Answer: ax^2 + bx + c = 0" << endl;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	float delta;
	delta = pow(b, 2) - 4 * a * c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c != 0)
				cout << "No solution" << endl; //нет решения
			else
				cout << "Wealth of cointer" << endl; //Бесчисленные решения
		}
		else
			cout << "Answer x = " << -c / b << endl;
	}
	else
	{
		if (delta > 0)
			cout << "Answer: x1 = " << (-b - sqrt(delta)) / (2 * a) << ", x2 = " << (-b + sqrt(delta)) / (2 * a) << endl;
		else
		{
			if (delta == 0)
				cout << "Answer: x = " << -b / (2 * a) << endl;
			else 
				cout << "No solution" << endl; //нет решения
		}
	}
	
	system("pause");
	return 0;

}