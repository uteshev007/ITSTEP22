#include "square.h"
#include "keyboard.h"
#include <conio.h>
#include <iostream>
using namespace std;

square::square() {
	key_left = KEY_ARROW_LEFT;
}

//���������
void square::decrease() {

}

//���������
void square::increase() {

}

//����������� �����
void square::move_left() {
	cout << "left\n";
}

//����������� ������
void square::move_right() {

}

//����������� �����
void square::move_up() {

}

//����������� ����
void square::move_down() {

}

// ���������� ������� ������
void square::handler(int key) {
	if (key == key_left) {
		move_left();
	}
	else if (key == KEY_F1) {
		int key;		// ��� ������� �������
		for (;;) {
			if (kbhit()) {// ���� ������ �������
				key = getch();// ����� ������� ������?
				if (kbhit()) {// ���� ������ �������
					key = getch();// ����� ������� ������?
				}
				key_left = key;
				break;
			}
		}
	}
}