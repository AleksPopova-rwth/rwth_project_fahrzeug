/*
 * PKW.h
 *
 *  Created on: 8 нояб. 2023 г.
 *      Author: alexp
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"

class PKW: public Fahrzeug {
private:

	double p_dVerbrauch; // (Liter/100km)
	double diff;
public:
	PKW();
	PKW(const PKW &p) = delete;
	PKW(string copyName, unsigned int copyID, double copyMaxG,
			double copyVerbrauch);
	virtual ~PKW();
	void pkwInitialisierung();

	double dTanken() override;
	double dTanken(double dMenge) override;
	void vSimulieren() override;
	void vSimulieren(bool Verbot,double next_fahrStreke) override;
	double get_Tankinhalt() const;
	double get_GesamtStrecke() const;
	double dGeschwindigkeit();
	void vZeichnen(const Weg&) override;
	// double getaktuellerTankinhalt(unsigned int life_time);
	// virtual double gesamtVerbrauch();
	// double dVerbrauch();
	void vAusgaben() override;
	// double getanktVolumen();
	virtual void vKopf();
	virtual std::ostream& vAusgeben(std::ostream &ausgabe) const override;

	//friend ostream& operator<<(ostream& ausgabe, const PKW& pkw);
	bool operator <(const PKW &pkw) const;
};
inline ostream& operator<<(ostream &ausgabe, const PKW &pkw) {
	return pkw.vAusgeben(ausgabe);
}
#endif /* PKW_H_ */
