#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		cout << endl;
		cout << "Transfer pieces from " << a << " to " << c << "." << endl;
	}
	else
	{
		hanoi(n - 1, a, c, b);
		hanoi(1, a, b, c);
		hanoi(n - 1, b, a, c);
	}
}
int main()
{
	int n;
	cout << "Enter the number of pieces: ";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}