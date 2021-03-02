#include "arrayListType.h"

#include <iostream>
#include <conio.h>


int main() {

	int deletedPosition = -1;
	int userNumber = -1;
	int position = -1;

	// Create a dynamic array with set number of elements
	const int MAX_NUMBER_OF_ELEMENTS = 5;
	int *userArray = NULL;
	userArray = new int[MAX_NUMBER_OF_ELEMENTS];

	// Set dynamic array elements
	arrayListType<int> testArray(MAX_NUMBER_OF_ELEMENTS);

	// Get the user input:
	std::cout << "\nEnter 5 integers: ";
	for (int x = 0; x < MAX_NUMBER_OF_ELEMENTS; ++x) {
		std::cin >> userNumber;
		testArray.insertAt(x, userNumber);
	}

	// Display the initialized list
	std::cout << "\nThe list you entered is: ";
	testArray.print();

	// Ask the user which array element position is to be deleted
	std::cout << "\n\nEnter the position of item to be deleted: ";
	std::cin >> deletedPosition;
	testArray.removeAt(deletedPosition);

	// Ask the user to enter an integer and a position and display 'final' list
	std::cout << "\nEnter the position and an integer to be inserted: ";
	std::cin >> position >> userNumber;
	testArray.insertAt(position, userNumber);
	std::cout << "Final List: ";
	testArray.print();

	// Display the smallest element
	std::cout << "\nThe smallest element: " << testArray.min();

	// Delete the userArray and remove the dangling pointer
	delete[] userArray;
	userArray = NULL;

	// Allow user to see results of program
	std::cout << "\n\nPress any key to continue...";
	_getch();

	return 0;
}
