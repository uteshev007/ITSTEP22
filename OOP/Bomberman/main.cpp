#include <iostream>
#include <string>       // для строк std::string
#include <time.h>
#include <vector>
#include <conio.h>      // для _getch(), _kbhit()
#include "Win10.h"
#include "BasePlayer.h"
#include "Menu.h"
using namespace std;

string Pole[]
{ "###################################",
  "#     1   1   1   1   1   1       #",
  "# # # # 1 # # # # # # # 1 # # # # #",
  "#     1       1   1   1      1    #",
  "# # # 1 1 # 1 # # # 1 # # # # # # #",
  "#     1   1       1   1   1  1    #",
  "# # # # # # # # # # # # # # # # # #",
  "#     1   1   1   1   1   1  1    #",
  "# # # # # # 1 # # # # # # # # # # #",
  "#     1       1   1   1   1  1    #",
  "# # # # # # # # # # 1 # 1 # 1 # # #",
  "#     1   1   1   1   1           #",
  "# # # # # # 1 # 1 #  1 # 1 # # 1# #",
  "#&    1   1   1   1          1    #",
  "###################################"
		
		
		
		
		
		
		

};

int PoleHeight;   // = 15
int PoleWidth;    // = 35

int PoleRow = 3; // по строке
int PoleCol = 8; // по столбцу

vector < BasePlayer*> lstPlayers;
int cntPlayer = 1;
int cntEnemy = 10;
bool isPause = false;
bool isGameOver = false;
bool isGameStart = false;
bool isWin = false;
int cntWin = 0;
int cntLost = 0;

// прототипы функций
void StartGame();       // ф-ция для запуска новой игры
//GetCoordHero();       // Функция для получения координаты главного игрока
//GetCoordEnemys();     // Функция для получения координат противников
void Menu();
void DrawPole();         // функция вывода игрового поля на экран
void InitNewGame();
int main()
{
	system("chcp 65001 > nul"); //setlocale(LC_ALL, "RUSSIAN");
	//system("chcp 866 > nul"); //setlocale(LC_ALL, "C");

	// вычисление высоты игрового поля:
	//   размер всего поля / размер одной строки
	PoleHeight = sizeof(Pole) / sizeof(Pole[0]);
	PoleWidth = Pole[0].size(); // ширина строки поля
	// MainMenu(); // Главное меню игры
	InitNewGame();
	Menu();
	StartGame();     // ф-ция для запуска новой игры
	// ContinueGame();  // ф-ция для продолжения игры после паузы
	// Settings();      // настройки
	// About();         // об авторах

	cin.get(); cin.get();
} // main()

void InitNewGame()
{
	for (size_t i = 0; i < lstPlayers.size(); i++)
		delete lstPlayers[i];
	lstPlayers.clear();
	cntEnemy = 0;
	for (int row = 0; row < PoleHeight; row++)
	{
		for (int col = 0; col < PoleWidth; col++)
		{
			if (Pole[row][col] == '@')
			{
				BasePlayer* temp = new Enemy;
				temp->SetRowCol(row, col);
				lstPlayers.push_back(temp);
				//lstPlayers.insert(begin(lstPlayers), temp);
				cntEnemy++;
			}
			if (Pole[row][col] == '&')
			{
				BasePlayer* temp = new Player;
				temp->SetRowCol(row, col);
				lstPlayers.insert(begin(lstPlayers), temp);
				//cntPlayer++

			}
		}
	}
	isGameOver = false;
	isWin = false;


} // InitNewGame

void StartGame()
{
	isPause = false;
	isGameStart = true;

	// получить текущую позицию игрока
	while (true) // цикл пока идет игра, завершить цикл по завершению игры
	{
		// 1) проверить нажатие клавиш
		// 2) получить код нажатой клавиши
		// 3) изменить позицию игрока, если он двигается
		// 4) движение противников
		for (size_t i = 0; i < lstPlayers.size(); i++)
		{
			lstPlayers[i]->Move(Pole);
			/*
			 if (lstPlayers[i]->IsShoot())
			 {
				 lstPlayers.append(lstPlayers[i]->Shoot());
				 BaseBullet* temp = lstPlayers[i]->Shoot();
				 lstPlayers.push_back(temp);
			 }
			*/
			lstPlayers[i]->Draw(Pole);
			if (lstPlayers[i]->IsPause())
			{
				isPause = true;
			}
		}
		// 5) перепросивока поля на экране
		DrawPole(); // вывод поля на экран
		if (isPause) { return; }


		// 6) проверка на завершение: победа или поражение
		Sleep(100);
	} // while(true)

} // StartGame()

void DrawPole()
{
	int iEn = 1;
	for (int i = 0; i < PoleHeight; i++)
	{
		// поставить курсор консоли для i-ой строки поля
		SetPos(PoleRow + i, PoleCol);

		for (int j = 0; j < PoleWidth; j++)
		{
			if (Pole[i][j] == '#') { // символ стены 
				SetColor(COLOR::black, COLOR::gray);   cout << char(177);
			}
			else if (Pole[i][j] == '?') { // дверь - переход на новый уровень
				SetColor(COLOR::black, COLOR::light_yellow);  cout << char(178);
			}
			else if (Pole[i][j] == '1') { // бонус №1
				SetColor(COLOR::black, COLOR::light_purple);  cout << '/';
			}
			else if (Pole[i][j] == '2') { // бонус №2
				SetColor(COLOR::black, COLOR::light_purple);  cout << '!';
			}
			else if (Pole[i][j] == '3') { // бонус №3
				SetColor(COLOR::black, COLOR::light_purple);  cout << char(24);
			}
			else if (Pole[i][j] == '4') { // бонус №4
				SetColor(COLOR::black, COLOR::light_purple);  cout << 'l';
			}
			else if (Pole[i][j] == '@') { // противники
				// SetColor(COLOR::black, COLOR::light_aqua);    cout << char(2); // лицо
				cout << *lstPlayers[iEn++];
				//iEn++;
			}

			else if (Pole[i][j] == '&') { // главный герой игры
				//SetColor(COLOR::black, COLOR::light_yellow);  cout << char(2);
				cout << *lstPlayers[0];
			}
			else { cout << Pole[i][j]; } // все остальные символы поля

		} // for (j : PoleWidth)
	} // for (i : PoleHeight)
} // void DrawPole()

void Menu()
{
    system("chcp 1251 > nul");
    cout << endl << endl;
    cout << " ▀█████████▄   ▄██████▄    ▄▄▄▄███▄▄▄▄   ▀█████████▄     ▄████████    ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████ ███▄▄▄▄   " << endl;
    cout << "   ███    ███ ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ███▀▀▀██▄ " << endl;
    cout << "   ███    ███ ███    ███ ███   ███   ███   ███    ███   ███    █▀    ███    ███ ███   ███   ███   ███    ███ ███   ███ " << endl;
    cout << "  ▄███▄▄▄██▀  ███    ███ ███   ███   ███  ▄███▄▄▄██▀   ▄███▄▄▄      ▄███▄▄▄▄██▀ ███   ███   ███   ███    ███ ███   ███ " << endl;
    cout << " ▀▀███▀▀▀██▄  ███    ███ ███   ███   ███ ▀▀███▀▀▀██▄  ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ███   ███   ███ ▀███████████ ███   ███ " << endl;
    cout << "   ███    ██▄ ███    ███ ███   ███   ███   ███    ██▄   ███    █▄  ▀███████████ ███   ███   ███   ███    ███ ███   ███ " << endl;
    cout << "   ███    ███ ███    ███ ███   ███   ███   ███    ███   ███    ███   ███    ███ ███   ███   ███   ███    ███ ███   ███ " << endl;
    cout << " ▄█████████▀   ▀██████▀   ▀█   ███   █▀  ▄█████████▀    ██████████   ███    ███  ▀█   ███   █▀    ███    █▀   ▀█   █▀  " << endl;
    cout << "                                                                     ███    ███                                        " << endl;
    cout << endl;
    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "//////////////////////////////******////////////////////" << endl;
    cout << "/(///(/////////////////////, .@@@@@&  //////////////////" << endl;
    cout << "///(///(/////(/////////////, .@#         .//////////////" << endl;
    cout << "/////(///%%(///////////////,      @@@@@@@%    //////////" << endl;
    cout << "/////%%%%@@&%(///////////,   .@@@@@@@@@@@@@@@&  ////////" << endl;
    cout << "///(/%%@@. ////(///////, .@@@&%%%%%%%%%%%%%%@@@%  //////" << endl;
    cout << "/(///(/%%//. ./////////, .@&%%%#  %%%%%&  %%%%@%  //////" << endl;
    cout << "/////(/////. ,/////////, .@&%%%#  %%%%%&  %%%%@%  //////" << endl;
    cout << "///(/////        */////, .@&%%%#  %%%%%%  %%%%@%  //////" << endl;
    cout << "/////. @@@@@@        ,///, .@@@@@@@@@@@@@@@@@&  ////////" << endl;
    cout << "/////    #@          ./, .@/                  @%  //////" << endl;
    cout << "/////                  ,@@@/ ./////////////*  @@@&  ////" << endl;
    cout << "/////                  ,@  *//////////////////  @&  ////" << endl;
    cout << "///////..          **....  ......,%%%%%#......  ....  //" << endl;
    cout << "/////////////////////      (@@@#/////////(@@@&        //" << endl;
    cout << "/////////////////////////. (@@@@@*     .@@@@@&  ////////" << endl;
    cout << "/////////////////////////.         ./,          ////////" << endl;
    cout << "/////////////////////////. */////* ./, ,//////  ////////" << endl;
    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "" << endl;
    int mRow = 16, mCol = 80;
    int Select = 0;
    int selColorFon = COLOR::white;
    int selColorSym = COLOR::blue;
    int defColorFon = COLOR::black;
    int defColorSym = light_yellow;

    for (;;) {
        int i = 0;

        if (Select == i) SetColor(selColorFon, selColorSym);
        else            SetColor(defColorFon, defColorSym);
        SetPos(mRow + i++, mCol);
        cout << "   Начать игру   ";

        if (Select == i) SetColor(selColorFon, selColorSym);
        else            SetColor(defColorFon, defColorSym);
        SetPos(mRow + i++, mCol);
        cout << " Статистика игры ";

        if (Select == i) SetColor(selColorFon, selColorSym);
        else            SetColor(defColorFon, defColorSym);
        SetPos(mRow + i++, mCol);
        cout << "   Об Авторе  ";

        if (Select == i) SetColor(selColorFon, selColorSym);
        else            SetColor(defColorFon, defColorSym);
        SetPos(mRow + i++, mCol);
        cout << "      Выход       ";

        SetColor(black, white);

        int MaxSelect = i - 1;

        int key = _getch();
        if (key == _KEY::CURSOR1 || key == _KEY::CURSOR2) { key = _getch(); }
        while (_kbhit()) { _getch(); }
        switch (key)
        {
        case _KEY::UP:
        case _KEY::LEFT:
            if (Select > 0) Select--;
            else Select = MaxSelect;
            break;

        case _KEY::DOWN:
        case _KEY::RIGHT:
            if (Select < MaxSelect) Select++;
            else Select = 0;
            break;

        case _KEY::ENTER:
        {
            switch (Select)
            {
            case 0:
                system("cls");
                StartGame();
            case 1:
                system("cls");
                SetPos(1, 2); cout << "Рекорд :";
                SetPos(2, 2);
                cout << "Нажмите ENTER, чтобы вернуться назад" << endl;
                do
                {
                    key = _getch();
                } while (key != _KEY::ENTER);
                while (_kbhit()) { _getch(); }
                system("cls");
                Menu();

            case 2:
            {

                system("cls");
                SetPos(1, 2);
                cout << "Утешев Асхат. Экзаменационное задание " << endl;
                cout << "Нажмите ENTER, чтобы вернуться назад" << endl;
                do {
                    key = _getch();
                } while (key != _KEY::ENTER);
                while (_kbhit()) { _getch(); }
                system("cls");
                Menu();
                SetPos(8, 8);
                system("pause");
                system("cls");
                break;
            }
            case 5: cout << "Выход";
                exit(0);
                system("pause > nul");

                break;
            }

        }

        case _KEY::ESC:
            system("cls");
            exit(0);
            break;

        }
    }
};

