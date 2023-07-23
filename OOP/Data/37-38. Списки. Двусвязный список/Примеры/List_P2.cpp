#include <iostream>
#include <string>

using namespace std;

struct Element
{
	string data;			//������
	Element * next;			//����� ���������� �������� ������
};

//����������� ������
class List
{
	Element * head;			//����� ��������� �������� ������
	Element * tail;			//����� �������� ������ ������
	int count;				//���������� ��������� ������
public:
	List();					//�����������
	~List();				//����������
	void add(string data);	//���������� �������� � ������
							//(����� ������� ���������� ���������)

	void del();				//�������� �������� ������
							//(��������� �������� �������)

	void del_all();			//�������� ����� ������
	
	void print();			//���������� ����������� ������
							//(���������� ���������� � ��������� ��������)
	
	int get_count();			//��������� ���������� ���������,
								//����������� � ������

	void revert();
};
List::List()
{
	//���������� ������ ����
	head = tail = nullptr;
	count = 0;
}
List::~List()
{
	//����� ������� ��������
	del_all();
}
int List::get_count()
{
	//���������� ���������� ���������
	return count;
}
void List::add(string data)
{
	//�������� ������ ��������
	Element * temp = new Element;
	
	//���������� �������
	temp->data = data;
	
	//��������� ������� �����������
	temp->next = nullptr;
	
	//����� ������� ���������� ������������
	//���� �� ������ �����������

	if (head == nullptr) {
		head = tail = temp;
	}
	//����� ������� ���������� ��������� ��������� ������
	//���� �� �� ������ �����������
	else {
		tail->next = temp;
		tail = temp;


	}
}
void List::del()
{
	if (head == nullptr)
		return;

	Element * temp = head;		//���������� ����� ��������� ��������

	head = head->next;			//������������� ������ �� ��������� �������

	delete temp;				//������� ������ �������� �������
}
void List::del_all()
{
	//���� ��� ���� ��������
	while (head != nullptr)
		del();					//������� �������� �� ������
}
void List::print()
{
	cout << "--------------- List: ------------------\n";

	//���������� ����� ��������� ��������
	Element * temp = head;

	//���� ��� ���� ��������
	while (temp != 0)
	{
		cout << temp->data<< "\n";		//������� ������
		temp = temp->next;				//��������� �� ��������� �������
	}
	cout << "\n\n";

}

void List::revert() {
	Element* elem_next = nullptr;		//���������� ��������� �� ��������� �������
	Element* elem_curr = head;			//���������� ��������� �� ������� ������� (��������� �� ������ ������)
	Element* elem_prev = nullptr;		//���������� ��������� �� ���������� �������

	while (elem_curr != nullptr)
	{
		elem_next = elem_curr->next;	//������������� ���������� ��������� �� ��������� ������� 
		elem_curr->next = elem_prev;	//� ���� next �������� �������� �������� ��������� 
										//�� ���������� �������
		elem_prev = elem_curr;			//��������� ������ �� ������: ���������� ��������� �� ���������� ������� 
										//������ ��������� �� �������
		elem_curr = elem_next;			//���������� ��������� �� ������� ������� ������������ �� ��������� �������
	}
	head = elem_prev;
}

//�������� ������
void main()
{
	setlocale(LC_ALL, "RUSSIAN");


	//������� ������ ������
	List lst;

	//�������� ������
	char tony1[] = "1. Repetition is the mother of skill.";
	string tony2 = "2. Where focus goes, energy flows.";
	string aristotle={"3. Quality is not an act. It is a habit."};
	string tony3{"4. The difference between MUST & SHOULD is the life you want and the life you have."};

	//������� ������
	cout << tony1 << "\n";
	cout << tony2 << "\n";
	cout << aristotle << "\n";
	cout << tony3<< "\n\n";

	//�������� ������ � ������
	lst.add(tony1);
	lst.add(tony2);
	lst.add(aristotle);
	lst.add(tony3);

	
	lst.print();		//������� �� ����� ���������� ������

	lst.revert();		//������ ������� ���������� ���������

	lst.print();		//������������� ���������� ������

	/*string polozkova{"-. ����������� ������� � ����, ��� ����� ���. ������ ��������, �� �����. (��������� � ����� ������)"};
	lst.add(polozkova);

	lst.print();		//������� �� ����� ���������� ������*/

	system("pause");
}