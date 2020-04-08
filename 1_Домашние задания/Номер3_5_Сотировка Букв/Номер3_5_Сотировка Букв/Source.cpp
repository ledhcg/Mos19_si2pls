#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstring>
using namespace std;
const int MAX = 30;
void SortingLetter(char Letter[])
{
	int k = strlen(Letter);
	float CopyString[MAX];
	for (int i = 0; i < k; i++)
	{

		if (Letter[i] >= 'A' && Letter[i] <= 'Z')
		{
			CopyString[i] = Letter[i];
			CopyString[i] += 31.5;
		}
		else
			CopyString[i] = Letter[i];

	}
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
		{
			if (CopyString[i] < CopyString[j])
			{
				float x;
				x = CopyString[i];
				CopyString[i] = CopyString[j];
				CopyString[j] = x;
			}
		}
	for (int i = 0; i < k; i++)
	{
		if (CopyString[i] != (int)CopyString[i])
			CopyString[i] -= 31.5;
	}
	for (int i = 0; i < k; i++)
	{
		if ((CopyString[i] >= 65 && CopyString[i] <= 90) || (CopyString[i] >= 97 && CopyString[i] <= 122))
			cout << (char)CopyString[i] << " ";
	}

}

int main()
{

	char sorting[MAX];
	cout << "Enter any letter (Limited to 30 characters): ";
	cin.getline(sorting, MAX);
	SortingLetter(sorting);
	system("pause");
	return 0;

}