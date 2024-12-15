#pragma once
#include <iostream>
#include <string>
using namespace std;
class Row {
private:
	
	std::string* value = nullptr; //dynamic array for storing each value
	int noOfColumns = 0; //will be used for the dynamic array

	static int ROW_NUMBER;
	
public:
	friend void operator<<(std::ostream& console, const Row& other);
	Row(std::string* copyvalue, int noOfCol) :noOfColumns(noOfCol)
	{
		this->value = new std::string[noOfCol];
		for (int i = 0; i < noOfCol; i++) {
			this->value[i] = copyvalue[i];
		}

		Row::ROW_NUMBER++;
	}

	~Row() {
		delete[] this->value;
	}

	int getColNumber() {
		return this->noOfColumns;
	}

	void setColNumber(int columnNumber) {
		if (columnNumber <= 0)
			throw "No attributes added";
		else
		{
			std::string* newValues = new std::string[columnNumber];
			for (int i = 0; i < columnNumber; i++) {
				newValues[i] = this->value[i];
			}
		}
		delete[] this->value;
		
	}
	


};
int Row::ROW_NUMBER = 0;
void operator<<(std::ostream& console, const Row& other) {
	console << endl;
	console << "Row Number: " << other.ROW_NUMBER<<endl;
	console << "Items: " << endl;
	for (int i = 0; i < other.noOfColumns; i++)
		console << other.value[i] << ',';
}

