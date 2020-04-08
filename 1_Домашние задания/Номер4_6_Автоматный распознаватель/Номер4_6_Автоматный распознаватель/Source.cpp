#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define MAX 300
int main()
{
	char RomanNumber[MAX];
	cout << "Enter any roman number: ";
	cin.getline(RomanNumber, MAX);
	int k = strlen(RomanNumber);
	//Chuyen chu thuong thanh chu hoa
	for (int i = 0; i < k; i++)
	{
		if (RomanNumber[i] >= 'a' && RomanNumber[i] <= 'z')
			RomanNumber[i] -= 32;
	}
	//Kiem tra ki tu ngoai vi trong so La ma
	int ifdo = 1;
	
	for (int j = 0; j < k; j++)
	{
		if (RomanNumber[j] != 'I' && RomanNumber[j] != 'V' && RomanNumber[j] != 'X' && RomanNumber[j] != 'L' && RomanNumber[j] != 'C' && RomanNumber[j] != 'D' && RomanNumber[j] != 'M')
			ifdo = 0;
	}
	if (ifdo == 1)
	{
		for (int j = 0; j < k; j++)
		{

			//ham convert sang so nguyen
			int Convert[MAX];
			//dinh nghia cac ki tu sang so va truyen vao vao ham Convert
			for (int i = 0; i < k; i++)
			{
				// ASCII I = 73
				if (RomanNumber[i] == 'I')
					Convert[i] = RomanNumber[i] - 72;
				// ASCII V = 86
				if (RomanNumber[i] == 'V')
					Convert[i] = RomanNumber[i] - 81;
				// ASCII X = 88
				if (RomanNumber[i] == 'X')
					Convert[i] = RomanNumber[i] - 78;
				// ASCII L = 76
				if (RomanNumber[i] == 'L')
					Convert[i] = RomanNumber[i] - 26;
				// ASCII C = 67
				if (RomanNumber[i] == 'C')
					Convert[i] = RomanNumber[i] + 33;
				// ASCII D = 68
				if (RomanNumber[i] == 'D')
					Convert[i] = RomanNumber[i] + 432;
				// ASCII M = 77
				if (RomanNumber[i] == 'M')
					Convert[i] = RomanNumber[i] + 9923;

			}
			//dinh nghia quy luat so la ma
			for (int i = 0; i < k; i++)
			{
				if (Convert[i] == 1)
					if (Convert[i + 1] == 5 || Convert[i + 1] == 10)
					{
						Convert[i] = -1;
					}
					else
					{
						Convert[i] = 1;
					}
				if (Convert[i] == 10)
					if (Convert[i + 1] == 50 || Convert[i + 1] == 100)
					{
						Convert[i] = -10;
					}
					else
					{
						Convert[i] = 10;
					}
				if (Convert[i] == 100)
					if (Convert[i + 1] == 500 || Convert[i + 1] == 1000)
					{
						Convert[i] = -100;
					}
					else
					{
						Convert[i] = 100;
					}
			}
			cout << setfill('-');
			cout << setw(35) << "-";
			cout << endl;
			//Tinh tong
			int sum = 0;
			for (int i = 0; i < k; i++)
			{
				sum += Convert[i];
			}
			cout << "This roman number = " << sum << " (DEX)" << endl;
			break;
		}
		
	}
	else
	{
			cout << "ERROR - Cause this is not roman number!" << endl;
	}
	system("pause");
	return 0;
}