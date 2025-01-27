#ifndef SIMULATIONSOBJEKT_H
#define SIMULATIONSOBJEKT_H
#include <memory>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

inline int p_iMaxID = 0;
inline unsigned int dGlobaleZeit = 0;

enum fahrzeug_type {
	none = 0, fahrrad_type = 1, pkw_type = 2
};

class Simulationsobjekt {

public:
	string p_sName;
	unsigned int p_iID;

	unsigned int p_dGesamtZeit; //Current time of simulation
	const unsigned int p_dZeit = 1; //1 second simulation step

	Simulationsobjekt();
	Simulationsobjekt(string copyName, unsigned int copyID); //Конструкторы
	Simulationsobjekt(string copyName); //Конструкторы

	Simulationsobjekt(const Simulationsobjekt &f) = delete;
	virtual ~Simulationsobjekt(); //Деструктор

	// Rein virtuelle Methoden
	void vNewSimulationsobjekt();
	virtual void vSimulieren();
	virtual void vAusgaben();
	virtual string getName();
	virtual std::ostream& vAusgeben(std::ostream &ausgabe) const;

	//ostream& bool operatoren
	//friend ostream& operator<<(ostream& ausgabe, const Simulationsobjekt& simulationsobjekt);
	bool operator==(const Simulationsobjekt &other) const;
};

inline std::ostream& operator<<(std::ostream &ausgabe,
		const Simulationsobjekt &simulationsobjekt) {
	return simulationsobjekt.vAusgeben(ausgabe);
}

#endif /*SIMULATIONSOBJEKT_H*/
