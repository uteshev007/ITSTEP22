
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T>  
class TooBig
{
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; } // �������������� ������ ���������� �������� operator()()
};

void outint(int n) {std::cout << n << " ";}

int main()
{
    using std::list;
    using std::cout;
    using std::endl;
	using std::for_each;
	using std::remove_if;

	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");
	//system("pause");

    TooBig<int> f100(100); // ����������� = 100
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10); // ����������� ���������������� � ������� ���������
    list<int> etcetera(vals, vals + 10);
 
 // C++0x ����� ������������ ������ �����
//  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
//  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    cout << "�������������� ������:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    yadayada.remove_if(f100);               // ������������� ��������������� ������� (��������)
    etcetera.remove_if(TooBig<int>(200));   // �������� � ������������� ������ ��������������� ������� (��������)
    
	cout <<"������������������ ������:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);

    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    
	system("pause");
    return 0;
}
