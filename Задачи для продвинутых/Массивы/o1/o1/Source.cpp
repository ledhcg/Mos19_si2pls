#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 300
void inputArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> a[i];
	}
}
void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void changeNumber(int a[], int n)
{
	int b[MAX] ; //copy A
	int Max =0;
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
		Max = a[0];
	}
	//int Max = b[0];
	//find max
	for (int i = 1; i < n; i++)
	{
		if (b[i] > Max)
		{
			Max = b[i];
		}
	}
	// find min
	int Min = Max;
	for (int i = 0; i < n; i++)
	{
		if (b[i] < Min && b[i] > 0)
		{
			Min = b[i];
		}
	}
		//Debug
		cout << "Max = " << Max << "; Min = " << Min << endl;
	//change
		int tempChange;
		for (int i = 0; i < n; i++)
		{
			if (b[i] == Min)
			{
				b[i] = Max;
				tempChange = i;
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (b[i] == Max && i != tempChange)
			{
				b[i] = Min;
				break;
			}
		}
		cout << "1. After: ";
		printArr(b, n);
}

void check2(int a[], int n)
{
	int cnt = 5;
	int temp1;
	if (n < 5)
	{
		cout << "2. The program doesnt work with your input number!" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0)
			{
				cnt--;
				temp1 = i;
			}
		}
		//debug
		cout << "Count: " << cnt << "; The 5th number = " << a[temp1] << endl;

		if (cnt>0)
		{
			
			cout << "2. Cant find the 5th number /= 0!" << endl;
		}
		else
		{
			if (a[temp1] < 0)
			{
				if (-a[temp1] < 2)
					cout << "2. The 5th number /= 0: (< 2) Yes" << endl;
				else
					cout << "2. The 5th number /= 0: (< 2) No" << endl;
			}
			else
				if (a[temp1] < 2)
					cout << "2. The 5th number /= 0: (< 2) Yes" << endl;
				else
					cout << "2. The 5th number /= 0: (< 2) No" << endl;
		}
	}
}
void sortArr(int a[], int n)
{
	bool check[MAX] = {};
	int Copy[MAX];
	int j = 0;
	//Debug
	/*for (int i = 0; i < n; i++)
	{
		cout << check[i] << " ";

	}
	cout << endl;*/
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			check[i] = true;
		}
	}
	//Debug
	/*for (int i = 0; i < n; i++)
	{
		cout << check[i] << " ";

	}
	cout << endl;*/
	for (int i = 0; i < n; i++)
	{
		if (check[i] == true)
		{
			Copy[j] = a[i];
			j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] == false)
		{
			Copy[j] = a[i];
			j++;
		}
	}
	cout << "3. After Sort: ";
	for (int i = 0; i < n; i++)
	{
		cout << Copy[i] << " ";

	}
	cout << endl;
	// Debug
	/*for (int i = 0; i < n; i++)
	{
		cout << check[i] << " ";

	}
	cout << endl;*/
}
//void printArr(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	int arr[MAX];
	inputArr(arr, n);
	cout << "Source: ";
	printArr(arr, n);
	changeNumber(arr, n);
	//cout << "1. After: ";
	//printArr(arr, n);
	check2(arr, n);
	sortArr(arr, n);
	return 0;
}