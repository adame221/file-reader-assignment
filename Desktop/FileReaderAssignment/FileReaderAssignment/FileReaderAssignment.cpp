/* FileReaderAssignment.cpp : Reads a text file of numbers.  The program then puts the numbers into an integer array.  Once the 
	array is set, the program figures out the lowest and highest number in the array, the average of the array, and the total 
	of the numbers in the array.
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

//Declare prototypes
void getHighestValue(const int, int[]);
void getLowestValue(const int, int[]);
void getTotals(const int, int[]);

int main() {
	//Declare local variables
	const int ARRAY_SIZE = 12;
	int numbers[ARRAY_SIZE];
	int count = 0;
	ifstream inputFile;

	//Open the numbers files
	inputFile.open("numbers.txt");
	
	//Loop through the numbers.txt file and assign each number to the array
	while (count < ARRAY_SIZE && inputFile >> numbers[count]) {
		count++;
	}

	getLowestValue(ARRAY_SIZE, numbers);
	getHighestValue(ARRAY_SIZE, numbers);
	getTotals(ARRAY_SIZE, numbers);

    return 0;
}

/* This function accepts the size of the array and the array itself as parameters.  It then loops through the array
and calcualtes a totals. Once the loop is complete it then calcuates an average.
*/
void getTotals(const int SIZE, int highArray[]) {

	//Dclare local variables
	int count;
	int total = 0;
	int average;

	//Loop through the array and calucate the total
	for (count = 0; count < SIZE; count++) {
		total = total + highArray[count];
	}

	//Calculate average
	average = total / SIZE;

	//Output the total and average to the console
	cout << "Average of the numbers in the numbers.txt file: " << average << endl;
	cout << "Total of the numbers in the numbers.txt file: " << total << endl;
}

/* This function accepts the size of the array and the array itself as parameters.  It then loops through the array
and finds the highest number in the array.
*/
void getHighestValue(const int SIZE, int highArray[]) {

	//Dclare local variables
	int count;
	int highest;

	highest = highArray[0];

	//Loop through the array and find out what the highest number of the array is
	for (count = 1; count < SIZE; count++) {

		if (highArray[count] > highest) {
			highest = highArray[count];
		}
	}

	//Output the highest number to the console
	cout << "Higest number in the numbers.txt file: " << highest << endl;
}

/* This function accepts the size of the array and the array itself as parameters.  It then loops through the array
	and finds the lowest number in the array.
*/
void getLowestValue(const int SIZE, int lowArray[]) {

	//Dclare local variables
	int count;
	int lowest;

	lowest = lowArray[0];
	
	//Loop through the array and find out what the lowest number of the array is
	for (count = 1; count < SIZE; count++) {
		
		if (lowArray[count] < lowest) {
			lowest = lowArray[count];
		}
	}

	//Output the lowest number to the console
	cout << "Lowest number in the numbers.txt file: " << lowest << endl;
}

