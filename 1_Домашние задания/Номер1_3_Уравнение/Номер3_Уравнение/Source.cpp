#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float a, b;
	cout << "Input number 1 * a = ";
	cin >> a;
	cout << "Input number 2 * b = ";
	cin >> b;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "Answer: ax+b=0" << endl;
	if (a == 0)
	{
		if (b != 0)
			cout << "No solution" << endl; //нет решения
		else
			cout << "Wealth of cointer" << endl; //Бесчисленные решения
	}
	else
		cout << "Answer x = " << -b / a << endl;
	system("pause");
	return 0;
}
