// Kreuzung-Klasse

#include <list>
#include <vector>
#include "Simulationsobjekt.h"
#include "Tempolimit.h"

class Fahrzeug;
class Weg;
class Kreuzung: public Simulationsobjekt {

private:
	list<shared_ptr<Weg>> p_pWege;

public:
	double p_dTankstelle;
	Kreuzung(string sName, double dTankvolumen); //Конструкторы
	Kreuzung(const Kreuzung &f) = delete;
	virtual ~Kreuzung(); //Деструктор

	// Rein virtuelle Methoden
	void vSimulieren() override;
	static void vVerbinde(string sName, string sRueckName, double dWegLaenge,
			shared_ptr<Kreuzung> startKreuzung,
			shared_ptr<Kreuzung> zielKreuzung, Tempolimit dGeschwBegr,
			bool bUeberholV);
	//friend ostream& operator<<(ostream& ausgabe, const Kreuzung& kreuzung);
	//bool operator < (const Kreuzung& kreuzung) const;

	double vTanken(Fahrzeug &fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug> fahrzeug);
	double getTankstelle();

	shared_ptr<Weg> pZufaelligerWeg(Weg &weg);
};
