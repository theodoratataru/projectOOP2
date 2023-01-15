#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Bilet.h"
#include "Client.h"
#include "DataEveniment.h"
#include "Eveniment.h"
//#include "Pay.h"
using namespace std;
int main() 
{
	ofstream q("fisier.bin", ios::out | ios::binary);

	cout << "Welcome to The Ticketing App !" << endl;

	int click, i, j;
	Bilet bilet;
	Client client;

	double** sit = new double* [bilet.getNrRanduri()];
	for (i = 0; i < bilet.getNrRanduri(); i++) {
		sit[i] = new double[bilet.getNrColoane()];
	}

	for (i = 0; i < bilet.getNrRanduri(); i++) {
		for (j = 0; j < bilet.getNrColoane(); j++) {
			sit[i][j] = 0;
		}
	}

	int** dates = new int* [3];
	for (i = 0; i < 3; i++) {
		dates[i] = new int[3];
	}

	ifstream f;
	f.open("events.txt", ios::in);
	string event;
	map<int, string>m;
	for (int i = 1; i <= 4; i++) {
		getline(f, event, '\n');
		m.insert(make_pair(i, event));
	}
	f.close();

	//ticket reservation
	string tipBilet;
	char* zona = nullptr;
	int row, column;
	string nume,prenume;
	int varsta;
	char* categorie = nullptr;
	string bufferReader;

	//event & details
	string desiredEvent;
	char* locatie = nullptr;
	int* oreDisponibile = new int[3];
	int nrOreDisponibile = 3;

	int** hours = new int* [4];
	for (i = 0; i < 4; i++) {
		hours[i] = new int[3];
	}

	//tickets Standard
	int nrGeneratedVIPTickets = 0;
	int nrGeneratedStandardTickets = 0;

	//method to pay
	//Pay* pay = nullptr;

	//==============================================================================================================================================
	int buffer1 = 0;
	while (buffer1 == 0) 
	{
		cout << "Choose from the following functionalities:" << endl;
		cout << "1.Display all events" << endl;
		cout << "2.Search an event" << endl;
		cout << "3.Select the date" << endl;
		cout << "4.Ticket reservation" << endl;
		//cout << "5.Pay method" << endl;
		cout << "5.Exit" << endl;
		cout << "Please, choose a number: ";

		int click;
		cin >> click;

		//=========OPTION 8===============
		if (click == 5) {
			exit(0);
		}

		//=========OPTION 1===============
		if (click == 1) 
		{
			cout << "All events: ";
			for (j = 0; j < m.size(); j++) 
			{
				cout << m[j] << endl;
			}
			cout << endl;
		}

		//=========OPTION 2===============

		if (click == 2) 
		{
					cout << "Please enter the name of the event that you want to attend: ";
					cin >> desiredEvent;
					ifstream g;
					g.open("events.txt", ios::in);

					int OK1 = 0;
					for (int j = 0; j < m.size(); j++)
					{
						if (_strcmpi(desiredEvent.c_str(), m[j].c_str()) == 0)
						{
							OK1 = 1;
							break;
						}
					}
					g.close();

					if (OK1 == 1)
					{
						cout << "The event you were looking for was found!";
					}
					else
					{
						cout << "The event you were looking doesn't exist!";
					}

					cout << endl << "Details about the event: " << endl;
					if (OK1 == 1) 
					{
						cout << "Name of the event: " << desiredEvent<<endl;
						cout << "Location: ";

						ifstream r;
						r.open("locations.txt", ios::in);
						string nameOfEvent;
						map<int, string>mapOfEvents;
						for (int i = 0; i < 4; i++) {
							getline(r, nameOfEvent, '\n');
							mapOfEvents.insert(make_pair(i, nameOfEvent));
						}
						r.close();

						if (_strcmpi(desiredEvent.c_str(), "Movie") == 0) 
						{
							cout << mapOfEvents[0] << endl;
						}
						else if (_strcmpi(desiredEvent.c_str(), "Theater") == 0) 
						{
							cout << mapOfEvents[1] << endl;
						}
						else if (_strcmpi(desiredEvent.c_str(), "Stand-up") == 0)
						{
							cout << mapOfEvents[2] << endl;
						}
						else if (_strcmpi(desiredEvent.c_str(), "Football") == 0) 
						{
							cout << mapOfEvents[3] << endl;
						}

						cout << "Available hours: ";
						int ora;
						ifstream hour;
						hour.open("availableHours.txt");
						for (i = 0; i < 4; i++)
						{
							for (j = 0; j < 3; j++)
							{
								hour >> ora;
								hours[i][j] = ora;
							}
						}
						hour.close();

						if (_strcmpi(desiredEvent.c_str(), "Movie") == 0)
						{
							for (j = 0; j < 3; j++) 
							{
								oreDisponibile[j] = hours[0][j];
								cout << oreDisponibile[j] << " ";
							}
						}
						else if (_strcmpi(desiredEvent.c_str(), "Theater") == 0) 
						{
							for (j = 0; j < 3; j++)
							{
								oreDisponibile[j] = hours[1][j];
								cout << oreDisponibile[j] << " ";
							}
						}
						else if (_strcmpi(desiredEvent.c_str(), "Stand-up") == 0) 
						{
							for (j = 0; j < 3; j++)
							{
								oreDisponibile[j] = hours[2][j];
								cout << oreDisponibile[j] << " ";
							}
						}
						else if (_strcmpi(desiredEvent.c_str(), "Football") == 0)
						{
							for (j = 0; j < 3; j++)
							{
								oreDisponibile[j] = hours[3][j];
								cout << oreDisponibile[j] << " ";
							}
						}
						cout << endl;
					}
					else {
						cout << "The event you were looking doesn't exist!" << endl;
					}
					cout << endl;
		}

		if (click == 3)
		{
			int num;
			ifstream l;
			l.open("dates.txt");
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++) 
				{
					l >> num;
					dates[i][j] = num;
				}
			}
			l.close();

			cout << "Available events dates: " << endl;
			for (i = 0; i < 3; i++)
			{
				cout << i + 1 << ". ";
				for (j = 0; j < 3; j++)
				{
					if (j == 0) {
						cout << "year " << dates[i][j] << " ";
					}
					else if (j == 1) {
						cout << "month " << dates[i][j] << " ";
					}
					else if (j == 2) {
						cout << "day " << dates[i][j] << " ";
					}
				}
				cout << endl;
			}
			int chooseDate;
			cout << "Please, select a date from 1,2,3: ";
			cin >> chooseDate;

			int* vector = new int[3];
			for (j = 0; j < 3; j++)
			{
				vector[j] = dates[chooseDate - 1][j];
			}

			cout << "The selected date is: "<<endl;
			for (j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					cout << "year " << vector[j] << " ";
				}
				else if (j == 1)
				{
					cout << "month " << vector[j] << " ";
				}
				else if (j == 2)
				{
					cout << "day " << vector[j];
				}
			}
			cout << endl;
		}


		//==========OPTION 4==============
		if (click == 4)
		{
			int buffer2 = 0;
			while (buffer2 == 0) 
			{
				int click2;
				cout << "1.The type of ticket" << endl;
				cout << "2.Choose the row and column where you want to sit" << endl;
				cout << "3.Personal data" << endl;
				cout << "4.The price of the ticket" << endl;
				cout << "5.Ticket check" << endl;
				cout << "6.Exit" << endl;
				cout << "Please, choose a number: ";

				cin >> click2;

				if (click2 == 1) 
				{
					cout << "Do you want a standard or a vip ticket?" << endl;

					cin >> tipBilet;

					zona = new char[tipBilet.length() + 1];
					strcpy_s(zona, tipBilet.length() + 1, tipBilet.c_str());
					bilet.setZona(zona);
				}
	
				if (click2 == 2)
				{
					cout << "Row: ";
					cin >> row;
					bilet.setRand(row);

					cout << "Column: ";
					cin >> column;
					bilet.setColoana(column);

					bilet.setID(row, column, sit);

					q.write(reinterpret_cast<char*>(&bilet), sizeof(bilet));
					
					if (_strcmpi(bilet.getZona(), "VIP") == 0)
					{
						bilet.setNrBileteGenerateVIP(nrGeneratedVIPTickets);
						nrGeneratedVIPTickets++;
						cout << "Generated VIP tickets: " << nrGeneratedVIPTickets << endl;
						cout << "VIP tickets left: " << bilet.getNrMaxVIP() - nrGeneratedVIPTickets << endl;
					}
					else if (_strcmpi(bilet.getZona(), "standard") == 0)
					{
						bilet.setNrBileteGenerateStandard(nrGeneratedStandardTickets);
						nrGeneratedStandardTickets++;
						cout << "Generated standard tickets: " << nrGeneratedStandardTickets << endl;
						cout << "Standard tickets left: " << bilet.getNrMaxStandard() - nrGeneratedStandardTickets << endl;
					}
					
				}

				if (click2 == 3)
				{
					cout << "Last name: ";
					cin >> nume;
					client.setNume(nume);
					cout << "First name: ";
					cin >> prenume;
					client.setPrenume(prenume);
					cout << "Age: ";
					cin >> varsta;
					client.setVarsta(varsta);
					cout << "Category: ";
					cin >> bufferReader;
					if (_strcmpi(bufferReader.c_str(), "pensionar") == 0 || _strcmpi(bufferReader.c_str(), "adult") == 0 || _strcmpi(bufferReader.c_str(), "student") == 0 || _strcmpi(bufferReader.c_str(), "copil") == 0)
					{
						client.setCategorie(bufferReader.c_str());
					}
					else {
						cout << "TRY AGAIN, this category doesn't exist!" << endl;
						cout << "Category: ";
						cin >> bufferReader;

					}
					cout << endl;
				}

				if (click2 == 4) 
				{
					cout << "What type of ticket do you want to buy?" << endl;
					cin >> tipBilet;
					if (_strcmpi(tipBilet.c_str(), "Standard") == 0 || _strcmpi(tipBilet.c_str(), "VIP") == 0)
					{
						bilet.setPret(10.5, zona);
						cout << "The price of the ticket is: " << bilet.getPret() << endl;
					}
					else 
					{
						cout << "TRY AGAIN, this type of ticket doesn't exist!" << endl;
						cout << "What type of ticket do you want to buy?" << endl;
						cin >> tipBilet;
					}
					
				}

				if (click2 == 5) 
				{
					cout << "Row: ";
					cin >> row;
					bilet.setRand(row);
					cout << "Column: ";
					bilet.setColoana(column);
					cin >> column;
					int k = 0;
					for (i = 0; i < bilet.getNrRanduri(); i++) {
						for (j = 0; j < bilet.getNrColoane(); j++) {
							if (sit[bilet.getRand()][bilet.getColoana()] == sit[i][j]) {
								k++;
							}
						}
					}
					if (k == 1)
					{
						cout << "Valid ticket !";
					}
					else if (k > 1) {
						cout << "Invalid ticket !";

					}
					cout << endl;
				}

				if (click2 == 6)
				{
					break;
				}
				
				//buffer2 = 1;
				cout << endl;
			}
		}	
		//if (click == 5) {
		//	//pay = &client;
		//	pay->disponibilitate();
		//}
	}
	q.close();
}
		
	
