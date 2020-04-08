#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159
float hamtinhphu(int n)
{
	float mau = 0;
	for (int i = 1; i <= n; i++)
	{
		float d = i * PI / 180;
		mau += sin(d);
	}
	return n / mau;
}
int main()
{
	int n;
	cin >> n;
	//cout << sin(n) << endl;
	float ketqua = 0;
	for (int i = 1; i <= n; i++)
	{
		ketqua += hamtinhphu(i);
	}
	cout << ketqua << endl;
	return 0;
} 