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
		cout << "Создание bаsе-объекта.\n";
	}
	void show() { show_base("show()"); };
	void show_base(string s="show_base()") { cout << "Вызов функции "<<s<<" класса Base:" << i << " " << j << "\n"; };

	~Base() { cout << "Разрушение base1-объекта.\n"; }
};

class Derived : private Base {

public:
	// Класс derived использует параметр x, а параметр у передается конструктору класса base. 
	Derived(int x, int y) : Base(x, y) {
		int k = x+y;
		cout << "Создание derived-объекта."<<k<<"\n";
	}
	//using Base::show_base;


	~Derived() { cout << "Разрушение derived-объекта.\n"; }

	void show() { 
		Base::show();
		cout <<"Вызов функции show() класса Derived:"<< i << " " << j << "\n"; 
	}
};



int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Derived ob(3, 4);
	ob.show(); // отображает числа 4 3 
	
	//ob.show_base();

	system("pause");
	return 0;
}

