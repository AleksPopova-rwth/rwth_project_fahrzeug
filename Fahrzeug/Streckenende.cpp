/*
 * Streckenende.cpp
 *
 *  Created on: 30 дек. 2023 г.
 *      Author: alexp
 */

#include "Streckenende.h"
using namespace std;

Streckenende::Streckenende(Fahrzeug &copyFahrzeug, Weg &copyWeg) :
		Fahrausnahme(copyFahrzeug, copyWeg) {
	// TODO Auto-generated constructor stub

}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

void Streckenende::vBearbeiten() {
	cout << "Streckende-Ausnahme: Fahrzeug " << p_pFahrzeug.getID()
			<< " auf Weg " << p_pWeg.p_iID << endl;
//TODO переопределение машины
	//p_pWeg->vAbgabe(p_pFahrzeug);
}
