#pragma once
#include <iostream>
#include <string>

class Row {
private:
	int rowNumber;
	std::string* value; //dynamic array for storing each value
	int columnNumber; //will be used for the dynamic array

public:
	
	Row(int rowNumber, std::string copyvalue, int columnNumber) : rowNumber(rowNumber), columnNumber(columnNumber)
	{
		this->value = new std::string[columnNumber];
		for (int i = 0; i < columnNumber; i++)
			this->value[i] = copyvalue[i];
	}

	~Row() {
		delete[] this->value;
	}


};