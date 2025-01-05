/*
 * Losfahren.cpp
 *
 *  Created on: 30 дек. 2023 г.
 *      Author: alexp
 */

#include "Losfahren.h"

Losfahren::Losfahren(Fahrzeug &copyFahrzeug, Weg &copyWeg) :
		Fahrausnahme(copyFahrzeug, copyWeg) {
	// TODO Auto-generated constructor stub

}

Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}
void Losfahren::vBearbeiten() {
	cout << "Losfahren-Ausnahme: Fahrzeug " << p_pFahrzeug.getID()
			<< " auf Weg " << p_pWeg.p_iID << endl;

}
