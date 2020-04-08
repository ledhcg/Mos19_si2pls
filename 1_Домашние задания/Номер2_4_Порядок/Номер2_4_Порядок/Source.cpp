#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cout << "Enter a any natural number" << endl;
	cout << "Your natural number = ";
	cin >> n;
	cout << setfill('.');
	cout << setw(30) << "." << endl;
	cout << "List of 10 natural number in ascending order from your number" << endl; //10 so tu nhien lien tiep bat dau tu so da nhap
	if (n >= 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i < 9)
				cout << n + i << ", ";
			else
				cout << n + i << "." << endl;
		}
	}
	else
	{
		{
			for (int i = 0; i < 10; i++)
			{
				if (i < 9)
					cout << i << ", ";
				else
					cout << i << "." << endl;
			}
		}
	}
	system("pause");
	return 0;

}