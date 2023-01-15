//#include "Pay.h"
//#include "Client.h"
//Pay::Pay() {
//	metodaPlata = "";
//	numar = "";
//	anExpirare = NULL;
//	lunaExpirare = NULL;
//	CVC = NULL;
//}
//
//Pay::Pay(string metodaPlata, string numar, int CVC, int anExpirare, int lunaExpirare) {
//	this->metodaPlata = metodaPlata;
//	this->numar = numar;
//	this->CVC = CVC;
//	this->anExpirare = anExpirare;
//	this->lunaExpirare = lunaExpirare;
//}
//
//void Pay::setMetodaPlata(string metodaPlata) {
//	if (_strcmpi(metodaPlata.c_str(), "cash") == 0 || _strcmpi(metodaPlata.c_str(), "card") == 0) {
//		this->metodaPlata = metodaPlata;
//	}
//	else {
//		this->metodaPlata = "";
//	}
//}
//
//string Pay::getMetodatPlata() {
//	return metodaPlata;
//}
//
//void Pay::setNumar(string numar) {
//	this->numar = numar;
//}
//
//string Pay::getNumar() {
//	return numar;
//}
//
//void Pay::setCVC(int CVC) {
//	if (CVC >= 100 && CVC <= 999) {
//		this->CVC = CVC;
//	}
//	else {
//		this->CVC = NULL;
//	}
//}
//
//int Pay::getCVC() {
//	return CVC;
//}
//
//void Pay::setAnExpirare(int anExpirare) {
//	if (anExpirare >= 2023) {
//		this->anExpirare = anExpirare;
//	}
//	else {
//		this->anExpirare = 0;
//	}
//}
//
//int Pay::getAnExpirare() {
//	return anExpirare;
//}
//
//void Pay::setLunaExpirare(int lunaExpirare) {
//	if (lunaExpirare >= 1 && lunaExpirare <= 12) {
//		this->lunaExpirare = lunaExpirare;
//	}
//	else {
//		this->lunaExpirare = 0;
//	}
//}
//
//int Pay::getLunaExpirare() {
//	return lunaExpirare;
//}
//
//void Pay::disponibilitate() {
//	cout << "If the year is greater than or equal to 2023 and the month greater than January, the card is functional, otherwise it has expired.";
//}