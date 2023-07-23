#include <iostream>
#include <memory>


using namespace std;


class Base {
public:
	virtual void f() = 0;
	virtual ~Base() {};
};

class Derived :public Base {
public:
	void f() { p = new char[1024](); };
	~Derived() { if (p) delete[] p; }
private:
	char*p{ nullptr };
};

void g(Base *pb)
{
	if (!pb) return;

	pb->f();

}

constexpr int iteration_number = 1000000;

int main()
{

	cout << "Start" << endl;

	for (int i = 0; i < iteration_number; ++i)
	{
		Base* pb = new Derived() ;
		g(pb);
		//...
	}

	cout << "Finish" << endl;


	system("PAUSE");
	return 0;
}