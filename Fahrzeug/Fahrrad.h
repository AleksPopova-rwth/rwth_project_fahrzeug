/*
 * Fahrrad.h
 *
 *  Created on: 8 нояб. 2023 г.
 *      Author: alexp
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug {
private:
	double const copyAlteGeschwindigkeit = p_dMaxGeschwindigkeit;
	double deltaGesamtStrecke = 0.0;

public:

	Fahrrad();
	Fahrrad(string copyName, unsigned int copyID, double copyMaxG);
	Fahrrad(const Fahrrad &fahr) = delete;
	virtual ~Fahrrad();
	double dGeschwindigkeit();
	void vSimulieren() override;
	void vSimulieren(bool Verbot, double next_fahrStreke) override;
	double get_Tankinhalt() override;
	double get_GesamtStrecke() override;
	void vKopf();
	virtual std::ostream& vAusgeben(std::ostream &ausgabe) const override;
	void vZeichnen(const Weg&) override;
	//friend ostream& operator<<(ostream& ausgabe, const Fahrrad& fahrrad);
	bool operator <(const Fahrrad &fahrrad) const;
	void vAusgaben() override;
};
inline ostream& operator<<(ostream &ausgabe, const Fahrrad &fahrrad) {
	return fahrrad.vAusgeben(ausgabe);
}

#endif /* FAHRRAD_H_ */
