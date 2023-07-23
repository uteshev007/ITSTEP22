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
	head = tail = nullptr;		//���������� ������ ����
	count = 0;
}

List::~List()
{
	del_all();		//������� ��� ��������
}
void List::add_head(int n)
{
	Elem * temp = new Elem;		//����� �������
	temp->prev = 0;				//����������� ���
	temp->data = n;				//��������� ������
	temp->next = head;			//��������� - ������ ������
	
	if (head != 0)				//���� �������� ����?
		head->prev = temp;
	
	//���� ������� ������, �� �� ������������
	//� ������ � �����
	if (count == 0)
		head = tail = temp;
	else
		head = temp;			//����� ����� ������� - ��������
	count++;
}
void List::add_tail(int n)
{
	Elem * temp = new Elem;		//������� ����� �������
	temp->next = 0;				//���������� ���
	temp->data = n;				//��������� ������
	temp->prev = tail;			//���������� - ������ �����
	
	if (tail != 0)				//���� �������� ����?
		tail->next = temp;

	//���� ������� ������, �� �� ������������
	//� ������ � �����
	if (count == 0)
		head = tail = temp;
	else
		tail = temp;			//����� ����� ������� - ���������
	count++;
}
void List::del(int pos)
{
	//���� �������� ����������� ��� ����� 0,
	//�� ����������� ���
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	//������� �� 1 �� Count?
	if (pos < 1 || pos > count)
	{
		//�������� �������
		cout << "Incorrect position !!!\n";
		return;
	}
	//�������
	int i = 1;
	Elem * del_elem = head;
	while (i < pos)
	{
		//������� �� ��������,
		//������� ���������
		del_elem = del_elem->next;
		i++;
	}
	

	Elem * prev_del_elem = del_elem->prev;					//������� �� ��������,
															//������� ������������ ����������
	Elem * next_del_elem = del_elem->next;					//������� �� ��������, ������� ������� �� ���������
	
	if (prev_del_elem != 0 && count != 1)					//���� ������� �� ������
		if (next_del_elem != 0 && count != 1)				//���� ������� �� �����
		{
			next_del_elem->prev = prev_del_elem;
			prev_del_elem->next = next_del_elem;
		}
	
	if (pos == 1)											//��������� �������?
	{
		head = next_del_elem;
		
		if(head)
			head->prev = nullptr;
	}

	if (pos == count)
	{
		tail = prev_del_elem;
		
		if(tail)
			tail->next = nullptr;
	}

	delete del_elem;									//�������� ��������
	count--;
}

void List::del_from_head() {
	del(1);
}

void List::del_from_tail() {
	del(count);
}

void List::print()
{
	//���� � ������ ������������ ��������,
	//�� ��������� �� ����
	//� �������� ��������, ������� � ���������
	if (count != 0)
	{
		Elem * temp = head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}

void List::del_all()
{
	//���� �������� ��������, ������� �� ������ � ������
	while (count != 0)
		del(1);
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
