/*
 * Parken.cpp
 *
 *  Created on: 28 дек. 2023 г.
 *      Author: alexp
 */

#include "Parken.h"

Parken::Parken(Weg &weg, double dStartzeitpunkt) :
		Verhalten(weg), p_dStartzeitpunkt(dStartzeitpunkt) {
	// TODO Auto-generated constructor stub
}

Parken::~Parken() {
	// TODO Auto-generated destructor stub
}
double Parken::dStrecke(Fahrzeug &fahrzeug, unsigned int dZeitIntervall) const {
	if (dGlobaleZeit > p_dStartzeitpunkt) {
		//throw Losfahren(fahrzeug, Fahrausnahme.getWeg());
		throw Losfahren(fahrzeug, this->referenzWeg); // Startzeit erreicht
		//cout<< "das Auto kann nicht mehr halten";
	}
	return 0.0;
}
