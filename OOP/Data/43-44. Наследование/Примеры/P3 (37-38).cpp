#include <iostream> 
using namespace std;

class Base {
protected:
	int i, j; // Эти члены закрыты в классе base, но доступны для класса derived.
public:
	void set(int a, int b) { i = a; j = b; }
	void show() { cout << i << " " << j << "\n"; }
};

class Derived : public Base {
	int k;
public:
	// Класс derived имеет доступ к членам класса base i и j.
	void setk() { k = i*j; }
	void showk() { cout << k << "\n"; }
};

int main()
{
	Derived derv;
	derv.set(2, 3);	// OK, классу derived это позволено. 
	derv.show();		// OK, классу derived это позволено.
	derv.setk();
	derv.showk();
	system("pause");
	return 0;
}
