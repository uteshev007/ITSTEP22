#pragma once
class square {
	int X, Y;	// Координаты квадрата
	int size;	// Размеры квадрата
	int key_decrease;
	int key_increase;
	int key_left;
	int key_right;
	int key_up;
	int key_down;
	void decrease();//уменьшить
	void increase();//увеличить
	void move_left();//переместить влево
	void move_right();//переместить вправо
	void move_up();//переместить вверх
	void move_down();//переместить вниз
public:
	void handler(int key);	// Обработчик нажатых клавиш
};