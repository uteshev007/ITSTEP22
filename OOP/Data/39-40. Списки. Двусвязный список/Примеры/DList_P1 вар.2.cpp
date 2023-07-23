#include <iostream>
using namespace std;

struct Elem
{
	int data;					//данные
	Elem * next;				//указатель на следующий элемент
	Elem * prev;				//указатель на предыдущий элемент
};

class List
{
	Elem * head, *tail;			//Голова, хвост
	int count;					//Количество элементов

public:
	
	List();						//Конструктор
	~List();					//Деструктор
	void del_all();				//Удаление всех элементов
	
	void add_tail(int n);		//Добавление в конец списка
	void add_head(int n);		//Добавление в начало списка
	void del_from_head();		//удаление элемента из головы
	void del_from_tail();		//удаление элемента из хвоста
	void print();				//Печать списка
	void del(int pos = 0);		//Удаление элемента, если параметр
								//не указывается,
								//то функция его запрашивает

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
	//если параметр отсутствует или равен 0,
	//то запрашиваем его
	
	if (pos<1 || pos>count)
	{
		cout << "указанная позиция " << pos << " не входит в диапазон возможных значений [1," << count << "]" << endl;
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
	//Если в списке присутствуют элементы,
	//то пробегаем по нему
	//и печатаем элементы, начиная с головного

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
	//Пока остаются элементы, удаляем по одному с головы
	while (count)
		del_from_head();
}


//Тестовый пример
void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	List lst;
	const int n = 10;
	int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

	//Добавляем элементы, стоящие на четных
	//индексах, в голову,
	//на нечетных - в хвост
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			lst.add_head(a[i]);
		else
			lst.add_tail(a[i]);
	
	cout << "List lst:\n";					//Распечатка списка
	lst.print();
	cout << endl;

	lst.del(-1);
	lst.del(50);
	cout << endl;

	lst.del(5);
	cout << "List lst after call del(5) :\n"; lst.print();		//Распечатка списка
	cout << endl;

	lst.del(9);
	cout << "List lst after call del(9) :\n"; lst.print();		//Распечатка списка
	cout << endl;

	lst.del_from_head();
	cout << "List lst after call del_from_head() :\n"; lst.print();		//Распечатка списка
	cout << endl;

	lst.del_from_tail();
	cout << "List lst after call del_from_tail() :\n"; lst.print();		//Распечатка списка
	cout << endl;


	lst.del_all();
	cout << "List lst after call del_all() :\n"; lst.print();			//Распечатка списка
	cout << endl;
	

	system("pause");
}
