#include <iostream> 
using namespace std;

class Base {
protected:
	int i, j;
public:
	void set(int a, int b) { i = a; j = b; }
	void show() { cout << i << " " << j << "\n"; }
};

// ������ ��� �������� ������ base ����� ������� 
// � ������ ������ derived1. 
class Derived1 : private Base {
	int k;
public:
	// ������ ���� ������� ������ �������, ��������� 
	// ���������� i � j �������� ������������ 
	// private-������� ������ derived1. 
	void setk() { k = i*j; } // OK 
	void showk() { cout << k << "\n"; }
};

// ������ � ������ i, j, set() � show() �� �����������. 
class Derived2 : public Derived1 {
	int m;
public:
	// �������, ��������� ����� i � j ������� � ������
	// ������ derived1.
	void setm() { m = i - j; } // ������
	void showm() { cout << m << "\n"; }
};


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Derived1 derv1;
	Derived2 derv2;

	derv1.set(1, 2);		// ������: ������ �������� ������� set(). 
	derv1.show();			 // ������: ������ �������� ������� show().

	derv2.set(3, 4);		// ������: ������ �������� ������� set(). 
	derv2.show();			// ������: ������ �������� ������� show().

	system("pause");
	return 0;
}
