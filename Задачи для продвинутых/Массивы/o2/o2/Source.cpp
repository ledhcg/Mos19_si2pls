#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;
#define MAX 300
#define PI 3.1415
void inputArr(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> a[i];
	}
}
void inputB(float a[], int n)
{
	float k;
	for (int i = 0; i < n; i++)
	{
		k = (1 + pow(i, 2))*PI/ 180;
		a[i] = 1 / tan(k);
	}
}
void inputC(int a[], int n, int sTa, int fNi)
{
	srand(time_t(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (fNi - sTa) + sTa;
	}
}
void InputD(float a[], float b[], int c[], float d[], int n, int x, int y, int z)
{
	for (int i = 0; i < n; i++)
	{
		d[i] = x * a[i] + y * b[i] + z * (float) c[i];
	}
}
void printArr(float a[], int n) 
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void printArrInt(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	cout << "Arr A[n]" << endl;
	float A[MAX];
	int n;
	cout << "Enter number: ";
	cin >> n;
	inputArr(A, n);
	int sTa, fNi, x, y, z;
	cout << "[Start;Finish]=[a;b]; D = x*A + y*C + z*B" << endl;
	cout << "Enter number start: ";
	cin >> sTa;
	cout << "Enter number finish: ";
	cin >> fNi;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Enter z: ";
	cin >> z;
	float B[MAX];
	int C[MAX];
	float D[MAX];
	inputB(B, n);
	inputC(C, n, sTa, fNi);
	InputD(A, B, C, D, n, x, y, z);
	cout << "Arr A: " << endl;
	printArr(A, n);
	cout << "Arr B: " << endl;
	printArr(B, n);
	cout << "Arr C: " << endl;
	printArrInt(C, n);
	cout << "Arr D: " << endl;
	printArr(D, n);
	return 0;
}