
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
const long Size1 = 39L;
const long Size2 = 100*Size1;
const long Size3 = 100*Size2;

bool f3(int x) {return x % 3 == 0;}
bool f13(int x) {return x % 13 == 0;}

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	system("cls");
	//system("pause");

    using std::cout;
    std::vector<int> numbers(Size1);

    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);			// использование указателя на функцию


    cout << "Кол-во чисел = " << Size1 << '\n';

    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);		// использование указателя на функцию
    cout << "Кол-во чисел, кратных 3: " << count3 << '\n';

    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);	// использование указателя на функцию
    cout << "Кол-во чисел, кратных 13: " << count13 << "\n\n";

// увеличиваем кол-во чисел
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Кол-во чисел = " << Size2 << '\n';

// используем функтор
    class f_mod
    {
    private:
        int dv;
    public:
        f_mod(int d = 1) : dv(d) {}
        bool operator()(int x) {return x % dv == 0;}
    };

    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Кол-во чисел, кратных  3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Кол-во чисел, кратных  13: " << count13 << "\n\n";

	// опять увеличиваем кол-во чисел
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Кол-во чисел = " << Size3 << '\n';

	// используем лямды
    count3 = std::count_if(numbers.begin(), numbers.end(),
             [](int x){return x % 3 == 0;});
    cout << "Кол-во чисел, кратных  3: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(),
              [](int x){return x % 13 == 0;});
    cout << "Кол-во чисел, кратных  13: " << count13 << '\n';

	system("pause");
    return 0;
}