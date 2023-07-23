#include <iostream>
#include <Windows.h>
#include <time.h>
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

	cin.get();
}