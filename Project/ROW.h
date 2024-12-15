#pragma once
#include <iostream>
#include <string>
using namespace std;
class Row {
private:
	int rowNumber = 0;
	std::string* value = nullptr; //dynamic array for storing each value
	int columnNumber = 0; //will be used for the dynamic array
	
public:
	friend void operator<<(std::ostream& console, const Row& other);
	Row(int rowNumber, std::string* copyvalue, int columnNumber) : rowNumber(rowNumber), columnNumber(columnNumber)
	{
		this->value = new std::string[columnNumber];
		for (int i = 0; i < columnNumber; i++)
			this->value[i] = copyvalue[i];
	}

	~Row() {
		delete[] this->value;
	}


};
void operator<<(std::ostream& console, const Row& other) {
	console << "Row Number: " << other.rowNumber<<endl;
	console << "Items: " << endl;
	for (int i = 0; i < other.columnNumber; i++)
		console << other.value[i] << ',';
}

