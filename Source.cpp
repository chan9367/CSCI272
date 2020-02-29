#include "Date.h"
#include "Time.h"
#include "MovieTheater.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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
	kioskPrintTicket(myTheater, 100);
	kioskPrintTicket(myTheater, Ticket::getNextTicket());

	myTheater.cancelTicket(100);
	myTheater.cancelTicket(102); kioskPrintTicket(myTheater, 102);
	myTheater.cancelTicket(104); kioskPrintTicket(myTheater, 104);
	myTheater.ticketReport();

	system("pause");
}