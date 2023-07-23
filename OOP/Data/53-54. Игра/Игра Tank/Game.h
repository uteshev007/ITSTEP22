//
// Game
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include "Tank.h"       // �����
#include "BaseBullet.h" // ������
using namespace std;

// ����� ���� ����
class Pole {
private:
  vector<string> canvas; // ���������� ������� �������� ����
  int Height, Width;
public:
  Pole() : Height(), Width() { Create(30, 60); }
  void Create(int height, int width) {
    canvas.clear();
    Height = height;
    Width = width;
    canvas.resize(height);
    for (auto& s : canvas) { //for (string& s : canvas)
      s.resize(width, ' ');
    }
  }
  void Load(const string& FileName) {}
};

// ������� ����� ���� Tank
class Game {
private:
  Pole  pole; // ������� ����
  vector<BaseTank*> enemy;    // ������ �����������
  vector<BaseTank*> players;  // ������ �������
  // 
  size_t cntEnemyLite, cntEnemyMiddle, cntEnemyHeave;
  size_t cntPlayers;
  bool   isGameOver;
  // ��� �����
  list<BaseBullet*> listBullet; // ������ ������� �����
  //Menu mainMenu; // ������� ���� ����

public:
  Game();
  void Start(bool isNewGame = true); // ����� ����
  void Init();  // ���� ��� ����� ���� - �����
  void Logic(); // ����� ���������� ����
  // �������� - ��� ������ ������ � ����-������ ��� �� ������, ������� �� ������� ����
  void Damage(BaseBullet * pBullet);
};

