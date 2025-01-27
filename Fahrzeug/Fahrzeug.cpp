/*
 * Fahrzeug.cpp
 *
 *  Created on: 25 окт. 2023 г.
 *      Author: alexp
 */
#include <iostream>
#include <iomanip>
#include <memory>
#include "Fahrzeug.h"
#include "Fahren.h"
#include "Parken.h"
#include "Verhalten.h"
#include "Kreuzung.h"

Fahrzeug::Fahrzeug() {
	vNewFahrzeug();
} //var 1, default version

Fahrzeug::Fahrzeug(string copyName, unsigned int copyID, double copyMaxG,
		fahrzeug_type t_fahrzeug) :
		Simulationsobjekt(copyName, copyID), p_dMaxGeschwindigkeit(copyMaxG), t_fahrzeug(
				t_fahrzeug) {

	p_dTankvolumen = 0;
	p_dGesamtStrecke = 0;
	p_dTankinhalt = 0;
	p_dAbschnittStrecke = 0;
	p_dCurGeschwindigkeit = p_dMaxGeschwindigkeit;
} //var 2

Fahrzeug::~Fahrzeug() {
}

void Fahrzeug::vNewFahrzeug() {
	Simulationsobjekt::vNewSimulationsobjekt();
	p_dGesamtStrecke = 0;
	p_dMaxGeschwindigkeit = 50;
	p_dCurGeschwindigkeit = p_dMaxGeschwindigkeit;
	p_dTankvolumen = 0;
}

void Fahrzeug::vAusgaben() {
	Simulationsobjekt::vAusgaben();
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(40)
			<< p_dCurGeschwindigkeit << " ";
}
void Fahrzeug::vKopf() {
	cout << endl
			<< "-------------------------------------------------------------------------------------------------------------------"
			<< endl;
	cout << endl << resetiosflags(ios::left) << setiosflags(ios::right)
			<< setw(5) << "ID";
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(10)
			<< "Name";
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(40)
			<< "aktuelle Geschwind.";
}
void Fahrzeug::vSimulieren() {
	if (dGlobaleZeit != p_dGesamtZeit) {
		unsigned int delta_t = dGlobaleZeit - p_dGesamtZeit;
		double dTeilStrecke = 0;
		try {
			dTeilStrecke = p_pVerhalten->dStrecke(*this, delta_t);
		} catch (const Losfahren &e) {
			cout << "Das Fahrzeug " << this->getName() << " losfahren" << endl;
			vFahren(p_pVerhalten->referenzWeg);
			dTeilStrecke = p_pVerhalten->dStrecke(*this, delta_t);
		} catch (const Streckenende &e) {
			p_pVerhalten->referenzWeg.getKreuzung()->vTanken(*this);
			cout << "Das Fahrzeug " << getName() << " aus dem Weg" << endl;
			//std::cout << "ZEIT: " << dGlobalezeit << ":" << localTime->tm_min << ":" << localTime->tm_sec << std::endl;
			cout << "KREUZUNG: "
					<< p_pVerhalten->referenzWeg.getKreuzung()->getName()
					<< " Tankstelle: "
					<< p_pVerhalten->referenzWeg.getKreuzung()->getTankstelle()
					<< endl;
			cout << "WECHSEL: " << p_pVerhalten->referenzWeg;

			p_pVerhalten->referenzWeg.vUmstellen(*this);

			cout << " → " << p_pVerhalten->referenzWeg << std::endl;
			cout << "FAHRZEUG: " << getName() << std::endl;
		};
//		p_dCurGeschwindigkeit = dTeilStrecke * 60;
//		p_dAbschnittStrecke += dTeilStrecke;
//		p_dGesamtStrecke += dTeilStrecke;
//		if (dTeilStrecke == 0) p_dCurGeschwindigkeit = 0;
	};
}

double Fahrzeug::dTanken() {
	return 0.0;
}

double Fahrzeug::dTanken(double dMenge) {
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const{
	return p_dMaxGeschwindigkeit;
}
//
//ostream& operator<<(ostream& ausgabe, const Fahrzeug& fahrzeug)
//{
//		ausgabe<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(5) << fahrzeug.p_iID << " " // ID rechtsb�ndig
//		<< resetiosflags(ios::right) << setiosflags(ios::left) << setw(10) <<  fahrzeug.p_sName << ": " // Name linksb�ndig
//		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(40) <<  fahrzeug.p_dMaxGeschwindigkeit << " km/h";
//	return ausgabe;
//}

bool Fahrzeug::operator <(const Fahrzeug &fahrzeug) const {
	return (this->p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke);
}

double Fahrzeug::get_Tankinhalt() {
	return p_dTankinhalt;
}
double Fahrzeug::get_Tankvolumen() {
	return p_dTankvolumen;
}
double Fahrzeug::get_GesamtStrecke() {
	return p_dGesamtStrecke;
}
double Fahrzeug::set_GesamtStrecke(double copyGesamtStrecke) {
	p_dGesamtStrecke += copyGesamtStrecke;
	return p_dGesamtStrecke;
}
double Fahrzeug::get_TeilStrecke() {
	return p_dAbschnittStrecke;
}
double Fahrzeug::set_TeilStrecke(double copyTeilStrecke) {
	p_dAbschnittStrecke += copyTeilStrecke;
	return p_dAbschnittStrecke;
}

double Fahrzeug::set_CurGeschwindigkeit(double copyCurG) {
	p_dCurGeschwindigkeit = copyCurG;
	return p_dCurGeschwindigkeit;
}

string Fahrzeug::getName() const {
	return p_sName;
}
unsigned int Fahrzeug::getID() const {
	return p_iID;
}

ostream& Fahrzeug::vAusgeben(ostream &ausgabe) const {
	// Rufe die vAusgeben-Methode der Basisklasse auf
	Simulationsobjekt::vAusgeben(ausgabe);
	ausgabe << resetiosflags(ios::left) << setiosflags(ios::right) << setw(40)
			<< (*this).dGeschwindigkeit() << " km/h";
	return ausgabe;
}

void Fahrzeug::vNeueStrecke(Weg &weg) {
	p_pVerhalten.reset(); // Setzt den einzigartigen Zeiger zurück und kümmert sich um die Freigabe des zugehörigen Speichers
	p_dAbschnittStrecke = 0.0;
	p_pVerhalten = make_unique<Fahren>(weg);
	// Neue Instanz von V erstellen und in pVerhalten speichern
}
void Fahrzeug::vNeueStrecke(Weg &weg, double dStartzeitpunkt) {
	p_pVerhalten.reset();
	p_dAbschnittStrecke = 0.0;
	p_pVerhalten = make_unique<Parken>(weg, dStartzeitpunkt);
}

void Fahrzeug::vParken(Weg &weg, double dStartzeitpunkt) {
	p_pVerhalten.reset();
	p_pVerhalten = make_unique<Parken>(weg, dStartzeitpunkt);
}

void Fahrzeug::vFahren(Weg &weg) {
	p_pVerhalten.reset();
	p_pVerhalten = make_unique<Fahren>(weg);
}
void Fahrzeug::vZeichnen(const Weg&) {

}
bool Fahrzeug::operator==(const Fahrzeug &other) const {
	return this->getID() == other.getID();
}
