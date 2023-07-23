#include <iostream> 
using namespace std;

class Base {
public:
	Base() { cout << "Создание Base-объекта.\n"; }
	~Base() { cout << "Разрушение Base-объекта.\n"; }
};

class Derived1 : public Base {
public:
	Derived1() { cout << "Создание Derived1-объекта.\n"; }
	~Derived1() { cout << "Разрушение Derived1-объекта.\n"; }
};

class Derived2 : public Derived1 {
public:
	Derived2() { cout << "Создание Derived2-oбъeктa.\n"; }
	~Derived2() { cout << "Разрушение Derived2-oбъeктa.\n"; }
};


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	{
		Derived2 ob;
		// Создание и разрушение объекта ob.

		// Никаких действий, кроме создания и разрушения объекта ob.
	}
	system("pause");
	return 0;
}

