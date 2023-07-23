//
// Game
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include "Tank.h"       // танки
#include "BaseBullet.h" // пульки
using namespace std;

// класс поля игры
class Pole {
private:
  vector<string> canvas; // символьный рисунок игрового поля
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

// главный класс игры Tank
class Game {
private:
  Pole  pole; // игровое поле
  vector<BaseTank*> enemy;    // массив противников
  vector<BaseTank*> players;  // массив игроков
  // 
  size_t cntEnemyLite, cntEnemyMiddle, cntEnemyHeave;
  size_t cntPlayers;
  bool   isGameOver;
  // для пулек
  list<BaseBullet*> listBullet; // список летящих пулек
  //Menu mainMenu; // главное меню игры

public:
  Game();
  void Start(bool isNewGame = true); // новая игра
  void Init();  // иниц для новой игры - сброс
  void Logic(); // метод собственно игры
  // проверка - что пулька попала в кого-нибудь или не попала, улетела за пределы поля
  void Damage(BaseBullet * pBullet);
};

