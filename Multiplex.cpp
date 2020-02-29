#include "Multiplex.h"
#include <sstream>

/*
================
  DEFINE THESE
================
*/

bool Multiplex::find_movie(std::string movie_search) const {
	for (int i = 0; i < screenings.size(); i++) {
		if (screenings[i]->getCurrentMovie() == movie_search)return true;
	}
	return false;
	// complete definition
}

Multiplex& Multiplex::operator+=(MovieTheater* mt) {
	screenings.push_back(mt);
	return *this;
	// complete definition

}

Multiplex& Multiplex::operator+=(ConcessionStand* cs) {
	foodcourt.push_back(cs);
	return *this;
	// complete definition

}

std::ostream& operator << (std::ostream& out, const Multiplex& mp) {
	out << mp.print_header(); // keep to include "welcome" heading
	out << "\nNOW SHOWING\n===========";
	for (int i = 0; i < mp.screenings.size(); i++) { out << "\n" << mp.screenings[i]->getCurrentMovie(); }
	out << "\n\nVISIT OUR FOOD COURT\n====================\n";
	for (int j = 0; j < mp.foodcourt.size(); j++) { out << mp.foodcourt[j]->getStandName() << "\n"; }
	return out;
	// complete definition

}


/*
===============
ALREADY DEFINED
===============
*/

Multiplex::Multiplex(std::string name) :
	brandname{ name }
{}

std::string Multiplex::get_brandname() const {
	return brandname;
}

std::string Multiplex::print_header() const {

	std::ostringstream output;
	std::string message = "WELCOME TO ";
	int length = get_brandname().size() + message.size();

	output << "\n";

	for (int i = 0; i < length; i++) {
		output << '*';
	}

	output << "\n" << message << get_brandname() << "\n";

	for (int i = 0; i < length; i++) {
		output << '*';
	}

	output << "\n";

	return output.str();
}

