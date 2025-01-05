/*
 * Fahrausnahme.cpp
 *
 *  Created on: 30 дек. 2023 г.
 *      Author: alexp
 */

#include "Fahrausnahme.h"

Fahrausnahme::Fahrausnahme(Fahrzeug &copyFahrzeug, Weg &copyWeg) :
		p_pFahrzeug(copyFahrzeug), p_pWeg(copyWeg) {

}

Fahrausnahme::~Fahrausnahme() {
}

Weg& Fahrausnahme::getWeg() const {
	return p_pWeg;
}
void Fahrausnahme::vBearbeiten() {
}
