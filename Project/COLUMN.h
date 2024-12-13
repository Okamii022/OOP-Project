#pragma once

#include <iostream>
#include <string>

class Column {
private:
	std::string columnName = ""; //name of the column
	std::string columnType = ""; // type of the column, integer, float or text
	int size = 0; //the size of the data associated to each column
	std::string defaultValue = ""; // default value if no value is added
	bool isPrimaryKey = false; //is the column a primary key or not
	bool isForeignKey = false; //is the column a foreign key or not
public:
	//parameterized ctor using initializer list
	Column (const std::string columnName, const std::string columnType, const int size, 
		const std::string defaultValue, const bool isPrimaryKey, const bool isForeignKey)
		:columnName(columnName), columnType(columnType), size(size), defaultValue(defaultValue),
		isPrimaryKey(isPrimaryKey), isForeignKey(isForeignKey){ }
	
	//getters and setters
	std::string getName();
	void setName(const std::string name);

	std::string getType();
	void setType(const std::string type);

	int getSize();
	void setSize(const int sizeOfAttribute);

	std::string getDefaultVal();
	void setDefaultVal(const std::string def);

	bool getPk();
	void setPk(const bool isPk);

	bool getFk();
	void setFk(const bool isFk);

	//destructor
	~Column() {

	}
};