#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include "rectangle.h"

using namespace std;
void SetColor(WORD wAttributes) {// функция для смена цвет
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}
/*
Фигуры
Квадрат
Прямоугольник


1) Переключаться между фигурами
2) Перемещение (стрелками)
3) Изменение размеров (+, -)
*/



int main() {
	int row1=2, column1=2, row2=4, column2=3;
	char **ptr1, **ptr2;
	ptr1 = new char*[row1];
	ptr2 = new char*[row2];
	for (size_t i = 0; i < row1; i++) {
		ptr1[i] = new char[column1];
	}
	for (size_t i = 0; i < row2; i++) {
		ptr2[i] = new char[column2];
	}
	memcpy(ptr1[0], "+-", column1);
	memcpy(ptr1[1], "-+", column1);

	memcpy(ptr2[0], "/-\\", column2);
	memcpy(ptr2[1], "| |", column2);
	memcpy(ptr2[2], "| |", column2);

	figure rc(ptr1, row1, 15, 10);
	rectangle rc2(ptr2, row2, column2);

	//rc(0, "+-");
	//rc(1, "-+");

	//rc2(0, "/-\\");
	//rc2(1, "| |");
	//rc2(2, "| |");

	// Освободить занимаемую память ptr1 и ptr2

	cout << rc << rc2;

	int key;
	bool object1=true;
	for (;;) {
		if (kbhit()) {
			key=getch();
			if (key == ' ')
				object1 = !object1;
			else if (object1)
				rc.handler(key);
			else
				rc2.handler(key);
			// Добавить выход из программы
		}
	}
}