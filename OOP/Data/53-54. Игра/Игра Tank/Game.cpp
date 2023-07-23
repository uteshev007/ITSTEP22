#include "Game.h"

Game::Game() { Init(); }

// новая игра
void Game::Start(bool isNewGame) {
  if (isNewGame || isGameOver) {
    Init();
  }
  Logic();
}

void Game::Init() {
  // игровое поле
  pole.Create(Rows, Cols);
  //Load(pole);
  isGameOver = false; // новая игра
  // кол-во участников игры
  cntEnemyLite = 3; 
  cntEnemyMiddle = 2;
  cntEnemyHeave = 1;
  cntPlayers = 1;   // по умолчанию один игрок
  // массив противников
  // очистка массива танчиков
  for (BaseTank* p : enemy) { delete p; }
  enemy.clear();
  // создание легких танчиков противников
  for (size_t i = 0; i < cntEnemyLite; ++i) {
    enemy.push_back(new TankLite); 
  }
  // создание средних танчиков противников
  for (size_t i = 0; i < cntEnemyMiddle; i++){
    enemy.push_back(new TankMiddle);
  }
  // создание тяжелых танчиков противников
  for (size_t i = 0; i < cntEnemyHeave; i++) {
    enemy.push_back(new TankHeave);
  }
  // массив игроков
  for (BaseTank* p : players) { delete p; }
  players.clear();
  // создание массива игроков
  for (size_t i = 0; i < cntPlayers; i++) {
    players.push_back(new TankPlayer);
  }
  // удаление пулек от старой игры
  for (BaseBullet* p : listBullet) { delete p; }
  listBullet.clear(); // удаление элементов списка
}

void Game::Logic() {
  //while (true) {
  while (isGameOver == false) {
    // цикл для противников
    /*for (size_t i = 0; i < enemy.size(); ++i) {
      BaseTank* p = enemy[i];
      p->Move(pole);
      ....
    }*/
    for (auto p : enemy) {
      p->Move(pole); // движение противника
      BaseBullet * temp = p->Shot(); // предоставление противнику шанс на выстрел
      if (temp != nullptr) {
        // если противник выстрелил и появилась пулька на поле
        listBullet.push_back(temp);
      }
    }
    // цикл для игроков
    for (auto p : players) {
      p->Move(pole); // движение игрока
      BaseBullet* temp = p->Shot(); // проверка, что игрок выстрелил
      if (temp != nullptr) {
        // если игрок выстрелил и появилась пулька на поле
        listBullet.push_back(temp);
      }
    }
    // цикл для пулек
    for (auto p : listBullet) {
      p->Move(pole); // движение, полет пульки
      Damage(p); // проверка - что пулька попала в кого-нибудь или не попала, улетела за пределы поля
    }
    // условия конца игры
    int cnt = 0;
    for (auto p : players) { if (p->IsAlive()) cnt++; }
    if (!cnt) { isGameOver = true; break; }
    cnt = 0;
    for (auto p : enemy) { if (p->IsAlive()) cnt++; }
    if (!cnt) { isGameOver = true; break; }
  } // while(isGameOver);
} // Logic()

void Game::Damage(BaseBullet* pBullet) {
  // потом сделаем
}