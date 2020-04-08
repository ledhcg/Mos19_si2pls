#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 100
//Chuyen doi a to A
void atoA(char a[])
{
	int k = strlen(a);
	for (int i = 0; i < k; i++)
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;

	//Debug
	/*for (int i = 0; i < k; i++)
		cout << a[i] << " ";*/
}
//Ham chuyen chu thanh so
void ConvertLetterToNumber(char a[], int Copy1[])
{
	int k = strlen(a);
	for (int i =0; i < k; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			Copy1[i] = (int)a[i];
			Copy1[i] -= 48;
		}
		if (a[i] >= 'A')
		{
			Copy1[i] = (int)a[i];
			Copy1[i] -= 55;
		}
	}
	//Debug :
	/*for (int i = 0; i < k; i++)
		cout << Copy1[i] << " ";*/
}
//Ham kiem tra so input co cung co so input 
int Checkbase(char a[], int Copy1[], int n0)
{
	int k = strlen(a);
	int c=1;
	for (int i = 0; i < k; i++)
	{
		if (Copy1[i] >= n0)
			return 0;			
	}
	return c;
}
//Ham Convert ra so thap phan
int ConverttoDex(char a[], int n0, int Copy1[])
{
	int k = strlen(a);
	int Dex = 0;
	for (int i = 0; i < k; i++)
	{
		Dex += Copy1[i] * (int)pow(n0, k-i-1);
	}
	//DEbug cout << Dex << endl;
	return Dex;
}
//Ham chuyen so thap phan thanh he co so n1
void Convert(char a[], int n0, int n1)
{
	atoA(a);
	int Copy1[MAX];
	ConvertLetterToNumber(a, Copy1);
	int c = Checkbase(a, Copy1, n0);
	if (c == 1)
	{
		int Dex = ConverttoDex(a, n0, Copy1);
		//Debug : cout << Dex;
		int k = strlen(a);
		//so du
		int Copy[MAX];
		// Cho m chay tu 0 va gan Copy[m] bang ket qua tnh mod cua Dex va n1
		int m = 0;
		while (Dex != 0)
		{

			{
				if (Dex == 0)
					break;

				Copy[m] = Dex % n1;
				++m;
				// Debug :cout << " Du : " << Dex % n1 << endl;
				Dex = Dex / n1;
				// Debug : cout << "Day la" << Dex << endl;

			}
		}
		cout << "Your number in base (" << n1 << "): ";
		for (int j = m - 1; j >= 0; j--)
		{
			if (Copy[j] >= 0 && Copy[j] <= 9)
				cout << Copy[j];
			if (Copy[j] >= 10)
			{
				cout << (char)(Copy[j] + 55);
			}
		}
		cout << endl;
	}
	else
		cout << "Your number is not in base input!" << endl;
}
int main()
{
	cout << "Enter your number (any base of systems): ";
	char Input[MAX];
	cin.getline(Input, MAX);
	cout << "Enter base of system (input): ";
	int n0, n1;
	cin >> n0;
	cout << "Enter base of system (output): ";
	cin >> n1;
	//int Copy[MAX];
	cout << setfill('-');
	cout << setw(40) << "-";
	cout << endl;
	//cout << "Your number in base (" << n1 << "): ";
	Convert(Input, n0, n1);
	system("pause");
	return 0;

}