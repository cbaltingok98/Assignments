// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>


using namespace std;

template <typename Data>
class DynamicgArray {
public:
	DynamicArray();
	DynamicArray(const DynamicArray& otherObj);
	~DynamicArray();
	DynamicArray& operator = (const DynamicArray& rightSide);
	void addEntry(Data newEntry);
	string deleteEntry(Data newEntyr);
	string getEntry(Data index);
	int getSize();
private:
	Data *dynamicArray;
	int size;
	
};

template <typename Data>
DynamicArray<Data>::DynamicArray() {
	dynamicArray = NULL;
	size = 0;
}

//Copy constructor
template <typename Data>
DynamicArray<Data>::DynamicArray(const DynamicArray& otherObj) {
	this->size = otherObj.size;
	if (size == 0) {
		dynamicArray = NULL;
	}
	else {
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = otherObj.dynamicArray[i];
		}
	}
}

//overload asignment
template <typename Data>
DynamicArray<Data> & DynamicArray<Data>::operator=(const DynamicArray& rightSide) {
	if (this->dynamicArray != NULL) {
		delete[] dynamicArray;
	}
	if (rightSide.size == 0) {
		size - 0;
		dynamicArray = NULL;
	}
	else {
		size = rightSide.size;
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++) {
			dynamicArray[i] = rightSide.dynamicArray[i];
		}
	}
	return *this;
}

template <typename Data>
DynamicArray<Data>::~DynamicArray() {
	if (dynamicArray != NULL) {
		delete[] dynamicArray;
	}

}

template <typename Data>
int DynamicArray<Data>::getSize() {
	return size;
}

template <typename Data>
void DynamicArray<Data>::addEntry(Data newEntry) {
	Data *newArray = new Data[size + 1];
	for (int i = 0; i < size; i++) {
		newArray[i] = dynamicArray[i];
	}
	delete[] dynamicArray;
	dynamicArray = newArray;

	newArray[size++] = newEntry;
}

template <typename Data>
string DynamicArray<Data>::deleteEntry(Data entry) {

	Data *result = NULL;
	int pos = -1;

	for (int i = 0; (i < size) && (pos == -1); i++) {
		if (dynamicArray[i] == entry) {
			pos = i;
		}
	}

	if (pos == -1) {
		return false;
	}
	if (size > 1) {
		result = new Data[size - 1];
	}
	for (int i = 0; j = 0; i < size; i++) {
		if (i != pos) {
			result[j++] = dynamicArray[i];
		}
	}
	size--;
	delete[] dynamicArray;
	dynamicArray = result;

	return true;
}

template <typename Data>
string DynamicArray<Data>::getEntry(Data index) {
	if ((index < 0) || (index >= size)) {
		return NULL;
	}
	return dynamicArray[index];
}


template <typename Data>
int main()
{
	DynamicArray<Data> names;
	// List of names
	names.addEntry("Frank");
	names.addEntry("Wiggum");
	names.addEntry("Nahasapeemapetilon");
	names.addEntry("Quimby");
	names.addEntry("Flanders");
	// Output list
	cout << "List of names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	// Add and remove some names
	names.addEntry("Spuckler");
	cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.deleteEntry("Nahasapeemapetilon");
	cout << "After removing a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.deleteEntry("Skinner");
	cout << "After removing a name that isn't on the list:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.addEntry("Muntz");
	cout << "After adding another name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	// Remove all of the names by repeatedly deleting the last one
	while (names.getSize() > 0) {
		names.deleteEntry(names.getEntry(names.getSize() - 1));
	}
	cout << "After removing all of the names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.addEntry("Olivia");
	cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	cout << "Testing copy constructor" << endl;
	DynamicArray<string> names2(names);
	// Remove Olivia from names
	names.deleteEntry("Olivia");
	cout << "Copied names:" << endl;
	for (int i = 0; i < names2.getSize(); i++)
		cout << names2.getEntry(i) << endl;
	cout << endl;
	cout << "Testing assignment" << endl;
	DynamicArray<string> names3 = names2;
	// Remove Olivia from names2
	names2.deleteEntry("Olivia");
	cout << "Copied names:" << endl;
	for (int i = 0; i < names3.getSize(); i++)
		cout << names3.getEntry(i) << endl;
	cout << endl;
	cout << "Testing dynamic array of ints" << endl;
	DynamicArray<int> nums;
	nums.addEntry(10);
	nums.addEntry(20);
	nums.addEntry(30);
	for (int i = 0; i < nums.getSize(); i++)
		cout << nums.getEntry(i) << endl;
	cout << endl;
	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;

	return 0;
}

