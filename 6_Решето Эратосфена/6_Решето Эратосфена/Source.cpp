#include <iostream>
using namespace std;
#define MAX 300

int UCLN(int a, int b)
{
	if (b == 0)
		return a;
	else
		return UCLN(b, a % b);
}
int main()
{
	int n;
	cout << "Enter limit number, which you want :";
	cin >> n;
	bool SNT[MAX];
	for (int i = 2; i <= n; i++)
		SNT[i] = true;
	
	for (int i = 3; i <= n; i++)
		if (i%2==0)
			SNT[i] = false;

	for (int i = 3; i <= n; i+=2)
	{
		for (int j = 1; j < i; j+=2)
			if (UCLN(i,j) != 1)
				SNT[i] = false;
	}
	cout << "Prime numbers: ";
	for (int i = 2; i <= n; i++)
	{
		if (SNT[i] == true)
			cout << i << " ";
	}
	cout << endl << endl;
	return 0; 

		
}