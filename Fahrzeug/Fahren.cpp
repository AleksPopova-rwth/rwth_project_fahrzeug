/*
 * Fahren.cpp
 *
 *  Created on: 28 дек. 2023 г.
 *      Author: alexp
 */

#include "Fahren.h"

Fahren::Fahren(Weg &weg) :
		Verhalten(weg) {
	// TODO Auto-generated constructor stub

}

Fahren::~Fahren() {
	// TODO Auto-generated destructor stub
}

double Fahren::dStrecke(Fahrzeug &fahrzeug, unsigned int dZeitIntervall) const {
	return Verhalten::dStrecke(fahrzeug, dZeitIntervall);

	// Strecke bis der Weg endet
//	double dStreckeWegende = referenzWeg.getLaenge() - fahrzeug.get_TeilStrecke();
//
//	// Strecke die das Fahrzeug mit normaler Geschwindigkeit zur�cklegen w�rde
//	double dStreckeGeschwindigkeit = fahrzeug.dGeschwindigkeit() * dZeitIntervall;
//
//	if (dStreckeWegende == 0.0)
//	{
//		//throw Streckenende(fahrzeug, referenzWeg); // Streckenende erreicht
//	}
//
//	// Der kleinere Wert ist ma�gebend
//	return min<double>(dStreckeWegende, dStreckeGeschwindigkeit);
}
