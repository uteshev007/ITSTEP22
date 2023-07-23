// ������������ ������������.
#include <iostream> 
using namespace std;

// ���������� ������� ����� ������������ �������. 
class Road_Vehicle {
	int wheels;			//���-�� �����
	int passengers;		//���-�� ����������
public:
	void set_wheels(int num) { wheels = num; }	//���������� ���-�� �����
	int get_wheels() { return wheels; }			//�������� ���-�� �����
	void set_pass(int num) { passengers = num; }//���������� ���-�� ����������
	int get_pass() { return passengers; }		//�������� ���-�� ����������
};

// ���������� ����� ����������. 
class Truck : public Road_Vehicle {
	int cargo;									//���������������� � ���������� �����
public:
	void set_cargo(int size) { cargo = size; }	//���������� ���������������� � ���������� �����
	int get_cargo() { return cargo; }			//�������� ���������������� � ���������� �����
	void show();								//���������� ���������� � ���-�� �����, ���������� � ����������������
};

//���������� ���������� � ���-�� �����, ���������� � ����������������
void Truck::show()
{
	cout << "�����: " << get_wheels() << "\n";
	cout << "����������: " << get_pass() << "\n";
	cout << "���������������� � ���������� �����: " << cargo << "\n";
}

enum Type { CAR, VAN, WAGON };

// ���������� ����� �����������. 
class Automobile : public Road_Vehicle {
	Type car_type;
public:
	void set_type(Type t) { car_type = t; }
	Type get_type() { return car_type; }
	void show();
};

//���������� ���������� � ���-�� �����, ����������, � ����� ���� ����������
void Automobile::show()
{
	cout << "�����: " << get_wheels() << "\n";
	cout << "����������: " << get_pass() << "\n";
	cout << "���: ";

	switch (get_type()) {
	case VAN: cout << "����������\n";
		break;
	case CAR: cout << "��������\n";
		break;
	case WAGON: cout << "����\n";
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