#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const float PI = 3.14159;
void AreaOfRectangle(float a, float b)
{
	float S;
	S = a * b;
	cout << "S(Rectangle) = " << S << endl;
}
void AreaOfTriangle(float a, float b)
{
	float S;
	S = (a * b)/2;
	cout << "S(Triangle) = " << S << endl;
}
void AreaOfCircle(float r)
{
	float S;
	S = pow(r, 2) * PI;
	cout << "S(Circle) = " << S << endl;
}
int main()
{
	cout << "Area Of Retangle" << endl;
	cout << "Enter length and width: ";
	float a, b;
	cin >> a >> b;
	AreaOfRectangle(a, b);
	cout << setfill('-');
	cout << setw(20) << "-" << endl;
	cout << "Area Of Triangle" << endl;
	cout << "Enter height and base: ";
	float a1, b1;
	cin >> a1 >> b1;
	AreaOfTriangle(a1, b1);
	cout << setfill('-');
	cout << setw(20) << "-" << endl;
	cout << "Area Of Circle" << endl;
	cout << "Enter radius: ";
	float r;
	cin >> r;
	AreaOfCircle(r);
	system("pause");
	return 0;
}