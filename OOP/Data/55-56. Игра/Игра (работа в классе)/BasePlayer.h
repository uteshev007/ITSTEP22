//
// BasePlayer.h
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Win10.h"
using namespace std;

// Направления
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
  char Sym;     // символ для игрока - для вывода
  char SymMap;  // символ для игрока - на карте
  int  clrFon, clrSym; // цвет фона, цвет символа
public:
  Image() : Sym(char(1)), SymMap('@'),
    clrFon(COLOR::black), clrSym(COLOR::yellow) {}
  // Image img(char(2), '@', blue, black);
  Image(char s, char sMap, int color, int fon = black)
    : Sym(s), SymMap(sMap), clrFon(fon), clrSym(color) {}

  void SetSym(char s, char sMap) {
    Sym = s;       // для экрана
    SymMap = sMap; // для карты
  }
  char GetSym()    const { return Sym; }    // для экрана
  char GetSymMap() const { return SymMap; } // для карты

  void SetColor(int color, int fon = COLOR::black) {
    clrSym = color; // цвет символа
    clrFon = fon;   // цвет заднего фона
  }
  int GetSymCol()const { return clrSym; }
  int GetSymFon()const { return clrFon; }
  // os << Player.Img
  friend ostream& operator << (ostream& os,
                       const Image& obj)
  {
    // ::SetColor() - вызов ф-ции из глобальной, безымянной области
    ::SetColor(obj.clrFon, obj.clrSym);
    os << obj.Sym;  // для экрана
    return os;
  }
}; // class Image;

class BasePlayer {
protected:
  string  Name;
  int     Row, Col;       // координаты игрока
  int     OldRow, OldCol; // стар. коорд.
  Image   Img;        // внешний вид игрока
  int     HPLife;     // жизни (3, %)
  Direct  Dir;        // текущее направление игрока
  int     Damage;     // урон от игрока
  bool    isShoot;    // для выстрела
  int     Score;      // очки
  bool    isPause;    // для паузы
public:
  BasePlayer() : Row(), Col(), OldRow(), OldCol(),
    Img(char(2), '@', COLOR::light_aqua),
    HPLife(1), Dir(Direct::Left), Damage(1),
    isShoot(false), Score(), isPause(false) {}
  // виртуальный деструктор класса
  virtual ~BasePlayer() {}
  //virtual ~BasePlayer() = 0; // тогда класс абстрактный

  // cout << Players[i];
  friend ostream& operator <<(ostream& os,
                        const BasePlayer& obj)
  {
    os << obj.Img;
    return os;
  }
  // Будет ли пауза?
  virtual bool IsPause() const { return isPause; }
  // Жив ли игрок?
  virtual bool IsAlive() const { return HPLife > 0; }
  // установка координат
  virtual void SetRowCol(int row, int col) {
    Row = OldRow = row;
    Col = OldCol = col;
  }
  virtual int GetRow() const { return Row; }
  virtual int GetCol() const { return Col; }

  virtual void Move(string Pole[])
  {
    //Dir = Direct(rand() % Direct::MAX_Dir);
    Direct mas[Direct::MAX_Dir]; // список возможных направлений
    int cntDir{}; // int cntDir = 0; - счетчик возможных направлений
    if (Pole[Row][Col - 1] != '#' && Pole[Row][Col - 1] != '?') { mas[cntDir++] = Direct::Left; }
    if (Pole[Row][Col + 1] != '#' && Pole[Row][Col + 1] != '?') { mas[cntDir++] = Direct::Right; }
    if (Pole[Row - 1][Col] != '#' && Pole[Row - 1][Col] != '?') { mas[cntDir++] = Direct::Up; }
    if (Pole[Row + 1][Col] != '#' && Pole[Row + 1][Col] != '?') { mas[cntDir++] = Direct::Down;  }

    //if (Pole[Row][Col - 1] == ' ') { mas[cntDir++] = Direct::Left; }
    //if (Pole[Row][Col + 1] == ' ') { mas[cntDir++] = Direct::Right; }
    //if (Pole[Row - 1][Col] == ' ') { mas[cntDir++] = Direct::Up; }
    //if (Pole[Row + 1][Col] == ' ') { mas[cntDir++] = Direct::Down;  }

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
  // прорисовка игрока на карте поля
  virtual void Draw(string Pole[])
  {
    Pole[OldRow][OldCol] = ' '; // Img.Blank(); // удаляем из старой позиции
    Pole[Row][Col]       = Img.GetSymMap(); // в новой позиции
    // обновляем текущие координаты
    OldRow = Row;
    OldCol = Col;
  }
  // Хочет ли игрок сделать выстрел
  virtual bool IsShoot() const { return isShoot; }
  // метод - собственно выстрел
  //virtual BaseBullet * Shoot(){}

}; // class BasePlayer


class Enemy : virtual public BasePlayer
{
protected:
public:
  Enemy()
  {
    Img.SetSym( char(2), '@' );
    Img.SetColor(COLOR::white, black);
    HPLife = 1;
    Damage = 1;
    Row = OldRow = RAND(1, 10);
    Col = OldCol = RAND(1, 10);
    //Dir = (Direct)RAND(Direct::Left, Direct::Down);
    Dir = Direct(rand() % Direct::MAX_Dir);
  }
  // виртуальный деструктор для дочернего объекта
  virtual ~Enemy() override {}

}; // class Enemy;

//
class Player : virtual public BasePlayer
{
protected:
public:
  Player()
  {
    Img.SetSym( char(1), '&');
    Img.SetColor(COLOR::light_green, COLOR::black);
    HPLife = 3; // три жизни для игрока
    Damage = 1;
    Row = OldRow = RAND(1,10);
    Col = OldCol = RAND(1,10);
    Dir = Direct::Stop;
  }
  //
  virtual ~Player() override {}

  // метод движения для игрока-человека
  virtual void Move(string Pole[]) override {
    if (_kbhit()) {
      int key = _getch();

      // проверка, что нажата клавиша управления курсора
      if (key == _KEY::CURSOR1 || key == CURSOR2) {
        key = _getch(); // истинный код клавиши курсора
      }
      // сброс буфера клавиатуры - защита от "кривых" клавиатур
      while (_kbhit()) { _getch(); }

      switch (key)
      {
        case 'a': case 'A': case _KEY::LEFT: // влево
          Dir = Direct::Left;
          break;
        case 'd': case 'D': case _KEY::RIGHT: // вправо
          Dir = Direct::Right;
          break;
        case 'w': case 'W': case _KEY::UP: // вверх
          Dir = Direct::Up;
          break;
        case 's': case 'S': case _KEY::DOWN: // вниз
          Dir = Direct::Down;
          break;
        case _KEY::SPACE: case _KEY::ENTER: // выстрел
          isShoot = true; // мы хотим выстрелить
          break;
        case _KEY::ESC: // пауза - выход в главное меню
          isPause = true; // мы хотим сделать паузу
          break;
      } // switch( key )
    }
    OneStep(Pole); // сделать один шаг
  } // Move()

}; // class Player;
