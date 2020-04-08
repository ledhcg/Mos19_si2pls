#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159
int giaithua(int n)
{
	if (n == 0)
		return 1;
	else
		return n * giaithua(n - 1);
}

double baitap3(int n)
{	double mau = 0;
	double ketqua = 1;
	for (int i = 1; i <= n; i ++)
	{ 
		mau += sin(2 * i * PI / 180);
		ketqua *= giaithua(i) / mau;
	}
	return ketqua;
}
int main()
{
	int n;
	cout << "Enter any number, you want n = ";
	cin >> n;



}