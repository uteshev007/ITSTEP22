#include <iostream>
#include <string>

using namespace std;

struct Word_Info{
	string en_name;
	string ru_name;
	int count{ 0 };
	string& key() { return en_name; };
	void incr() { ++count; };
};

ostream& operator<<(ostream& os, Word_Info wi) { 
	os << wi.en_name << " - " << wi.ru_name << " (кол-во использований: " << wi.count << ")";
	return os;
}


template <class Item, class Key>
class BTree
{
private:
	struct node	
	{
		Item item; node * l, *r;
		node(Item x)
		{
			item = x; l = nullptr; r = nullptr;
		}
	};
	using link = node *;
	link head;
	Item null_item;
	Item searchR(link h, Key v)	{
		if (h == nullptr)
			return null_item;
		Key t = h->item.key();
		if (v == t)
		{
			h->item.incr();
			return h->item;
		}
		if (v < t) 
			return searchR(h->l, v);
		else 
			return searchR(h->r, v);
	}

	void insertR(link& h, Item x)
	{
		if (h == nullptr) { 
			h = new node(x); 
			return; 
		}
		if ( x.key() < h->item.key() )
			insertR(h->l, x);
		else 
			insertR(h->r, x);
	}

	void showR(link h, ostream& os)
	{
		if (h == nullptr) 
			return;

		showR(h->l, os);

		os << h->item << endl;
		showR(h->r, os);
	}

public:
	BTree()
	{
		head = nullptr;
	}
	Item search(Key v)
	{
		return searchR(head, v);
	}
	void insert(Item x)
	{
		insertR(head, x);
	}

	void show(ostream& os)
	{
		showR(head, os);
	}

};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	BTree<Word_Info, string> lib_tree;

	Word_Info wi;

	wi.en_name = "Hello";
	wi.ru_name = "Привет";
	lib_tree.insert(wi);

	wi.en_name = "Home";
	wi.ru_name = "Дом";
	lib_tree.insert(wi);

	wi.en_name = "Aple";
	wi.ru_name = "Яблоко";
	lib_tree.insert(wi);


	wi.en_name = "Tree";
	wi.ru_name = "Дерево";
	lib_tree.insert(wi);



	cout << "Список всех слов библиотеки сразу после ввода: " << endl;
	lib_tree.show(cout);

	cout <<endl << "поиск слова: Tree" << endl;
	cout << lib_tree.search("Tree")<<endl;
	cout << endl << "поиск слова: Tree" << endl;
	cout << lib_tree.search("Tree") << endl;


	system("pause");
	return 0;
}

