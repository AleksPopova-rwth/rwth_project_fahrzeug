/*
 * Fahrausnahme.h
 *
 *  Created on: 30 дек. 2023 г.
 *      Author: alexp
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_
#include "Weg.h"
#include "Fahrzeug.h"
#include <stdexcept>
#include <iostream>

class Fahrausnahme : std::exception{

protected:
	Weg& p_pWeg;
	Fahrzeug& p_pFahrzeug;
public:
	Fahrausnahme(Fahrzeug& copyFahrzeug, Weg& copyWeg);
	virtual ~Fahrausnahme();
	virtual void vBearbeiten();
	Weg& getWeg() const;

};

#endif /* FAHRAUSNAHME_H_ */
