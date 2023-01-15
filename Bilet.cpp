#include "Bilet.h"
#include "Client.h"
int Bilet::counter = 2;
int Bilet::nrBileteGenerateVIP = 0;
int Bilet::nrBileteGenerateStandard = 0;

Bilet::Bilet():nrRanduri(10),nrColoane(10),nrMaxBileteVIP(40),nrMaxBileteStandard(60)
{
	ID = NULL;
	loc = NULL;
	pret = 0;
	zona = nullptr;
	rand = -1;
	coloana = -1;
}

Bilet::Bilet(int rand, int coloana, float pret, char* zona,double** loc) : nrRanduri(10),nrColoane(10),nrMaxBileteVIP(40),nrMaxBileteStandard(60)
{
	this->pret = pret;

	if (zona != nullptr) {
		this->zona = new char[strlen(zona) + 1];
		for (int i = 0; i < strlen(zona) + 1; i++) {
			this->zona[i] = zona[i];
		}
	}
	else {
		this->zona = nullptr;
	}


	if (nrRanduri > 0 && nrColoane > 0 && rand <= nrRanduri && coloana <= nrColoane) {
		this->rand = rand;
		this->coloana = coloana;
		this->loc = new double* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++) {
			this->loc[i] = new double[nrColoane];
		}
	}
	else {
		this->loc = NULL;
		this->rand = -1;
		this->coloana = -1;
	}

}

Bilet::Bilet(const Bilet& bilet) :nrRanduri(10), nrColoane(10),nrMaxBileteVIP(40),nrMaxBileteStandard(60)
{
	this->pret = pret;
	this->ID = bilet.ID;

	if (bilet.nrRanduri > 0 && bilet.nrColoane > 0 && bilet.rand <= nrRanduri && bilet.coloana <= bilet.nrColoane) {
		this->rand = bilet.rand;
		this->coloana = bilet.coloana;
		this->loc = new double* [bilet.nrRanduri];
		for (int i = 0; i < bilet.nrRanduri; i++) {
			this->loc[i] = new double[bilet.nrColoane];
		}
	}
	else {
		this->loc = NULL;
		this->rand = -1;
		this->coloana = -1;
	}
	if (bilet.zona != nullptr) {
		this->zona = new char[strlen(bilet.zona) + 1];
		for (int i = 0; i < strlen(bilet.zona) + 1; i++) {
			this->zona[i] = bilet.zona[i];
		}
	}
	else {
		this->zona = nullptr;
	}
}

Bilet& Bilet::operator=(const Bilet& bilet) {
	if (this != &bilet) {
		if (zona != nullptr) {
			delete[] zona;
			zona = nullptr;
		}
		if (loc != NULL) {
			for (int i = 0; i < nrRanduri; i++) {
				delete[] loc[i];
			}
			delete[] loc;
			loc = nullptr;
		}

		this->zona = new char[strlen(bilet.zona) + 1];
		for (int i = 0; i < strlen(bilet.zona) + 1; i++) {
			this->zona[i] = bilet.zona[i];
		}

		this->pret = bilet.pret;
		this->rand = bilet.rand;
		this->coloana = bilet.coloana;

		this->loc = new double* [bilet.nrRanduri];
		for (int i = 0; i < bilet.nrRanduri; i++) {
			this->loc[i] = new double[bilet.nrColoane];
		}
	}
	return *this;
}

int Bilet::getNrMaxVIP() {
	return nrMaxBileteVIP;
}

int Bilet::getNrMaxStandard() {
	return nrMaxBileteStandard;
}

int Bilet::getNrBileteGenerateVIP(){
	return Bilet::nrBileteGenerateVIP;
}

int Bilet::getNrBileteGenerateStandard() {
	return Bilet::nrBileteGenerateStandard;
}

void Bilet::setNrBileteGenerateVIP(int val) {
	nrBileteGenerateVIP = val;
}

void Bilet::setNrBileteGenerateStandard(int val) {
	nrBileteGenerateStandard = val;
}


void Bilet::setID(int rand,int coloana,double** loc) {
	ID = log10(counter);
	counter++;
	loc[rand][coloana] = ID;
}

double Bilet::getID() {
	return ID;
}


int Bilet::getNrRanduri() {
	return nrRanduri;
}


int Bilet::getNrColoane() {
	return nrColoane;
}

void Bilet::setRand(int rand) {
	if (rand <= nrRanduri) {
		this->rand = rand;
	}
}

int Bilet::getRand() {
	return rand;
}

void Bilet::setColoana(int coloana) {
	if (coloana <= nrColoane) {
		this->coloana = coloana;
	}
}

int Bilet::getColoana() {
	return coloana;
}

double Bilet::getLoc(int rand, int coloana) {
	if (rand >= 0 && coloana >= 0 && rand <= nrRanduri && coloana <= nrColoane) {
		return loc[rand][coloana];
	}
	return -1;
}

void Bilet::setLoc(double** loc) {
	
		if (loc != nullptr)
		{
			delete[] this->loc;
			this->loc = new double* [10];
			for (int i = 0; i < 10; i++)
			{
				this->loc[i] = new double[10];
			}
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
				{
					this->loc[i][j] = loc[i][j];
				}
		}
}

void Bilet::setPret(float pret, char* zona) {
	if (_strcmpi(zona, "VIP") == 0) {
		this->pret = pret * 2;
	}
	else if (_strcmpi(zona, "Standard") == 0) {
		this->pret = pret;
	}
}

float Bilet::getPret() {
	return pret;
}

void Bilet::setZona(char* zona) {
	if (zona != nullptr)
	{
		delete[] this->zona;
		this->zona = new char[strlen(zona) + 1];
		for (int i = 0; i < strlen(zona) + 1; i++) {
			this->zona[i] = zona[i];
		}
	}
}

char* Bilet::getZona()
{
	if (this->zona != nullptr){
		char* copy = new char[strlen(zona) + 1];
		for (int i = 0; i < strlen(zona) + 1; i++) {
			copy[i] = this->zona[i];
		}
		return copy;
	}
	return nullptr;
}

istream& operator>>(istream& in, Bilet& bilet) {
	string buffer;
	in >> buffer;
	strcpy_s(bilet.zona, buffer.length()+1, buffer.c_str());
	in >> bilet.rand;
	in >> bilet.coloana;
	return in;
}

ostream& operator<<(ostream& out, Bilet bilet) {
	if (bilet.zona != nullptr) {
		if (_strcmpi(bilet.zona, "VIP") == 0 || _strcmpi(bilet.zona, "standard") == 0) {
			out << "Zona aleasa de dumneavoastra este: " << bilet.zona<<endl;
		}
		if (bilet.pret != 0) {
			if (_strcmpi(bilet.zona, "VIP") == 0) {
				out << "Pretul biletului VIP: " << bilet.pret * 2;
			}
			else if (_strcmpi(bilet.zona, "standard") == 0) {
				out << "Pretul biletului standard: " << bilet.pret;
			}
		}
	}
	if (bilet.ID != 0) {
		out << "ID-ul biletului: " << bilet.ID << endl;
	}

	if (bilet.nrRanduri != NULL && bilet.nrColoane != NULL) {
		out << "Nr maxim de randuri: " << bilet.nrRanduri<< endl;
		out << "Nr maxim de coloane: " << bilet.nrColoane << endl;
	}
	if (bilet.rand != NULL && bilet.rand <= bilet.nrRanduri && bilet.coloana != NULL && bilet.coloana <= bilet.nrColoane) {
		out << "Randul selectat de dumneavostra se afla pe randul " << bilet.rand << " si pe coloana " << bilet.coloana << endl;
	}
	return out;
}

int Bilet::getNrTotalTicketsLeftPerTotal() {
	int nrBileteRamasePerTotal = (nrMaxBileteVIP + nrMaxBileteStandard) - (nrBileteGenerateVIP + nrBileteGenerateStandard);
	return nrBileteRamasePerTotal;
}

int Bilet::getNrTotalTicketsLeftPerArea(char* zona) {
	int nrBileteRamasePeZona = 0;
	if (zona != nullptr) {
		if (_strcmpi(zona, "VIP") == 0) {
			nrBileteRamasePeZona = nrMaxBileteVIP - nrBileteGenerateVIP;
		}
		else if (_strcmpi(zona, "standard") == 0) {
			nrBileteRamasePeZona = nrMaxBileteStandard - nrBileteGenerateStandard;
		}
	}
	return nrBileteRamasePeZona;
}

Bilet Bilet::operator++(int i) {
	Bilet copie = *this;
	if (_strcmpi(copie.zona, "standard") == 0) {
			copie.pret++;
	}
	return copie;
}

Bilet Bilet::operator--(int i) {
	Bilet copie = *this;
	if (_strcmpi(copie.zona, "standard") == 0) {
			copie.pret--;
	}
	return copie;
}

Bilet::~Bilet() {
	if (zona != nullptr) {
		delete[] zona;
		zona = nullptr;
	}
	if (loc != NULL) {
		for (int i = 0; i < nrRanduri; i++) {
			delete[] loc[i];
		}
		delete[] loc;
		loc = nullptr;
	}
}