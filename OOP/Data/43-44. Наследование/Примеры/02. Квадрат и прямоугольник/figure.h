#pragma once
#include "SOURCE_COORD.h"
#include "SOURCE_DATA.h"
#include <iostream>
using namespace std;

class figure :public SOURCE_COORD {
	SOURCE_DATA data;
public:
	figure(char **pdata, size_t size, size_t posX = 0, size_t posY = 0);
	friend ostream& operator<<(ostream& out, figure&);
	
	/*
	Сторона1
	Двумерный массив символов

	####
	#**#
	#**#
	####

	Координаты

	Прорисовка
	Перемещение
	Очистка
	Инициализация двумерного массива
	Сеттеры
	Геттеры
	*/
};