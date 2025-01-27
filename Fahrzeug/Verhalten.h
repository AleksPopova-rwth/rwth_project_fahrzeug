#ifndef VERHALTEN_H
#define VERHALTEN_H
#include "Weg.h"

class Weg;
class Verhalten {
protected:
	//Weg& referenzWeg;  // Referenz auf einen Weg

public:
	Weg &referenzWeg;  // Referenz auf einen Weg

	Verhalten(Weg &weg);
	virtual ~Verhalten();
	virtual double dStrecke(Fahrzeug &fahrzeug,
			unsigned int dZeitIntervall) const; // Neue Funktion zur Berechnung der Strecke
};

#endif // VERHALTEN_H
