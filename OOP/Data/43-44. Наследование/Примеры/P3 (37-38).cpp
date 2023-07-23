#include <iostream> 
using namespace std;

class Base {
protected:
	int i, j; // ��� ����� ������� � ������ base, �� �������� ��� ������ derived.
public:
	void set(int a, int b) { i = a; j = b; }
	void show() { cout << i << " " << j << "\n"; }
};

class Derived : public Base {
	int k;
public:
	// ����� derived ����� ������ � ������ ������ base i � j.
	void setk() { k = i*j; }
	void showk() { cout << k << "\n"; }
};

int main()
{
	Derived derv;
	derv.set(2, 3);	// OK, ������ derived ��� ���������. 
	derv.show();		// OK, ������ derived ��� ���������.
	derv.setk();
	derv.showk();
	system("pause");
	return 0;
}
