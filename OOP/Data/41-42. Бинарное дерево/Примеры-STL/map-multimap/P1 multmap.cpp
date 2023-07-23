// multmap.cpp -- use a multimap
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");

    MapCode codes;


    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));

    cout << "Кол-во городов с кодом 415: "
         << codes.count(415) << endl;
    cout << "Кол-во городов с кодом  718: "
         << codes.count(718) << endl;
    cout << "Кол-во городов с кодом  510: "
         << codes.count(510) << endl;
    
	cout << "Города и коды\n";
    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it)
        cout << "    " << (*it).first << "     "
            << (*it).second    << endl;

   // pair<MapCode::iterator, MapCode::iterator> 
	auto range = codes.equal_range(718);
		
    cout << "Города с кодом 718:\n";
    for (it = range.first; it != range.second; ++it)
        cout <<  (*it).second    << endl;

	cout << "Удаление городов с кодом 718:\n";
	for (it = codes.begin(); it != codes.end(); )
		if (it->first == 718)
			it = codes.erase(it);
		else
			++it;


	cout << "Города и коды\n";

	for (it = codes.begin(); it != codes.end(); ++it)
		cout << "    " << (*it).first << "     "
		<< (*it).second << endl;


	system("pause");
    return 0; 
}
