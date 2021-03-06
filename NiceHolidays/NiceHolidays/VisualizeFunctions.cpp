#include <iostream>
#include <iomanip>
#include <vector>
#include <fcntl.h>
#include <io.h>
#include "Structs.h"
#include "AuxiliaryFunctions.h"
#include "VisualizeFunctions.h"
#include "ReadFunctions.h"

void visualizeSpecificClient(int ClientNumber, std::vector <Client> StructClients) {
	std::cout << "Name: " << StructClients[ClientNumber].Name << std::endl
	          << "NIF: " << StructClients[ClientNumber].NIF << std::endl
		      << "Household: " << StructClients[ClientNumber].Household << std::endl
		      << "Address: " << StructClients[ClientNumber].ClientAddress.Street << ", " //Modify to paragrafh and insert blank spaces
		      << StructClients[ClientNumber].ClientAddress.DoorNumber << ", "
		      << StructClients[ClientNumber].ClientAddress.Apartment << ", "
		      << StructClients[ClientNumber].ClientAddress.ZIPCode << ", "
		      << StructClients[ClientNumber].ClientAddress.Province << std::endl
		      << "Adquired Travel Packs: ";

	for (int i = 0; i < size(StructClients[ClientNumber].AdquiredTravelPacks); i++) {
		if (i < size(StructClients[ClientNumber].AdquiredTravelPacks) - 1)
			std::cout << StructClients[ClientNumber].AdquiredTravelPacks[i] << ", ";

		else
			std::cout << StructClients[ClientNumber].AdquiredTravelPacks[i] << std::endl << std::endl;
	}
}

void visualizeAgencyClients(std::vector <Client> StructClients) {
	for (int i = 0; i < size(StructClients); i++)
		visualizeSpecificClient(i, StructClients);
}

void visualizeSpecificTravelPack(int TravelPackNumber, std::vector <TravelPack> StructTravelPacks) {
	std::cout << "Numeric identifier: " << StructTravelPacks[TravelPackNumber].Identifier << std::endl
              << "Travel destination: ";

	for (int i = 0; i < size(StructTravelPacks[TravelPackNumber].TravelDestination); i++) {
		if (i == 0) 
			std::cout << StructTravelPacks[TravelPackNumber].TravelDestination[i] << " - ";
		
		else if (i < size(StructTravelPacks[TravelPackNumber].TravelDestination) - 1)
			std::cout << StructTravelPacks[TravelPackNumber].TravelDestination[i] << ", ";

		else
			std::cout << StructTravelPacks[TravelPackNumber].TravelDestination[i] << std::endl;
}

	std::cout << "Departure date: " << StructTravelPacks[TravelPackNumber].DepartureDate.Year
			  << '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].DepartureDate.Month
			  << '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].DepartureDate.Day << std::endl
			  << "Arrival date: " << StructTravelPacks[TravelPackNumber].ArrivalDate.Year
			  << '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].ArrivalDate.Month
			  << '/' << std::setw(2) << std::setfill('0') << StructTravelPacks[TravelPackNumber].ArrivalDate.Day << std::endl
			  << "Price per person: " << StructTravelPacks[TravelPackNumber].Price << std::endl
			  << "Initially available seats: " << StructTravelPacks[TravelPackNumber].InitiallyAvailableSeats << std::endl
			  << "Sold seats: " << StructTravelPacks[TravelPackNumber].SoldSeats << std::endl << std::endl;
}

void visualizeAvailableTravelPacks(std::vector <TravelPack> StructTravelPacks) {
	std::string AuxString;
	int selection, AuxYear1, AuxMonth1, AuxDay1, AuxYear2, AuxMonth2, AuxDay2;
	char FirstSlash, SecondSlash;

	std::cout << "What travel packs do you want to consult? Insert the corresponding key." << std::endl << std::endl
		      << "1) All." << std::endl
		 	  << "2) All related to a specific travel destination." << std::endl
			  << "3) All between two dates." << std::endl
			  << "4) All related to a specific travel destination and between two dates." << std::endl
			  << "0) Go back." << std::endl;

	selection = readSelection(0, 4);
	std::cin.ignore();

	switch (selection) {
		case 1:
			system("cls");
			for (int i = 0; i < size(StructTravelPacks); i++) {
				if (isAvailable(i, StructTravelPacks))
					visualizeSpecificTravelPack(i, StructTravelPacks);
			}
			break;
		case 2:
			std::cout << std::endl << "Insert the travel destination: ";
			getline(std::cin, AuxString);

			for (int i = 0; i <= 2; i++) {
				if (find(StructTravelPacks[i].TravelDestination.begin(), StructTravelPacks[i].TravelDestination.end(), AuxString) != StructTravelPacks[i].TravelDestination.end() 
					&& isAvailable(i, StructTravelPacks))
					visualizeSpecificTravelPack(i, StructTravelPacks);
			}
			break;
		case 3:
			std::cout << "Insert the first date (in the format 'YYYY/MM/DD'): ";
			std::cin >> AuxYear1 >> FirstSlash >> AuxMonth1 >> SecondSlash >> AuxDay1; //validar
			std::cin.ignore();
			std::cout << "Insert the second date (in the format 'YYYY/MM/DD'): ";
			std::cin >> AuxYear2 >> FirstSlash >> AuxMonth2 >> SecondSlash >> AuxDay2;

			for (int i = 0; i <= 2; i++) {
				if (isBefore(AuxYear1, AuxMonth1, AuxDay1, StructTravelPacks[i].DepartureDate.Year, StructTravelPacks[i].DepartureDate.Month, StructTravelPacks[i].DepartureDate.Day)
					&& isAfter(AuxYear2, AuxMonth2, AuxDay2, StructTravelPacks[i].ArrivalDate.Year, StructTravelPacks[i].ArrivalDate.Month, StructTravelPacks[i].ArrivalDate.Day)
					&& isAvailable(i, StructTravelPacks))
					visualizeSpecificTravelPack(i, StructTravelPacks);
			}
			break;
		case 4:
			std::cout << "Insert the first date (YYYY/MM/DD): ";
			std::cin >> AuxYear1 >> FirstSlash >> AuxMonth1 >> SecondSlash >> AuxDay1;
			std::cin.ignore();
			std::cout << "Insert the second date (YYYY/MM/DD): ";
			std::cin >> AuxYear2 >> FirstSlash >> AuxMonth2 >> SecondSlash >> AuxDay2;
			std::cin.ignore();
			std::cout << std::endl << "Insert the travel destination: ";
			getline(std::cin, AuxString);

			for (int i = 0; i <= 2; i++) {
				if (isBefore(AuxYear1, AuxMonth1, AuxDay1, StructTravelPacks[i].DepartureDate.Year, StructTravelPacks[i].DepartureDate.Month, StructTravelPacks[i].DepartureDate.Day) 
					&& isAfter(AuxYear2, AuxMonth2, AuxDay2, StructTravelPacks[i].ArrivalDate.Year, StructTravelPacks[i].ArrivalDate.Month, StructTravelPacks[i].ArrivalDate.Day)					
					&& find(StructTravelPacks[i].TravelDestination.begin(), StructTravelPacks[i].TravelDestination.end(), AuxString) != StructTravelPacks[i].TravelDestination.end() 
					&& isAvailable(i, StructTravelPacks))
					visualizeSpecificTravelPack(i, StructTravelPacks);
			}

			break;
		case 0:
			system("cls");
			break;
	}
}

void visualizeSoldTravelPacks(std::vector <TravelPack> StructTravelPacks, std::vector <Client> StructClients) {
	int selection, AuxNumber;

	std::cout << "What travel packs do you want to consult? Insert the corresponding key." << std::endl << std::endl
		      << "1) Related to a specific client." << std::endl
			  << "2) Related to any client" << std::endl
			  << "0) Go back." << std::endl;

	selection = readSelection(0, 2);
	std::cin.ignore();

	switch (selection) {
		case 1:
			system("cls");
			std::cout << "Related to which client? Insert the corresponding key." << std::endl << std::endl;
			visualizeClientsSelection(StructClients);

			AuxNumber = readSelection(1, size(StructClients));
			std::cin.ignore();

			for (int i1 = 0; i1 < size(StructClients[AuxNumber].AdquiredTravelPacks); i1++) {
				for (int i2 = 0; i2 < size(StructTravelPacks); i2++) 
					if (StructClients[AuxNumber].AdquiredTravelPacks[i1] == abs(StructTravelPacks[i2].Identifier))
						visualizeSpecificTravelPack(i2, StructTravelPacks);
			}
			
			break;
		case 2: //Fazer
			system("cls");
			break;
		case 0:
			system("cls");
			break;
	}
}

void visualizeClientsSelection(std::vector <Client> StructClients) {
	for (int i = 0; i < size(StructClients); i++) 
		std::cout << i + 1 << ") " << StructClients[i].Name << " (" << StructClients[i].NIF << ")" << std::endl;	
}

void visualizeTravelPacksSelection(std::vector <TravelPack> StructTravelPacks) { //availabel and non available
	for (int i = 0; i < size(StructTravelPacks); i++)
		std::cout << i + 1 << ") " << StructTravelPacks[i].TravelDestination[0] << " (" << StructTravelPacks[i].Identifier << ")" << std::endl;
}