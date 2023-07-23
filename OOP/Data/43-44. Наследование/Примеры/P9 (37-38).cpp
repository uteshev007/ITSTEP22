#include <iostream> 
using namespace std;

class Base {
protected:
	int i;
public:
	Base(int x) {
		i = x;
		cout << "�������� b�s�-�������.\n";
	}

	~Base() { cout << "���������� base1-�������.\n"; }
};

class Derived : public Base {
	int j;
public:
	// ����� derived ���������� �������� x, � �������� � ���������� ������������ ������ base. 
	Derived(int x, int y) : Base(y) {
		j = x;
		cout << "�������� derived-�������.\n";
	}

	~Derived() { cout << "���������� derived-�������.\n"; }

	void show() { cout << i << " " << j << "\n"; }
};



int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Derived ob(3, 4);
	ob.show(); // ���������� ����� 4 3 

	system("pause");
	return 0;
}

