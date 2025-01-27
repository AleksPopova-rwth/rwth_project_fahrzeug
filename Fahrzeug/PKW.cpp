/*
 * PKW.cpp
 *
 *  Created on: 8 нояб. 2023 г.
 *      Author: alexp
 */

#include "PKW.h"
#include "SimuClient.h"
PKW::PKW() :
		Fahrzeug() {
	pkwInitialisierung();
}

PKW::PKW(string copyName, unsigned int copyID, double copyMaxG,
		double copyVerbrauch) :
		Fahrzeug(copyName, copyID, copyMaxG, pkw_type), p_dVerbrauch(
				copyVerbrauch) {
	p_dTankvolumen = 55;
	p_dTankinhalt = p_dTankvolumen / 2; //Liter
}

PKW::~PKW() {
}

void PKW::pkwInitialisierung() {
	p_dVerbrauch = 5.0; // (Liter/100km)
	p_dTankvolumen = 55;
	p_dTankinhalt = p_dTankvolumen / 2; //Liter
}

double PKW::get_Tankinhalt() const {
	return p_dTankinhalt;
}

double PKW::get_GesamtStrecke() const {
	return p_dGesamtStrecke;

}

double PKW::dTanken() {
	double diff = p_dTankvolumen - p_dTankinhalt;
	p_dTankinhalt = p_dTankvolumen;
	return p_dTankinhalt;
}
;

double PKW::dTanken(double dMenge) {
	double diff = min(p_dTankinhalt + dMenge, p_dTankvolumen) - p_dTankinhalt;
	p_dTankinhalt = min(p_dTankinhalt + dMenge, p_dTankvolumen);
	return diff;
}
;

void PKW::vSimulieren() {
	if (p_dTankinhalt > 0.0) {
		p_dCurGeschwindigkeit = p_dMaxGeschwindigkeit;
		double dGesamtStreckeTemp = p_dGesamtStrecke; // Streckenz�hler zwischenspeichern
		Fahrzeug::vSimulieren();
		p_dTankinhalt -= (p_dGesamtStrecke - dGesamtStreckeTemp) * p_dVerbrauch
				/ 100; // Verbrauch nachrechnen
		p_dTankinhalt = max(0.0, p_dTankinhalt);
	}
	Simulationsobjekt::vSimulieren(); //simulation step

}

void PKW::vSimulieren(bool Verbot, double next_fahrStreke) {
	if (p_dTankinhalt > 0.0) {
		p_dCurGeschwindigkeit = p_dMaxGeschwindigkeit;
		double dGesamtStreckeTemp = p_dGesamtStrecke; //
		double dTeilStreckeTemp = p_dAbschnittStrecke; //
		Fahrzeug::vSimulieren();
		if (Verbot && p_dAbschnittStrecke > next_fahrStreke) {
			double tmp = p_dAbschnittStrecke - next_fahrStreke;
			p_dAbschnittStrecke = next_fahrStreke;
			p_dGesamtStrecke = p_dGesamtStrecke - tmp;
		}
		p_dCurGeschwindigkeit = (p_dGesamtStrecke - dGesamtStreckeTemp) * 60;
		p_dTankinhalt -= (p_dGesamtStrecke - dGesamtStreckeTemp) * p_dVerbrauch
				/ 100; // Verbrauch nachrechnen
		p_dTankinhalt = max(0.0, p_dTankinhalt);
	}
	Simulationsobjekt::vSimulieren(); //simulation step
}

void PKW::vAusgaben() {
	Fahrzeug::vAusgaben();
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< fixed << setprecision(1) << get_GesamtStrecke();
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< fixed << setprecision(1) << get_Tankinhalt() << " " << endl;
}
void PKW::vKopf() {
	Fahrzeug::vKopf();
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< "GesamtStrecke (km)";
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< "akt. Tankinhalt (l)" << endl << endl;
}
//ostream& operator<<(ostream& ausgabe, const PKW& pkw) {
//	ausgabe << resetiosflags(ios::left)<<setiosflags(ios::right) << setw(5) << pkw.p_iID;
//	ausgabe << resetiosflags(ios::left)<<setiosflags(ios::right) << setw(10)<< pkw.p_sName;
//	ausgabe <<resetiosflags(ios::left)<< setiosflags(ios::right) << setw(40)<<fixed<<setprecision(1)<< pkw.p_dMaxGeschwindigkeit;
//    ausgabe <<resetiosflags(ios::left)<< setiosflags(ios::right) << setw(30)<<fixed<<setprecision(1)<< ((PKW&)pkw).get_GesamtStrecke();
//    ausgabe << resetiosflags(ios::left)<<setiosflags(ios::right) << setw(30)<<fixed<<setprecision(1)<< ((PKW&)pkw).get_Tankinhalt();
//    return ausgabe;
//}

bool PKW::operator <(const PKW &pkw) const {
	return (this->p_dGesamtStrecke < pkw.p_dGesamtStrecke);
}

std::ostream& PKW::vAusgeben(std::ostream &ausgabe) const {
// Rufe die vAusgeben-Methode der Basisklasse auf
	Fahrzeug::vAusgeben(ausgabe);
	ausgabe << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< fixed << setprecision(1) << this->get_GesamtStrecke()
			<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< fixed << setprecision(1) << this->get_Tankinhalt();
	return ausgabe;
}

double PKW::dGeschwindigkeit()  {
	if (p_pVerhalten != nullptr) {
		double tmp = min(p_pVerhalten->referenzWeg.p_eTempolimit,
				p_dMaxGeschwindigkeit);
		p_dCurGeschwindigkeit=tmp;
		return p_dCurGeschwindigkeit;
	} else {
		return p_dMaxGeschwindigkeit; //
	}
}
void PKW::vZeichnen(const Weg&)  {
	bZeichnePKW(this->p_sName, p_pVerhalten->referenzWeg.getName(),
			p_dAbschnittStrecke / p_pVerhalten->referenzWeg.getLaenge(),
			this->p_dCurGeschwindigkeit, this->p_dTankinhalt);

}

