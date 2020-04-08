#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Provide information" << endl;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "Light (1. Turn on | 2. Turn off)" << endl; //Введите состояние лампа - 1.выключена, 2.включена
		cout << "Enter status: ";
	int light;
	cin >> light;
	cout << "Curtain (1. Pushed in | 2. Push out)" << endl; //Введите состояние штор - 1.задвинуты, 2.раздвинуты
		cout << "Enter status: ";
	int curtain;
	cin >> curtain;
	cout << "Time (0. Night | 1. Morning | 2. Afternoon | 3. Evening )" << endl; //Введите время суток
	cout << "Enter status: ";
	int time;
	cin >> time;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << ">> ";
	if (light == 1)
		cout << "The room is light!" << endl;
	else
	{
		if (curtain == 2)
		{
			if (time == 1 || time == 2)
				cout << "The room is light!" << endl;
			else
				cout << "The room is dark!" << endl;
		}
		else
			cout << "The room is dark!" << endl;
	}
	system("pause");
	return 0;
}