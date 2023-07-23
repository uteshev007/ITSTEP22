#include <iostream> 
using namespace std;

class Base {
protected:
	int i;
public:
	Base(int x) {
		i = x;
		cout << "Создание bаsе-объекта.\n";
	}

	~Base() { cout << "Разрушение base1-объекта.\n"; }
};

class Derived : public Base {
	int j;
public:
	// Класс derived использует параметр x, а параметр у передается конструктору класса base. 
	Derived(int x, int y) : Base(y) {
		j = x;
		cout << "Создание derived-объекта.\n";
	}

	~Derived() { cout << "Разрушение derived-объекта.\n"; }

	void show() { cout << i << " " << j << "\n"; }
};



int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Derived ob(3, 4);
	ob.show(); // отображает числа 4 3 

	system("pause");
	return 0;
}

