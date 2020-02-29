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
	int position = -1;
	int low = 0;
	int high = soldTickets.size() - 1;
	int middle = (low + high + 1) / 2;

	for (int i = 0; i < soldTickets.size(); i++) {
		
		do {
			if (n == soldTickets[i].ticketNumber){
				position = middle;
				Ticket found = soldTickets[i];
				return found;
				}

			else if (n < soldTickets[i].ticketNumber)
				high = middle - 1;
			else
				low = middle + 1;
			middle = (low + high + 1) / 2;
		} while (low <= high&&position == -1);
		
	}
}