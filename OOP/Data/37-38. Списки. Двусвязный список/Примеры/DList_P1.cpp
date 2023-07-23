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
	head = tail = nullptr;		//Изначально список пуст
	count = 0;
}

List::~List()
{
	del_all();		//Удаляем все элементы
}
void List::add_head(int n)
{
	Elem * temp = new Elem;		//новый элемент
	temp->prev = 0;				//Предыдущего нет
	temp->data = n;				//Заполняем данные
	temp->next = head;			//Следующий - бывшая голова
	
	if (head != 0)				//Если элементы есть?
		head->prev = temp;
	
	//Если элемент первый, то он одновременно
	//и голова и хвост
	if (count == 0)
		head = tail = temp;
	else
		head = temp;			//иначе новый элемент - головной
	count++;
}
void List::add_tail(int n)
{
	Elem * temp = new Elem;		//Создаем новый элемент
	temp->next = 0;				//Следующего нет
	temp->data = n;				//Заполняем данные
	temp->prev = tail;			//Предыдущий - бывший хвост
	
	if (tail != 0)				//Если элементы есть?
		tail->next = temp;

	//Если элемент первый, то он одновременно
	//и голова и хвост
	if (count == 0)
		head = tail = temp;
	else
		tail = temp;			//иначе новый элемент - хвостовой
	count++;
}
void List::del(int pos)
{
	//если параметр отсутствует или равен 0,
	//то запрашиваем его
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	//Позиция от 1 до Count?
	if (pos < 1 || pos > count)
	{
		//Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}
	//Счетчик
	int i = 1;
	Elem * del_elem = head;
	while (i < pos)
	{
		//Доходим до элемента,
		//который удаляется
		del_elem = del_elem->next;
		i++;
	}
	

	Elem * prev_del_elem = del_elem->prev;					//Доходим до элемента,
															//который предшествует удаляемому
	Elem * next_del_elem = del_elem->next;					//Доходим до элемента, который следует за удаляемым
	
	if (prev_del_elem != 0 && count != 1)					//Если удаляем не голову
		if (next_del_elem != 0 && count != 1)				//Если удаляем не хвост
		{
			next_del_elem->prev = prev_del_elem;
			prev_del_elem->next = next_del_elem;
		}
	
	if (pos == 1)											//Удаляются крайние?
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

	delete del_elem;									//Удаление элемента
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
	//Если в списке присутствуют элементы,
	//то пробегаем по нему
	//и печатаем элементы, начиная с головного
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
	//Пока остаются элементы, удаляем по одному с головы
	while (count != 0)
		del(1);
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
