#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
int giaithua(int a)
{
	if (a == 0)
		return 1;
	else 
		return a*giaithua(a - 1);
}
int findMax(int a[MAX], int b)
{
	int Max = a[0];
	for (int i = 1; i < b; i++)
		if (a[i] > Max)
			Max = a[i];
	return Max;
}
int findMin(int a[MAX], int b)
{
	int Min = a[0];
	for (int i = 1; i < b; i++)
		if (a[i] < Min)
			Min = a[i];
	return Min;
}
int main()
{
	ifstream fileOpen;
	fileOpen.open("C:\\FileForVS2019\\File\\input.txt");
	char data[100];
	int n;
	//int sum = 0;
	//int tich = 1;
	//int Min;
	//int Max;
	while (!fileOpen.eof())

	{
	char c;
	fileOpen.get(c);
	//cout << c;
	if (c == '+')
	{
		int sum = 0;
		while (fileOpen && c != '\n')
		{

			fileOpen >> n;

			//cout << n << endl;
			sum += n;
			if (n == 0)
				break;
			fileOpen.get(c);
			if (c == '\n')
				break;
		}
		cout << "The sum is: " << sum << endl;
	}

	if (c == '/')
	{
		int outputphepchia; // so de in trong ket qua phep chia
		while (fileOpen && c != '\n')
		{
			fileOpen >> n;
			outputphepchia = n;
			break;
		}
		cout << "1/" << outputphepchia << " = " << (float)1 / 5 << endl;
	}
	if (c == '!')
	{
		int outputgiaithua; //so de in trong ket qua giai thua
		while (fileOpen && c != '\n')
		{
			fileOpen >> n;
			outputgiaithua = n;
			break;
		}
		cout << outputgiaithua << "! = " << giaithua(outputgiaithua) << endl;

	}
	if (c == '*')
	{
		int tich = 1;
		while (fileOpen && c != '\n')
		{

			fileOpen >> n;

			cout << n;
			tich *= n;

			fileOpen.get(c);
			if (c == '\n')
				break;
			cout << "*";
		}
		cout << " = " << tich << endl;
	}
	if (c == 'X')
	{
		int Min;
		int temp[MAX];
		int cnt = 0;
		while (fileOpen && c != '\n')
		{

			fileOpen >> n;

			//cout << n << endl;
			temp[cnt] = n;
			cnt++;
			fileOpen.get(c);
			if (c == '\n')
				break;
		}
		Min = findMin(temp, cnt);
		/*cout << "Deug" << endl;
		for (int i = 0; i < cnt; i++)
			cout << temp[i] << " ";
		cout << "Deug" << endl;*/
		cout << "The place of the minimum is: " << Min << endl;
	}
	if (c == 'M')
	{
		int Max;
		int temp[MAX];
		int cnt = 0;
		while (fileOpen && c != '\n')
		{

			fileOpen >> n;

			//cout << n << endl;
			temp[cnt] = n;
			cnt++;
			if (cnt == 5)
				break;
			fileOpen.get(c);
			if (c == '\n')
				break;
		}
		Max = findMax(temp, cnt);
		/*cout << "Deug" << endl;
		for (int i = 0; i < cnt; i++)
			cout << temp[i] << " ";
		cout << "Deug" << endl;*/
		cout << "The maximum of the first 5 numbers is: " << Max << endl;
	}
}
	//cout << "The sum is: " << sum << endl;
	fileOpen.close();
	return 0;
}