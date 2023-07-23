#include <iostream>
using namespace std;

struct Elem
{
	int data;					//������
	Elem * next;				//��������� �� ��������� �������
	Elem * prev;				//��������� �� ���������� �������
};

class List
{
	Elem * head, *tail;			//������, �����
	int count;					//���������� ���������

public:
	
	List();						//�����������
	~List();					//����������
	void del_all();				//�������� ���� ���������
	
	void add_tail(int n);		//���������� � ����� ������
	void add_head(int n);		//���������� � ������ ������
	void del_from_head();		//�������� �������� �� ������
	void del_from_tail();		//�������� �������� �� ������
	void print();				//������ ������
	void del(int pos = 0);		//�������� ��������, ���� ��������
								//�� �����������,
								//�� ������� ��� �����������

};

List::List()
{
}

List::~List()
{

}
void List::add_head(int n)
{

}
void List::add_tail(int n)
{
	
}
void List::del(int pos)
{
	//���� �������� ����������� ��� ����� 0,
	//�� ����������� ���
	
}

void List::del_from_head() {

}

void List::del_from_tail() {

}

void List::print()
{
	//���� � ������ ������������ ��������,
	//�� ��������� �� ����
	//� �������� ��������, ������� � ���������

}

void List::del_all()
{
	//���� �������� ��������, ������� �� ������ � ������

}


//�������� ������
void main()
{
	List lst;
	const int n = 10;
	int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

	//��������� ��������, ������� �� ������
	//��������, � ������,
	//�� �������� - � �����
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			lst.add_head(a[i]);
		else
			lst.add_tail(a[i]);
	
	cout << "List lst:\n";					//���������� ������
	lst.print();
	cout << endl;

	lst.del(-1);
	lst.del(50);
	cout << endl;

	lst.del(5);
	cout << "List lst after call del(5) :\n"; lst.print();		//���������� ������
	cout << endl;

	lst.del_from_head();
	cout << "List lst after call del_from_head() :\n"; lst.print();		//���������� ������
	cout << endl;

	lst.del_from_tail();
	cout << "List lst after call del_from_tail() :\n"; lst.print();		//���������� ������
	cout << endl;


	lst.del_all();
	cout << "List lst after call del_all() :\n"; lst.print();			//���������� ������
	cout << endl;

	system("pause");
}
