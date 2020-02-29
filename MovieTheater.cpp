#include "MovieTheater.h"
#include "Ticket.h"
#include <vector>

// constructor
MovieTheater::MovieTheater(unsigned int capacity)
{
	setCapacity(capacity);
	setAvailableSeats(capacity);
}

// change values
void MovieTheater::setMovieName(std::string movie) {
	this->movie = movie;
}

void MovieTheater::setCapacity(unsigned int capacity) {
	if (capacity > 0) {
		this->capacity = capacity;
	}
}

void MovieTheater::setAvailableSeats(unsigned int capacity) {
	if (capacity > 0) {
		availableSeats = capacity;
	}
}

int MovieTheater::sellTicket() {
	int number = -1;
	if (availableSeats > 0) {
		Ticket newTicket{ movie, selldate, screentime };
		number = newTicket.ticketNumber;
		soldTickets.push_back(newTicket);
		availableSeats--;
	}
	return number;
}

bool MovieTheater::cancelTicket(int Ticket) {
	if (Ticket < Ticket::getStartTicket() || Ticket >= Ticket::getNextTicket()) { std::cout << "\nERROR INVALID TICKET NUMBER\n"; return false; }
	else { soldTickets[Ticket - Ticket::getStartTicket()].status = "Cancelled";  return true; }
}

// get information (const functions)
unsigned int MovieTheater::getCapacity() const {
	return capacity;
}

unsigned int MovieTheater::getAvailableSeats() const {
	return availableSeats;
}

unsigned int MovieTheater::getNumberSold() const {
	return soldTickets.size();
}

std::string MovieTheater::getCurrentMovie() const {
	return movie;
}

Ticket MovieTheater::findTicket(int n) const {
	for (int i = 0; i < soldTickets.size(); i++) {
		if (soldTickets[i].ticketNumber == n) {
			Ticket found = soldTickets[i];
			return found;
		}
	}
}
void MovieTheater::ticketReport() const {
	for (int k = 0; k < soldTickets.size(); k++) {
		if (soldTickets[k].status == "Active") {
			std::cout << "\n\n====================\nActive Ticket Numbers"
				<< "\nTicket Number " << k+Ticket::getStartTicket() << std::endl;
		}
	}
	for (int j = 0; j < soldTickets.size(); j++) {
		if (soldTickets[j].status == "Cancelled") {
			std::cout << "\n\n====================\nCancelled Ticket Numbers"
				<< "\nTicket Number " << j+Ticket::getStartTicket() << std::endl;
		}
	}

} // lab 4