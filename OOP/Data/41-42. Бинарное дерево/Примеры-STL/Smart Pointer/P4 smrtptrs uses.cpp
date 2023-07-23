// smrtptrs.cpp -- using three kinds of smart pointers
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s) { std::cout << "Объект создан\n"; }
    ~Report() { std::cout << "Объект удален\n ----------------------\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");

    {
        std::auto_ptr<Report> ps (new Report("использование auto_ptr"));
        ps->comment();  
    }
    {
		Report* prp = new Report("использование shared_ptr");
        std::shared_ptr<Report> ps (prp);
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps (new Report("использование unique_ptr"));
        ps->comment();
    }

	//Так делать нельзя! Почему?
	{
		std::string wrong_using_string{ "Так делать нельзя!" };

		std::auto_ptr<std::string> pstr(&wrong_using_string);
	}

	system("pause");
    return 0;
}
