//
// BasePlayer.h
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Win10.h"
using namespace std;

// �����������
enum Direct
{
  Stop = -1,
  Left, Right, Up, Down,
  MAX_Dir
};

//
class Image
{
private:
  char Sym; // ������ ��� ������
  int  clrFon, clrSym; // ���� ����, ���� �������
public:
  Image() : Sym(char(1)),
    clrFon(COLOR::black), clrSym(COLOR::yellow) {}
  Image(char s, int color, int fon = black)
    : Sym(s), clrFon(fon), clrSym(color) {}

  void SetSym(char s) { Sym = s; }
  char GetSym() const { return Sym; }

  void SetColor(int color, int fon = COLOR::black) {
    clrSym = color; // ���� �������
    clrFon = fon;   // ���� ������� ����
  }
  int GetSymCol()const { return clrSym; }
  int GetSymFon()const { return clrFon; }
  // os << Player.Img
  friend ostream& operator<<(ostream& os,
                       const Image& obj)
  {
    // ::SetColor() - ����� �-��� �� ����������, ���������� �������
    ::SetColor(obj.clrSym, obj.clrFon);
    os << obj.Sym;
    return os;
  }
}; // class Image;

class BasePlayer {
protected:
  string  Name;
  int     Row, Col;       // ���������� ������
  int     OldRow, OldCol; // ����. �����.
  Image   Img;        // ������� ��� ������
  int     HPLife;     // ����� (3, %)
  Direct  Dir;        // ������� ����������� ������
  int     Damage;     // ���� �� ������
  bool    isShoot;    // ��� ��������
  int     Score;      // ����
  bool    isPause;    // ��� �����
public:
  BasePlayer() : Row(), Col(), OldRow(), OldCol(),
    Img(char(2), COLOR::light_aqua),
    HPLife(1), Dir(Direct::Left), Damage(1),
    isShoot(false), Score(), isPause(false) {}
  // ����������� ���������� ������
  virtual ~BasePlayer() {}

  // cout << Players[i];
  friend ostream& operator <<(ostream& os,
                        const BasePlayer& obj)
  {
    os << obj.Img;
    return os;
  }
  // ����� �� �����?
  virtual bool IsPause() const { return isPause; }
  // ��� �� �����?
  virtual bool IsAlive() const { return HPLife > 0; }

  virtual void Move(string Pole[])
  {
    //Dir = Direct(rand() % Direct::MAX_Dir);
    Direct mas[Direct::MAX_Dir]; // ������ ��������� �����������
    int cntDir{}; // int cntDir = 0; - ������� ��������� �����������
    if (Pole[Row][Col - 1] != '#') { mas[cntDir++] = Direct::Left;  }
    if (Pole[Row][Col + 1] != '#') { mas[cntDir++] = Direct::Right; }
    if (Pole[Row - 1][Col] != '#') { mas[cntDir++] = Direct::Up;    }
    if (Pole[Row + 1][Col] != '#') { mas[cntDir++] = Direct::Down;  }
    if (cntDir > 0) {
      Dir = mas[rand() % cntDir];
      OneStep(Pole);
    }
    //else { Dir = Direct::Stop; }
  }

  virtual void OneStep(string Pole[])
  {
    if (Dir == Direct::Left && Pole[Row][Col - 1] != '#') {
      Col--;
    }
    if (Dir == Direct::Right && Pole[Row][Col + 1] != '#') {
      Col++;
    }
    if (Dir == Direct::Up && Pole[Row - 1][Col] != '#') {
      Row--;
    }
    if (Dir == Direct::Down && Pole[Row + 1][Col] != '#') {
      Row++;
    }
  }

  virtual void Draw(string Pole[])
  {
    Pole[OldRow][OldCol] = ' '; // Img.Blank(); // ������� �� ������ �������
    Pole[Row][Col]       = Img.GetSym(); // � ����� �������
    // ��������� ������� ����������
    OldRow = Row;
    OldCol = Col;
  }
  // ����� �� ����� ������� �������
  virtual bool IsShoot() const { return isShoot; }
  // ����� - ���������� �������
  //virtual BaseBullet * Shoot(){}

}; // class BasePlayer


class Enemy : virtual public BasePlayer
{
protected:
public:
  Enemy()
  {
    Img.SetSym( char(2) );
    Img.SetColor(COLOR::light_yellow, black);
    HPLife = 1;
    Damage = 1;
    Row = OldRow = RAND(1, 10);
    Col = OldCol = RAND(1, 10);
    //Dir = (Direct)RAND(Direct::Left, Direct::Down);
    Dir = Direct(rand() % Direct::MAX_Dir);
  }
  // ����������� ���������� ��� ��������� �������
  virtual ~Enemy() override {}

}; // class Enemy;

//
class Player : virtual public BasePlayer
{
protected:
public:
  Player()
  {
    Img.SetSym( char(1) );
    Img.SetColor(COLOR::light_green, COLOR::black);
    HPLife = 3; // ��� ����� ��� ������
    Damage = 1;
    Row = OldRow = RAND(1,10);
    Col = OldCol = RAND(1,10);
    Dir = Direct::Stop;
  }
  //
  virtual ~Player() override {}

  // ����� �������� ��� ������-��������
  virtual void Move(string Pole[]) override {
    if (_kbhit()) {
      int key = _getch();
      switch (key)
      {
        case 'a': case 'A': case _KEY::LEFT: // �����
          Dir = Direct::Left;
          break;
        case 'd': case 'D': case _KEY::RIGHT: // ������
          Dir = Direct::Right;
          break;
        case 'w': case 'W': case _KEY::UP: // �����
          Dir = Direct::Up;
          break;
        case 's': case 'S': case _KEY::DOWN: // ����
          Dir = Direct::Down;
          break;
        case _KEY::SPACE: case _KEY::ENTER: // �������
          isShoot = true; // �� ����� ����������
          break;
        case _KEY::ESC: // ����� - ����� � ������� ����
          isPause = true; // �� ����� ������� �����
          break;
      } // switch( key )
      OneStep(Pole); // ������� ���� ���
    }
  } // Move()

}; // class Player;
