#include <iostream>
#include "square.h"
#include <conio.h>
using namespace std;



int main() {
	int key;		// ��� ������� �������
	square sqr;		// �������
	for (;;) {
		if (kbhit()) {// ���� ������ �������
			key = getch();// ����� ������� ������?
			sqr.handler(key);// ��� ����������� �������� ������������ �������
			// �������
			// ���� ���������� ������, �� ������� ���� ������� ������
#ifdef _DEBUG
			cout << key << " ";
#endif
		}
	}

	cin.get();
}