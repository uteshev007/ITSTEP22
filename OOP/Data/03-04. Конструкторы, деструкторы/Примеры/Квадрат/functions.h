#pragma once
/*
	***********************************************
	*	Заголовочный файл с функциями WIN API	  *
	*	Версия: 0.01							  *
	*	Автор: СтаценкоА						  *
	*	email: admin@saa.kz						  *
	*	Дата создания: 03.04.2017 19:38			  *
	***********************************************
	*	Готовность данной версии: 100%			  *
	***********************************************
	*	SetColor - Смена цвета для рисования в	  *
	*			консоли							  *
	***********************************************
	*	SetConsoleColor - Объединение цвета		  *
	*			фона и цвета текста для SetColor  *
	*	Нерекомендуемая deprecated функция		  *
	*	в связи с добавлением более удобного	  *
	*	решения color.h							  *
	***********************************************
	*	SetPosMain - Смена позиции в стиле		  *
	*			WIN API							  *
	***********************************************
	*	SetPos - Смена позиции путём указания	  *
	*			позиции по Х и Y				  *
	***********************************************
	*	CursorHide - Скрытие каретки/курсора	  *
	***********************************************
	*	CursorShow - Отображение каретки/курсора  *
	***********************************************
	*	color - перечесление с 16 консольными	  *
	*			цветами							  *
	***********************************************

*/
#include <Windows.h>

// Функция для выбора цвета
void SetColor(WORD wAttributes) {// функция для смена цвета
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

// Функция для выбора позиции
void SetPosMain(COORD dwCursorPosition) {// функция для установки позиции каретки по координатам
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
}

// Функция для выбора позиции
void SetPos(int x, int y) {
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetPosMain(cd);
}

// Функция для скрытия каретки
void CursorHide() {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	// Get console handle
	hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// Hide console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(hOUTPUT, &cursorInfo);
}

// Функция для отображения каретки
void CursorShow() {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	// Get console handle
	hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// Hide console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 1;
	SetConsoleCursorInfo(hOUTPUT, &cursorInfo);
}

// Устанавливаем цвет текста и фона
int SetConsoleColor(int symbolColor, int backgroundColor) {
	int consoleColor = symbolColor | (backgroundColor << 4);
	return consoleColor;
}
/*
0x1			0x7
0000 0001	0000 0111
0000 0001	0111 0000

0000 0001
|0111 0000
----------
0111 0001

*/

