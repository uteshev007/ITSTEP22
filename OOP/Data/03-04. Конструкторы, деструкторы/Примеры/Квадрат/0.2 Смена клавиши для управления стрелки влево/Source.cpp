#include <iostream>
#include "square.h"
#include <conio.h>
using namespace std;



int main() {
	int key;		// Код нажатой клавиши
	square sqr;		// Квадрат
	for (;;) {
		if (kbhit()) {// Если нажата клавиша
			key = getch();// Какая клавиша нажата?
			sqr.handler(key);// Даём возможность квадрату обрабатывать нажатые
			// клавиши
			// Если отладочная сборка, то выводим коды нажатых клавиш
#ifdef _DEBUG
			cout << key << " ";
#endif
		}
	}

	cin.get();
}