/*
 * Verhalten.cpp
 *
 *  Created on: 27 дек. 2023 г.
 *      Author: alexp
 */

#include "Verhalten.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Streckenende.h"

Verhalten::~Verhalten() {

}

Verhalten::Verhalten(Weg &weg) :
		referenzWeg(weg) {

	// Initialisierung des Fahrverhalten-Objekts mit dem übergebenen Weg
}

double Verhalten::dStrecke(Fahrzeug &fahrzeug,
		unsigned int dZeitIntervall) const {
	double aktuelleGeschwindigkeit;  // скорость
	double aktuelleStrecke;  //весь пройденный путь
	double aktuelleTeilStrecke;  //пройденный путь на данной дороге
	// Implementierung der dStrecke-Funktion
	// Hier wird berechnet, wie weit ein Fahrzeug innerhalb des übergebenen Zeitintervalls fahren kann
	// Beachten Sie, dass der Aufruf auf private Variablen von Weg und Fahrzeug über Getter-Funktionen erfolgen sollte
	double dMoeglicheStrecke = referenzWeg.getLaenge();    //длина дороги

	// Beispiel:
	if (fahrzeug.t_fahrzeug == pkw_type) {
		PKW &pkw = dynamic_cast<PKW&>(fahrzeug);
		aktuelleGeschwindigkeit = pkw.dGeschwindigkeit();  // скорость
		aktuelleStrecke = pkw.get_GesamtStrecke();  //весь пройденный путь
		aktuelleTeilStrecke = pkw.get_TeilStrecke(); //пройденный путь на данной дороге
	} else {
		Fahrrad &fahrrad = dynamic_cast<Fahrrad&>(fahrzeug);
		aktuelleGeschwindigkeit = fahrrad.dGeschwindigkeit();  // скорость
		aktuelleStrecke = fahrrad.get_GesamtStrecke();  //весь пройденный путь
		aktuelleTeilStrecke = fahrrad.get_TeilStrecke(); //пройденный путь на данной дороге
	}
	//deltaTeilStrecke:
	double deltaTeilStrecke = aktuelleGeschwindigkeit / 60 * dZeitIntervall;
	if (deltaTeilStrecke == 0)
		fahrzeug.set_CurGeschwindigkeit(0);
	if (dMoeglicheStrecke > aktuelleTeilStrecke + deltaTeilStrecke) {
		fahrzeug.set_TeilStrecke(deltaTeilStrecke);
		fahrzeug.set_GesamtStrecke(deltaTeilStrecke);
		return deltaTeilStrecke;
	} else if (dMoeglicheStrecke == aktuelleTeilStrecke + deltaTeilStrecke) {
		//TODO: выдать сигнал  конца дороги
		cout << "Es ist das Ende des Weges" << endl;
		fahrzeug.set_TeilStrecke(deltaTeilStrecke);
		fahrzeug.set_GesamtStrecke(deltaTeilStrecke);
		//throw Streckenende(fahrzeug, referenzWeg);
		return deltaTeilStrecke;
	} else {
		//TODO: выдать сигнал  конца дороги
		cout << "Es ist das Ende des Weges" << endl;

		fahrzeug.set_TeilStrecke(dMoeglicheStrecke - aktuelleTeilStrecke);
		fahrzeug.set_GesamtStrecke(dMoeglicheStrecke - aktuelleTeilStrecke);
		throw Streckenende(fahrzeug, referenzWeg);
		return dMoeglicheStrecke - aktuelleTeilStrecke;
	}
}

