// Демонстрация наследования.
#include <iostream> 
using namespace std;

// Определяем базовый класс транспортных средств. 
class Road_Vehicle {
	int wheels;			//кол-во колес
	int passengers;		//кол-во пассажиров
public:
	void set_wheels(int num) { wheels = num; }	//установить кол-во колес
	int get_wheels() { return wheels; }			//получить кол-во колес
	void set_pass(int num) { passengers = num; }//установить кол-во пассажиров
	int get_pass() { return passengers; }		//получить кол-во пассажиров
};

// Определяем класс грузовиков. 
class Truck : public Road_Vehicle {
	int cargo;									//грузовместимость в кубических футах
public:
	void set_cargo(int size) { cargo = size; }	//установить грузовместимость в кубических футах
	int get_cargo() { return cargo; }			//получить грузовместимость в кубических футах
	void show();								//отобразить информацию о кол-ве колес, пассажиров и грузовместимости
};

//отобразить информацию о кол-ве колес, пассажиров и грузовместимости
void Truck::show()
{
	cout << "колес: " << get_wheels() << "\n";
	cout << "пассажиров: " << get_pass() << "\n";
	cout << "грузовместимость в кубических футах: " << cargo << "\n";
}

enum Type { CAR, VAN, WAGON };

// Определяем класс автомобилей. 
class Automobile : public Road_Vehicle {
	Type car_type;
public:
	void set_type(Type t) { car_type = t; }
	Type get_type() { return car_type; }
	void show();
};

//отобразить информацию о кол-ве колес, пассажиров, а аткже типе автомобиля
void Automobile::show()
{
	cout << "колес: " << get_wheels() << "\n";
	cout << "пассажиров: " << get_pass() << "\n";
	cout << "тип: ";

	switch (get_type()) {
	case VAN: cout << "автофургон\n";
		break;
	case CAR: cout << "легковой\n";
		break;
	case WAGON: cout << "фура\n";
	}
}



int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Truck t1, t2;
	Automobile a;

	t1.set_wheels(18);
	t1.set_pass(2);
	t1.set_cargo(3200);

	t2.set_wheels(6);
	t2.set_pass(3);
	t2.set_cargo(1200);

	t1.show();
	cout << "\n";
	t2.show();
	cout << "\n";

	a.set_wheels(4);
	a.set_pass(6);
	a.set_type(VAN);

	a.show();
	
	system("pause");
	return 0;
}