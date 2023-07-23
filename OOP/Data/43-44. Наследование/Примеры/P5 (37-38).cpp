#include <iostream> 
using namespace std;

class Base {
protected:
	int i, j;
public:
	void set(int a, int b) { i = a; j = b; }
	void show() { cout << i << " " << j << "\n"; }
};

// Теперь все элементы класса base будут закрыты 
// в рамках класса derived1. 
class Derived1 : private Base {
	int k;
public:
	// Вызовы этих функций вполне законны, поскольку 
	// переменные i и j являются одновременно 
	// private-членами класса derived1. 
	void setk() { k = i*j; } // OK 
	void showk() { cout << k << "\n"; }
};

// Доступ к членам i, j, set() и show() не наследуется. 
class Derived2 : public Derived1 {
	int m;
public:
	// Неверно, поскольку члены i и j закрыты в рамках
	// класса derived1.
	void setm() { m = i - j; } // ошибка
	void showm() { cout << m << "\n"; }
};


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Derived1 derv1;
	Derived2 derv2;

	derv1.set(1, 2);		// Ошибка: нельзя вызывать функцию set(). 
	derv1.show();			 // Ошибка: нельзя вызывать функцию show().

	derv2.set(3, 4);		// Ошибка: нельзя вызывать функцию set(). 
	derv2.show();			// Ошибка: нельзя вызывать функцию show().

	system("pause");
	return 0;
}
