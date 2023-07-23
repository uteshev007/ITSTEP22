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
	//если параметр отсутствует или равен 0,
	//то запрашиваем его
	
}

void List::del_from_head() {

}

void List::del_from_tail() {

}

void List::print()
{
	//Если в списке присутствуют элементы,
	//то пробегаем по нему
	//и печатаем элементы, начиная с головного

}

void List::del_all()
{
	//Пока остаются элементы, удаляем по одному с головы

}


//Тестовый пример
void main()
{
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
