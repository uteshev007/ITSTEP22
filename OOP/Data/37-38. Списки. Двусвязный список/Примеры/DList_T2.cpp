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
	void del_all();				//������� ���� ������
	void del(int pos = 0);		//�������� ��������, ���� ��������
								//�� �����������,
								//�� ������� ��� �����������
	
	void insert(int pos, int v);	//������� �������� � �������� �������
	
	void add_tail(int n);		//���������� � ����� ������
	
	void add_head(int n);		//���������� � ������ ������
	void del_from_head();		//�������� �������� �� ������
	void del_from_tail();		//�������� �������� �� ������

	void print();				//������ ������
	int find(int v);			//����� �������� �� �������� (������� ���������� ������� ���������� �������� � 								//������ ������ ��� NULL � ������ �������)
	int update(int cur_value, int new_value );	//����� � ������ ��������� �� ��� �������� (������� ���������� 
												//���������� ���������� ��������� � ������ ������ ��� 
												//-1 � ������ �������)
	void print(int pos);		//������ ������������� ��������
	int get_count() { return -100; };// ������� ���-�� ��������� � ������
	List operator - ();			//��������������� ������
};
int List::update(int cur_value, int new_value)
{
	return -100;
}
int List::find(int v)
{
	return -100;
}

List::List()
{
	head = tail = NULL;			//���������� ������ ����
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

void List::insert(int pos, int v)
{
	//���� �������� ����������� ��� ����� 0,
	//�� ����������� ���
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	//������� �� 1 �� Count?
	if (pos < 1 || pos > count + 1)
	{
		//�������� �������
		cout << "Incorrect position !!!\n";
		return;
	}


	//���� ������� � ����� ������
	if (pos == count + 1)
	{
		add_tail(v);			//���������� � ����� ������
		return;
	}
	else if (pos == 1)
	{
		add_head(v);			//���������� � ������ ������
		return;
	}

	
	int i = 1;					//�������
	
	Elem * curr = head;			//����������� �� ������ n - 1 ���������
	while (i < pos)
	{
		curr = curr->next;		//������� �� ��������,
		i++;					//����� ������� �����������
	}

	
	Elem * prev_new = curr->prev;		//������� �� ��������,
										//������� ������������
	
	Elem * new_elem = new Elem;			//������� ����� �������
	new_elem->data = v;				//������������� ������
									
	if (prev_new != nullptr && count != 1)	//��������� ������
		prev_new->next = new_elem;

	new_elem->next = curr;
	new_elem->prev = prev_new;

	curr->prev = new_elem;
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

		if (head)
			head->prev = nullptr;
	}

	if (pos == count)
	{
		tail = prev_del_elem;

		if (tail)
			tail->next = nullptr;
	}

	delete del_elem;									//�������� ��������
	count--;
}
void List::print(int pos)
{
	
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

//���������
List List::operator - ()
{
	List Result;

	return Result;
}
void List::del_from_head() {
	del(1);
}

void List::del_from_tail() {
	del(count);
}

void P1();
//�������� ������
void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	//P1();

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

	
	int v = 0;
	cout << "������� �������� �� ��������� "<<v<<"= "<< lst.find(v) << endl;
	cout << "������� �������� �� ��������� " << (v=8) << "= " << lst.find(v) << endl;
	cout << "������� �������� �� ��������� " << (v=9) << "= " << lst.find(v) << endl;
	cout << "������� �������� �� ��������� " << (v = -1) << "= " << lst.find(-1) << endl;

	cout << "\n���-�� ��������� � ������: " << lst.get_count()<<endl;

	lst.insert(1, 11);							//������� �������� � ������ ����� ������ 
	lst.insert(lst.get_count(), 11);			//������� �������� � ������ ����� ��������� 
	lst.insert(5, 11);							//������� �������� � ������

	lst.insert(-1, -1);							//������� �������� � ������
	lst.insert(100, 100);						//������� �������� � ������

	cout << "List lst:\n"; lst.print();			//���������� ������
	
	lst.print(2);								//���������� 2-�� � 8-�� ��������� ������
	lst.print(8);

	cout<<"���-�� ���������� ���������: "<<lst.update(11, -7)<< endl;
	cout << "List lst:\n"; lst.print();			//���������� ������

	system("pause");
}

void P1()
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
}