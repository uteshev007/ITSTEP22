#include <iostream> 
using namespace std;

class Base {
	int i;
protected:
	int j;
public:
	int k;
	void seti(int a) { i = a; }
	int geti() { return i; }
};

// ��������� ����� base ��� protected-�����. 
class Derived : protected Base {
public:
	void setj(int a) { j = a; } // j � ����� protected-���� 
	void setk(int a) { k = a; } // k � ����� protected-���� 
	int getj() { return j; }
	int getk() { return k; }
	//void show() { cout << i << endl; } // i �� ��������
};



int main()
{
	setlocale(LC_ALL, "RUSSIAN");


	Derived drv;
	/* ��������� ������ ������������, ��������� ������� seti() �������� protected-������ ������ derived, ��� ������ �� ����������� �� ��� ���������. */
	// ob.seti (10);
	// cout << ob.geti(); // �������, ��������� ������� geti() � protected-����.
	//ob.k=10; // �������, ��������� ���������� k � protected-����.

	// ��������� ���������� ����������.
	drv.setk(10);
	cout << drv.getk() << ' ';
	drv.setj(12);
	cout << drv.getj() << ' ';
	cout << endl;


	system("pause");
	return 0;
}
