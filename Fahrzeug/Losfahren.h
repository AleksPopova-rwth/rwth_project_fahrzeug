/*
 * Losfahren.h
 *
 *  Created on: 30 дек. 2023 г.
 *      Author: alexp
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren: public Fahrausnahme {
public:
	Losfahren(Fahrzeug &copyFahrzeug, Weg &copyWeg);
	virtual ~Losfahren();
	void vBearbeiten();

};

#endif /* LOSFAHREN_H_ */
