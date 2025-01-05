/*
 * Fahrrad.cpp
 *
 *  Created on: 8 нояб. 2023 г.
 *      Author: alexp
 */
#include <iostream>
#include <iomanip>
#include "Fahrrad.h"
#include <string>
using namespace std;
#include "SimuClient.h"

Fahrrad::Fahrrad() :
		Fahrzeug() {
	deltaGesamtStrecke = 0.0; //km
}

Fahrrad::Fahrrad(string copyName, unsigned int copyID, double copyMaxG) :
		Fahrzeug(copyName, copyID, copyMaxG, fahrrad_type) {
	deltaGesamtStrecke = 0.0; //km
}

Fahrrad::~Fahrrad() {
}

double Fahrrad::get_Tankinhalt() {
	return p_dTankinhalt;
}

double Fahrrad::get_GesamtStrecke() {
	return p_dGesamtStrecke;
}

double Fahrrad::dGeschwindigkeit() {
	int iFull20km = (int) (p_dGesamtStrecke / 20);
	double tmp = p_dMaxGeschwindigkeit;
	// Verringerung der Geschwindigkeit um 10% mit jedem vollen 20km-Abschnitt
	// Also 0.9 zur Potenz der vollen 20km-Abschnitte mal die Maximalgeschwindigkeit
	for (int i = 0; i < iFull20km; ++i) {
		// Multipliziere mit 0.9 für jeden vollen 20 km-Abschnitt
		tmp *= 0.9;
	}
	p_dCurGeschwindigkeit = max(12.0, tmp);
	return p_dCurGeschwindigkeit;
}

void Fahrrad::vSimulieren() {
//		for (unsigned int ctime=p_dGesamtZeit; ctime<dGlobaleZeit; ctime+=p_dZeit) {
//
//			//var 2.
//			if (deltaGesamtStrecke >= 20.0) {
//				//ruduzieren geschwindigkeit
//				p_dMaxGeschwindigkeit = max(12.0,p_dMaxGeschwindigkeit*0.9);
//				deltaGesamtStrecke = 0.0; //km
//			}
//			//deltaGesamtStreke
//			deltaGesamtStrecke += p_dMaxGeschwindigkeit/60;
//			//Strecke
//			p_dGesamtStrecke += p_dMaxGeschwindigkeit/60;
//			//
//			Fahrzeug::vSimulieren();
	double dGesamtStreckeTemp = p_dGesamtStrecke; // Streckenz�hler zwischenspeichern
	Fahrzeug::vSimulieren();
	Simulationsobjekt::vSimulieren();
	//simulation step
}

void Fahrrad::vSimulieren(bool Verbot, double next_fahrStreke) {
	//		for (unsigned int ctime=p_dGesamtZeit; ctime<dGlobaleZeit; ctime+=p_dZeit) {
	//
	//			//var 2.
	//			if (deltaGesamtStrecke >= 20.0) {
	//				//ruduzieren geschwindigkeit
	//				p_dMaxGeschwindigkeit = max(12.0,p_dMaxGeschwindigkeit*0.9);
	//				deltaGesamtStrecke = 0.0; //km
	//			}
	//			//deltaGesamtStreke
	//			deltaGesamtStrecke += p_dMaxGeschwindigkeit/60;
	//			//Strecke
	//			p_dGesamtStrecke += p_dMaxGeschwindigkeit/60;
	//			//
	//			Fahrzeug::vSimulieren();
		double dGesamtStreckeTemp = p_dGesamtStrecke;
		double dTeilStreckeTemp = p_dAbschnittStrecke;
		Fahrzeug::vSimulieren();
		if (Verbot && p_dAbschnittStrecke > next_fahrStreke) {
			double tmp = p_dAbschnittStrecke - next_fahrStreke;
			p_dAbschnittStrecke = next_fahrStreke;
			p_dGesamtStrecke = p_dGesamtStrecke - tmp;
		}
		p_dCurGeschwindigkeit = (p_dGesamtStrecke - dGesamtStreckeTemp) * 60;
		Simulationsobjekt::vSimulieren(); //simulation step
	}


void Fahrrad::vKopf() {
	Fahrzeug::vKopf();
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< "GesamtStrecke (km)" << endl;
}
void Fahrrad::vAusgaben() {
	Fahrzeug::vAusgaben();
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< fixed << setprecision(1) << get_GesamtStrecke() << endl;
}
//ostream& operator<<(ostream& ausgabe, const Fahrrad& fahrrad) {
//	ausgabe << resetiosflags(ios::left)<<setiosflags(ios::right) << setw(5) << fahrrad.p_iID;
//	ausgabe << resetiosflags(ios::left)<<setiosflags(ios::right) << setw(10)<< fahrrad.p_sName;
//	ausgabe <<resetiosflags(ios::left)<< setiosflags(ios::right) << setw(40)<<fixed<<setprecision(1)<<fahrrad.p_dMaxGeschwindigkeit;
//    ausgabe <<resetiosflags(ios::left)<< setiosflags(ios::right) << setw(30)<<fixed<<setprecision(1)<<((Fahrrad&)fahrrad).get_GesamtStrecke()<<endl;
//    return ausgabe;
//}

bool Fahrrad::operator <(const Fahrrad &fahrrad) const {
	return (this->p_dGesamtStrecke < fahrrad.p_dGesamtStrecke);
}

ostream& Fahrrad::vAusgeben(std::ostream &ausgabe) const {
	// Rufe die vAusgeben-Methode der Basisklasse auf
	Fahrzeug::vAusgeben(ausgabe);
	ausgabe << resetiosflags(ios::left) << setiosflags(ios::right) << setw(30)
			<< fixed << setprecision(1) << this->p_dGesamtStrecke << endl;
	return ausgabe;
}
void Fahrrad::vZeichnen(const Weg&) {
	bZeichneFahrrad(this->p_sName, p_pVerhalten->referenzWeg.getName(),
			p_dAbschnittStrecke / p_pVerhalten->referenzWeg.getLaenge(),
			this->p_dCurGeschwindigkeit);
}
