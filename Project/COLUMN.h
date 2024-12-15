#pragma once

#include <iostream>
#include <string>

class Column {
private:
	std::string columnName = ""; //name of the column
	std::string columnType = ""; // type of the column, integer, float or text
	int size = 0;//the size of the data associated to each column
	std::string defaultValue = "";// default value if no value is added
	bool isPrimaryKey = false; //is the column a primary key or not

public:
	// Getters and Setters
	std::string getName() {
		return this->columnName;
	};

	void setName(const std::string name) {
		// Validation: Ensure that the name is not empty
		if (name.empty()) {
			throw std::invalid_argument("Column name cannot be empty.");
		}
		this->columnName = name;
	};

	std::string getType() {
		return this->columnType;
	};

	void setType(const std::string type) {
		// Validation: Ensure that the type is one of the accepted data types
		if (type != "int" && type != "varchar" && type != "float" && type != "bool" && type != "date") {
			throw std::invalid_argument("Invalid column type. Accepted types are: int, varchar, float, bool, date.");
		}
		this->columnType = type;
	};

	int getSize() {
		return this->size;
	};

	void setSize(const int sizeOfAttribute) {
		// Validation: Ensure that size is a positive number
		if (sizeOfAttribute <= 0) {
			throw std::invalid_argument("Size must be a positive integer.");
		}
		this->size = sizeOfAttribute;
	};

	std::string getDefaultVal() {
		return this->defaultValue;
	};

	void setDefaultVal(const std::string defaultVal) {
		// Validation: Ensure that the default value is not empty if it is being set
		if (defaultVal.empty()) {
			throw std::invalid_argument("Default value cannot be empty.");
		}
		this->defaultValue = defaultVal;
	};

	bool getIsPk() {
		return this->isPrimaryKey;
	};

	void setIsPk(const bool isPk) {
		// No validation rule needed.
		this->isPrimaryKey = isPk;
	};

	// Parameterized ctor using initializer list
	Column(const std::string columnName, const std::string columnType, const int size,
		const bool isPrimaryKey) :columnName(columnName),
		columnType(columnType), size(size), defaultValue(defaultValue), isPrimaryKey(isPrimaryKey) {
		this->setName(columnName);
		this->setType(columnType);
		this->setSize(size);
		this->setIsPk(isPrimaryKey);
	};

	// Parameterized ctor using initializer list, with all parameters
	Column(const std::string columnName, const std::string columnType, const int size,
		const std::string defaultValue, const bool isPrimaryKey) :columnName(columnName),
		columnType(columnType), size(size), defaultValue(defaultValue), isPrimaryKey(isPrimaryKey) {
		this->setName(columnName);
		this->setType(columnType);
		this->setSize(size);
		this->setDefaultVal(defaultValue);
		this->setIsPk(isPrimaryKey);
	};

	// Copy ctor
	Column(const Column& col) : columnName(columnName), columnType(columnType), size(size),
		defaultValue(defaultValue), isPrimaryKey(isPrimaryKey) {
		this->setName(col.columnName);
		this->setType(col.columnType);
		this->setSize(col.size);
		this->setDefaultVal(col.defaultValue);
		this->setIsPk(col.isPrimaryKey);
	}

	// = operator
	Column& operator=(const Column& col) {
		this->setName(col.columnName);
		this->setType(col.columnType);
		this->setSize(col.size);
		this->setDefaultVal(col.defaultValue);
		this->setIsPk(col.isPrimaryKey);
		return *this;
	}

	// Overloaded cast operator to std::string (returns the column name)
	operator std::string() const {
		return this->columnName;
	}

	// Overloaded cast operator to bool (checks if the column is a primary key)
	operator bool() const {
		return this->isPrimaryKey;
	}

	// Overloaded equality operator
	bool operator==(const Column& col) const {
		return columnName == col.columnName &&
			columnType == col.columnType &&
			size == col.size &&
			defaultValue == col.defaultValue &&
			isPrimaryKey == col.isPrimaryKey;
	}

	bool operator!=(const Column& col) const {
		return !(*this == col);
	}

	friend void operator<<(std::ostream& console, const Column& col);

	friend std::istream& operator>>(std::istream& input, Column& col);

	//destructor
	~Column() {
	
	};

};

void operator<<(std::ostream& console, const Column& col) {
	console << std::endl << "Column name: " << col.columnName;
	console << std::endl << "Column type: " << col.columnType;
	console << std::endl << "Column size: " << col.size;
	console << std::endl << "Default value: " << col.defaultValue;
	console << std::endl << "Primary key? " << col.isPrimaryKey;
}

std::istream& operator>>(std::istream& input, Column& col) {
	std::cout << "\nColumn name: ";
	input >> col.columnName;

	std::cout << "\nColumn type: ";
	input >> col.columnType;

	std::cout << "\nColumn size: ";
	input >> col.size;

	std::cout << "\nDefault value: ";
	input >> col.defaultValue;

	std::cout << "\nPrimary key? ";
	input >> col.isPrimaryKey;

	return input;
}
