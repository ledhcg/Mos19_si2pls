#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define PI 3.14159

double Volume(double r, double r1, double h);
double TotalSurface(double r, double r1, double h);
double Volume(double r, double r1, double h)		//Tính thể tích
{
	double v;
	v = (PI * h * (pow(r, 2) + pow(r1, 2) + r * r1)) / 3;
	return v;
}
double TotalSurface(double r, double r1, double h) //Tính diện tích toàn phần
{
	double s, l, k;
	k = r1 - r;
	l = sqrt( pow(k, 2) + pow(h, 2) );
	s = PI * (pow(r, 2) + (r + r1) * l + pow(r1, 2));
	return s;
}
int main()
{
	cout << "Calculate Volume and total surface of Truncated cone" << endl;
	cout << "Provide information:" << endl;
	cout << "1. r - (radius of upper base)" << endl;	// Đáy bé - đáy bị cắt
	cout << "2. R - (radius of lower base)" << endl;	// Đáy lớn 
	cout << "3. h - (hight)" << endl;					// Chiều cao
	cout << "Enter information:" << endl;
	double r, r1, h; // v, s;
	cout << "r = ";
	cin >> r;
	cout << "R = ";
	cin >> r1;
	cout << "h = ";
	cin >> h;
	//v = Volume(r, r1, h);
	//s = TotalSurface(r, r1, h);
	cout << "Volume: V = " << Volume(r, r1, h) << endl;
	cout << "Total Surface: S = " << TotalSurface(r, r1, h) << endl;
	system("pause");
	return 0;
}