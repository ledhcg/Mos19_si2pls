#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MAX 50
int main()
{
	ifstream inFile;
	inFile.open("C:\\FileForVS2019\\2_File\\input.txt");
	char a[MAX];
	int k =0;
	int k1;
	char copy[MAX];
	cout << "The text found in file:" << endl;
	while (!inFile.eof())
	{
		inFile >> a;
		cout << a << " ";
		k1 = strlen(a);
		if (k1 > k)
		{
			k = k1;
			for (int i = 0; i < k; i++)
			{
				copy[i] = a[i];
			}
		}
	}
	cout << endl << endl;
	inFile.close();
	cout << "Longest word found in file: ";
	for (int i = 0; i < k; i++)
		cout << copy[i];
	cout << endl;
	return 0;
}