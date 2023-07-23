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
	head = nullptr;
	tail = nullptr;
	count = 0;
}

List::~List()
{

}
void List::add_head(int n)
{
	Elem * temp = new Elem;
	temp->data = n;

	temp->next = head;

	temp->prev = nullptr;

	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		head->prev = temp;
		head = temp;
	}
	++count;

}
void List::add_tail(int n)
{
	Elem * temp = new Elem;
	temp->data = n;

	temp->next = nullptr;

	temp->prev = tail;

	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	++count;
}
void List::del(int pos)
{
	//���� �������� ����������� ��� ����� 0,
	//�� ����������� ���
	
	if (pos<1 || pos>count)
	{
		cout << "��������� ������� " << pos << " �� ������ � �������� ��������� �������� [1," << count << "]" << endl;
		return;
	}

	if (!head)
		return;
	
	if (pos == 1)
		del_from_head();
	else if (pos == count)
		del_from_tail();
	else
	{
		Elem* curr_elem = head;
		int i = 1;
		while (curr_elem)
		{

			if (i == pos)
			{
				Elem* prev_elem = curr_elem->prev;
				Elem* next_elem = curr_elem->next;

				if(prev_elem)
					prev_elem->next = next_elem;

				if(next_elem)
					next_elem->prev = prev_elem;
			}

			curr_elem = curr_elem->next;
			++i;
		}
		--count;
	}


}

void List::del_from_head() {
	Elem* curr = head;
	if (head->next)
	{
		head = head->next;
		head->prev = nullptr;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
	}

	delete curr;
	--count;
}

void List::del_from_tail() {

	Elem* curr = tail;
	if (tail->prev)
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
	}


	delete curr;

	--count;
}

void List::print()
{
	//���� � ������ ������������ ��������,
	//�� ��������� �� ����
	//� �������� ��������, ������� � ���������

	Elem * temp = head;
	cout << "(";
	while (temp)
	{
		cout << temp->data;
		temp = temp->next;
		if (temp)
			cout << ",";
	}
	cout << ")";
}

void List::del_all()
{
	//���� �������� ��������, ������� �� ������ � ������
	while (count)
		del_from_head();
}


//�������� ������
void main()
{
	setlocale(LC_ALL, "RUSSIAN");

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

	lst.del(9);
	cout << "List lst after call del(9) :\n"; lst.print();		//���������� ������
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
