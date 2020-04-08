#include <iostream>
#include <ctime>
#include "console.h"
using namespace std;
#define DOT_RAN 178
#define MAX 100
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define TUONG_TREN 3 //y=3 khong doi
#define TUONG_DUOI 20 //y = 13 khong doi
#define TUONG_TRAI 3 // x=3 khong doi
#define TUONG_PHAI 80 // X =56 KHONG DOI
#define MAU_TUONG 4
#define MAU_RAN 10
#define MAU_MOI 3
struct ToaDo
{
	int x;
	int y;
};

ToaDo ran[MAX];
//ToaDo ranCu[MAX];
	//So luong phan tu
	int soDot = 3;
void khoitaoRan();
void hienthiRan(ToaDo dotCuoiCu);
ToaDo diChuyen(int huong);
void batSuKien(int &huong);
void veTuong();
bool kiemTraThua();
void xuLyThua(int diem);
ToaDo hienThiMoi();
bool kiemTraDaAnMoi(ToaDo moi);
void themDot();
void GameOver(int diem);
//void runTime();

void Gameloop(int level)
{

	system("cls");
	//clrscr();
	khoitaoRan();
	int huong = RIGHT;
	int x = 0, y = 0;
	veTuong();
	srand(time_t(NULL));
	ToaDo moi = hienThiMoi();
	//runTime();
	// Tao so ngau nhien // random trong [a,b]: a+rand()%(b-a+1)
	gotoXY(TUONG_PHAI + 3, TUONG_TREN);
	cout << (char)176 << " GAME SNAKE " << (char)176;

	gotoXY(TUONG_PHAI + 3, TUONG_TREN + 1);
	cout << "@ Creat by Le Dinh Cuong";
	gotoXY(TUONG_PHAI + 3, TUONG_TREN + 2);
	cout << "# From IKB0-07-19 MIREA";
	//Game loop
	int diem = 0;
	gotoXY(TUONG_PHAI + 3, TUONG_TREN + 3);
	cout << "------------------------";
	
	switch (level)
	{
	case 1: 
	{
		/*gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		cout << "Level:           ";*/
		gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		cout << "Level: Easy";
		break;
	}
	case 2:
	{
		/*gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		cout << "Level:           ";*/
		gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		cout << "Level: Normal";
		break;
	}
	case 3:
	{
		/*gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		cout << "Level:           ";*/
		gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		cout << "Level: Hard";
		break;
	}
	}
	gotoXY(TUONG_PHAI + 3, TUONG_TREN + 5);
	cout << "Score: " << diem;
	while (1)
	{


		ToaDo dotCuoiCu = diChuyen(huong);
		batSuKien(huong);
		hienthiRan(dotCuoiCu);

		//ToaDo moi = hienThiMoi();
		if (kiemTraDaAnMoi(moi))
		{
			moi = hienThiMoi();
			themDot();
			diem++;
			gotoXY(TUONG_PHAI + 3, TUONG_TREN + 5);
			cout << "Scoce: " << diem;
		}
		if (kiemTraThua())
			break;
		Sleep(300/(pow(level,2)));
		//runTime();

	}xuLyThua(diem);
}
void Menu()
{

		cout << "Do you want level? - 1. Easy | 2. Normal | 3. Hard" << endl;
		cout << "Level - ";
		int level;
		cin >> level;
		Gameloop(level);
}
void main()
{
	char play;
	cout << "!!! WELCOME TO GAME SNAKE !!!" << endl;
	cout << "Do you want to play? (Y/N) - ";
	cin >> play;
	if (play == 'Y' || play == 'y')
	{
		/*cout << "Do you want level? - 1. Easy | 2. Normal | 3. Hard" << endl;
		cout << "Level - ";
		int level;
		cin >> level;
		Gameloop(level);*/
		Menu();
	}
	else
	{
		cout << "See you again!!!" << endl;
	}
		//system("cls");
		//khoitaoRan();
		//int huong = RIGHT;
		//int x = 0, y = 0;
		//veTuong();
		//srand(time_t(NULL));
		//ToaDo moi = hienThiMoi();
		////runTime();
		//// Tao so ngau nhien // random trong [a,b]: a+rand()%(b-a+1)
		//gotoXY(TUONG_PHAI + 3, TUONG_TREN);
		//cout << (char)176 << " GAME SNAKE " << (char)176;

		//gotoXY(TUONG_PHAI + 3, TUONG_TREN + 1);
		//cout << "@ Creat by Le Dinh Cuong";
		//gotoXY(TUONG_PHAI + 3, TUONG_TREN + 2);
		//cout << "# From IKB0-07-19 MIREA";
		////Game loop
		//int diem = 0;
		//gotoXY(TUONG_PHAI + 3, TUONG_TREN + 3);
		//cout << "------------------------";
		//gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		//cout << "Score: " << diem;
		//while (1)
		//{


		//	ToaDo dotCuoiCu = diChuyen(huong);
		//	batSuKien(huong);
		//	hienthiRan(dotCuoiCu);

		//	//ToaDo moi = hienThiMoi();
		//	if (kiemTraDaAnMoi(moi))
		//	{
		//		moi = hienThiMoi();
		//		themDot();
		//		diem++;
		//		gotoXY(TUONG_PHAI + 3, TUONG_TREN + 4);
		//		cout << "Scoce: " << diem;
		//	}
		//	if (kiemTraThua())
		//		break;
		//	Sleep(100);
		//	//runTime();

		//}xuLyThua(diem);
}
void khoitaoRan()
{
	ran[0].x = TUONG_TRAI + 3;
	ran[1].x = TUONG_TRAI + 2;
	ran[2].x = TUONG_TRAI + 1;
	ran[0].y = ran[1].y = ran[2].y = TUONG_TREN + 1;
}
void hienthiRan(ToaDo dotCuoiCu)
{
	gotoXY(ran[0].x, ran[0].y);
	cout << (char)176;
	for (int i = 1; i < soDot; i++)
	{
		gotoXY(ran[i].x, ran[i].y);
		setTextColor(MAU_RAN);
		cout << (char)DOT_RAN;

	}
	gotoXY(dotCuoiCu.x, dotCuoiCu.y);
	cout << " ";
}
ToaDo diChuyen(int huong)
{
	// Luu toa do dot cuoi cu de xoa
	ToaDo dotCuoiCu = ran[soDot - 1];

	for (int i = soDot - 1; i >= 1; i--)
	{
		ran[i] = ran[i - 1];
	}
	switch (huong)
	{
	case UP:
		ran[0].y--;
		break;
	case DOWN:
		ran[0].y++;
		break;
	case LEFT:
		ran[0].x--;
		break;
	case RIGHT:
		ran[0].x++;
		break;
	}
	return dotCuoiCu;
}
void batSuKien(int &huong)
{
	int key = inputKey();
	if (key == 'w' || key == 'W' || key == KEY_UP)
	{
		if (huong == DOWN)
		{
			huong = DOWN;
		}
		else
		{
			huong = UP;
		}
	}
	else
		if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			if (huong == UP)
			{
				huong = UP;
			}
			else
			{
				huong = DOWN;
			}
		}
		else if (key == 'a' || key == 'A' || key == KEY_LEFT)
		{
			if (huong == RIGHT)
			{
				huong = RIGHT;
			}
			else
			{
				huong = LEFT;
			}
		}
		else if (key == 'd' || key == 'D' || key == KEY_RIGHT)
		{
			if (huong == LEFT)
			{
				huong = LEFT;
			}
			else
			{
				huong = RIGHT;
			}
		}
}
void veTuong()
{
	for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
	{
		gotoXY(i, TUONG_TREN);
		setTextColor(MAU_TUONG);
		cout << (char)223;
	}
	for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
	{
		gotoXY(i, TUONG_DUOI);
		setTextColor(MAU_TUONG);
		cout << (char)220;
	}
	for (int i = TUONG_TREN; i <= TUONG_DUOI; i++)
	{
		gotoXY(TUONG_TRAI, i);
		setTextColor(MAU_TUONG);
		cout << (char)222;
	}
	for (int i = TUONG_TREN; i <= TUONG_DUOI; i++)
	{
		gotoXY(TUONG_PHAI, i);
		setTextColor(MAU_TUONG);
		cout << (char)221;
	}

}
bool kiemTraThua()
{
	/*if (ran[0].y == TUONG_TREN || ran[0].y == TUONG_DUOI || ran[0].x == TUONG_PHAI || ran[0].x == TUONG_TRAI)
		return true;
	else
		return false;*/
	
		if (ran[0].y == TUONG_TREN || ran[0].y == TUONG_DUOI || ran[0].x == TUONG_PHAI || ran[0].x == TUONG_TRAI)
			return true;
		else
			return false;
	
}
void xuLyThua(int diem)
{
	if (kiemTraThua())
	{
		//clrscr();
		GameOver(diem);
		//cout << "Game over!" << endl;
	}
}
ToaDo hienThiMoi()
{
	//srand(time_t(NULL));
	int x = (TUONG_TRAI + 1) + rand() % ((TUONG_PHAI - 1) - (TUONG_TRAI + 1) + 1);
	int y = (TUONG_TREN + 1) + rand() % ((TUONG_DUOI - 1) - (TUONG_TREN + 1) + 1);
	gotoXY(x, y);
	setTextColor(MAU_MOI);
	cout << "#";
	/*ToaDo temp;
	temp.x = x;
	temp.y = y;
	return temp;*/
	return ToaDo{ x,y };
}
bool kiemTraDaAnMoi(ToaDo moi)
{
	if (ran[0].x == moi.x && ran[0].y == moi.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void themDot()
{
	ran[soDot] = ran[soDot - 1];
	soDot++;
}
//void runTime()
//{
//	int time = 0;
//	while (1)
//	{
//		gotoXY(TUONG_PHAI + 3, TUONG_TREN + 1);
//		cout << "Time: " << time << " s";
//		Sleep(1000);
//		time++;
//	}
//}
void GameOver(int diem)
{
	int i = TUONG_TRAI + 6;
	int j = TUONG_TREN + 3;
	gotoXY(i, j);
	cout << " ****   ****  **    ** ******           ****  **  ** ****** ***** ";
	j++;
	gotoXY(i, j);
	cout << "****** ****** **    ** ******          ****** **  ** ****** ******";
	j++;
	gotoXY(i, j);
	cout << "**  ** **  ** ***  *** **              **  ** **  ** **     **  **";
	j++;
	gotoXY(i, j);
	cout << "**     **  ** ******** **              **  ** **  ** **     **  **";
	j++;
	gotoXY(i, j);
	cout << "** *** **  ** ** ** ** ******          **  ** **  ** ****** ******";
	j++;
	gotoXY(i, j);
	cout << "** *** ****** ** ** ** ******          **  ** **  ** ****** ***** ";
	j++;
	gotoXY(i, j);
	cout << "**  ** ****** **    ** **              **  ** **  ** **     ****  ";
	j++;
	gotoXY(i, j);
	cout << "**  ** **  ** **    ** **              **  ** **  ** **     ***** ";
	j++;
	gotoXY(i, j);
	cout << "****** **  ** **    ** ******          ****** ****** ****** ** ***";
	j++;
	gotoXY(i, j);
	cout << " ****  **  ** **    ** ******           ****   ****  ****** **  **";
	j+=2;
	gotoXY(i, j);
	cout << "                         Your score: " << diem;
	j ++;
	gotoXY(i, j);
	cout << "                     Thanks for playing!!!";

	j += 4;
	gotoXY(i, j);
	char playagain;
	cout << "Do you want to play agian? (Y/N) - ";
	cin >> playagain;
	if (playagain  == 'Y' || playagain == 'y')
	{
		soDot = 3;
		//system("cls");
		clrscr();
		Menu();
	}
	else
	{
		cout << "See you again!!!" << endl;
	}
	
}