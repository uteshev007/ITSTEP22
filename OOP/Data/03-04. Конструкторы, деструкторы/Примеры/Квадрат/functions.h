#pragma once
/*
	***********************************************
	*	������������ ���� � ��������� WIN API	  *
	*	������: 0.01							  *
	*	�����: ���������						  *
	*	email: admin@saa.kz						  *
	*	���� ��������: 03.04.2017 19:38			  *
	***********************************************
	*	���������� ������ ������: 100%			  *
	***********************************************
	*	SetColor - ����� ����� ��� ��������� �	  *
	*			�������							  *
	***********************************************
	*	SetConsoleColor - ����������� �����		  *
	*			���� � ����� ������ ��� SetColor  *
	*	��������������� deprecated �������		  *
	*	� ����� � ����������� ����� ��������	  *
	*	������� color.h							  *
	***********************************************
	*	SetPosMain - ����� ������� � �����		  *
	*			WIN API							  *
	***********************************************
	*	SetPos - ����� ������� ���� ��������	  *
	*			������� �� � � Y				  *
	***********************************************
	*	CursorHide - ������� �������/�������	  *
	***********************************************
	*	CursorShow - ����������� �������/�������  *
	***********************************************
	*	color - ������������ � 16 �����������	  *
	*			�������							  *
	***********************************************

*/
#include <Windows.h>

// ������� ��� ������ �����
void SetColor(WORD wAttributes) {// ������� ��� ����� �����
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

// ������� ��� ������ �������
void SetPosMain(COORD dwCursorPosition) {// ������� ��� ��������� ������� ������� �� �����������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
}

// ������� ��� ������ �������
void SetPos(int x, int y) {
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetPosMain(cd);
}

// ������� ��� ������� �������
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

// ������� ��� ����������� �������
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

// ������������� ���� ������ � ����
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

