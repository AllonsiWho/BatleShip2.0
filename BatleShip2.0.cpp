// BatleShip.cpp :
//

#include <iostream>
#include<time.h>
#include<Windows.h>
#include <conio.h>
using namespace std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, spase = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
//объект корабль
struct Ship
{
	int palub = 4;
	int hp;
	int x;
	int y;
	int h_v = 1;
};
//рисовка поля
void Displei(int mas[][10], int x, int y);
void Displei(char mas[][10], int x, int y);
//Проверка выставления коробля											
int Proverk(Ship user, int x, int y, int mas[][10]);

void Random_Ship(Ship user, int mas3[][10]);

void Print_Displei(int mas[][10], char mas4[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (mas[i][j] != 0)
			{
				mas4[i][j] = '#';
			}

		}


	}



}
//Рисовка коробля
void printPalub(Ship ship, int x, int y)
{

	for (int i = 0; i < ship.palub; i++)
	{
		for (int j = 0; j < ship.palub; j++)
		{
			if (ship.h_v == 0)
			{
				SetColor(LightBlue, Black);
				SetCursor(x + i, y);
				//cout << ship.palub;
				cout << "#";
			}
			else if (ship.h_v != 0)
			{
				SetColor(LightBlue, Black);
				SetCursor(x, y + i);
				//cout <<ship.palub;
				cout << "#";
			}
			SetColor(White, Black);

		}


	}


}
////сохранение места коробля в массиве
void Palub(Ship& obj, int x, int y, int mas[][10])
{
	for (int i = 0; i < obj.palub; i++)
	{
		if (obj.h_v == 0)
		{
			mas[x - 8 + i][y - 5] = obj.palub;
		}
		else
		{
			mas[x - 8][y - 5 + i] = obj.palub;
		}


	}
}
void Palub(Ship& obj, int mas3[][10], int x, int y)
{
	for (int i = 0; i < obj.palub; i++)
	{
		if (obj.h_v == 0)
		{
			mas3[x + i][y] = obj.palub;
		}
		else
		{
			mas3[x][y + i] = obj.palub;
		}


	}
}
//перемещение коробля по полю для выставления
void dowPalub(int mas[][10], Ship& user, int x, int y, char mas2[][10], char mas4[][10])
{
	int poz = 0;
	do
	{
		SetCursor(45, 10);
		cout << "Пробел повернуть корабль";
		SetCursor(45, 11);
		cout << "Enter поставить корабль";
		Print_Displei(mas, mas4);
		Displei(mas4, 8, 5);
		Displei(mas2, 32, 5);
		printPalub(user, x, y);

		poz = _getch();

		switch (poz)
		{
		case Left:
			x--;

			if (x <= 7 && user.h_v == 0)
			{
				x++;
			}
			else if (x <= 7 && user.h_v == 1)
			{
				x++;
			}
			break;
		case Right:
			x++;
			if (x >= 18 && user.h_v == 0 && user.palub == 1)
			{
				x--;
				break;
			}
			if (x >= 17 && user.h_v == 0 && user.palub == 2)
			{
				x--;
				break;
			}
			else if (x >= 16 && user.h_v == 0 && user.palub == 3)
			{
				x--;
				break;
			}
			else if (x >= 15 && user.h_v == 0 && user.palub == 4)
			{
				x--;
				break;
			}
			else if (x >= 18 && user.h_v == 1)
			{
				x--;
			}
			break;
		case Up:
			y--;
			if (y <= 4 && user.h_v == 0)
			{
				y++;
			}
			else if (y <= 4 && user.h_v == 1)
			{
				y++;
			}
			break;
		case Down:
			y++;
			if (y >= 15 && user.h_v == 0)
			{
				y--;
			}
			else if (y >= 15 && user.h_v == 1 && user.palub == 1)
			{
				y--;
				break;
			}
			else if (y >= 14 && user.h_v == 1 && user.palub == 2)
			{
				y--;
				break;
			}
			else if (y >= 13 && user.h_v == 1 && user.palub == 3)
			{
				y--;
				break;
			}
			else if (y >= 12 && user.h_v == 1 && user.palub == 4)
			{
				y--;
			}
			break;
		case Enter:
		{
			/*
			if (koll == 4)
			{

				Palub(*user, x, y, h_v, mas, koll);

			}
			if (koll == 3)
			{
				Palub(*user, x, y, h_v, mas, koll);
			}
			if (koll == 2)
			{
				Palub(*user, x, y, h_v, mas, koll);
			}
			if (koll == 1)
			{
				Palub(*user, x, y, h_v, mas, koll);
			}*/
			Proverk(user, x, y, mas);
			if (Proverk(user, x, y, mas) == 1)
			{
				Palub(user, x, y, mas);
			}
			else { SetCursor(10, 15); cout << "Нельзя ставить так близко коробли"; Sleep(2000); system("cls"); poz = 1; }

			break;
		}
		case spase:
			if (user.h_v == 0)
			{

				if (y > 13)
				{
					y = y - user.palub;

				}
				user.h_v = 1;

			}
			else
			{
				if (x > 16)
				{
					x = x - user.palub;
				}
				user.h_v = 0;

			}
			break;
		}







	} while (poz != Enter);
}
//заполнение поля числами
void massdo(int mas[][10], char mas2[][10], int mas3[][10], char mas4[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mas[i][j] = 0;
			mas2[i][j] = '.';
			mas3[i][j] = 0;
			mas4[i][j] = '.';
		}
	}
}
void SshipKontrl(Ship user, int mas[][10], int x, int y, char mas2[][10], char mas4[][10],int poz3)
{
	for (int i = 0; i < 10; i++)
	{

		if (user.palub == 4)
		{
			if (poz3 == 0) { dowPalub(mas, user, x, y, mas2, mas4); }//Выставление коробля 
			else { Random_Ship(user, mas); }
			user.palub--;
		}
		else if (user.palub == 3 && i <= 2)
		{

			if (poz3 == 0) { dowPalub(mas, user, x, y, mas2, mas4); }//Выставление коробля 
			else { Random_Ship(user, mas); }
			if (i == 2)
			{
				user.palub--;
				continue;
			}
		}
		else if (user.palub == 2 && i <= 5)
		{

			if (poz3 == 0) { dowPalub(mas, user, x, y, mas2, mas4); }//Выставление коробля 
			else { Random_Ship(user, mas); }
			if (i == 5)
			{
				user.palub--;
				continue;
			}
		}
		else if (user.palub == 1 && i >= 6)
		{
			if (poz3 == 0) { dowPalub(mas, user, x, y, mas2, mas4); }//Выставление коробля 
			else { Random_Ship(user, mas); }
		}
	}
	return;
}
void SshipKontrl(Ship user, int mas3[][10])
{
	user.palub = 4;
	for (int i = 0; i < 10; i++)
	{

		if (user.palub == 4)
		{
			//dowPalub(mas, user, x, y, mas2);//Выставление коробля
			Random_Ship(user, mas3);
			user.palub--;
		}
		else if (user.palub == 3 && i <= 2)
		{
			Random_Ship(user, mas3);
			//dowPalub(mas, user, x, y, mas2);//Выставление коробля
			if (i == 2)
			{

				user.palub--;
				continue;
			}
		}
		else if (user.palub == 2 && i <= 5)
		{
			Random_Ship(user, mas3);
			//dowPalub(mas, user, x, y, mas2);//Выставление коробля
			if (i == 5)
			{

				user.palub--;
				continue;
			}
		}
		else if (user.palub == 1 && i >= 6)
		{
			Random_Ship(user, mas3);
			//dowPalub(mas, user, x, y, mas2);//Выставление коробля
		}
	}
	return;
}
int menu();//Отрисовка меню
int winn(int mas[][10], int mas3[][10],int game)
{
	int palub4=0, palub3=0, palub2=0, palub1=0;
	if(game==0){
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (mas[i][j] == -4)
				{
					palub4++;
				}
				if (mas[i][j] == -3)
				{
					palub3++;
				}
				if (mas[i][j] == -2)
				{
					palub2++;
				}
				if (mas[i][j] == -1)
				{
					palub1++;
				}
				if (palub4 == 4 && palub3 == 6 && palub2 == 6 && palub1 == 4)
				{
					return 1;
				}

			}
		}
	}

	else{for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(mas3[i][j]==-4)
			{ 
				palub4++;
			}
			if (mas3[i][j] == -3)
			{
				palub3++;
			}
			if (mas3[i][j] == -2)
			{
				palub2++;
			}
			if (mas3[i][j] == -1)
			{
				palub1++;
			}
			if (palub4 == 4 && palub3 == 6 && palub2 == 6 && palub1 == 4)
			{
				return 1;
			}

		}
	}}
	
	return 0;




}
void Print_Fire(int x, int y)
{

	/*for (int i = 0; i < 1; i++)
	{*/
		SetCursor(x , y);
		cout << "@";
	/*}*/
}
int sravnenie_damge(char mas2[][10], int mas3[][10], int x, int y);

int sravnenie(char mas2[][10], int mas3[][10], int x, int y)
{
	x = x - 32;
	y = y - 5;
	int DD = 0;
	if (mas2[x][y] == '*')
	{
		return 0;
	}
	if (mas3[x][y] == 0)
	{
		mas2[x][y] = '*';
		return 1;
	}
	else
	{
		DD=sravnenie_damge(mas2, mas3, x, y);
		if (DD == 1)
		{
			mas2[x][y] = 'X';
		}
		else
		{mas2[x][y] = '%';}
		mas3[x][y] = -mas3[x][y];
		
		return 2;
	}
}
void doFire(char mas2[][10], int x, int y, int mas3[][10], int game,int mas[][10],char mas4[][10])
{
	//x+32,y+5
	int poz = 0, key = 0;
	for(;;)
	{
		if (game == 1)
		{
			if (key == 2)
			{
				int nap=rand()%4;
				if (nap == 0)
				{
					if (x - 1 >= 0)
					{
						x--;
					}
					else { nap++; }
				}
				if (nap == 1)
				{
					if (x + 1 <= 9)
					{
						x++;
					}
					else { nap++; }
				if (nap == 2)
					{
						if(y-1>=0)
						{
							y--;
						}
						else { nap++; }
					}
				if (nap == 3)
					{
						if (y + 1 <= 9)
						{
							y++;
						}
						else { nap = 0; }
					}
				}
			}
			else
			{
				x = rand() % 10;
				y = rand() % 10;
			}
			
			key = sravnenie(mas4, mas, x+32, y+5);
			
			if (key == 1)
			{
				poz = spase;
			}

		}
		else {



			Displei(mas2, 32, 5);
			Print_Fire(x, y);

			poz = _getch();

			switch (poz)
			{
			case Left:
				x--;

				if (x <= 31)
				{
					x++;
				}
				break;
			case Right:
				x++;
				if (x >= 42)
				{
					x--;
					break;
				}

				break;
			case Up:
				y--;
				if (y <= 4)
				{
					y++;
				}

				break;
			case Down:
				y++;
				if (y >= 15)
				{
					y--;
				}

				break;
			
			case spase:
			{

				key = sravnenie(mas2, mas3, x, y);

				break;
			}

			}

		}
		if (poz == spase && key == 1) { break; }
	} 

}
int menu2();
int main()
{

	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int mas[10][10] = {};//массив игрока
	char mas2[10][10];//Поле компьютера
	int mas3[10][10];//массив КОМПЬЮТЕРА
	char mas4[10][10];//Поле игрока
	int poz, poz2, game = 0, win = 0,poz3;//поз- нажатие на клавишу, h_v- горизонтальльно\вертикально, poz2 выбор меню,poz3-выбор растановки

	
	Ship user;
	int x = 8, y = 5;//Положение центра на первом поле
	massdo(mas, mas2, mas3, mas4);
	SetCursor(13, 1);
	cout<<R"(
__________________¶¶¶¶¶¶¶_________¶_______________
__________________¶__¶__¶_______¶¶¶¶¶_____________
____________¶_____¶__¶__¶_______¶_¶_¶_____________
____________¶¶___¶¶¶¶¶¶¶¶¶_____¶¶¶¶¶¶¶____________
____¶¶______¶¶¶__¶___¶___¶_____¶__¶__¶____________
____¶¶¶______¶___¶___¶____¶___¶___¶___¶___________
____¶¶¶¶__¶¶¶¶__¶___¶¶¶___¶__¶____¶____¶__________
____¶¶¶¶¶__¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__________
_____¶__¶¶__¶¶¶______¶______¶_____¶____¶____¶¶_¶__
_____¶¶¶¶____¶_______¶______¶_____¶_____¶__¶¶¶¶___
___¶¶¶¶¶¶¶___¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__
___¶¶¶¶¶¶¶¶¶¶¶¶¶_____¶_________¶¶¶¶¶¶¶__¶¶¶__¶¶¶__
____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶___¶¶¶__¶¶¶¶¶¶¶¶¶¶¶_________
____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶___________
____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________)";
	cout << R"(
`````````````````````````````````````````````¶¶
¶¶```¶¶``¶¶¶¶``¶¶¶¶¶```¶¶¶¶``¶¶``¶¶``¶¶¶¶``¶¶``¶¶
¶¶¶`¶¶¶`¶¶``¶¶`¶¶``¶¶`¶¶``¶¶`¶¶`¶¶``¶¶``¶¶`¶¶``¶¶
¶¶`¶`¶¶`¶¶``¶¶`¶¶¶¶¶¶`¶¶`````¶¶¶¶```¶¶``¶¶`¶¶`¶¶¶
¶¶```¶¶`¶¶``¶¶`¶¶`````¶¶``¶¶`¶¶`¶¶``¶¶``¶¶`¶¶¶`¶¶
¶¶```¶¶``¶¶¶¶``¶¶``````¶¶¶¶``¶¶``¶¶``¶¶¶¶``¶¶``¶¶
````````````````¶¶
¶¶¶¶¶```¶¶¶¶``¶¶``¶¶
¶¶`````¶¶``¶¶`¶¶``¶¶
¶¶¶¶¶``¶¶``¶¶`¶¶`¶¶¶
¶¶``¶¶`¶¶``¶¶`¶¶¶`¶¶
¶¶¶¶¶```¶¶¶¶``¶¶``¶¶)";
	Sleep(4500);
	system("cls");
do{
	
	poz2 = menu();
	system("cls");
	poz3 = menu2();
	system("cls");
	//Displei(mas2, 32, 5);
	if(poz2==1)
	{		
	SshipKontrl(user, mas, x, y, mas2,mas4,poz3);//выставление короблей Игрока
		
	SshipKontrl(user, mas3);//выставление короблей компьютера
	Print_Displei(mas, mas4);
	do {
		Displei(mas4, 8, 5);
		Displei(mas2, 32, 5);
		
		if (game == 0)
		{
			//Displei(mas3, 32, 20);
			/*SetCursor(15, 20);
			cout << game;*/
			win = winn(mas, mas3, game);
			if (win == 1) { break; }
			doFire(mas2, 32, 10, mas3, game,mas,mas4);//выбор выстрела на поле противника Игрока
			
			
			win = winn(mas, mas3,game);
			if (win == 1) { break; }
			else{game = 1;}
			/*SetCursor(15, 20);
			cout << game;*/
			//Displei(mas3, 32, 20);
		}
		else
		{
			doFire(mas2, 0, 0, mas3, game, mas,mas4);
			win = winn(mas, mas3,game);
			if (win == 1) { break; }
			else { game = 0; }
		}
		

	} while (win!=1);
	system("cls");
	if (game == 0)
	{
		SetCursor(15, 5);
		cout << "Игрок победил";
	}
	else
	{
		SetCursor(15, 5);
		cout << "Победил компьютер";
	}

	}
	if (poz2 == 0) 
	{
		SetCursor(15, 5); 
		cout << "В разработке";
		Sleep(2000);
		system("cls");
	}
	if (poz2 == 2) 
	{ 
		SetCursor(15, 5); 
		cout << "Уничтож их быстрее";
		Sleep(2000);
		system("cls");
	}
} while (esc);






	SetColor(White, Black);
	SetCursor(0, 25);
	system("pause>>NULL");

}



void Displei(int mas[][10], int x, int y)
{
	int poz = 0, koll = 1;
	SetCursor(10, 2);
	cout << "Мой Флот";
	SetCursor(30, 2);
	cout << "Флот Противника";
	SetCursor(8, 4);
	cout << "АБВГДУШЗЫК";
	SetCursor(32, 4);
	cout << "АБВГДУШЗЫК";
	
	for (int i = 0; i < 10; i++)//рисование боковых стенок с цифрами для первого поля
	{

		if (i != 9)
		{
			SetCursor(6, 5 + i);
			cout << koll << "|";
			koll++;
		}
		else
		{
			SetCursor(5, 5 + i);
			cout << koll << "|";


		}
	}koll = 1;//обнуление счетчика для второго поля
	for (int i = 0; i < 10; i++)//рисование боковых стенок с цифрами для второго поля
	{

		if (i != 9)
		{
			SetCursor(30, 5 + i);
			cout << koll << "|";
			koll++;
		}
		else
		{
			SetCursor(29, 5 + i);
			cout << koll << "|";


		}
	}
	for (int i = 0; i < 10; i++)//первое поле рисовка
	{
		for (int j = 0; j < 10; j++)
		{

			SetCursor(x + i, y + j);
			//mas[i][j] = '.';
			cout << mas[i][j];

		}

	}


	




}
void Displei(char mas[][10], int x, int y)
{
	int poz = 0, koll = 1;
	SetCursor(10, 2);
	cout << "Мой Флот";
	SetCursor(30, 2);
	cout << "Флот Противника";
	SetCursor(8, 4);
	cout << "АБВГДУШЗЫК";
	SetCursor(32, 4);
	cout << "АБВГДУШЗЫК";
	for (int i = 0; i < 10; i++)//рисование боковых стенок с цифрами для первого поля
	{

		if (i != 9)
		{
			SetCursor(6, 5 + i);
			cout << koll << "|";
			koll++;
		}
		else
		{
			SetCursor(5, 5 + i);
			cout << koll << "|";


		}
	}koll = 1;//обнуление счетчика для второго поля
	for (int i = 0; i < 10; i++)//рисование боковых стенок с цифрами для второго поля
	{

		if (i != 9)
		{
			SetCursor(30, 5 + i);
			cout << koll << "|";
			koll++;
		}
		else
		{
			SetCursor(29, 5 + i);
			cout << koll << "|";


		}
	}
	for (int i = 0; i < 10; i++)//первое поле рисовка
	{
		for (int j = 0; j < 10; j++)
		{

			SetCursor(x + i, y + j);
			//mas[i][j] = '.';
			cout << mas[i][j];

		}

	}


	//for (int i = 0; i < 10; i++)//второе поле рисовка
	//{
	//	for (int j = 0; j < 10; j++)
	//	{

	//		SetCursor(32 + i, 5 + j);
	//		//mas2[i][j] = '+';
	//		cout << mas2[i][j];

	//	}

	//}




}
int menu()
{

	char menu[3][10] = { "PvP","PvE","Правила" };//Пункты меню
	int poz = 0, key;//поз-пункта меню, кей-кнопка нажатия

	for (int i = 0; i < 3; i++)//Рисовка меню
	{
		SetCursor(15, 10 + i);
		cout << menu[i];

	}
	do {
		for (int i = 0; i < 3; i++)//изменения цвета выбронного пункта
		{
			SetCursor(15, 10 + i);

			if (i == poz)
			{
				SetColor(Red, Black);
			}
			else
			{
				SetColor(White, Black);
			}

			cout << menu[i];

		}

		key = _getch();
		switch (key)
		{
		case Up:
		{	poz--;
		if (poz < 0)
		{
			poz = 2;
		}
		break;
		}
		case Down:
		{
			poz++;
			if (poz > 2)
			{
				poz = 0;
			}
			break;
		}
		case Enter:
		{
			SetColor(White, Black);
			return(poz);//возвращение выбронного пункта меню
		}


		}

	} while (true);



}
int menu2()
{
	char menu[2][35] = { "Ручная выставка коробля","Автоматическая выставка коробля" };//Пункты меню
	int poz = 0, key;//поз-пункта меню, кей-кнопка нажатия

	for (int i = 0; i < 2; i++)//Рисовка меню
	{
		SetCursor(15, 10 + i);
		cout << menu[i];

	}
	do {
		for (int i = 0; i < 2; i++)//изменения цвета выбронного пункта
		{
			SetCursor(15, 10 + i);

			if (i == poz)
			{
				SetColor(Red, Black);
			}
			else
			{
				SetColor(White, Black);
			}

			cout << menu[i];

		}

		key = _getch();
		switch (key)
		{
		case Up:
		{	poz--;
		if (poz < 0)
		{
			poz = 2;
		}
		break;
		}
		case Down:
		{
			poz++;
			if (poz > 1)
			{
				poz = 0;
			}
			break;
		}
		case Enter:
		{
			SetColor(White, Black);
			return(poz);//возвращение выбронного пункта меню
		}


		}

	} while (true);



}

int Proverk(Ship user, int x, int y, int mas[][10])
{
	x = x - 8;
	y = y - 5;
	if ((x + user.palub - 1) > 9 && user.h_v == 0) { return 0; }
	if ((y + user.palub - 1) > 9 && user.h_v == 1) { return 0; }
	switch (user.h_v)
	{
	case 0://Горизонтально
	{


		if (mas[x - 1][y - 1] != 0) { if (y == 0) {} else if (x == 0 && y == 0) {} else if (x == 0) {} else { return 0; } }
		/*-------
		|х
		| 4444
		|
		*/

		if (mas[x + user.palub][y - 1] != 0) { if (y == 0) {} else if (x + user.palub - 1 >= 9) {} else { return 0; } }
		/*-------
		|     х
		| 4444
		|
		*/
		if (mas[x - 1][y + 1] != 0) { if (y == 9) {} else if (x == 0) {} else { return 0; } }
		/*-------
		|
		| 4444
		|х
		*/
		if (mas[x + user.palub][y + 1] != 0) { if (y == 9) {} else if (x + user.palub - 1 >= 9) {} else { return 0; } }
		/*-------
		|
		| 4444
		|     х
		*/
		if (mas[x - 1][y] != 0) { if (x == 0) {} else { return 0; } }
		/*-------
		|
		| x4444
		|
		*/
		if (mas[x + user.palub][y] != 0) { if (x + user.palub - 1 == 9) {} else if (x + user.palub - 1 >= 9) { return 0; } else { return 0; } }
		/*-------
		|
		| 4444x
		|
		*/
		for (int i = 0; i < user.palub; i++)
		{
			if (mas[x + i][y - 1] != 0) { if (y == 0) {} else if (x == 0 && y == 0) {} else { return 0; } }
			/*-------
		| xxxx
		| 4444
		|
		*/
			if (mas[x + i][y + 1] != 0) { if (y == 9) {} else { return 0; } }
			/*-------
		|
		| 4444
		| xxxx
		*/
		}
		break;
	}
	case 1://Вертикально
	{
		if (mas[x - 1][y - 1] != 0) { if (y == 0) {} else if (x == 0 && y == 0) {} else if (x == 0) {} else { return 0; } }
		/*-------
		|x
		| 4
		| 4
		| 4
		| 4
		*/
		if (mas[x + 1][y - 1] != 0) { if (y == 0) {} else if (x == 9 && y == 0) {} else if (x == 9) {} else { return 0; } }
		/*-------
		|  x
		| 4
		| 4
		| 4
		| 4
		*/
		if (mas[x - 1][y + user.palub] != 0) { if (x == 0) {} else if (y + user.palub - 1 >= 9) {} else { return 0; } }
		/*-------
		|
		| 4
		| 4
		| 4
		| 4
		|x
		*/
		if (mas[x + 1][y + user.palub] != 0) { if (x == 9) {} else if (y + user.palub - 1 >= 9) {} else { return 0; } }
		/*-------
		|
		| 4
		| 4
		| 4
		| 4
		|  x
		*/
		if (mas[x][y - 1] != 0) { if (y == 0) {} else { return 0; } }
		/*-------
		| x
		| 4
		| 4
		| 4
		| 4
		|
		*/
		if (mas[x][y + user.palub] != 0) { if (y + user.palub - 1 == 9) {} else if ((y + user.palub - 1) >= 9) { return 0; } else { return 0; } }
		/*-------
		|
		| 4
		| 4
		| 4
		| 4
		| x
		*/
		for (int i = 0; i < user.palub; i++)
		{
			if (mas[x - 1][y + i] != 0) { if (x == 0) {} else { return 0; } }
			/*-------
			|
			|x4
			|x4
			|x4
			|x4
			|
			*/
			if (mas[x + 1][y + i] != 0) { if (x == 9) {} else { return 0; } }
			/*-------
		|
		| 4x
		| 4x
		| 4x
		| 4x
		|
		*/
		}
		break;
	}
	}

	return 1;




}
int sravnenie_damge(char mas2[][10], int mas3[][10], int x, int y)
{
	
	int palub = 0;
	
		if(mas3[x][y]==-4)
	{
		
		for (int i = 1; i <= 3; i++)
		{
			if (x + 3 <= 9)
			{
				if (mas3[x][y] == -mas3[x + i][y])
				{
				palub++;
				}
			}

			if (x - 3 >=0) 
			{
				if (mas3[x][y] == -mas3[x - i][y])
				{
				palub++;
				}
			}
			
			if (y + 3 <= 9) 
			{
				if (mas3[x][y] == -mas3[x ][y+ i])
				{
				palub++;
				}
			}
			if (y - 3 >= 0) 
			{
				if (mas3[x][y] == -mas3[x ][y- i])
				{
				palub++;
				}
			}
		}
		
		
		
	}

		if(mas3[x][y]==-3)
		{
			for (int i = 1; i <= 2; i++)
			{
				if (x + 2 <= 9)
				{
					if (mas3[x][y] == -mas3[x + i][y])
					{
						palub++;
					}
				}

				if (x - 2 >= 0)
				{
					if (mas3[x][y] == -mas3[x - i][y])
					{
						palub++;
					}
				}

				if (y + 2 <= 9)
				{
					if (mas3[x][y] == -mas3[x][y + i])
					{
						palub++;
					}
				}
				if (y - 2 >= 0)
				{
					if (mas3[x][y] == -mas3[x][y - i])
					{
						palub++;
					}
				}
			}

			
			
		}

		if (mas3[x][y] == -2)
		{
			for (int i = 1; i <= 1; i++)
			{
				if (x + 1 <= 9)
				{
					if (mas3[x][y] == -mas3[x + i][y])
					{
						palub++;
					}
				}

				if (x - 1 >= 0)
				{
					if (mas3[x][y] == -mas3[x - i][y])
					{
						palub++;
					}
				}

				if (y + 1 <= 9)
				{
					if (mas3[x][y] == -mas3[x][y + i])
					{
						palub++;
					}
				}
				if (y - 1 >= 0)
				{
					if (mas3[x][y] == -mas3[x][y - i])
					{
						palub++;
					}
				}
			}

			

		}

		if (mas3[x][y] == -1)
		{
			mas2[x][y] = 'X';
			return 1;
				
		}
		
		if (palub == 4)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (mas3[i][j] == -4) { mas2[i][j] = 'X'; }
				}
			}
			return 1;
		}
		if (palub == 3) 
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (mas3[i][j] == -3) { mas2[i][j] = 'X'; }
				}
			}
			return 1;
		}
		if (palub == 2)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (mas3[i][j] == -2) { mas2[i][j] = 'X'; }
				}
			}return 1;
		}
			
		return 0;
}
	

void Random_Ship(Ship user, int mas3[][10])
{

	do {
		int x = rand() % 10;
		int y = rand() % 10;
		user.h_v = rand() % 2;

		if (Proverk(user, x + 8, y + 5, mas3) == 1)
		{
			Palub(user, mas3, x, y);
			return;
		}


	} while (true);




}


