#include <iostream>
#include "diophantine.h"
using namespace std;
void main() {

	int x, y, z, w, k;
	cout << "Genetic Logic and solving Diophantine equations" << endl;
	cout << "Form: x.a + y.b + z.c + w.d = k" << endl;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "z = ";
	cin >> z;
	cout << "w = ";
	cin >> w;
	cout << "k = ";
	cin >> k;
	CDiophantine dp(x, y, z, w, k);

	int ans;
	ans = dp.Solve();
	if (ans == -1) {
		cout << "No solution found." << endl;
	}
	else {
		gene gn = dp.GetGene(ans);

		cout << "The solution set to "<<x<<"a + "<<y<<"b + "<<z<<"c + "<<w<<"d = "<<k<<" is:\n";
		cout << "a = " << gn.alleles[0] << "." << endl;
		cout << "b = " << gn.alleles[1] << "." << endl;
		cout << "c = " << gn.alleles[2] << "." << endl;
		cout << "d = " << gn.alleles[3] << "." << endl;
	}
}