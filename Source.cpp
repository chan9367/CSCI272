#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include "Account.h"
#include <iomanip>
#include <iostream>
#include "MovieTheater.h"
#include "Ticket.h"
#include <fstream>
#include <sstream>

using namespace std;

void printArray(int arr[], int size) {
	int count = 1;
	for (int i = 0; i < size; i++) { 
		cout << setw(3) << arr[i];
		if (count % 10 == 0)cout << "\n";
		else cout << " ";
		count++;
	
	}
	cout << "\n\n";
}

void printAccounts(vector<Account*> accts) {
	for (int i = 0; i < accts.size(); i++) {
		cout << accts[i]->getName() << "\t" << accts[i]->getBalance() << endl;
	}
}

int linearSearch(const int numbers[], const int size, const int searchvalue) {
	for (int i = 0; i < size; i++) {if (searchvalue == numbers[i])return i;}
	return -1;
}

int binarySearch(const int numbers[], const int size, const int searchvalue) {
	int position = -1;
	int low = 0;
	int high = size - 1;
	int middle = (low + high + 1) / 2;

	do {
		if (searchvalue == numbers[middle])
			position = middle;
		else if (searchvalue < numbers[middle])
			high = middle - 1;
		else
			low = middle + 1;
		middle = (low + high + 1) / 2;
	} while (low <= high&&position == -1);
	return position;
}

void insertSort(int numbers[], const int size) {
	for (int i = 0; i < size; i++) {
		int insert = numbers[i];
		int moveTo = i;
		while ((moveTo > 0) && (numbers[moveTo - 1] > insert)) {
			numbers[moveTo] = numbers[moveTo - 1];
			moveTo--;
		}
		numbers[moveTo] = insert;
	}
}

void insertSort(vector<Account*>&accts) {
	for (int i = 0; i < accts.size(); i++) {
		Account* insert = accts[i];
		int moveTo = i;
		while ((moveTo > 0) && (accts[moveTo - 1]->getName() > insert->getName())) {
			accts[moveTo] = accts[moveTo - 1];
			moveTo--;
		}
		accts[moveTo] = insert;
	}
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int size) { 
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				swapped = true;
			}
		}
	} while (swapped == true);
}

void kioskPrintTicket(MovieTheater mt, int number) {
	if (number >= Ticket::getNextTicket() || number < Ticket::getStartTicket()) {
		cout << "\nTicket " << number << " not found.\n";
	}
	else {
		Ticket custTicket = mt.findTicket(number);
		cout << "\n\n====================\nTicket Details"
			<< "\nMovie: " << custTicket.movie
			<< "\nShow Date: " << custTicket.showdate.toString()
			<< "\nShow Time: " << custTicket.showtime.toAMPMformat()
			<< "\nStatus: " << custTicket.status
			<< "\nNumber: " << custTicket.ticketNumber << endl;
	}
}

int main() {
	srand(time(0));
	/*
	const int size = 10;
	int myArray[size];

	int userArraySize;
	cout << "Enter array size: ";
	cin >> userArraySize;

	int * numbers = new int[userArraySize];
	for (int i = 0; i < userArraySize; i++) { numbers[i] = rand() % 1000; }
	
	printArray(numbers, userArraySize);
	bubbleSort(numbers, userArraySize);
	printArray(numbers, userArraySize);

	int search = 555;
	int position = linearSearch(numbers, userArraySize, search);
	if (position != -1) { cout << search << " found at position " << position << endl; }
	else { cout << search << " not found in linear search. \n"; }
	position = binarySearch(numbers, userArraySize, search);
	if (position != -1) {cout << search << " found at position " << position << "\n";}
	else {cout << search << " not found in binary search.\n";}

	
	delete[] numbers;
	*/
	vector<Account*> accounts;
	char accountID = 'E';

	for (int i = 1; i <= 5; i++) {
		int startBal = rand() % 1000;
		string name{ accountID, 1 };
		name = name + "_Account";
		Account* temp = new Account{ name,startBal };
		accounts.push_back(temp);
		accountID -= 1;
	}

	printAccounts(accounts);
	insertSort(accounts);
	cout << endl;
	printAccounts(accounts);


	ofstream outfile("movies.txt", ios::out);
	if (!outfile) {
		cout << "\nCould not open file";
	}
	else {
		outfile << "1,Movie Title,12.50\n";
		outfile.close();
	}

	ifstream infile("movies.txt", ios::in);
	if (!infile) {
		cout << "\nCould not open file";
	}
	else {
		string line, title, price, number;
		getline(infile, line);
		istringstream rowdata{ line };
		getline(rowdata, number, ',');
		getline(rowdata, title, ',');
		getline(rowdata, price, ',');
		cout << "\nNumber: " << number << "\nTitle: " << title << "\nPrice: " << price << endl;
	}

	outfile.open("movies.txt", ios::app);
	if (!outfile) {
		cout << "\nCould not open file";
	}
	else {
		outfile << "2,Movie Title 2,10.00\n";
		outfile.close();
	}

	cout << "\nNext ticket: " << Ticket::getNextTicket();
	cout << "\nStart ticket: " << Ticket::getStartTicket();

	MovieTheater myTheater{ 114 };
	myTheater.setMovieName("Hollywood Blockbuster");
	cout << "\nNow Showing: " << myTheater.getCurrentMovie() << endl;
	cout << "\nAvailable seats: " << myTheater.getAvailableSeats() << endl;

	for (int i = 1; i <= 5; i++) {
		myTheater.sellTicket();
		kioskPrintTicket(myTheater, Ticket::getNextTicket() - 1);
	}

	kioskPrintTicket(myTheater, 103);
	kioskPrintTicket(myTheater, 105);
	kioskPrintTicket(myTheater, 100);
	kioskPrintTicket(myTheater, Ticket::getNextTicket());

	system("pause");
}