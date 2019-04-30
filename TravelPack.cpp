#include "TravelPack.h"

TravelPack::TravelPack(int identifier, string travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats) {
	this->identifier = identifier;
	this->travelDestination = convertTravelDestination(travel_destination);
	this->DepartureDate = DepartureDate;
	this->ArrivalDate = ArrivalDate;
	this->price = price;
	this->maximum_seats = maximum_seats;
}

int TravelPack::getIdentifier() const {
	return identifier;
}

vector <string> TravelPack::getTravelDestination() const {
	return travelDestination;
}

void TravelPack::setIdentifier(int identifier) {
	this->identifier = identifier;
}

void TravelPack::setTravelDestination(vector <string> travelDestination) {
	this->travelDestination = travelDestination;
}
void TravelPack::setArrivalDate(Date ArrivalDate) {
	this->ArrivalDate = ArrivalDate;
}

void TravelPack::setDepartureDate(Date DepartureDate) {
	this->DepartureDate = DepartureDate;
}

void TravelPack::setPrice(int price) {
	this->price = price;
}

void TravelPack::setMaximumSeats(int maximum_seats) {
	this->maximum_seats = maximum_seats;
}

vector <string> TravelPack::convertTravelDestination(string travel_destination) {
	vector <string> result;
	string aux_string;

	for (int i = 0; i < travel_destination.length(); i++)
		if (travel_destination[i] == '�' || travel_destination[i] == ',' || travel_destination[i] == '-') {
			result.push_back(trim(aux_string));
			aux_string = "";
		}

		else
			aux_string += travel_destination[i];

	result.push_back(trim(aux_string));

	return result;
}