#include <iostream> 
using namespace std;

class Base {
protected:
	int i, j;
public:
	void set(int a, int b) { i = a; j = b; }
	void show() { cout << i << " " << j << "\n"; }
};

// „лены i и j наследуютс€ как protected-члены. 
class Derived1 : public Base {
	int k;
public:
	void setk() { k = i*j; } // правомерный доступ 
	void showk() { cout << k << "\n"; }
};

// „лены i и j наследуютс€ косвенно через класс derived1. 
class Derived2 : public Derived1 {
	int m;
public:
	void setm() { m = i - j; } // правомерный доступ 
	void showm() { cout << m << "\n"; }
};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Derived1 der1;
	Derived2 der2;

	der1.set(2, 3);
	der1.show();
	der1.setk();
	der1.showk();

	der2.set(3, 4);
	der2.show();
	der2.setk();
	der2.setm();
	der2.showk();
	der2.showm();
	system("pause");
	return 0;
}
