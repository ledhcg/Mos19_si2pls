#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n;

	cout << "Enter number: ";
	cin >> n;
	if (n < 0)
		cout << "�� �������������: ��!" << endl;
	else
		cout << "�� �������������: ���!" << endl;
	if (n % 2)
		cout << "��������: ��!" << endl;
	else
		cout << "��������: ���!" << endl;
	if (n > -3)
		cout << "������������� ����� -3: ��!" << endl;
	else
		cout << "������������� ����� -3: ���!" << endl;
	cout << "��������� ������: " << pow(2, n) << endl;
	return 0;
}