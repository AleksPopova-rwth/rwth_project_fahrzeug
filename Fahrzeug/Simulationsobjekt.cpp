#include "Simulationsobjekt.h"

Simulationsobjekt::Simulationsobjekt() {
	vNewSimulationsobjekt();
}
Simulationsobjekt::Simulationsobjekt(string copyName, unsigned int copyID) :
		p_sName(copyName), p_iID(copyID) {
	p_dGesamtZeit = 0;
}
Simulationsobjekt::Simulationsobjekt(string copyName) :
		p_sName(copyName) {
	p_dGesamtZeit = 0;
}

Simulationsobjekt::~Simulationsobjekt() {
	std::cout << "Objekt " << p_sName << " mit ID " << p_iID
			<< " wird gelöscht." << std::endl;
}

void Simulationsobjekt::vSimulieren() {
	p_dGesamtZeit = dGlobaleZeit;
}

void Simulationsobjekt::vAusgaben() {
	cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(5)
			<< p_iID << "   "; // ID rechtsbndig
	cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(10)
			<< p_sName; // Name linksbndig
}
;

//ostream& operator<<(ostream& ausgabe, const Simulationsobjekt& simulationsobjekt)
//{
//		ausgabe<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(5) << simulationsobjekt.p_iID << " " // ID rechtsb�ndig
//		<< resetiosflags(ios::right) << setiosflags(ios::left) << setw(10) <<  simulationsobjekt.p_sName << ": " // Name linksb�ndig
//		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(40) <<  simulationsobjekt.p_dMaxGeschwindigkeit << " km/h";
//	return ausgabe;
//}

void Simulationsobjekt::vNewSimulationsobjekt() {
	p_sName = "";
	p_iID = p_iMaxID++;
}

bool Simulationsobjekt::operator==(const Simulationsobjekt &other) const {
	return (p_iID == other.p_iID);
}
string Simulationsobjekt::getName() {
	return p_sName;
}

ostream& Simulationsobjekt::vAusgeben(ostream &ausgabe) const {
	ausgabe << resetiosflags(ios::left) << setiosflags(ios::right) << setw(5)
			<< this->p_iID << " "
			// ID rechtsb�ndig
			<< resetiosflags(ios::right) << setiosflags(ios::left) << setw(10)
			<< this->p_sName << ": "; // Name linksb�ndig
	return ausgabe;
}
