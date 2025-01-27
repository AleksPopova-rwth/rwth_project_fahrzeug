#ifndef WEG_H
#define WEG_H
#include <list>
#include <vector>
#include <algorithm>
#include <limits>
#include <mutex>

#include "Tempolimit.h"
#include "Simulationsobjekt.h"
#include "vertagt_liste.h"

class Fahrzeug;
class Kreuzung;
class Weg: public Simulationsobjekt {
private:
	weak_ptr<Weg> p_pRueckWeg;
	weak_ptr<Kreuzung> p_pZielKreuzung;
protected:
	double p_dLaenge;
	bool u_bVerbot;
	double next_fahrStrecke;

	vertagt::VListe<unique_ptr<Fahrzeug> > p_pFahrzeuge;
public:
	double p_eTempolimit;
	Weg();
	Weg(string copyName, double copyLaenge, Tempolimit copyTempolimit,
			bool uVerbot);
	Weg(const Weg &f);
	virtual ~Weg();

	void vSimulieren() override; //rein virtuelle Methode
	//friend ostream& operator<<(ostream& ausgabe, const Weg& weg);
	virtual std::ostream& vAusgeben(std::ostream &ausgabe) const override;

	double getTempolimit(Tempolimit tempolimit) const;

	static void vKopf();

	double getLaenge();
	void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug);
	void vAnnahme(unique_ptr<Fahrzeug> fahrzeug, double dStartzeitpunkt);
	unique_ptr<Fahrzeug> vAbgabe(const Fahrzeug &fahrzeug);
	void vUmstellen(const Fahrzeug &fahrzeug);

	shared_ptr<Kreuzung> getKreuzung() const;
	shared_ptr<Weg> getRueckweg() const;

	void setRueckweg(shared_ptr<Weg> rueckweg);
	void set_next_FahrStrecke(double next_FahrCopyStreke);

	void setKreuzung(shared_ptr<Kreuzung> kreuzung);

	//weak_ptr<Kreuzung>& operator=(const weak_ptr<Kreuzung>& other) const;
};

#endif /* WEG_H */
