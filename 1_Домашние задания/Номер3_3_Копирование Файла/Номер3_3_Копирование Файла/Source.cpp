#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int length = 300;
int main()
{	//Input file name.
	char fileName[length], input;
	cout << "Your file name: ";
	cin >> setw(length) >> fileName;
	//Khai bao va mo tep tin
	char data[100];
	//Open a file in Write mode
	ofstream myFile;
	myFile.open(fileName);
	cout << "File is in Write mode" << endl;
	cout << "Warning: Limited to 500 characters!" << endl;
	//input is ignored
	cin.ignore();
	cout << "Please enter your name: ";
	cin.getline(data, 100);
	//write inputted data into the file
	myFile << data << endl;
	cout << "Please enter your age: ";
	cin >> data;
	cin.ignore();
	myFile << data << endl;
	cout << "Please enter your education: ";
	cin.getline(data, 100);
	myFile << data << endl;
	//Close the opened file
	myFile.close();
	cout << setfill('-');
	cout << setw(50) << "-" << endl;
	//Open a file in Read mode
	ifstream ReadFile;
	ReadFile.open(fileName);
	cout << "File is in Read mode" << endl;
	//endoffile
	while (!ReadFile.eof()) 
	{
		ReadFile >> data;
		//write the data at the screen
		cout << data << " ";
		char c;
		ReadFile.get(c);
		if(c == '\n')
			cout << endl;
	}
	system("pause");
	return 0;
}