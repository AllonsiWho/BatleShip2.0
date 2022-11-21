// Arrays.cpp 

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
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
int menu();
void FillRand(int mas[], int n, int a, int b);
void FillRand(double mas[], int n, int a, int b);
void FillRand(float mas[], int n, int a, int b);
void FillRand(char mas[], int n, int a, int b);

void Prit(int mas[], int n);
double Prit(double mas[], int n);
float Prit(float mas[], int n);
char Prit(char mas[], int n);

int Sum(int mas[], int n);
double Sum(double mas[], int n);
float Sum(float mas[], int n);
char Sum(char mas[], int n);

int Avg(int Sum, int n);
double Avg(double Sum, int n);
float Avg(float Sum, int n);
char Avg(char Sum, int n);

int minValueln(int mas[], int n);
double minValueln(double mas[], int n);
float minValueln(float mas[], int n);
char minValueln(char mas[], int n);

int maxValueln(int mas[], int n);
double maxValueln(double mas[], int n);
float maxValueln(float mas[], int n);
char maxValueln(char mas[], int n);

void Sort(int mas[], int n);
double Sort(double mas[], int n);
float Sort(float mas[], int n);
char Sort(char mas[], int n);

void UniqueRand(int mas[], int n, int a, int b);
double UniqueRand(double mas[], int n, int a, int b);
float UniqueRand(float mas[], int n, int a, int b);
char UniqueRand(char mas[], int n, int a, int b);

void Search(int mas[], int n);
double Search(double mas[], int n);
float Search(float mas[], int n);
char Search(char mas[], int n);

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    const int n = 10;
    int mas[n];
    double mas_d[n];
    float mas_f[n];
    char mas_ch[n];
    int a = 0, b = 6;



    int poz = 0;
    int key;
    do
    {
        system("cls");
        poz = menu();
        system("cls");
        switch (poz)
        {
        case 1:
        {



            const int n = 10;
            int mas[n];
            int size = 0;
            for (int i = 0; i < 10; i++)
            {

                mas[i] = i + 1;
                cout << mas[i] << "\t";
            }

            do {
                system("cls");

                for (int i = 0; i < 10; i++)
                {


                    cout << mas[i] << "\t";
                }

                cout << endl;
                cout << "Нажмите Enter для выхода";



                key = _getch();
                switch (key)
                {
                case Left:
                {
                    size--;
                    break;
                }
                case Right:
                {
                    size++;
                    break;
                }
                case Enter:
                {
                    break;
                }

                }
                if (size < 0)
                {
                    size = 9;
                }
                if (size > 9 && key == Right)
                {
                    size = 0;
                }
                size = n - size;
                for (int i = 0; i < size; i++)
                {
                    int d = mas[0];
                    for (int i = 0; i < n; i++)
                    {

                        mas[i] = mas[i + 1];

                    }
                    mas[n - 1] = d;
                }


            } while (key != Enter);
            break;
        }

        case 0:
        {
            do {
                system("cls");
                cout << "Введите диапазон от "; cin >> a; cout << " до "; cin >> b;
                system("cls");
                FillRand(mas, n, a, b);
                FillRand(mas_d, n, a, b);
                FillRand(mas_f, n, a, b);
                FillRand(mas_ch, n, a, b);
                Prit(mas, n);
                cout << endl;
                Prit(mas_d, n);
                cout << endl;
                Prit(mas_f, n);
                cout << endl;
                Prit(mas_ch, n);
                cout << endl << Sum(mas, n);
                cout << endl << Sum(mas_d, n);
                cout << endl << Sum(mas_f, n);
                cout << endl << Sum(mas_ch, n);

                cout << endl << Avg(Sum(mas, n), n);
                cout << endl << Avg(Sum(mas_d, n), n);
                cout << endl << Avg(Sum(mas_f, n), n);
                cout << endl << Avg(Sum(mas_ch, n), n);

                cout << endl << minValueln(mas, n);
                cout << endl << minValueln(mas_d, n);
                cout << endl << minValueln(mas_f, n);
                cout << endl << minValueln(mas_ch, n);

                cout << endl << maxValueln(mas, n);
                cout << endl << maxValueln(mas_d, n);
                cout << endl << maxValueln(mas_f, n);
                cout << endl << maxValueln(mas_ch, n);
                cout << "\nESC-для Выхода";
                key = _getch();
            } while (key != esc);
            break;

        }

        case 2:
        {
            do {
                system("cls");
                Prit(mas, n);
                cout << endl;
                Prit(mas_d, n);
                cout << endl;
                Prit(mas_f, n);
                cout << endl;
                Prit(mas_ch, n);
                cout << endl;

                Sort(mas, n);               
                Sort(mas_d, n);                
                Sort(mas_f, n);                
                Sort(mas_ch, n);

                cout << endl;
                Prit(mas, n);
                cout << endl;
                Prit(mas_d, n);
                cout << endl;
                Prit(mas_f, n);
                cout << endl;
                Prit(mas_ch, n);
                cout << endl;
                cout << "\nESC-для Выхода";
                key = _getch();
            } while (key != esc);
            break;
        }

        case 3:
        {
            do {
                system("cls");
                cout << "Введите диапазон от "; cin >> a; cout << "до "; cin >> b;
                system("cls");

                UniqueRand(mas, n, a, b);
                UniqueRand(mas_d, n, a, b);
                UniqueRand(mas_f, n, a, b);
                UniqueRand(mas_ch, n, a, b);
                Prit(mas, n);
                cout << endl;
                Prit(mas_d, n);
                cout << endl;
                Prit(mas_f, n);
                cout << endl;
                Prit(mas_ch, n);
                cout << endl;
                cout << "\nESC-для Выхода";
                key = _getch();
            } while (key != esc);
            break;
        }
        case 4:
        {
            do
            {
                system("cls");
                FillRand(mas, n, a, b);
                FillRand(mas_d, n, a, b);
                FillRand(mas_f, n, a, b);
                FillRand(mas_ch, n, a, b);
                Prit(mas, n);
                Search(mas, n);
                cout<<"\n" << endl;
                Prit(mas_d, n);
                Search(mas_d, n);
                cout << "\n" << endl;
                Prit(mas_f, n);
                Search(mas_f, n);
                cout << "\n" << endl;
                Prit(mas_ch, n);
                Search(mas_ch, n);
                cout << "\n" << endl;
                
                cout << endl;
                cout << "\nESC-для Выхода";
                key = _getch();
            } while (key != esc);

        }
        case 5:
        {
            break;
        }

        }

    } while (poz != 5);
}

void FillRand(int mas[], int n, int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        mas[i] = a + rand() % (b - a);

    }

}
void FillRand(double mas[], int n, int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        mas[i] = a + rand() % (b - a) * 1.1;

    }

}
void FillRand(float mas[], int n, int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        mas[i] = a + rand() % (b - a) * 1.1;

    }

}
void FillRand(char mas[], int n, int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand()%256;

    }

}

void Prit(int mas[], int n)
{
    for (int i = -0; i < n; i++)
    {
        cout << mas[i] << "\t";

    }

}
double Prit(double mas[], int n)
{
    for (int i = -0; i < n; i++)
    {
        cout << mas[i] << "\t";

    }
    return 0;
}
float Prit(float mas[], int n)
{
    for (int i = -0; i < n; i++)
    {
        cout << mas[i] << "\t";

    }
    return 0;
}
char Prit(char mas[], int n)
{
    for (int i = -0; i < n; i++)
    {
        cout << mas[i] << "\t";

    }
    return 0;
}

int Sum(int mas[], int n)
{
    int Sum = 0;

    for (int i = 0; i < n; i++)
    {
        Sum = Sum + mas[i];

    }



    return Sum;
}
double Sum(double mas[], int n)
{
    double Sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        Sum = Sum + mas[i];

    }



    return Sum;
}
float Sum(float mas[], int n)
{
    float Sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        Sum = Sum + mas[i];

    }



    return Sum;
}
char Sum(char mas[], int n)
{
    char Sum = 0;

    for (int i = 0; i < n; i++)
    {
        Sum = Sum + mas[i];

    }



    return Sum;
}


int Avg(int Sum, int n)
{
    int Avg = 0;
    Avg = Sum / n;

    return Avg;
}
double Avg(double Sum, int n)
{
    double Avg = 0;
    Avg = Sum / n;

    return Avg;
}
float Avg(float Sum, int n)
{
    float Avg = 0;
    Avg = Sum / n;

    return Avg;
}
char Avg(char Sum, int n)
{
    char Avg = 0;
    Avg = Sum / n;

    return Avg;
}

int minValueln(int mas[], int n)
{
    int Min = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] < Min)
        {
            Min = mas[i];
        }


    }


    return Min;
}
double minValueln(double mas[], int n)
{
    double Min = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] < Min)
        {
            Min = mas[i];
        }


    }


    return Min;
}
float minValueln(float mas[], int n)
{
    float Min = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] < Min)
        {
            Min = mas[i];
        }


    }


    return Min;
}
char minValueln(char mas[], int n)
{
    char Min = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] < Min)
        {
            Min = mas[i];
        }


    }


    return Min;
}

int maxValueln(int mas[], int n)
{

    int Max = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] > Max)
        {
            Max = mas[i];
        }


    }


    return Max;


}
double maxValueln(double mas[], int n)
{

    double Max = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] > Max)
        {
            Max = mas[i];
        }


    }


    return Max;

}
float maxValueln(float mas[], int n)
{

    float Max = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] > Max)
        {
            Max = mas[i];
        }


    }


    return Max;


}
char maxValueln(char mas[], int n)
{

    char Max = mas[0];

    for (int i = 1; i < n; i++)
    {
        if (mas[i] > Max)
        {
            Max = mas[i];
        }


    }


    return Max;


}

void Sort(int mas[], int n)
{
    int boof = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1])
            {
                boof = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = boof;
            }
        }
    }
}
double Sort(double mas[], int n)
{
    double boof = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1])
            {
                boof = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = boof;
            }
        }
    }
    return 0;
}
float Sort(float mas[], int n)
{
    float boof = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1])
            {
                boof = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = boof;
            }
        }
    }
    return 0;
}
char Sort(char mas[], int n)
{
    char boof = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1])
            {
                boof = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = boof;
            }
        }
    }
    return 0;
}

void UniqueRand(int mas[], int n, int a, int b)
{
    FillRand(mas, n, a, b);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[j] == mas[i] && i != j)
            {
                mas[i] = a + rand() % (b - a);
                j = -1;
            }
        }

    }


}
double UniqueRand(double mas[], int n, int a, int b)
{
    FillRand(mas, n, a, b);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[j] == mas[i] && i != j)
            {
                mas[i] = a + rand() % (b - a);
                j = -1;
            }
        }

    }

    return 0;
}
float UniqueRand(float mas[], int n, int a, int b)
{
    FillRand(mas, n, a, b);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[j] == mas[i] && i != j)
            {
                mas[i] = a + rand() % (b - a);
                j = -1;
            }
        }

    }

    return 0;
}
char UniqueRand(char mas[], int n, int a, int b)
{
    FillRand(mas, n, a, b);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[j] == mas[i] && i != j)
            {
                mas[i] = a + rand() % (b - a);
                j = -1;
            }
        }

    }

    return 0;
}

void Search(int mas[], int n)
{
    int arr[10]{};
    cout << endl;
    int coll = 0, cikl = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[i] == mas[j])
            {
                coll++;
            }


        }

        if (coll > 0)
        {

            for (int g = 0; g < n; g++)
            {
                if (mas[i] == arr[g])
                {
                    cikl++;
                }

            }

            if (cikl == 0)
            {
                arr[i] = mas[i];
                cout << mas[i] << "|" << coll;
            }
            cikl = 0;


        }
        coll = 0;
        cout << "\t";
    }

}
double Search(double mas[], int n)
{
    double arr[10]{};
    cout << endl;
    int coll = 0, cikl = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[i] == mas[j])
            {
                coll++;
            }


        }

        if (coll > 0)
        {

            for (int g = 0; g < n; g++)
            {
                if (mas[i] == arr[g])
                {
                    cikl++;
                }

            }

            if (cikl == 0)
            {
                arr[i] = mas[i];
                cout << mas[i] << "|" << coll;
            }
            cikl = 0;


        }
        coll = 0;
        cout << "\t";
    }
    return 0;
}
float Search(float mas[], int n)
{
    float arr[10]{};
    cout << endl;
    int coll = 0, cikl = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[i] == mas[j])
            {
                coll++;
            }


        }

        if (coll > 0)
        {

            for (int g = 0; g < n; g++)
            {
                if (mas[i] == arr[g])
                {
                    cikl++;
                }

            }

            if (cikl == 0)
            {
                arr[i] = mas[i];
                cout << mas[i] << "|" << coll;
            }
            cikl = 0;


        }
        coll = 0;
        cout << "\t";
    }
    return 0;
}
char Search(char mas[], int n)
{
    char arr[10]{};
    cout << endl;
    int coll = 0, cikl = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mas[i] == mas[j])
            {
                coll++;
            }


        }

        if (coll > 0)
        {

            for (int g = 0; g < n; g++)
            {
                if (mas[i] == arr[g])
                {
                    cikl++;
                }

            }

            if (cikl == 0)
            {
                arr[i] = mas[i];
                cout << mas[i] << "|" << coll;
            }
            cikl = 0;


        }
        coll = 0;
        cout << "\t";
    }
    return 0;
}

int menu()
{
    char menu[6][50] = { "Вывод массива и работа с ним","Движение массива","Сортировка массива","Заполнение массива уник числами","Нахожденеи повторений","Выход" };//Пункты меню
    int poz = 0, key;//поз-пункта меню, кей-кнопка нажатия

    for (int i = 0; i < 6; i++)//Рисовка меню
    {
        SetCursor(15, 10 + i);
        cout << menu[i];

    }
    do {
        for (int i = 0; i < 6; i++)//изменения цвета выбронного пункта
        {
            SetCursor(15, 10 + i);

            if (i == poz)
            {
                SetColor(Yellow, Black);
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
            poz = 5;
        }
        break;
        }
        case Down:
        {
            poz++;
            if (poz > 5)
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
