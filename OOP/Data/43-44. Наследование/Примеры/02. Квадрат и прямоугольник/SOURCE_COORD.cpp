#include "SOURCE_COORD.h"
using namespace std;
//! ���������� 100%
SOURCE_COORD::SOURCE_COORD(size_t posX, size_t posY) {
	setPosX(posX);
	setPosY(posY);
	// ��������� ��� ������������. �������� ������, ������, ����� ��������� ������ ���� ��������� ������ ����� ������ ��������
	// ���������� ������ ��������� ��������� ��������� ������ ������ ��������. ��� ��� ������� �� ������� �� ���� ������ :)
	minPosX = minPosY = 0;
	maxPosX = 70;
	maxPosY = 20;
}
size_t SOURCE_COORD::getPosX()const {
	return posX;
}
size_t SOURCE_COORD::getPosY()const {
	return posY;
}
void SOURCE_COORD::setPosX(size_t posX) {
	if (posX >= minPosX && posX <= maxPosX)
		this->posX = posX;
}
void SOURCE_COORD::setPosY(size_t posX) {
	if (posY >= minPosY && posY <= maxPosY)
		this->posY = posY;
}
ostream& operator<<(ostream& in, SOURCE_COORD & data) {
	data.SetPos();
	return in;
}