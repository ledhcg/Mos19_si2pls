#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
void RandomNumber(int m, int i, int c)
{
	int s;
	int cnt = 0;
	for (int j = 0; j <= c; j++)
	{
		s = j;
		int k = (m * s + i) % c;
		if (s == k)
		{
			cout << "Random number: " << s << endl;
			cnt++;
			break;
		}
				
	}
	if (cnt ==0)
	cout << "Can not create random number from your random numbers!" << endl;
}
void RandomNumber1(int m, int i, int c)
{
	for (int j = 0; j <= 1000; j++)
	{
		int s = j;

		int k = (m * s + i) % c;
		if (s==k)
		{
			cout << "Random number: " << s << endl;
		}
		else
		{
			cout << "ERROss";
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int m, i, c;
	cout << "Create random number s" << endl;
	cout << "Form s = (m * s + i) % c" << endl;
	cout << "Enter 3 random numbers (intergers) m, i, c: ";
	cin >> m >> i >> c;
	RandomNumber(m, i, c);
	RandomNumber1(m, i, c);
	system("pause");
	return 0;
}