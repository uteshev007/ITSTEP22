#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
void SetColor(WORD wAttributes) {// ������� ��� ����� ����
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, wAttributes);
}
/*
������
�������
�������������


1) ������������� ����� ��������
2) ����������� (���������)
3) ��������� �������� (+, -)
*/



int main() {

	cin.get();
}