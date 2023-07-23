//
// Tank.h
//
#pragma once
#include <iostream>
using namespace std;

#define DIR_CNT   4 // кол-во направлений для изобр. танчика
#define TANK_ROWS 3 // высота танчика в строках
#define TANK_COLS 3 // длина танчика в символах

// вид танчика по умолчанию
char allImage[DIR_CNT][TANK_ROWS][TANK_COLS + 1] = {
  { // left
    {" ##"},
    {"-@@"},
    {" ##"},
  },
  {  // right
    {"## "},
    {"@@-"},
    {"## "},
  },
  { // up
    {" | "},
    {"#@#"},
    {"#@#"},
  },
  { // down
    {"#@#"},
    {"#@#"},
    {" | "},
  },
}; // char allImage[4][3][3 + 1];

// класс для изображения танчика
class Image {
protected:
  char img[DIR_CNT][TANK_ROWS][TANK_COLS + 1];
public:
  Image() { setImg(allImage); }
  Image( const char texture[DIR_CNT][TANK_ROWS][TANK_COLS + 1] ) {
    setImg(texture);
  }
  void setImg(const char texture[DIR_CNT][TANK_ROWS][TANK_COLS + 1]) {
    for (int i = 0; i < DIR_CNT; ++i) {
      for (int j = 0; j < TANK_ROWS; ++j) {
        strcpy_s(img[i][j], TANK_COLS + 1, texture[i][j]);
      }
    }
  }
  char* operator[](int dir) {return (char*)img[dir];}
};

// базовый класса танчика
class BaseTank {
public:
  enum Direct { left, right, up, down, MAX_DIR };
protected:
  Image   img; // образ танчика
  int     x, y; // координаты танчика на поле - относительно поля
  int     xOld, yOld; // старые координаты
  int     Health; // жизнь
  bool    isActive; // активный (видимый) танчик на поле
  float   Speed;  // скорость танчика
  Direct  dir;    // направление танчика
  bool    isStop; // флаг о том, что танчик стоит или движется
public:
  BaseTank();
  BaseTank(const Image& img, int xStart, int yStart);
  virtual void Move(); // перемещение
  virtual void Shot(); // выстрел
  virtual bool Damage(int dam); // получение урона, если попали
  virtual void Draw(/*Pole& gamePole*/); // прорисовка танчика на поле
  virtual bool IsAlive() const { return Health > 0; }
};

