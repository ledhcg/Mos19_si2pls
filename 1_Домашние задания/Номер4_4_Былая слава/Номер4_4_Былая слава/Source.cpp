#include <iostream>
#include <iomanip>
using namespace std;
const int DAI = 55;
const int RONG = 14;
int main()
{
	char FlagUSA[RONG][DAI];
	cout << "Flag of USA 1912" << endl;
	for (int i = 0; i < RONG; i++)
		for (int j = 0; j < DAI; j++)
		{
			FlagUSA[i][j] = ' ';
		}
	for (int i = 0; i < RONG; i++)
	{
		for (int j = 0; j < DAI; j++)
		{
			FlagUSA[0][0] = '+';
			FlagUSA[0][DAI - 1] = '+';
			FlagUSA[RONG - 1][DAI - 1] = '+';
			FlagUSA[RONG - 1][0] = '+';
		}
	}
	for (int i = 1; i < RONG-1; i++)
	{
		for (int j = 0; j < DAI; j++)
		{
			FlagUSA[i][0] = '|';
			FlagUSA[i][DAI - 1] = '|';
		}
	}
	for (int i = 7; i < RONG; i++)
	{
		for (int j = 1; j < DAI-1; j++)
		{
			FlagUSA[i][j] = '-';
		}
	}
	for (int j = 1; j < DAI - 1; j++)
	{
		FlagUSA[0][j] = '-';
	}
	for (int i = 1; i < 7; i++)
	{
		for (int j = 2; j < 18; j+=2)
		{
			FlagUSA[i][j] = '*';
		}
	}
	for (int i = 1; i < 7; i++)
	{
		FlagUSA[i][18] = '|';
	}
	for (int i = 1; i < 7; i++)
	{
		for (int j = 19; j < DAI-1; j ++)
		{
			FlagUSA[i][j] = '-';
		}
	}
	for (int i = 0; i < RONG; i++)
	{
		for (int j = 0; j < DAI; j++)
		{
			cout << FlagUSA[i][j] << "";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}