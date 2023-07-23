#pragma once
// Исходные данные квадрата
class SOURCE_DATA {
	char **pdata;
	size_t size;
public:
	SOURCE_DATA(char **pdata, size_t size);
	void ReSize(int key);
	friend ostream& operator<<(ostream& out, SOURCE_DATA& data);
};