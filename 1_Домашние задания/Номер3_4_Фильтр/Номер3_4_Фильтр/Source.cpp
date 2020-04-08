#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define MAX 100
int main()
{
	ifstream Read;
	Read.open("C:\\FileForVS2019\\1\\file3_4.txt");
	
	if (Read.fail())
	{
		cout << "Can not open file 'file3_4.txt'!" << endl;
	}
	else
	{
			
		while (!Read.eof())
		{
			char a;
			Read >> a;
			if (a >= '0' && a <= '9')
			{
					cout << a << " ";
			}

			if (Read.eof())
			{
				break;
			}
		}

	}
	Read.close();
	cout << endl;
	system("pause");
	return 0;


}