#include "Game.h"

Game::Game() { Init(); }

// ����� ����
void Game::Start(bool isNewGame) {
  if (isNewGame || isGameOver) {
    Init();
  }
  Logic();
}

void Game::Init() {
  // ������� ����
  pole.Create(Rows, Cols);
  //Load(pole);
  isGameOver = false; // ����� ����
  // ���-�� ���������� ����
  cntEnemyLite = 3; 
  cntEnemyMiddle = 2;
  cntEnemyHeave = 1;
  cntPlayers = 1;   // �� ��������� ���� �����
  // ������ �����������
  // ������� ������� ��������
  for (BaseTank* p : enemy) { delete p; }
  enemy.clear();
  // �������� ������ �������� �����������
  for (size_t i = 0; i < cntEnemyLite; ++i) {
    enemy.push_back(new TankLite); 
  }
  // �������� ������� �������� �����������
  for (size_t i = 0; i < cntEnemyMiddle; i++){
    enemy.push_back(new TankMiddle);
  }
  // �������� ������� �������� �����������
  for (size_t i = 0; i < cntEnemyHeave; i++) {
    enemy.push_back(new TankHeave);
  }
  // ������ �������
  for (BaseTank* p : players) { delete p; }
  players.clear();
  // �������� ������� �������
  for (size_t i = 0; i < cntPlayers; i++) {
    players.push_back(new TankPlayer);
  }
  // �������� ����� �� ������ ����
  for (BaseBullet* p : listBullet) { delete p; }
  listBullet.clear(); // �������� ��������� ������
}

void Game::Logic() {
  //while (true) {
  while (isGameOver == false) {
    // ���� ��� �����������
    /*for (size_t i = 0; i < enemy.size(); ++i) {
      BaseTank* p = enemy[i];
      p->Move(pole);
      ....
    }*/
    for (auto p : enemy) {
      p->Move(pole); // �������� ����������
      BaseBullet * temp = p->Shot(); // �������������� ���������� ���� �� �������
      if (temp != nullptr) {
        // ���� ��������� ��������� � ��������� ������ �� ����
        listBullet.push_back(temp);
      }
    }
    // ���� ��� �������
    for (auto p : players) {
      p->Move(pole); // �������� ������
      BaseBullet* temp = p->Shot(); // ��������, ��� ����� ���������
      if (temp != nullptr) {
        // ���� ����� ��������� � ��������� ������ �� ����
        listBullet.push_back(temp);
      }
    }
    // ���� ��� �����
    for (auto p : listBullet) {
      p->Move(pole); // ��������, ����� ������
      Damage(p); // �������� - ��� ������ ������ � ����-������ ��� �� ������, ������� �� ������� ����
    }
    // ������� ����� ����
    int cnt = 0;
    for (auto p : players) { if (p->IsAlive()) cnt++; }
    if (!cnt) { isGameOver = true; break; }
    cnt = 0;
    for (auto p : enemy) { if (p->IsAlive()) cnt++; }
    if (!cnt) { isGameOver = true; break; }
  } // while(isGameOver);
} // Logic()

void Game::Damage(BaseBullet* pBullet) {
  // ����� �������
}