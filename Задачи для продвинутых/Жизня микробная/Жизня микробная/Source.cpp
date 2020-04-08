//#include <iostream>
//#include <ctime>
//
//using namespace std;
//
//int main()
//{
//	const int Width(21);
//	const char live('1'), dead('0');
//	cout << "Enter a gen number: ";
//	int gen;
//	cin >> gen;
//
//	bool mas[Width * Width] = { false };
//	bool mas2[Width * Width] = { false };
//
//	srand((unsigned)time(NULL));
//
//	for (int i = 0; i < Width; i++)
//	{
//		for (int k = 0; k < Width; k++)
//		{
//			if (mas[i + k * Width])
//			{
//				cout << live;
//			}
//			else
//			{
//				cout << dead;
//			}
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//
//	for (int i = 0; i < Width; i++)
//	{
//		for (int k = 0; k < Width; k++)
//		{
//			mas[i + k * Width] = rand() % 2;
//
//			if (mas[i + k * Width])
//			{
//				cout << live;
//			}
//			else
//			{
//				cout << dead;
//			}
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//	for (int g = 0; g < gen; g++)
//
//	{
//		cout << "Gen: " << g+1  << endl;
//		for (int i = 0; i < Width; i++)
//		{
//			for (int k = 0, count = 0; k < Width; k++)
//			{
//				if (((i - 1) >= 0) && ((k - 1) >= 0))
//				{
//					if (mas[(i - 1) + (k - 1) * Width]) count++;
//				}
//				if ((i - 1) >= 0)
//				{
//					if (mas[(i - 1) + (k - 1) * Width]) count++;
//				}
//				if (((k + 1) <= Width) && ((i - 1) >= 0))
//				{
//					if (mas[(i + 1) + (k - 1) * Width]) count++;
//				}
//				if ((i - 1) >= 0)
//				{
//					if (mas[(i - 1) + k * Width]) count++;
//				}
//				if ((i + 1) <= Width - 1)
//				{
//					if (mas[(i + 1) + k * Width]) count++;
//				}
//				if (((i - 1) >= 0) && ((k + 1) <= Width - 1))
//				{
//					if (mas[(i - 1) + (k + 1) * Width]) count++;
//				}
//				if ((k + 1) <= Width - 1)
//				{
//					if (mas[i + (k + 1) * Width]) count++;
//				}
//				if (((i + 1) <= Width - 1) && ((k + 1) <= Width - 1))
//				{
//					if (mas[(i + 1) + (k + 1) * Width]) count++;
//				}
//
//				if ((count < 2) || (count > 3))
//				{
//					mas2[i + k * Width] = false;
//					cout << dead;
//				}
//				else
//				{
//					if ((!mas2[i + k * Width]) && (count != 3))
//					{
//						mas2[i + k * Width] = false;
//						cout << dead;
//					}
//					else
//					{
//						mas2[i + k * Width] = true;
//						cout << live;
//					}
//				}
//				count = 0;
//
//			}
//			cout << '\n';
//		}
//		cout << '\n';
//
//		for (int i = 0; i < (Width * Width); i++)
//		{
//			mas[i] = mas2[i];
//		}
//	}
//	return 0;
//}

//#include <windows.h> 
//#include <iostream> 
//#include <array> 
//#include <ctime> 
//#include <conio.h> 
//
//typedef unsigned char BYTE;
//
//using std::array;
//
//template<size_t I, size_t J, typename T>
//void Generate(array<array<T, J>, I>& arr);
//
//template<size_t I, size_t J, typename T>
//void UpdateGeneration(array<array<T, J>, I>& arr, array<array<T, J>, I>& oldarr);
//
//template<size_t I, size_t J, typename T>
//BYTE GetCell(BYTE x, BYTE y, array<array<T, J>, I> const& arr);
//
//template<size_t I, size_t J, typename T>
//BYTE GetCellsCount(BYTE x, BYTE y, array<array<T, J>, I> const& arr);
//
//template<size_t I, size_t J, typename T>
//int sumOrganism(array<array<T, J>, I> const& arr);
//
//template<size_t I, size_t J, typename T>
//void print(const HANDLE& StdOut, const COORD& Coord, array<array<T, J>, I> const& arr);
//
//int main(void) {
//	srand(time(NULL));
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD coord{ 0, 0 };
//
//	array<array<bool, 60>, 20> Generation{ false };
//	array<array<bool, 60>, 20> oldGeneration{ false };
//	int sum{};
//
//	Generate(Generation);
//
//	do {
//		UpdateGeneration(Generation, oldGeneration);
//		print(hStdOut, coord, Generation);
//		sum = sumOrganism(Generation);
//		if (_kbhit() && (_getch() == 27)) return 0;
//		if (Generation == oldGeneration) break;
//		Sleep(100);
//	} while (sum);
//
//	if (!sum) {
//		system("cls");
//		std::cout << "All organisms were lost!" << std::endl;
//	}
//	else {
//		std::cout << "\nFinish!" << std::endl;
//	}
//	system("pause");
//	return 0;
//}
//
//template<size_t I, size_t J, typename T>
//void Generate(array<array<T, J>, I>& arr) {
//	for (auto& i : arr) {
//		for (auto& j : i) {
//			j = rand() % 2;
//		}
//	}
//}
//
//template<size_t I, size_t J, typename T>
//void UpdateGeneration(array<array<T, J>, I>& arr, array<array<T, J>, I>& oldarr) {
//	BYTE cellsCount{};
//	oldarr = arr;
//	for (int i{}; i < I; i++) {
//		for (int j{}; j < J; j++) {
//			cellsCount = GetCellsCount(i, j, oldarr);
//			if (!oldarr[i][j]) {
//				if (cellsCount == static_cast<BYTE>(3)) arr[i][j] = true;
//			}
//			else {
//				if ((cellsCount < static_cast<BYTE>(2)) || (cellsCount > static_cast<BYTE>(3))) arr[i][j] = false;
//			}
//		}
//	}
//}
//
//template<size_t I, size_t J, typename T>
//BYTE GetCell(BYTE x, BYTE y, array<array<T, J>, I> const& arr) {
//	if ((x > I - 1) || (y > J - 1)) {
//		return 0;
//	}
//	return static_cast<BYTE>(arr[x][y]);
//}
//
//template<size_t I, size_t J, typename T>
//BYTE GetCellsCount(BYTE x, BYTE y, array<array<T, J>, I> const& arr) {
//	BYTE Result{};
//	Result += GetCell(x - 1, y, arr);
//	Result += GetCell(x - 1, y - 1, arr);
//	Result += GetCell(x, y - 1, arr);
//	Result += GetCell(x + 1, y - 1, arr);
//	Result += GetCell(x + 1, y, arr);
//	Result += GetCell(x + 1, y + 1, arr);
//	Result += GetCell(x, y + 1, arr);
//	Result += GetCell(x - 1, y + 1, arr);
//	return Result;
//}
//
//template<size_t I, size_t J, typename T>
//int sumOrganism(array<array<T, J>, I> const& arr) {
//	int Result{};
//	for (auto const i : arr) {
//		for (auto const j : i) {
//			Result += j;
//		}
//	}
//	return Result;
//}
//
//template<size_t I, size_t J, typename T>
//void print(const HANDLE& StdOut, const COORD& Coord, array<array<T, J>, I> const& arr) {
//	SetConsoleCursorPosition(StdOut, Coord);
//	SetConsoleTextAttribute(StdOut, FOREGROUND_RED);
//	for (auto const i : arr) {
//		for (auto const j : i) {
//			if (!j) {
//				std::cout << " ";
//			}
//			else {
//				std::cout << "X";
//			}
//		}
//		std::cout << std::endl;
//	}
//	SetConsoleTextAttribute(StdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
//	std::cout << "\nESC = Exit" << std::endl;
//}
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
	const int Width(5);
	const char live('1'), dead('0');
	cout << "Enter a gen number: ";
	int gen;
	cin >> gen;

	bool mas[Width][Width] = { false };
	bool mas2[Width][Width] = { false };
	////Mảng đếm mức sống(1-12)
	//int check[Width][Width];
	//for (int i = 0; i < Width; i++)
	//{
	//	for (int j = 0; j < Width; j++)
	//	{
	//		check[i][j] = (int)mas[i][j];
	//		cout << check[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	srand((unsigned)time(NULL));

	/*for (int i = 0; i < Width; i++)
	{
		for (int k = 0; k < Width; k++)
		{
			if (mas[i][k])
			{
				cout << live;
			}
			else
			{
				cout << dead;
			}
		}
		cout << '\n';
	}*/
	

	//input file
	ofstream workdat;
	workdat.open("work.dat");
	for (int i = 0; i < Width; i++)
	{
		for (int k = 0; k < Width; k++)
		{
			//mas[i][k] = rand() % 2;
			cout << "input" << i + 1 << "," << k + 1 << ": ";
			int y;
			cin >> y;

			if (y)
			{
				workdat << 1 << " ";
			}
			else
			{
				workdat << 0 << " ";
			}
		}
		workdat << endl;
	}
	workdat.close();

	//read file
	ifstream readWork;
	readWork.open("work.dat");
	int a;
	cout << "Source from file: " << endl;
	for (int i = 0; i < Width; i++)
	{
		for (int k = 0; k < Width; k++)
		{
			readWork >> a;
			mas[i][k] = a;
			if (mas[i][k])
			{
				cout << live << " ";
			}
			else
			{
				cout << dead << " ";
			}
		}
		cout << endl;
	}


	cout << '\n';
	//Mảng hiện tại
	//cout << "Source: " << endl;
	//for (int i = 0; i < Width; i++)
	//{
	//	for (int k = 0; k < Width; k++)
	//	{
	//		mas[i][k] = rand() % 2;

	//		if (mas[i][k])
	//		{
	//			cout << live << " ";
	//		}
	//		else
	//		{
	//			cout << dead << " ";
	//		}
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	//Mảng đếm mức sống(1-12)
	//Check the age of bacteria
	cout << "Check the age of bacteria: " << endl;
	int check[Width][Width];
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			check[i][j] = (int)mas[i][j];
			cout << check[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//Cho vòng for chạy gen

	ofstream workout;
	workout.open("work.out");
	for (int g = 0; g < gen; g++)

	{
		cout << "Gen: " << g + 1 << endl;
		workout << "Gen: " << g + 1 << endl;
		for (int i = 0; i < Width; i++)
		{
			for (int k = 0, count = 0; k < Width; k++)
			{
				
					if (((i - 1) >= 0) && ((k - 1) >= 0))
					{
						if (mas[(i - 1)][(k - 1)]) count++;
					}
					if ((i - 1) >= 0)
					{
						if (mas[(i - 1)][(k - 1)]) count++;
					}
					if (((k + 1) <= Width) && ((i - 1) >= 0))
					{
						if (mas[(i + 1)][(k - 1)]) count++;
					}
					if ((i - 1) >= 0)
					{
						if (mas[(i - 1)][k]) count++;
					}
					if ((i + 1) <= Width - 1)
					{
						if (mas[(i + 1)][k]) count++;
					}
					if (((i - 1) >= 0) && ((k + 1) <= Width - 1))
					{
						if (mas[(i - 1)][(k + 1)]) count++;
					}
					if ((k + 1) <= Width - 1)
					{
						if (mas[i][(k + 1)]) count++;
					}
					if (((i + 1) <= Width - 1) && ((k + 1) <= Width - 1))
					{
						if (mas[(i + 1)][(k + 1)]) count++;
					}
				
				
				if ((count < 2) || (count > 3))
				{
					mas2[i][k] = false;
					cout << dead << " ";
					workout << dead << " ";
					check[i][k]=0;
				}
				else
				{
					//nếu mảng hiện tại có vi khuẩn bằng 0 thì thế hệ mới sống lại (1)
					if (check[i][k] == 12)
						{
						mas2[i][k] = false;
						cout << dead<< " ";
						workout << dead << " ";
						check[i][k] = 0;
						}
					else
					{
						mas2[i][k] = true;
						cout << live << " ";
						workout << live << " ";
						check[i][k]++;
					}
				
				}
				count = 0;

			}
			cout << '\n';
			workout << endl;
		}
		cout << '\n';
		workout << endl;
		// Gán giá trị vi khuẩn vào mảng hiện tại
		for (int i = 0; i < Width; i++)
			for (int j = 0; j< Width; j++)
		{
			mas[i][j] = mas2[i][j];
		}
		//Check the age of bacteria
		cout << "Check the age of bacteria: " << endl;
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				cout << check[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}