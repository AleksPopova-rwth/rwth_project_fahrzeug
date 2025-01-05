/*
 * Parken.h
 *
 *  Created on: 28 дек. 2023 г.
 *      Author: alexp
 */

#ifndef PARKEN_H_
#define PARKEN_H_

#include "Verhalten.h"
#include "Losfahren.h"
#include "Fahrzeug.h"
class Parken: public Verhalten {
public:
	Parken(Weg &weg, double dStartzeitpunkt);
	virtual ~Parken();
	double dStrecke(Fahrzeug &fahrzeug, unsigned int dZeitIntervall) const
			override;
private:
	double p_dStartzeitpunkt;

};

#endif /* PARKEN_H_ */
