/*
  BTree.h
  template<class T>
  class Tree;
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>  // STL C++ ==> class string
#include <array>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <time.h>
using namespace std;

#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

template<class T>
struct Node {
  T key;    // Полезные данные
            // Указатели на родителя, левого и правого потомков
  int cnt;  // счетчик повторений
  Node<T>* parent;
  Node<T>* left, * right;
  // конструкторы узла
  Node() : key(), cnt(), parent(), left(), right() {}
  Node(T Key, Node<T>* Parent = nullptr)
    : key(Key), cnt(), parent(Parent), left(), right() {}

  // перегруженный оператор для узла дерева Node<T>
  friend ostream& operator << (ostream& os, const Node<T>& obj) {
    os << obj.cnt << ": " << obj.key;
    return os;
  }
}; // struct Node<>


template<class T>
class Tree
{
  Node<T>* root;    // Корень
public:
  // Конструктор по умолчанию
  Tree() : root() {}

  // Конструктор принимающий массив элементов
  Tree(T* mas, size_t size);

  ~Tree() { Clear(); }

  // Получить корень дерева
  Node<T>* GetRoot() { return root; }

  // Добавление элемента
  void push(const T& val); // add();

  // Отображение дерева с начального узла
  void Print(Node<T>* pNode);
  // Отображение всего дерева
  void Print();

  // Поиск данных в узле 
  Node<T>* Search(T Key) { return Search(root, Key); }
  Node<T>* Search(Node<T>* pNode, const T& key);

  // Поиск минимума
  Node<T>* Min() { return Min(root); }
  Node<T>* Min(Node<T>* pNode);
  // Поиск максимума
  Node<T>* Max() { return Max(root); };
  Node<T>* Max(Node<T>* pNode);

  // Удаление узла/ветки
  //  (nullptr удаление всего дерева)
  void Del(Node<T>* pNode = nullptr) {
    if (!pNode) return;
    Del(pNode->left);
    Del(pNode->right);
    delete pNode;
  }

  //void Clear() { Del(root); }
  void Clear() { WalkAfter([](auto a) {delete a; }); }

  // обход дерева от минимального узла к максимальному
  //  обработка когда Left to Right
  template<class F>
  void Walk(F fn) const { Walk(root, fn); }

  template<class F>
  void Walk(Node<T>* pNode, F fn) const
  {
    if (!pNode) return;
    Node<T>* pLast = pNode;
    while (pLast->right) { pLast = pLast->right; }
    enum { toLeft, toRight, toParent, toExit } dir = toLeft;
    do
    {
      // walk to left while pLeft is not NULL
      if (dir == toLeft) {
        while (pNode->left) pNode = pNode->left;
        fn(pNode);
        dir = toRight;
      }
      // one step to right
      if (dir == toRight) {
        if (pNode->right) {
          pNode = pNode->right;
          dir = toLeft;
        }
        else
          dir = (pNode == pLast) ? toExit : toParent;
      }
      // one step to up - to parent node
      if (dir == toParent) {
        if (pNode == pNode->parent->left) {
          pNode = pNode->parent;
          fn(pNode);
          dir = toRight;
        }
        else {
          pNode = pNode->parent;
        }
      }
    } while (dir != toExit);
  }

  // обход дерева от минимального узла к максимальному
  //  обработка когда Right to Parent
  template<class F>
  void WalkAfter(F fn) { WalkAfter(root, fn); }

  template<class F>
  void WalkAfter(Node<T>* pNode, F fn)
  {
    if (!pNode) return;
    Node<T>* pToPrepare = nullptr;
    enum { toLeft, toRight, toParent, toExit } dir = toLeft;
    do
    {
      // walk to left while pLeft is not NULL
      if (dir == toLeft) {
        while (pNode->left) pNode = pNode->left;
        dir = toRight;
      }
      // one step to right
      if (dir == toRight) {
        if (pNode->right) {
          pNode = pNode->right;
          dir = toLeft;
        }
        else {
          pToPrepare = pNode;
          dir = toParent;
        }
      }
      // one step to up - to parent node
      if (dir == toParent) {
        if (!pNode->parent) {
          dir = toExit;
          fn(pNode);
        }
        else if (pNode == pNode->parent->left) {
          pNode = pNode->parent;
          dir = toRight;
          if (pToPrepare) {
            fn(pToPrepare);
            pToPrepare = nullptr;
          }
        }
        else {
          pNode = pNode->parent;
          if (pToPrepare) {
            fn(pToPrepare);
          }
          pToPrepare = pNode;
        }
      }
    } while (dir != toExit);
  }

}; // class Tree<>


// Конструктор принимающий массив элементов
template<class T>
Tree<T>::Tree(T* mas, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    push(mas[i]);
  }
}

// Добавление элемента
template<class T>
void Tree<T>::push(const T& val)
{
  if (!root) { // если деревое пустое
    root = new Node<T>(val, nullptr);
  }
  else {
    Node<T>* temp = root;
    Node<T>* temp_parent = nullptr;
    while (temp) { // while (temp != nullptr)
      temp_parent = temp; // запоминаем родительский узел
      if (val < temp->key) {
        temp = temp->left; // уходим влево
      }
      else if (val > temp->key) {
        temp = temp->right; // уходим вправо
      }
      else /*if (val == temp->key)*/ {
        temp->cnt++; // учет дубликата
        break; // выходим из цикла
      }
    }
    // если temp == nullptr - добавляем новый узел в дерево
    if (!temp) {
      temp = new Node<T>(val, temp_parent);
      if (val < temp_parent->key) {
        temp_parent->left = temp; // добавляем слева
      }
      else {
        temp_parent->right = temp; // добавляем справа
      }
      //Count++; - если надо считать кол-во узлов в дереве
    }
  }
}

// Отображение дерева с начального узла
// Рекурсивный вариант печати всего дерева
template<class T>
void Tree<T>::Print(Node<T>* pNode) {
  if (!pNode) return;
  Print(pNode->left);
  cout << pNode->cnt << " : " << pNode->key << endl;
  Print(pNode->right);
}

// Отображение всего дерева
template<class T>
void Tree<T>::Print() {
  Print(root);
}

// Поиск данных в узле 
// Search(GetRoot(), key)
template<class T>
Node<T>* Tree<T>::Search(Node<T>* pNode, const T& Key)
{
  while (pNode) {
    if (pNode->key < Key) { pNode = pNode->right; }
    else if (pNode->key > Key) { pNode = pNode->left; }
    //else if (Key < pNode->key) { pNode = pNode->left; } - такое используется в STL C++
    else { return pNode; }
  }
  return pNode;
}

// Поиск минимума - самый левый узел
// Вариант с циклом
template<class T>
Node<T>* Tree<T>::Min(Node<T>* pNode) {
  //if (pNode == nullptr) { return nullptr; }
  if (pNode) {
    while (pNode->left != nullptr) {
      pNode = pNode->left;
    }
  }
  return pNode;
}

// Поиск максимума - крайний правый узел
// Рекурсивный вариант
template<class T>
Node<T>* Tree<T>::Max(Node<T>* pNode) {
  if (pNode == nullptr) { return nullptr; }
  if (pNode->right == nullptr) { return pNode; }
  return Max(pNode->right);
}


// перегруженный оператор для объекта бинарное дерево Tree<T>
template<class T>
ostream& operator << (ostream& os, const Tree<T>& obj)
{
  obj.Walk( [&os](auto a) { os << *a << endl; } );
  return os;
}



int main1()
{
  auto fn = [](auto a) { cout << *a << endl; };
  Tree<int> t1;

  int sz = 10; // RAND(10, 30);
  for (int i = 0; i < sz; i++) {
    int tmp = RAND(1, 100);
    cout << tmp << " ";
    t1.push(tmp);
  }
  cout << endl << endl;

  cout << "-- Tree<int>::Print() --------------------------\n";
  t1.Print();
  cout << "-- Tree<int>::Walk() --------------------------\n";
  t1.Walk(fn); //t1.Walk([](auto p) { cout << *p << endl; });
  cout << "-- Tree<int>::WalkAfter() --------------------------\n";
  t1.WalkAfter(fn);
  cout << "---------------------------\n";
  cout << t1 << endl;
  cout << "---------------------------\n";

  cout << "Vvedite chislo dla poiska: ";
  int s;
  cin >> s;
  // Поиск без сохранения узла
  if (t1.Search(s)) {
    cout << "Найдено" << endl;
  }
  else {
    cout << "Таково значения в дереве нет!" << endl;
  }
  // Поиск с извлечением узла при поиске
  Node<int>* res = t1.Search(s);
  if (res) {
    cout << "Найдено: " << res->cnt << ":" << res->key << endl;
  }
  else {
    cout << "Таково значения в дереве нет!" << endl;
  }
  // Поиск мин/макс
  cout << "Min = " << t1.Min()->key << endl;
  Node<int>* pMax = t1.Max();
  cout << "Max = " << pMax->key << endl;
  return 0;
}




class Man
{
private:
  string FIO;
  string IIN;
  int Age;
  static string RandFIO(int len) {
    string str;
    //insert_iterator<string> it(str, begin(str)); - вставочный итератор для string
    generate_n( insert_iterator<string>(str, begin(str)), len, []() {return char(RAND('A', 'Z')); });
    return str;
  }
  static string RandIIN(int len = 12) {
    string str;
    generate_n(insert_iterator<string>(str, begin(str)), len, []() {return char(RAND('0', '9')); });
    return str;
  }
public:
  Man() : Age(RAND(20, 60)), FIO(RandFIO(RAND(5, 8))), IIN(RandIIN()) {}
  bool operator< (const Man& obj) const { return this->IIN < obj.IIN; }
  bool operator> (const Man& obj) const { return this->IIN > obj.IIN; }
  bool operator==(const Man& obj) const { return this->IIN == obj.IIN; }
  bool operator!=(const Man& obj) const { return this->IIN != obj.IIN; }
  friend ostream& operator << (ostream& os, const Man& obj) {
    return os << obj.IIN << " - "
      << std::left << std::setw(10) << obj.FIO
      << std::right << std::setw(3) << obj.Age;
  }
}; // class Man


using MyType = typename Man;
//using MyType = typename string;
//using MyContainer = typename std::vector<MyType>;
using MyContainer = typename std::list<MyType>;
using MyIterator  = typename MyContainer::iterator;

int main()
{
  array<MyType, 10> mas; // MyType mas[10];
  for_each(std::begin(mas), std::end(mas),
    [](auto a) { std::cout << a << std::endl; });
  std::cout << "-----------------------\n";

  //Tree<Man> trMans1(mas.data(), mas.size());
  Tree<MyType> trMans1(mas.data(), mas.size());
  std::cout << trMans1;
  std::cout << "-----------------------\n\n";

  MyContainer vMans(10);
  auto fun =
    [](auto a) { std::cout << a << std::endl; };
  for_each(std::begin(vMans), std::end(vMans), fun);
  std::cout << "-----------------------\n";

  //Tree<Man> trMans2(vMans.data(), vMans.size());  // for vector<Man>
  //Tree<Man> trMans2;
  Tree<MyType> trMans2;
  for (auto a : vMans) { trMans2.push(a); }
  std::cout << trMans2;
  std::cout << "-----------------------\n\n";

}
