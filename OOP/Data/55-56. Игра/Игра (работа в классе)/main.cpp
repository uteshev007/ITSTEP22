//
// main.cpp
//

#include <iostream>
#include <string>       // ��� ����� std::string
#include <vector>
#include <time.h>
#include <conio.h>      // ��� _getch(), _kbhit()
#include "Win10.h"
#include "BasePlayer.h"
using namespace std;

//
// ������� ���� - ������ ����� ���� string
// ����� ����� ���� (Canvas)
// �������: & - ������� �����; @ - ����������;
//          # - �����; 1,2,3,4 - ������;
//          * - �����;
//          ? - �����, ������� �� ��������� �������;
//
//vector<string> Pole{{"", "", ""}};

string Pole[]   // <==> char pole[15][35+1];
{
  "###################################",
  "#   #*##      @          @        #",
  "# # @  #@############## ######### #",
  "# ###### #   #*#3  @  # ##@##   # #",
  "#       @  # # ###### # #@4   #@# #",
  "###### # ### #      # # ##@##   # #",
  "##  @# # # # #### # #   ##### # # #",
  "#* #   # # @    # ##*######*#   # #",
  "######## # ####         #   # # #@#",
  "#  2#    #      ####### # # #   # #",
  "# ### #### ######       # #   #   #",
  "#  @       #      ####### #########",
  "############ ######   #1# # @ #   #",
  "#      &            #   #   #@  #B#",
  "#################################?#"
};

// ���������� �������� ����
// ������ � ������ �������� ����
int PoleHeight;   // = 15
int PoleWidth;    // = 35

// �������� ���������� ������ ���� �� �����
int PoleRow = 3; // �� ������
int PoleCol = 8; // �� �������

// ���������� ���������� ����
vector<BasePlayer*> lstPlayers; // ������, ������ �������
int cntPlayer = 1;  // ��� ������ ������
int cntEnemy  = 10; // ���-�� �����������

// ����� ����
bool isPause     = false; // ��� �����
bool isGameOver  = false; // ���� ���� ��������
bool isGameStart = false; // ���� ��������
bool isWin       = false; // ���� ���� ������ �� �������
int  cntWin      = 0;     // ���-�� �����
int  cntLost     = 0;     // ���-�� ���������


// ��������� �������
void StartGame();     // �-��� ��� ������� ����� ����
//GetCoordHero();       // ������� ��� ��������� ���������� �������� ������
//GetCoordEnemys();     // ������� ��� ��������� ��������� �����������
void DrawPole();      // ������� ������ �������� ���� �� �����
void InitNewGame();   // ������� ����-��� ����� ����

int main()
{
  //system("chcp 1251 > nul"); //setlocale(LC_ALL, "RUSSIAN");
  //system("chcp 866 > nul"); //setlocale(LC_ALL, "C");

  // ���������� ������ �������� ����:
  //   ������ ����� ���� / ������ ����� ������
  PoleHeight = sizeof(Pole) / sizeof(Pole[0]);
  PoleWidth = Pole[0].size(); // ������ ������ ����

  // ������ ���� ���� ��� �������� ���� ���������
  // while(true) {
  // MainMenu(); // ������� ���� ����

  InitNewGame();   // ����-���� ����� ����
  StartGame();     // �-��� ��� ������� ����� ����
  // ContinueGame();  // �-��� ��� ����������� ���� ����� �����
  // Settings();      // ���������
  // About();         // �� �������

  cin.get(); cin.get();
} // main()

// �-��� ����-��� ���������� ��� ����� ����
void InitNewGame()
{
  // ���� �������� ������� �� ������
  for (size_t i = 0; i < lstPlayers.size(); i++) {
    delete lstPlayers[i]; // �������� �������� �������/�����������
                          // ����� ��������� �� ������� �������
  }
  // ������ ������ ���������� �� ������� ������ �������
  lstPlayers.clear();

  cntEnemy = 0;
  // �������� ������� ������� ������/�����������
  for (int row = 0; row < PoleHeight; row++) {
    for (int col = 0; col < PoleWidth; col++) {
      if (Pole[row][col] == '@') { // ��������� ������
        BasePlayer* temp = new Enemy;
        temp->SetRowCol(row, col); // ����������
        lstPlayers.push_back(temp); // ��������� � ������
        cntEnemy++; // ������� �����������
      }
      if (Pole[row][col] == '&') { // ����� ������
        BasePlayer* temp = new Player;
        temp->SetRowCol(row, col);
        // ������ ��������� ������ � ������� �������
        lstPlayers.insert(begin(lstPlayers), temp);
        //cntPlayer++; - ���� �� ���� �����
      }
    }
  } // for (int row = 0; row < PoleHeight; row++)
  // ������ lstPlayers �������� �������� � ������������
  // ���������� ���������� ��������� ����
  isGameOver = false;
  isWin = false;

} // InitNewGame()

// ������� ������ ����� ����
void StartGame()
{
  isPause = false;    // ������ � ����������� �����
  isGameStart = true; // ������ � ������ ����

  while (true) // ���� ���� ���� ����, ��������� ���� �� ���������� ����
  {
    // 1) ��������� ������� ������
    // 2) �������� ��� ������� �������
    // 3) �������� ������� ������, ���� �� ���������
    // 4) �������� �����������
    for (size_t i = 0; i < lstPlayers.size(); i++)
    {
      //lstPlayers[i]->Move(Pole, frame); // �������� ������ c ���������� ��������
      lstPlayers[i]->Move(Pole); // �������� ������
      // ��� ��� ��������� ��������� ������� � ����
      /*if (lstPlayers[i]->IsShoot()) {
        //lstBullet.append( lstPlayers[i]->Shoot() );
        BaseBullet * temp = lstPlayers[i]->Shoot();
        lstBullet.push_back(temp);
      }*/
      // ���������� ������ �� ������� ����
      lstPlayers[i]->Draw(Pole);

      // �������� �� ����� -����� �� i-�� ����� ������� �����?
      if (lstPlayers[i]->IsPause()) { isPause = true; }
    }

    // 5) �������������� ���� �� ������
    DrawPole(); // ����� ���� �� �����
    //frame++;
    // �������� �� �����
    if (isPause) { return; /*break*/ } // ����� � ������� ����

    //if (lstPlayers[0]->IsPause()) { return; } - �� ������ �������

    // 6) �������� �� ����������: ������ ��� ���������
    // {
    //    isGameOver = true;
    //    isGameStart = false;
    //    isWin = true/false;
    //    break;
    // }
    Sleep(100); // ������� ��������� �� 100 ����������
  } // while(true)

} // StartGame()

// ������� ������ �������� ���� �� �����
void DrawPole()
{
  int iEn = 1; // ������� ��� �����������
  for (int i = 0; i < PoleHeight; i++)
  {
    // ��������� ������ ������� ��� i-�� ������ ����
    SetPos(PoleRow + i, PoleCol);

    for (int j = 0; j < PoleWidth; j++)
    {
      if (Pole[i][j] == '#') { // ������ ����� 
        SetColor(COLOR::black, COLOR::light_green);
        cout << char(177);
      }
      else if (Pole[i][j] == '?') { // ����� - ������� �� ����� �������
        SetColor(COLOR::black, COLOR::light_yellow);  cout << char(178);
      }
      else if (Pole[i][j] == '1') { // ����� �1
        SetColor(COLOR::black, COLOR::light_purple);
        cout << '/';
      }
      else if (Pole[i][j] == '2') { // ����� �2
        SetColor(COLOR::black, COLOR::light_purple);
        cout << '!';
      }
      else if (Pole[i][j] == '3') { // ����� �3
        SetColor(COLOR::black, COLOR::light_purple);
        cout << char(24);
      }
      else if (Pole[i][j] == '4') { // ����� �4
        SetColor(COLOR::black, COLOR::light_purple);  cout << 'l';
      }
      else if (Pole[i][j] == '@') { // ����������
        //SetColor(COLOR::black, COLOR::light_aqua);
        //cout << char(2); // ����
        cout << *lstPlayers[iEn++]; // ����� ���������� � ����� �������
        //iEn++;
      }
      else if (Pole[i][j] == 'B') {
        SetColor(COLOR::black, COLOR::bright_white);  cout << char(1);
      }
      else if (Pole[i][j] == '*') {
        SetColor(COLOR::black, COLOR::light_red);     cout << char(3);
      }
      else if (Pole[i][j] == '&') { // ������� ����� ����
        //SetColor(COLOR::black, COLOR::light_yellow);
        //cout << char(2);
        cout << *lstPlayers[0]; // ����� ������ � ����� �������
      }
      else { cout << Pole[i][j]; } // ��� ��������� ������� ����

    } // for (j : PoleWidth)
  } // for (i : PoleHeight)
} // void DrawPole()
