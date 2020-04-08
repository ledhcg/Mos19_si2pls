#include <iostream>
using namespace std;
#define MAX 200
int checkMonk(int sourceM[][4], int n, int x, int copyM[MAX], int k, int cnt)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < 4; j++)
		{	//Kiẻm tra số nhập vào có phải là học trò không (học trò chạy từ i,1 - i,4) vì i,0 là tên thầy
			if (x == sourceM[i][j])
			{
				cnt++;
				//Debug------------
				//cout << "Count = " << cnt << endl;
				////Debug---------
				//cout << "x = source ij = " << sourceM[i][j] << endl;
				////------------


				// so sánh thầy của mã số đã nhập có phải Chúa hay thầy tu khác
				// Nếu là chúa thì dùng vòng đệ quy, không copy mã thầy tu vào mảng copy
				if (sourceM[i][0] == 1)
				{
					////Debug----------
					//cout << "Source 1 = " << sourceM[i][j] << endl;
					////----------
					break;
				}
				else
				//Nếu không phải Chúa thì copy mã số thầy vào mảng copy, và tiếp tục tìm thầy của thầy bằng đệ quy
				{
					////Debug-------------
					//cout << "k = " << k << endl;
					////------------------
					copyM[k] = sourceM[i][0];
					////Debug--------------
					//cout << "copy " << k << " = " << copyM[k] << endl;
					////Debug-------------
					//cout << "Source i,0 = " << sourceM[i][0] << endl;
					////------------------
				
					k++;
					k = checkMonk(sourceM, n, sourceM[i][0], copyM, k, cnt);
				}
			}
		}
		//Debug ---------
		//cout << "Debug Cnt : " << cnt << endl;
		//------------


	//Nếu là học trò của 1 thầy nào đó thì cnt sẽ khác không, gán giá trị -1 để tiện cho việc so sánh ở hàm main
	if (cnt == 0)
		k = -1;
	else
		k = k;
	return k;
}
void readInput(int a[][4], int n)
{
	for (int i = 0; i <n; i++)
		{
				cout << "Monk" << i + 1 << "'s number: ";
				cin >> a[i][0];
				for (int j = 1; j < 4; j++)
				{
					cout << "Student" << j << "'s number of monk" << i + 1 << ": ";
					cin >> a[i][j];
				}
		}
}
void readInput2(int a[][3], int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "Do: 1 or 2 - ";
		cin >> a[i][0];
		if (a[i][0] == 1)
		{
			cout << "Enter a number to check: ";
		cin >> a[i][1];
		}
		if (a[i][0] == 2)
		{
			for (int j = 1; j < 3; j++)
			{
				cout << "Enter numer " << j << " to check: ";
				cin >> a[i][j];
			}
		}
	}
}
int main()
{
	int n; 
	cout << "Enter number of monk: n = ";
	cin >> n;
	int monk[MAX][4]; /*=
	{
		{32,   41,   42,   43},
		{25,   31,   32,   0},
		{24,   33,   34,   0},
		{13,   24,   25,   0},
		{11,   21,   22,   23},
		{1,  11,   12,   13},
	};*/
	readInput(monk, n);
	int findMonk[MAX][3];/* =
	{
		{ 1, 31 },
		{ 1, 51 },
		{ 2, 34, 41 },
		{ 2, 31, 51 },
	};*/
	cout << endl;
	int m;
	cout << "Enter number of work: ";
	cin >> m;
	readInput2(findMonk, m);
	cout << endl;
	for (int i = 0; i < 4; i++)
		//for (int j = 0; j< 3; j++)
	{
			if (findMonk[i][0] == 1)
			{
				int x = findMonk[i][1];
				int n = 6;
				// Điểm xuất phát cho mảng copy[]
				int k = 0;
				int copyM[MAX];
				// biến đếm nếu mã số bằng mã học trò trong mảng 
				int cnt = 0;
				k = checkMonk(monk, n, x, copyM, k, cnt);
				//Nếu không phát hiện ra mã hố học sinh trong mảng thì k phải thầy tu ( vi phạm yếu tố thứ nhất )
				if (k < 0)
					cout << x << " - is not Monk" << endl;
				else
				{
					cout << x << " - is Monk, his teacher: ";
					for (int i = 0; i < k; i++)
					{
						if (i < k-1)
							cout << copyM[i] << ", ";
						else
							cout << copyM[i] << ".";
					}
					cout << endl;
				}
			}
			if (findMonk[i][0] == 2)
			{
				int x = findMonk[i][1];
				int x1 = findMonk[i][2];
				int n = 6;
				// Điểm xuất phát cho mảng copy[]
				int k = 0;
				int k1 = 0;
				int copyM[MAX];
				int copyM1[MAX];

				// biến đếm nếu mã số bằng mã học trò trong mảng 
				int cnt = 0;
				int cnt1 = 0;
				k = checkMonk(monk, n, x, copyM, k, cnt);
				k1 = checkMonk(monk, n, x1, copyM1, k1, cnt1);
				//Nếu không phát hiện ra mã hố học sinh trong mảng thì k phải thầy tu ( vi phạm yếu tố thứ nhất )
				if (k < 0 || k1 < 0)
				{
					if ( k < 0)
					cout << x << " - is not Monk" << endl;
					if ( k1 < 0)
					cout << x1 << " - is not Monk" << endl;
				}
				else
				{
					//debug -----------
					/*cout << "Debug :" << endl;
					cout << " keest qua tu k ";
					for (int i = 0; i < k; i++)
					{
						if (i < k-1)
							cout << copyM[i] << ", ";
						else
							cout << copyM[i] << ".";
					}
					cout << "Debug :" << endl;
					cout << " keest qua tu k1 ";
					for (int i = 0; i < k1; i++)
					{
						if (i < k1-1)
							cout << copyM1[i] << ", ";
						else
							cout << copyM1[i] << ".";
					}
					cout << endl;*/
					/////----------------------
					cout << x << " and " << x1 << " are both monks, and their common teacher: ";
					for (int i = 0; i < k; i++)
						for (int j =0; j < k1; j++)
					{
							if (copyM[i] == copyM1[j])
							{
								cout << copyM[i] << "."<< endl;
								break;
							}
					}
				}
			}
	}

	//cout << "DEBUG BIG -------" << endl;
	//int n = 6;
	////cout << "Enter n (Monks): ";
	////cin >> n;
	///*cout << "Input information: ";
	//for (int i = 0; i<n; i++)
	//for (int j = 0; j<4; j++)
	//{
	//cout << "Enter Monk[" <<i+1<<"]["<<j+1<<"]: ";
	//cin >> monk[i][j];
	//}*/
	//int x = 31;
	///*cout << "Enter x: ";
	//cin >> x;*/
	//// Điểm xuất phát cho mảng copy[]
	//int k = 0;
	//int copyM[MAX];
	//// biến đếm nếu mã số bằng mã học trò trong mảng 
	//int cnt = 0;
	//k = checkMonk(monk, n, x, copyM, k, cnt);
	////debug-----------
	////cout << endl;
	////cout << "k = " << k << endl;
	////cout << "Cnt = " << cnt << endl;
	////-----------
	////Nếu không phát hiện ra mã hố học sinh trong mảng thì k phải thầy tu ( vi phạm yếu tố thứ nhất )
	//if (k < 0)
	//	cout << x << " - is not Monk" << endl;
	//else
	//{
	//	cout << x << " - is Monk, his teacher: ";
	//	for (int i = 0; i < k; i++)
	//	{
	//		if (i < k-1)
	//			cout << copyM[i] << ", ";
	//		else
	//			cout << copyM[i] << ".";
	//	}
	//	cout << endl;
	//}
	return 0;
}