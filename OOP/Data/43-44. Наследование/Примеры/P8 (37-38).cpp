#include <iostream> 
using namespace std;

class Base {
public:
	Base() { cout << "�������� Base-�������.\n"; }
	~Base() { cout << "���������� Base-�������.\n"; }
};

class Derived1 : public Base {
public:
	Derived1() { cout << "�������� Derived1-�������.\n"; }
	~Derived1() { cout << "���������� Derived1-�������.\n"; }
};

class Derived2 : public Derived1 {
public:
	Derived2() { cout << "�������� Derived2-o��e��a.\n"; }
	~Derived2() { cout << "���������� Derived2-o��e��a.\n"; }
};


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	{
		Derived2 ob;
		// �������� � ���������� ������� ob.

		// ������� ��������, ����� �������� � ���������� ������� ob.
	}
	system("pause");
	return 0;
}

