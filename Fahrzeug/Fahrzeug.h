/*
 * Fahrzeug.h
 *
 *  Created on: 25 окт. 2023 г.
 *      Author: alexp
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <memory>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Simulationsobjekt.h"
#include "Verhalten.h"

class Fahrzeug: public Simulationsobjekt {
protected:

	double p_dMaxGeschwindigkeit;
	//double p_dCurGeschwindigkeit;
	double p_dGesamtStrecke;
	unique_ptr<Verhalten> p_pVerhalten; // Verhalten kann durch Austausch des unique_ptr-Objekts geändert werden
	double p_dAbschnittStrecke;

	//double p_dVerbrauch;// (Liter/100km)
	double p_dTankvolumen; //Max
	double p_dTankinhalt; //Liter
	virtual void vNewFahrzeug();

public:
	double p_dCurGeschwindigkeit;

	fahrzeug_type t_fahrzeug = none;
	Fahrzeug(); //Конструкторы
	Fahrzeug(const Fahrzeug &f) = delete;
	Fahrzeug(string copyName, unsigned int copyID, double copyMaxG,
			fahrzeug_type t_fahrzeug);
	virtual ~Fahrzeug(); //Деструктор
	unsigned int getID() const;
	string getName() const;
	void vAusgaben() override;
	virtual void vKopf();

	void vSimulieren() override;
	virtual void vSimulieren(bool Verbot,double next_fahrStreke) = 0;

	virtual double get_Tankinhalt();
	virtual double get_Tankvolumen();

	virtual double get_GesamtStrecke();
	virtual double get_TeilStrecke();
	virtual void vNeueStrecke(Weg &weg);
	virtual void vNeueStrecke(Weg &weg, double dStartzeitpunkt);
	double set_TeilStrecke(double copyTeilStrecke);
	double set_GesamtStrecke(double copyGesamtStrecke);
	double set_CurGeschwindigkeit(double copyCurG);
	virtual double dTanken();
	virtual double dTanken(double dMenge);
	virtual double dGeschwindigkeit() const;
	void vParken(Weg &weg, double dStartzeitpunkt);
	void vFahren(Weg &weg);
	virtual std::ostream& vAusgeben(std::ostream &ausgabe) const override;
	//friend ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug);
	bool operator <(const Fahrzeug &fahrzeug) const;
	virtual void vZeichnen(const Weg&);
	bool operator==(const Fahrzeug &other) const;  // Korrektur hier

};

inline ostream& operator<<(ostream &ausgabe, const Fahrzeug &fahrzeug) {
	return fahrzeug.vAusgeben(ausgabe);
}
#endif /* FAHRZEUG_H_ */

