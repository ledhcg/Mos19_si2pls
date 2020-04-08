#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX = 30;
int main()
{
	//Khai bao ten file
	char nameFile[MAX], input;
	cout << "Enter your name file: ";
	cin >> setw(MAX) >> nameFile;
	//Tao file moi
	ofstream myFile;
	myFile.open(nameFile);
	cout << "Enter random 10 numbers:" << endl;
	int k;
	for (int i = 0; i < 10;i++)
	{	
		cout << "Number " << i+1 << " : ";
		cin >> k;
		
		myFile << k;
		myFile << " ";
		
	}
	myFile.close();
	ifstream ReadFile;
	ReadFile.open(nameFile);
	int sum = 0;
	int n;
	while (!ReadFile.eof())
		{
		
			ReadFile >> n;
			
			
			
			if (ReadFile.eof())
			{
				break;
			}
			//Debug: cout << n << " ";
			sum += n;
		}
	cout << endl;
	cout << "SUM = "<< sum << endl;
	ReadFile.close();
	system("pause");
	return 0;

}