/*
 * Streckenende.h
 *
 *  Created on: 30 дек. 2023 г.
 *      Author: alexp
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende: public Fahrausnahme {

public:
	Streckenende(Fahrzeug &copyFahrzeug, Weg &copyWeg);
	virtual ~Streckenende();
	void vBearbeiten() override;

};

#endif /* STRECKENENDE_H_ */
