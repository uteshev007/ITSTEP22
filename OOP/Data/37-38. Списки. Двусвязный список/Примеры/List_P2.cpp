#include <iostream>
#include <string>

using namespace std;

struct Element
{
	string data;			//Данные
	Element * next;			//Адрес следующего элемента списка
};

//Односвязный список
class List
{
	Element * head;			//Адрес головного элемента списка
	Element * tail;			//Адрес элемента хвоста списка
	int count;				//Количество элементов списка
public:
	List();					//Конструктор
	~List();				//Деструктор
	void add(string data);	//Добавление элемента в список
							//(Новый элемент становится последним)

	void del();				//Удаление элемента списка
							//(Удаляется головной элемент)

	void del_all();			//Удаление всего списка
	
	void print();			//Распечатка содержимого списка
							//(Распечатка начинается с головного элемента)
	
	int get_count();			//Получение количества элементов,
								//находящихся в списке

	void revert();
};
List::List()
{
	//Изначально список пуст
	head = tail = nullptr;
	count = 0;
}
List::~List()
{
	//Вызов функции удаления
	del_all();
}
int List::get_count()
{
	//Возвращаем количество элементов
	return count;
}
void List::add(string data)
{
	//создание нового элемента
	Element * temp = new Element;
	
	//заполнение данными
	temp->data = data;
	
	//следующий элемент отсутствует
	temp->next = nullptr;
	
	//новый элемент становится единственным
	//если он первый добавленный

	if (head == nullptr) {
		head = tail = temp;
	}
	//новый элемент становится последним элементом списка
	//если он не первый добавленный
	else {
		tail->next = temp;
		tail = temp;


	}
}
void List::del()
{
	if (head == nullptr)
		return;

	Element * temp = head;		//запоминаем адрес головного элемента

	head = head->next;			//перебрасываем голову на следующий элемент

	delete temp;				//удаляем бывший головной элемент
}
void List::del_all()
{
	//Пока еще есть элементы
	while (head != nullptr)
		del();					//Удаляем элементы по одному
}
void List::print()
{
	cout << "--------------- List: ------------------\n";

	//запоминаем адрес головного элемента
	Element * temp = head;

	//Пока еще есть элементы
	while (temp != 0)
	{
		cout << temp->data<< "\n";		//Выводим данные
		temp = temp->next;				//Переходим на следующий элемент
	}
	cout << "\n\n";

}

void List::revert() {
	Element* elem_next = nullptr;		//переменная указатель на следующий элемент
	Element* elem_curr = head;			//переменная указатель на текущий элемент (указывает на голову списка)
	Element* elem_prev = nullptr;		//переменная указатель на предыдущий элемент

	while (elem_curr != nullptr)
	{
		elem_next = elem_curr->next;	//устанавливаем переменную указатель на следующий элемент 
		elem_curr->next = elem_prev;	//в поле next текущего элемента помещаем указатель 
										//на предыдущий элемент
		elem_prev = elem_curr;			//двигаемся дальше по списку: переменная указатель на предыдущий элемент 
										//теперь указывает на текущий
		elem_curr = elem_next;			//переменную указатель на текущий элемент перекидываем на следующий элемент
	}
	head = elem_prev;
}

//Тестовый пример
void main()
{
	setlocale(LC_ALL, "RUSSIAN");


	//Создаем объект класса
	List lst;

	//Тестовые строки
	char tony1[] = "1. Repetition is the mother of skill.";
	string tony2 = "2. Where focus goes, energy flows.";
	string aristotle={"3. Quality is not an act. It is a habit."};
	string tony3{"4. The difference between MUST & SHOULD is the life you want and the life you have."};

	//Выводим строки
	cout << tony1 << "\n";
	cout << tony2 << "\n";
	cout << aristotle << "\n";
	cout << tony3<< "\n\n";

	//Копируем строки в список
	lst.add(tony1);
	lst.add(tony2);
	lst.add(aristotle);
	lst.add(tony3);

	
	lst.print();		//Выводим на экран содержимое списка

	lst.revert();		//Меняем порядок следования элементов

	lst.print();		//Распечатываем содержимое списка

	/*string polozkova{"-. Обязательно дружите с теми, кто лучше вас. Будете мучиться, но расти. (добавлена в конец списка)"};
	lst.add(polozkova);

	lst.print();		//Выводим на экран содержимое списка*/

	system("pause");
}