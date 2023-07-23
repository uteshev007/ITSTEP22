// fowl.cpp  -- auto_ptr a poor choice
#include <iostream>
#include <string>
#include <memory>
using namespace std;

unique_ptr<string> demo(const char * s)
{
	unique_ptr<string> temp(new string(s));
	return temp;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");



	unique_ptr<string> ps1, ps2;
	ps1 = demo("Uniquely special");
	ps2 = move(ps1); // делает возможным присваивание 
	ps1 = demo(" and more");
	cout << *ps2 << *ps1 << endl;


	system("pause");
    return 0;
}
