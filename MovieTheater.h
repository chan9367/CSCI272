#pragma once
#include "Time.h"
#include "Date.h"
#include "Ticket.h"
#include <iostream>
#include <string>
#include <vector>

#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H


class MovieTheater {

public:

	// constructor
	MovieTheater(unsigned int);

	// change values
	void setMovieName(std::string);
	void setCapacity(unsigned int);
	void setAvailableSeats(unsigned int);
	int sellTicket();
	bool cancelTicket(int Ticket); // lab 4

	// get information (const functions)
	unsigned int getCapacity() const;
	unsigned int getAvailableSeats() const;
	unsigned int getNumberSold() const;
	std::string getCurrentMovie() const;
	Ticket findTicket(int) const;
	void ticketReport() const; // lab 4


private:
	// data members
	std::string movie{ "unknown" };
	unsigned int availableSeats{ 0 };
	unsigned int capacity{ 0 };
	Date selldate{ 3, 1, 2019 };
	Time screentime{ 20 };
	std::vector<Ticket> soldTickets;
};

#endif