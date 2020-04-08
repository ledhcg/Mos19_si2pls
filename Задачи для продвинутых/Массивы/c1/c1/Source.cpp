#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n;

	cout << "Enter number: ";
	cin >> n;
	if (n < 0)
		cout << "Не положительным: Да!" << endl;
	else
		cout << "Не положительным: Нет!" << endl;
	if (n % 2)
		cout << "Нечетным: Да!" << endl;
	else
		cout << "Нечетным: Нет!" << endl;
	if (n > -3)
		cout << "Превосходящим число -3: Да!" << endl;
	else
		cout << "Превосходящим число -3: Нет!" << endl;
	cout << "Степеньно двойки: " << pow(2, n) << endl;
	return 0;
}