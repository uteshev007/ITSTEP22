#pragma once
class square {
	int X, Y;	// ���������� ��������
	int size;	// ������� ��������
	int key_decrease;
	int key_increase;
	int key_left;
	int key_right;
	int key_up;
	int key_down;
	void decrease();//���������
	void increase();//���������
	void move_left();//����������� �����
	void move_right();//����������� ������
	void move_up();//����������� �����
	void move_down();//����������� ����
public:
	void handler(int key);	// ���������� ������� ������
};