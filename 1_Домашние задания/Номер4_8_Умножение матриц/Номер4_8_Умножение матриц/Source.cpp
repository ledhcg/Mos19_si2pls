#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 10
//Ham tim MAX (Gia)
int MaxPrince(float a[3][2])
{
	float ma= 0;
	int cnt = 0;
	for (int i =0; i < 3; i++)
	{
		if (a[i][0] > ma)
		{
			ma = a[i][0];
			cnt = i+1;
		}
	}
	return cnt;
}//Ham MIn Gia
int MinPrince(float a[3][2])
{
	float mi =a[0][0];
	int cnt = 1;
	for (int i = 0; i < 3; i++)
	{
		if (a[i][0] < mi)
		{
			mi = a[i][0];
			cnt = i + 1;

		}
	}
	return cnt;
}
//Ham tim MAX (lai)
int MaxInterest(float a[3][2])
{
	float ma = 0;
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		if (a[i][1] > ma)
		{
			ma = a[i][1];
			cnt = i+1;
		}
	}
	return cnt;
}
int MinInterest(float a[3][2])
{
	float mi = a[0][1];
	int cnt = 1;
	for (int i = 0; i < 3; i++)
	{
		if (a[i][1] < mi)
		{
			mi = a[i][1];
			cnt = i+1;
		}
	}
	return cnt;
}

//Ham tinh tong Gia
float SumPri(float a[3][2])
{
	float sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += a[i][0];
	}
	return sum;
}
//Ham tinh tong Lai
float SumInter(float a[3][2])
{
	float sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += a[i][1];
	}
	return sum;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int Product[3][4] =
	{
		{5, 2, 0, 10},
		{3, 5, 2, 5},
		{20}
	};
	float Price[4][2] =
	{
		{1.2, 0.5},
		{2.8, 0.4},
		{5.0, 1.0 },
		{2.0, 1.5 }
	};



	//Nhan ma tran Sum[3][2] = Product[3][4] x Price[4][2]
	float Sum[3][2];
	for (int i = 0; i < 3; i++)
	{
		for (int h = 0; h < 2; h++)
		{
			float sum1 = 0;
			for (int j = 0; j < 4; j++)
			{
				sum1 += (float)Product[i][j] * Price[j][h];
			}
			Sum[i][h] = sum1;
			sum1 = 0;
		}
	}
	cout << endl << endl;
	//in bang so luong san pham
	cout << setfill('-');
	cout << setw(34) << "-" << endl;
	cout << setw(13) << right << "       \\Товар" << "|" << setw(4) << left << "1" << "|" << setw(4) << left << "2" << "|" << setw(4) << left << "3" << "|" << setw(4) << left << "4" << "|" << endl;
	cout << setw(13) << left << "Продавец\\    " << "|" << setw(4) << left << " " << "|" << setw(4) << left << " " << "|" << setw(4) << left << " " << "|" << setw(4) << left << " " << "|" << endl;
	cout << setfill('-');
	cout << setw(34) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 3; i++)
	{
		cout << setw(13) << left << i + 1 << "|";
		for (int j = 0; j < 4; j++)
			cout << setw(4) << left << Product[i][j] << "|";
		cout << endl;
	}
	cout << setfill('-');
	cout << setw(34) << "-" << endl;
	cout << setfill(' ');
	cout << endl << endl;

	// in bang gia va hoa hong

	cout << setfill('-');
	cout << setw(39) << "-" << endl;
	cout << setw(6) << left << "Товар" << "|" << setw(15) << left << "Цена" << "|" << setw(15) << left << "Комиссионные" << "|" << endl;
	cout << setfill('-');
	cout << setw(39) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 4; i++)
	{
		cout << setw(6) << left << i + 1 << "|";
		for (int j = 0; j < 2; j++)
			cout << setw(15) << left << Price[i][j] << "|";
		cout << endl;
	}
	cout << setfill('-');
	cout << setw(39) << "-" << endl;
	cout << setfill(' ');
	cout << endl << endl;
	//In bang tinh nhan ma tran
	cout << setfill('-');
	cout << setw(43) << "-" << endl;
	cout << setw(10) << left << "Продавец" << "|" << setw(15) << left << "Цена" << "|" << setw(15) << left << "Комиссионные" << "|" << endl;
	cout << setfill('-');
	cout << setw(43) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 3; i++)
	{
		cout << setw(10) << left << i+1 << "|";
		for (int j = 0; j < 2; j++)
			cout << setw(15) << left << Sum[i][j] << "|";
		cout << endl;
	}
	cout << setfill('-');
	cout << setw(43) << "-" << endl;


	cout << endl;
	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	int MaxP = MaxPrince(Sum);
	cout << "Продавец (" << MaxP << ") выручил больше всего денег с продажи!" << endl;
	int MinP = MinPrince(Sum);
	cout << "Продавец (" << MinP << ") выручил меньше всего денег с продажи!" << endl;
	int MaxI = MaxInterest(Sum);
	cout << "Продавец (" << MaxI << ") получил наибольшие комиссионные!" << endl;
	int MinI = MinInterest(Sum);
	cout << "Продавец (" << MinI << ") получил наименьшие комиссионные!" << endl;
	float SumP = SumPri(Sum);						  
	cout << "Сумма денег, вырученные за проданные товары: \t " << SumP << endl;
	float SumI = SumInter(Sum);
	cout << "Всего комиссионных получили продавцы:        \t " << SumI << endl;
	cout << "Сумма денег, прошедших через руки продавцов: \t " << SumP + SumI << endl;
	cout << setfill('-');
	cout << setw(60) << "-" << endl;
	system("pause");		
	return 0;
}