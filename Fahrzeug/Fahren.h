/*
 * Fahren.h
 *
 *  Created on: 28 дек. 2023 г.
 *      Author: alexp
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include "Verhalten.h"
#include "Streckenende.h"
class Fahren: public Verhalten {
public:
	Fahren(Weg &weg);
	virtual ~Fahren();
	double dStrecke(Fahrzeug &fahrzeug, unsigned int dZeitIntervall) const
			override;

};

#endif /* FAHREN_H_ */
