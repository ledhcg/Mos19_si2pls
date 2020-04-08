#include <iostream>
using namespace std;

int giaithua(int n)
{
	
	if (n == 0)
		return 1;
	else
		return n * giaithua(n - 1);
}
double hamtinhbai2(int n)
{
	double tu;
	int m = 0;
	int cnt = 1;
	double ketqua = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		double tu = (double) giaithua(n - i + 1);
		for (int j = 1; j <= i; j++)
		{
			m += cnt;
			cnt++;
		}
		double mau = sqrt(m);
		ketqua += tu / mau;
		m = 0;
	}
	return ketqua;

}
int main()
{
	int n;
	cout << "Enter any number, you want: n = ";
	cin >> n;
	//debug
	//cout << giaithua(n) << endl;
	float ketqua = hamtinhbai2(n);
	cout << "Result: " << ketqua << endl;

	return 0;
}