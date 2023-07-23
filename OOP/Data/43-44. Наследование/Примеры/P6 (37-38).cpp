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

// Ќаследуем класс base как protected-класс. 
class Derived : protected Base {
public:
	void setj(int a) { j = a; } // j Ч здесь protected-член 
	void setk(int a) { k = a; } // k Ч здесь protected-член 
	int getj() { return j; }
	int getk() { return k; }
	//void show() { cout << i << endl; } // i не доступно
};



int main()
{
	setlocale(LC_ALL, "RUSSIAN");


	Derived drv;
	/* —ледующа€ строка неправомочна, поскольку функци€ seti() €вл€етс€ protected-членом класса derived, что делает ее недоступной за его пределами. */
	// ob.seti (10);
	// cout << ob.geti(); // Ќеверно, поскольку функци€ geti() Ч protected-член.
	//ob.k=10; // Ќеверно, поскольку переменна€ k Ч protected-член.

	// —ледующие инструкции правомочны.
	drv.setk(10);
	cout << drv.getk() << ' ';
	drv.setj(12);
	cout << drv.getj() << ' ';
	cout << endl;


	system("pause");
	return 0;
}
