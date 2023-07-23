#include "square.h"
#include "keyboard.h"
#include <conio.h>
#include <iostream>
using namespace std;

square::square() {
	key_left = KEY_ARROW_LEFT;
}

//уменьшить
void square::decrease() {

}

//увеличить
void square::increase() {

}

//переместить влево
void square::move_left() {
	cout << "left\n";
}

//переместить вправо
void square::move_right() {

}

//переместить вверх
void square::move_up() {

}

//переместить вниз
void square::move_down() {

}

// Обработчик нажатых клавиш
void square::handler(int key) {
	if (key == key_left) {
		move_left();
	}
	else if (key == KEY_F1) {
		int key;		// Код нажатой клавиши
		for (;;) {
			if (kbhit()) {// Если нажата клавиша
				key = getch();// Какая клавиша нажата?
				if (kbhit()) {// Если нажата клавиша
					key = getch();// Какая клавиша нажата?
				}
				key_left = key;
				break;
			}
		}
	}
}