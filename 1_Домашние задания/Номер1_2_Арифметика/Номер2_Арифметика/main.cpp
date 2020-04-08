#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b;
	cout << "Input number 1 * a = ";
	cin >> a;
	cout << "Input number 2 * b = ";
	cin >> b;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "SUM = " << a + b << endl; //Сумма
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "Raznost = " << a - b << endl; //разность
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "Proizvedenie = " << a * b << endl; //Произведение
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	if (b != 0)
	{
		cout << "Chastnoe = " << (float) a / b << endl; //частное
	}	
	else
	{
		cout << "Net Chastnoe" << endl;
	}
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	system("pause");
	return 0;
}