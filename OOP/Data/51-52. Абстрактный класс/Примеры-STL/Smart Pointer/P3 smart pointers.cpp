// random.cpp -- ������������ ������ � ��������� �����
#include <iostream>   
#include <string>
#include <memory>

using namespace std;

bool weird_thing() { return false; }

void remodel(std::string & str)
{
	std::string * ps = new std::string("���������� ������� ������");
	
	if (weird_thing())
		throw exception("weird_thing() is true");

	str = *ps;
	delete ps;

	return;
}

void remodel2(std::string & str);

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");
	string s;

	try
	{
		s= "������� ������" ;
		remodel(s);
		//remodel2(s);

	}
	catch (exception e)
	{
		cout << "����������: " << e.what() << endl;
	}

	cout << s << endl;
	system("pause");

    return 0; 
}

void remodel2(string & str)
{
	auto_ptr<string> ps(new string("���������� ������� ������"));

	if (weird_thing())
		throw exception("weird_thing() is true");

	str = *ps;
	//delete ps; �������� �� �����

	return;
}