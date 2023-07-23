#include <iostream>
#include <string>

using namespace std;

struct Word_Info{
	string en_name;
	string ru_name;
	int count{ 0 };
	string& key() { return en_name; };
};



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
	wi.ru_name = "������";
	lib_tree.insert(wi);

	wi.en_name = "Home";
	wi.ru_name = "���";
	lib_tree.insert(wi);

	wi.en_name = "Aple";
	wi.ru_name = "������";
	lib_tree.insert(wi);


	wi.en_name = "Tree";
	wi.ru_name = "������";
	lib_tree.insert(wi);



	/*cout << "������ ���� ���� ���������� ����� ����� �����: " << endl;
	lib_tree.show(cout);

	cout <<endl << "����� �����: Tree" << endl;
	cout << lib_tree.search("Tree")<<endl;
	cout << endl << "����� �����: Tree" << endl;
	cout << lib_tree.search("Tree") << endl;*/


	system("pause");
	return 0;
}

