#pragma once
#include <Windows.h>
#include <iostream>
//! Готовность 100%
class SOURCE_COORD {
	size_t posX;
	size_t posY;
	// Функция для выбора позиции
	void SetPos() {// функция для установки позиции каретки по координатам
		COORD cd;
		cd.X = posX;
		cd.Y = posY;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
	}
protected:
	size_t minPosX, minPosY, maxPosX, maxPosY;
public:
	SOURCE_COORD(size_t posX = 0, size_t posY = 0);
	size_t getPosX()const;
	size_t getPosY()const;
	void setPosX(size_t posX);
	void setPosY(size_t posX);
	friend std::ostream& operator<<(std::ostream& in, SOURCE_COORD & data);
};