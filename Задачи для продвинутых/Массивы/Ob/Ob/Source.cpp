#include <iostream>
#include <ctime>
using namespace std;
#define MAX 25
#define PI 3.1415
void inputArr(int a[][MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
	{
		cout << "Enter number A[" << i + 1 << "][" << j+1 << "]: ";
		cin >> a[i][j];
	}
}
void inputB(int a[][MAX], int n, int m)
{
	for (int i =0; i <n; i++)
		for (int j = 0; j < m; j++)
		{
			a[i][j] = i * j - (5 - i - j);
	    }
}
void inputC(int a[][MAX], int n, int m, int sTa, int fNi)
{
	srand(time_t(NULL));
	for (int i =0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % (fNi - sTa) + sTa;
		}
}
void inputE(int a[][MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
}
void inputD(int a[][MAX], int b[][MAX], int c[][MAX],int d[][MAX], int e[][MAX], int n, int m, int x, int y, int z, int w)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			d[i][j] = x * a[i][j] + y * b[i][j] + z * c[i][j] + w * e[i][j];
		}
}
void printArr(int a[][MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int A[MAX][MAX];
	int n;
	cout << "Matrix A[n*m]" << endl;
	cout << "Enter number n: ";
	cin >> n;
	int m;
	cout << "Enter number m: ";
	cin >> m;
	inputArr(A, n, m);
	cout << "[Start; Finish] = [a; b] || D = x*A + y*B + z*C + w*E" << endl;
	int sTa, fNi, x, y, z, w;
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
	cout << "Enter w: ";
	cin >> w;
	int B[MAX][MAX];
	int C[MAX][MAX];
	int D[MAX][MAX];
	int E[MAX][MAX];
	inputB(B, n, m);
	inputC(C, n, m, sTa, fNi);
	inputE(E, n, m);
	inputD(A, B, C, D, E, n, m, x, y, z, w);
	cout << endl;
	cout << "Matrix A: " << endl;
	printArr(A, n, m);
	cout << "Matrix B: " << endl;
	printArr(B, n, m);
	cout << "Matrix C: " << endl;
	printArr(C, n, m);
	cout << "Matrix D: " << endl;
	printArr(D, n, m);
	cout << "Matrix E: " << endl;
	printArr(E, n, m);
	return 0;
}