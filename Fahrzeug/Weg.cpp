#include "Weg.h"
#include "Fahrzeug.h"
#include <list>
#include "Kreuzung.h"

//#include "Fahrausnahme.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "vertagt_liste.h"
#include "vertagt_aktion.h"

#include <iomanip>

Weg::Weg() {
	Simulationsobjekt::vNewSimulationsobjekt();
	p_eTempolimit = getTempolimit(Tempolimit::Autobahn);
	p_dLaenge = 50.0; // in km;

}

Weg::Weg(string copyName, double copyLaenge, Tempolimit copyTempolimit,
		bool uVerbot) :
		Simulationsobjekt(copyName), p_dLaenge(copyLaenge), u_bVerbot(uVerbot) {

	p_eTempolimit = getTempolimit(copyTempolimit);
}
Weg::~Weg() {
	// Ваш код деструктора
}

double Weg::getTempolimit(Tempolimit tempolimit) const {
	switch (tempolimit) {
	case Tempolimit::Innerorts:
		return 50.0;
	case Tempolimit::Landstrasse:
		return 100.0;
	case Tempolimit::Autobahn:
		return numeric_limits<double>::max(); // Unbegrenztes Tempolimit
	default:
		return 0.0; // Fallback-Wert
	}
}
void Weg::vSimulieren() {
	if (!p_pFahrzeuge.empty()) {
		// Simulation aller auf dem Weg befindlichen Fahrzeuge

		auto fahrzeug = p_pFahrzeuge.begin();
		bool Verbot = false;
		next_fahrStrecke = 0;
		while (fahrzeug != p_pFahrzeuge.end()) {
			double tmp = fahrzeug->get()->get_TeilStrecke();
			if (tmp > next_fahrStrecke) {
				set_next_FahrStrecke(tmp);
			}
			fahrzeug->get()->vZeichnen(*this);
			fahrzeug->get()->vSimulieren(Verbot, next_fahrStrecke);

			if (fahrzeug->get() == nullptr) {
				auto next = p_pFahrzeuge.next(fahrzeug);
				p_pFahrzeuge.erase(fahrzeug);
				p_pFahrzeuge.vAktualisieren();
				fahrzeug = next;
			} else {
				auto next = p_pFahrzeuge.next(fahrzeug);
				fahrzeug = next;
				Verbot = u_bVerbot;

			}
		}
	}
}

ostream& Weg::vAusgeben(ostream &ausgabe) const {

	ausgabe << p_sName << " : " << p_dLaenge << "  ( ";
	for (const auto &fahrzeug : p_pFahrzeuge) {
		ausgabe << fahrzeug->getName() << " ";
	}
	ausgabe << ") ";

	return ausgabe;
}

void Weg::vKopf() {
	cout << std::setw(5) << "ID" << " | " << std::setw(10) << "Name" << " | "
			<< std::setw(10) << "Laenge" << " | " << std::setw(30)
			<< "Fahrzeuge" << std::endl;
	cout << std::string(55, '-') << std::endl;
}

double Weg::getLaenge() {
	return p_dLaenge;
}

void Weg::vAnnahme(unique_ptr<Fahrzeug> fahrzeug) {

	p_pFahrzeuge.push_back(std::move(fahrzeug));
	auto ptr = p_pFahrzeuge.end();
	--ptr;
	ptr->get()->vNeueStrecke(*this);

}
void Weg::vAnnahme(unique_ptr<Fahrzeug> fahrzeug, double dStartzeitpunkt) {

	p_pFahrzeuge.push_front(std::move(fahrzeug));
	auto ptr = p_pFahrzeuge.begin();
	ptr->get()->vNeueStrecke(*this, dStartzeitpunkt);

}
unique_ptr<Fahrzeug> Weg::vAbgabe(const Fahrzeug &fahrzeug) {
	auto it = find_if(p_pFahrzeuge.begin(), p_pFahrzeuge.end(),
			[&](const unique_ptr<Fahrzeug> &ptr) {
				return ptr && *ptr == fahrzeug;
			});

	if (it != p_pFahrzeuge.end()) {
		unique_ptr<Fahrzeug> removedFahrzeug = move(*it);
		p_pFahrzeuge.erase(it);
		return removedFahrzeug;
	}

	return nullptr;
}
void Weg::vUmstellen(const Fahrzeug &fahrzeug) {
//TODO:Надо затанковаться
	auto it = find_if(p_pFahrzeuge.begin(), p_pFahrzeuge.end(),
			[&](const unique_ptr<Fahrzeug> &ptr) {
				return ptr && *ptr == fahrzeug;
			});

	if (it != p_pFahrzeuge.end()) {
		unique_ptr<Fahrzeug> removedFahrzeug = move(*it);
		//p_pFahrzeuge.erase(it);

		auto zuFF = getKreuzung()->pZufaelligerWeg(*this);
		zuFF->vAnnahme(move(removedFahrzeug));
	}
}

shared_ptr<Kreuzung> Weg::getKreuzung() const {
	return p_pZielKreuzung.lock();
}
shared_ptr<Weg> Weg::getRueckweg() const {
	return p_pRueckWeg.lock();
}

void Weg::setRueckweg(shared_ptr<Weg> rueckweg) {
	p_pRueckWeg = rueckweg;
}
void Weg::setKreuzung(shared_ptr<Kreuzung> kreuzung) {
	//weak_ptr<Kreuzung>pKreuzung = kreuzung;
	p_pZielKreuzung = kreuzung;
	//p_pZielKreuzung=kreuzung;
}

void Weg::set_next_FahrStrecke(double next_FahrCopyStreke) {
	next_fahrStrecke = next_FahrCopyStreke;
}
