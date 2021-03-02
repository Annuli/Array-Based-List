
#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>

template <class T>
class arrayListType {

public:

	// Function to output the elements of the list
	void print() const;
	
	// Function to insert an item in the list at the 
	// position specified by location. The item to be inserted 
	// is passed as a parameter to the function.
	void insertAt(int location, const T& insertItem);

	// Function to remove the item from the list at the 
	// position specified by location 
	void removeAt(int location);

	// find the minimum value of the array
	T min() const;
	
	// Constructor
	arrayListType(int size = 5);
	
	// Destructor
	~arrayListType();
	
protected:
	T *list;		// array to hold the list elements
	int length;     // to store the length of the list
	int maxSize;    // to store the maximum size of the list
};

//-----------------------------------------------------------------------------------------------

// Definitions of the class template

// print function definition
template <class T>
void arrayListType<T>::print() const {

	// Display dereference array elements
	for (auto x = 0; x < length; ++x)
		std::cout << *(list + x) << ' ';
}

// find minimum value of the list
template <class T>
T arrayListType<T>::min() const
{
	int smallestArrayNumber = *(list + 0);
	
	// Determine smallest element in the array and return value
	for (auto x = 1; x < length; ++x) {
		if (*(list + x) < smallestArrayNumber)
			smallestArrayNumber = *(list + x);
	}
	// Return the smallest element for the user
	return smallestArrayNumber;
}

 // insertAt function definition
template <class T>
void arrayListType<T>::insertAt(int location, const T& insertItem)
{
	// Add the user's number to the location in the 'list'
	if ((length > -1 && length < maxSize) && (location > -1 && location <= maxSize)) {
		for (auto x = length; x > location; --x)
			list[x] = *(list + (x - 1));

		// Write to the array
		list[location] = insertItem;
		++length;
	}
	// Response if location is out of range of array size
	else {
		std::cout << "Position is out of range. The list does not change." << std::endl;
	}
}

// removeAt function definition
template <class T>
void arrayListType<T>::removeAt(int location)
{
	// Remove the element if location is within the size of the array
	if (location > -1 && location < maxSize) {
		for (auto x = location; x < length; ++x) {
			list[x] = *(list + (x + 1));
		}
		--length;
		std::cout << "After removing the element at position " << location << ", the list is: ";
		print();
		std::cout << "\n";
	}
	// Response if location is out of range of array size
	else {
		std::cout << "The location of the item to be removed is out of range.";
		std::cout << "\nThe list does not change." << std::endl;
	}
}

// constructor function
template <class T>
arrayListType<T>::arrayListType(int size)
{
	if (size < 0)
	{
		std::cout << "The array size must be positive. Creating "
			<< "an array of size 5. " << std::endl;
		maxSize = 5;
	}
	else
		maxSize = size;

	length = 0;
	list = new T[maxSize];
	assert(list != NULL);
}

// destructor function
template <class T>
arrayListType<T>::~arrayListType()
{
	delete[] list;

	// clean up the dangling pointer
	//list = NULL;
}

#endif


