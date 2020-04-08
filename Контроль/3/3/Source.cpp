#include <iostream>
#include <iomanip>
using namespace std;
//const int max = 1000;
int main()
{
	//int findRectangle[max][max];
	cout << "Find Rectangle: MATRIX[N*M]" << endl;
	cout << "Enter N = ";
	int n;
	cin >> n;
	cout << "Enter M = ";
	int m;
	cin >> m;
	if (n >= 75000 || m >= 75000)
	{
		cout << "The number input >= 75000!" << endl;
	}
	else
	{
		int k = ((n + 1) * n) / 2 * ((m + 1) * m) / 2;
		//specific method
		/*int ans_x = 0;
		int ans_y = 0;
			for (int i = 0; i < n; i++)
			{
				ans_x += n - i;
			}
		for (int j = 0; j < m; j++)
			{
				ans_y += m - j;
			}
		cout << (ans_x * ans_y) << endl;*/
		cout << "Number of rectangles found = " << k << endl;
	}
	return 0;
}