#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 20

int n;
int cnt = 0;
int Permutation[MAX] = { 0 };
int A[MAX];
void printPermutation()
{
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";
	cout << endl;
}
void check()
{
	for (int i = 1; i <= n; i++)
		if (A[i] == i)
		{
			cnt++;
			break;
		}
	//cout << "count = " << cnt << endl;
}
void Try(int k)
{
	for (int i = 1; i <= n; i++)
	{
		if (!Permutation[i])
		{
			A[k] = i;
			Permutation[i] = 1;
			if (k == n)
			{
				//printPermutation();
				check();
			}
			else
				Try(k + 1);
			Permutation[i] = 0;
		}
	}
}
int main()
{
	/*int Ball[MAX];*/
	cout << "Enter value of ball, that you want: ";
	cin >> n;
	Try(1);
	cout << "Permutation (the sequence number is equal to the value of the ball) = " << cnt << endl;
	return 0;
}