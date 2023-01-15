#pragma once
#include <string>
#include <iostream>
using namespace std;
class Bilet{
private:
	char* zona;
	int rand;
	int coloana;
	float pret;
	double** loc;
	double ID;
	const int nrRanduri;
	const int nrColoane;
	static int nrBileteGenerateVIP;
	static int nrBileteGenerateStandard;
	const int nrMaxBileteVIP;
	const int nrMaxBileteStandard;
	static int counter;

public:
	//constructorii
	Bilet();
	Bilet(int rand,int coloana, float pret,char* zona,double** loc);
	
	//constructor de copiere
	Bilet(const Bilet& bilet);
	
	//setteri si getteri
	void setID(int rand,int coloana,double** loc);
	double getID();

	void setLoc(double** loc);
	double getLoc(int rand,int coloana);

	int getNrMaxVIP();
	int getNrMaxStandard();

	void setNrBileteGenerateVIP(int val);
	void setNrBileteGenerateStandard(int val);

	int getNrBileteGenerateVIP();
	int getNrBileteGenerateStandard();

	int getNrRanduri();

	int getNrColoane();

	void setRand(int rand);
	int getRand();

	void setColoana(int coloana);
	int getColoana();

	void setPret(float pret, char* zona);
	float getPret();

	void setZona(char* zona);
	char* getZona();

	//operator=
	Bilet& operator=(const Bilet& bilet);

	friend istream& operator>>(istream& in, Bilet& bilet);
	friend ostream& operator<<(ostream& out, Bilet bilet);
	
	//metoda care returneaza numarul de bilete ramase pe total
	int getNrTotalTicketsLeftPerTotal();
	//metoda care returneaza numarul de bilete ramase pe zona
	int getNrTotalTicketsLeftPerArea(char* zona);

	//supraincarcare operator ++ si -- de postincrementare cu parametru pentru a modifica pretul
	Bilet operator++(int i);
	Bilet operator--(int i);
	
	//destructor
	~Bilet();
};

