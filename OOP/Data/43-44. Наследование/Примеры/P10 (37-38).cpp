#include <iostream> 
#include <string>

using namespace std;

class Base {
protected:
	int i;
	int j;
public:
	Base(int x, int y) {
		i = x;
		j = y;
		cout << "�������� b�s�-�������.\n";
	}
	void show() { show_base("show()"); };
	void show_base(string s="show_base()") { cout << "����� ������� "<<s<<" ������ Base:" << i << " " << j << "\n"; };

	~Base() { cout << "���������� base1-�������.\n"; }
};

class Derived : private Base {

public:
	// ����� derived ���������� �������� x, � �������� � ���������� ������������ ������ base. 
	Derived(int x, int y) : Base(x, y) {
		int k = x+y;
		cout << "�������� derived-�������."<<k<<"\n";
	}
	//using Base::show_base;


	~Derived() { cout << "���������� derived-�������.\n"; }

	void show() { 
		Base::show();
		cout <<"����� ������� show() ������ Derived:"<< i << " " << j << "\n"; 
	}
};



int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Derived ob(3, 4);
	ob.show(); // ���������� ����� 4 3 
	
	//ob.show_base();

	system("pause");
	return 0;
}

