// KorsarDice3.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	//SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "---Корсары. Игра в кости!---" << endl;
	//Перемнные
	int cach = 0, bet, strike_pc = 0, strike_player = 0, strike = 0;
	do//Провыерка ввода наличности
	{
		cout << "Выворачивай карманы "; cin >> cach;
		if (cach < 0)cout << "Кошелек в свинарнике оставил" << endl;
	} while (cach < 0);
	if (cach == 0)// сумма 0 отказ от игры
		cout << "Зачем тратишь мое время? Прощай басота!" << endl;
	else
	{//цикл самой игры
		do 
		{
			//обнуление перемнных перед новой игрой
			strike_pc = 0;
			strike_player = 0;
			//Необязатенльно
			strike = 0;
			bet = 0;
			system("cls");//очиста экрана
			cout << "----Деньги на бочку!---" << endl;
			cout << "Утебя в карманах не густо всего: " << cach << " Пиастров" << endl;
			do//цикл проверки ставки
			{
				cout << "Сколько ставишь? "; cin >> bet;
				if (bet < 0)cout << "Денег нет Но ты держись и Корабль ставь" << endl;
				if (bet > cach)cout << "Ты за кого меня держишь? Жизнью решил расплатиться" << endl;

			} while (bet<0 || bet>cach);
			if (bet == 0)//выход из игры
			{
				cout << "Ну ты и слабак! Проваливай" << endl;
				break;//выход из игры
			}
			else//ставка коректная
			{
				for (int i = 1; i <= 2; i++) //цикл из двух бросков ш==1 - бросок ПК, I==2 бросок игрока
				{
					strike = rand() % 6 + 1;//Делаем бросок кубика
					if (i == 1)// бросок пирата
					{
						strike_pc = strike;//присваеваем значение пирата
						cout << " У Пирата выпало: ";
					}
					else// инача игрока
					{
						strike_player = strike;
						cout << "Выпало у Корсара ";
					}
					switch (strike)
					{
					case 1:
						cout << R"(
  _ _ _
 |     |
 |  *  |
 |_ _ _|
 )";
						break;
					case 2:
						cout << R"(
  _ _ _
 |    *|
 |     |
 |* _ _|
 )";
						break;
					case 3:
						cout << R"(
  _ _ _
 |    *|
 |  *  |
 |* _ _|
 )";
						break;
					case 4:
						cout << R"(
  _ _ _
 | * * |
 |     |
 |_*_*_|
 )";
						break;
					case 5:
						cout << R"(
  _ _ _
 | * * |
 |  *  |
 |_*_*_|
 )";
						break;
					case 6:
						cout << R"(
  _ _ _
 | * * |
 | * * |
 |_*_*_|
 )";
						break;
					}
					if (strike_pc == strike_player)//если нечья
					{
						cout << "\nПогляди ровно Бросай еще раз\n" << endl;
						//обнуляем броски
						strike_pc = 0;
						strike_player = 0;
						i = 0;//устанавливаем счетчик передер броском пирата
					}

				}

				//определение победителя
				if (strike_pc > strike_player)//условие победы компьютера
				{
					cout << "\nХА-ХА-ХА-ХА Ты проиграл" << endl;
					cach -= bet; //отнимаем ставку от общей суммы
					cout << "у тебя осталось: " << cach << " пиастров" << endl;
				}
				else //победа игрока
				{
					cout << "\nКость мне в ногу и пулю мне в глаз. Я не верю своему последнгему глазу - ты победил!" << endl;
					cach += bet;
					cout << "у тебя осталось " << cach << " пиастров" << endl;

				}
				if (cach == 0)
				{
					cout << "Мы кредитов не выдаем Прощай" << endl;
					break;//выход
				}
				Sleep(1000);

			}
			system("pause");



		} while (cach > 0);

	}
	Sleep(1500);
}





		

