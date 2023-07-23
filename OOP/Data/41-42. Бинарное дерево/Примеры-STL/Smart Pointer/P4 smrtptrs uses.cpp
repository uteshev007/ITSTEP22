// smrtptrs.cpp -- using three kinds of smart pointers
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s) { std::cout << "������ ������\n"; }
    ~Report() { std::cout << "������ ������\n ----------------------\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");

    {
        std::auto_ptr<Report> ps (new Report("������������� auto_ptr"));
        ps->comment();  
    }
    {
		Report* prp = new Report("������������� shared_ptr");
        std::shared_ptr<Report> ps (prp);
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps (new Report("������������� unique_ptr"));
        ps->comment();
    }

	//��� ������ ������! ������?
	{
		std::string wrong_using_string{ "��� ������ ������!" };

		std::auto_ptr<std::string> pstr(&wrong_using_string);
	}

	system("pause");
    return 0;
}
