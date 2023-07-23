#include <iostream> 
using namespace std;

class Base {
public:
	int i, j;

	void set(int a, int b) { i = a; j = b; }
	void show() { cout << i << " " << j << "\n"; }
};

class Derived : public Base {
	int k;
public:
	Derived(int x) { k = x; }
	//void set2(int a, int b) { set(a, b); }
	//void show2() { show(); }
	void showk() { cout << k << "\n"<<i<<j<<endl; }
};

int main()
{
	Derived derv(3);
	derv.set(1, 2); // доступ к членам класса base 
	derv.show(); // доступ к членам класса base
	derv.showk(); // доступ к члену класса derived
	system("pause");
	return 0;
}
