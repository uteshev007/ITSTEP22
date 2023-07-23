//
// Tank.h
//
#pragma once
#include <iostream>
using namespace std;

#define DIR_CNT   4 // ���-�� ����������� ��� �����. �������
#define TANK_ROWS 3 // ������ ������� � �������
#define TANK_COLS 3 // ����� ������� � ��������

// ��� ������� �� ���������
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

// ����� ��� ����������� �������
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

// ������� ������ �������
class BaseTank {
public:
  enum Direct { left, right, up, down, MAX_DIR };
protected:
  Image   img; // ����� �������
  int     x, y; // ���������� ������� �� ���� - ������������ ����
  int     xOld, yOld; // ������ ����������
  int     Health; // �����
  bool    isActive; // �������� (�������) ������ �� ����
  float   Speed;  // �������� �������
  Direct  dir;    // ����������� �������
  bool    isStop; // ���� � ���, ��� ������ ����� ��� ��������
public:
  BaseTank();
  BaseTank(const Image& img, int xStart, int yStart);
  virtual void Move(); // �����������
  virtual void Shot(); // �������
  virtual bool Damage(int dam); // ��������� �����, ���� ������
  virtual void Draw(/*Pole& gamePole*/); // ���������� ������� �� ����
  virtual bool IsAlive() const { return Health > 0; }
};

