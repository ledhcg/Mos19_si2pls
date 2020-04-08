#include <iostream>
using namespace std;
#define MAX 300


void inputA(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Number " << i + 1 << " = ";
		cin >> a[i];
	}
}
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintA(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void ShakerSort1(int a[], int n)
{
	int Right = n - 1;
	int Left = 0;
	int k = 0;
	int cnt = 1;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				cout << "Step " << cnt << " | ";
				cnt++;
				PrintA(a, n);

				k = i;
				cout << endl;
			}
		Right = k;
		for (int i = Right; i > Left; i--)
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i + 1]);
				cout << "Step " << cnt << " | ";
				cnt++;
				PrintA(a, n);
				cout << endl;
				k = i;
			}
		Left = k;
	}
}
void ShakerSort(int a[], int n)
{
	int cnt = 1;
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	cout << "Source | ";
	PrintA(a, n);
	cout << endl;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				cout << "* Step " << cnt << " (";
				cout << "Value " << i + 1 << " and " << i + 2 << " be swap cause " << i + 1 << " > " << i + 2 << ") : ";
				cnt++;
				PrintA(a, n);
				cout << endl;
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				cout << "* Step " << cnt << " (";
				cout << "Value " << i + 1 << " and " << i << " be swap cause " << i + 1 << " < " << i << ") : ";
				cnt++;
				PrintA(a, n);
				cout << endl;
				k = i;
			}
		}
		Left = k;
	}
}
//void PrintA(int a[], int n)
//{
//	cout << endl;
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//	cout << endl;
//}
int main()
{
	int n;
	cout << "Value n = ";
	cin >> n;
	int a[MAX];
	inputA(a, n);
	cout << endl;
	ShakerSort(a, n);
	cout << "Finish | ";
	PrintA(a, n);
	return 0;
}