﻿/*                                                       |
												   --====|====--
														 |  

													 .-"""""-. 
												   .'_________'. 
												  /_/_|__|__|_\_\
												 ;'-._       _.-';
							,--------------------|    `-. .-'    |--------------------,
							 ``""--..__    ___   ;       '       ;   ___    __..--""``
									   `"-// \\.._\             /_..// \\-"`
										  \\_//    '._       _.'    \\_//
										   `"`        ``---``        `"` 

	1. Ler e guardar a informação da agência, dos clientes e dos pacotes turísticos armazenada em
	ficheiros. ✔
	2. Gerir os clientes e pacotes turísticos: criar, alterar e remover um cliente ou um pacote turístico. 
	3. Gerar e visualizar de modo formatado a informação de um cliente especificado. ✔
	4. Gerar e visualizar de modo formatado a informação de todos os clientes da agência. ✔
	5. Gerar e visualizar de modo formatado os pacotes turísticos disponíveis (todos, todos relativos a
	um destino específico, todos entre duas datas, todos os relativos a um destino específico e entre
	duas datas). ✔
	6. Gerar e visualizar de modo formatado os pacotes turísticos vendidos (a um cliente específico, a
	todos os clientes). 
	7. Efetuar a compra de um pacote turístico por um cliente.
	8. Calcular e visualizar o número e o valor total de pacotes vendidos.


	1 - Ler os ficheiros: ✔
		a) "agency.txt" (informação estática da agência) ✔
	    b) "clients.txt" (por exemplo) ✔
	    c) "packs.txt" (por exemplo) ✔

	2 - Guardar os dados lidos dos ficheiros nas estruturas de dados internas do programa ✔

	3 - Exibir um menu onde aparecem as opções que implementam as funcionalidades ✔
		a) Gestão de clientes 
		b) Gestão de pacotes turísticos
		c) Visualização de informação (sobre clientes e sobre pacote turísticos)

	4 - Atualizar os dados nos ficheiros antes do fim da execução (se necessário)
	
	PS: Tomar precauções contra entras válidas (i.e. valores fora da gama admissível)

*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
#include "AuxiliaryFunctions.h"
#include "GetFunctions.h"
#include "SaveFunctions.h"
#include "VisualizeFunctions.h"

using namespace std;

void BuyTravelPack(vector <TravelPack> StructTravelPacks) {
}

Client CreateClient(vector <Client> &StructClients) {
	Client AuxStruct;
	string ClientAddress, ClientAdquiredTravelPacks;
	
	cout << "What's the name of the new client? ";
	getline(cin, AuxStruct.Name);
	cout << "What's the NIF of the new client? ";
	cin >> AuxStruct.NIF;
	cin.ignore();
	cout << "What's the household of the new client? ";
	cin >> AuxStruct.Household;
	cin.ignore();
	cout << "What's the address of the new client (insert in the format 'Street / Door Number / Apartment / ZIP Code / Province')? ";
	getline(cin, ClientAddress);
	GetAddress(AuxStruct.ClientAddress, ClientAddress);
	cout << "Which travel packs did the new client adquire (separated by ';'): ";
	getline(cin, ClientAdquiredTravelPacks);
	AuxStruct.AdquiredTravelPacks = GetAdquiredTravelPacks(ClientAdquiredTravelPacks);

	return AuxStruct;
}

void ChangeClient(vector <Client> &StructClients) {
	
}

void RemoveClient(int ClientNumber, vector <Client> &StructClients) {
	vector <Client> AuxVector;

	for (int i = 0; i < size(StructClients); i++)
		if (i != ClientNumber)
			AuxVector.push_back(StructClients[i]);

	StructClients = AuxVector;
}

void ManageClients(vector <Client> &StructClients) {
	int Selection;

	cout << "What do you want to do ? Insert the corresponding key." << endl << endl
		 << "1) Create a new client." << endl
		 << "2) Change the information of a client." << endl
		 << "3) Remove an existent client." << endl;

	cin >> Selection;
	cin.ignore();
	cout << endl;

	switch (Selection) {
		case 1:
			StructClients.push_back(CreateClient(StructClients));
			break;
		case 2:
			ChangeClient(StructClients);
			break;
		case 3:
			int ClientNumber;

			cout << "Insert the number of the client that you want to remove: "; //Change to NIF or something else
			cin >> ClientNumber;
			cin.ignore();
			cout << endl;

			RemoveClient(ClientNumber, StructClients);
			break;
	}
}

void CreateTravelPack(vector <TravelPack> StructTravelPacks) {

}

void ChangeTravelPack(vector <TravelPack> StructTravelPacks) {

}

void RemoveTravelPack(vector <TravelPack> StructTravelPacks) {

}

void ManageTravelPacks(vector <TravelPack> StructTravelPacks) {
	int Selection;

	cout << "What do you want to do ? Insert the corresponding key." << endl << endl
		<< "1) Create a new travel pack." << endl
		<< "2) Change the information of a travel pack." << endl
		<< "3) Remove an existent travel pack." << endl;

	cin >> Selection;
	cin.ignore();
	cout << endl;

	switch (Selection) {
		case 1:
			CreateTravelPack(StructTravelPacks);
		case 2:
			ChangeTravelPack(StructTravelPacks);
		case 3:
			RemoveTravelPack(StructTravelPacks);
	}
}

void Menu(vector <Client> &StructClients, vector <TravelPack> &StructTravelPacks) {
	int Selection;

	cout << "What do you want to do? Insert the corresponding key." << endl << endl
		 << "1) Manage clients." << endl
		 << "2) Manage travel packs." << endl
		 << "3) Visualize a specific client." << endl
	     << "4) Visualize all the clients of the agency." << endl
		 << "5) Visualize available travel packs." << endl
	 	 << "6) Visualize sold travel packs." << endl
		 << "7) Buy a travel pack for a client." << endl 
		 << "0) Exit the program" << endl;

	cin >> Selection;
	cin.ignore();
	cout << endl;

	switch (Selection) {
		case 1:
			ManageClients(StructClients);
			break;
		case 2:
			ManageTravelPacks(StructTravelPacks);
			break;
		case 3:
			int ClientNumber;

			cout << "Insert the client number: "; 
			cin >> ClientNumber;
			cin.ignore();
			cout << endl;

			VisualizeSpecificClient(ClientNumber, StructClients);
			break;
		case 4:
			VisualizeAgencyClients(StructClients);
			break;
		case 5:
			VisualizeAvailableTravelPacks(StructTravelPacks);
			break;
		case 6:
			VisualizeSoldTravelPacks(StructTravelPacks, StructClients);
			break;
		case 7:
			BuyTravelPack(StructTravelPacks);
			break;	
	}
}

int main() {
	string AgencyFile = "agency.txt"; //Deixar o utilizador inserir o nome do ficheiro
	Agency StructAgency;
	vector <Client> StructClients; 
	vector <TravelPack> StructTravelPacks; 

	StructAgency = SaveAgency(AgencyFile);
	SaveClients(StructAgency.ClientsFile, StructClients);
	SaveTravelPacks(StructAgency.TravelPacksFile, StructTravelPacks);

	Menu(StructClients, StructTravelPacks);

	return 0;
}