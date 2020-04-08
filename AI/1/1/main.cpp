#include <iostream>
#include "fuzzy.h"
//#include "mymath.h"

using namespace std;

int main()
{
	// Distance
	double melee = FuzzyTriangle(18.0, -1.0, 0.0, 10.0); // Cận chiến 
	double projectile = FuzzyTrapezoid(18.0, 6.0, 10.0, 15.0, 20.0); // Vật bắn ra
	double outOfRange = FuzzyGrade(18.0, 15.0, 25.0); //Phạm vi bên ngoài

	cout << "Melee       : " << melee << endl;
	cout << "Projectile  : " << projectile << endl;
	cout << "Out of Range: " << outOfRange << endl;
	cout << endl;

	// Phy.Strength
	double nearDeath = FuzzyTriangle(60.0, -1.0, 0.0, 10.0); // sắp chết
	double critical = FuzzyTrapezoid(60.0, 6.0, 13.0, 21.0, 50.0); // nguy kịch
	double serious = FuzzyTrapezoid(60.0, 30.0, 55.0, 65.0, 80.0); // nguy hiểm
	double minor = FuzzyTrapezoid(60.0, 50.0, 70.0, 85.0, 100.0); // không quan trọng - k nguy hiểm
	double uninjured = FuzzyGrade(60.0, 90.0, 100.0); // bình yên 

	cout << "NearDeath   : " << nearDeath << endl;
	cout << "Critical    : " << critical << endl;
	cout << "Serious     : " << serious << endl;
	cout << "Minor       : " << minor << endl;
	cout << "Uninjured   : " << uninjured << endl;
	cout << endl;

	// RANK
	double wimp = FuzzyTriangle(10.0, -1.0, 0.0, 3.0);
	double easy = FuzzyTrapezoid(10.0, 2.0, 4.0, 6.0, 8.0);
	double moderate = FuzzyTrapezoid(10.0, 7.0, 9.0, 11.0, 14.0);
	double hard = FuzzyGrade(10.0, 12.0, 15.0);

	cout << "Wimp        : " << wimp << endl; // dễ nhất
	cout << "Easy        : " << easy << endl;  // dễ
	cout << "Moderate    : " << moderate << endl; // hơi ức chế
	cout << "Hard        : " << hard << endl; // khó
	cout << endl;

	return 0;
}