#pragma once
#include "Date.h"
#include "Auxiliary.h"

using namespace std;

class TravelPack {
	public:
		TravelPack(int identifier, string travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats, int sold_seats);
		TravelPack(int identifier, vector <string> travel_destination, Date DepartureDate, Date ArrivalDate, int price, int maximum_seats, int sold_seats);
		
		//Getters
		int getIdentifier() const;
		vector <string> getTravelDestination() const;
		Date getDepartureDate() const;
		Date getArrivalDate() const;
		int getPrice() const;
		int getMaximumSeats() const;
		int getSoldSeats() const;
		void show() const; //Displays information about the travel pack in question

		//Setters
		void setIdentifier(int identifier);
		void setTravelDestination(string travelDestination);
		void setTravelDestination(vector<string> travelDestination);
		void setArrivalDate(string ArrivalDate);
		void setArrivalDate(Date ArrivalDate);
		void setDepartureDate(string DepartureDate);
		void setDepartureDate(Date DepartureDate);
		void setPrice(int price);
		void setMaximumSeats(int maximum_seats);
		void setSoldSeats(int sold_seats);
	private:
		//Variables/Data Structure
		int identifier;
		vector <string> travelDestination; 
		Date DepartureDate;
		Date ArrivalDate;
		int price;
		int maximum_seats;
		int sold_seats;

		//Functions
		vector <string> convertTravelDestination(string travel_destination);
};