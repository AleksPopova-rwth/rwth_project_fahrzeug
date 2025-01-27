#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

Kreuzung::Kreuzung(string sName, double dTankvolumen) :
		Simulationsobjekt(sName), p_dTankstelle(dTankvolumen) {
}

Kreuzung::~Kreuzung() {
	// Ваш код деструктора
}

void Kreuzung::vSimulieren() {
	//Simulationsobjekt::vSimulieren();
	for (auto &weg : p_pWege) {
		weg->vSimulieren();
		cout << *weg << endl;
	}
}

void Kreuzung::vVerbinde(string sName, string sRueckName, double dWegLaenge,
		shared_ptr<Kreuzung> startKreuzung, shared_ptr<Kreuzung> zielKreuzung,
		Tempolimit dGeschwBegr, bool bUeberholV) {
	//TODO: Написать тут присвоение параметров;

	auto weg = make_shared<Weg>(sName, dWegLaenge, dGeschwBegr, bUeberholV);
	auto rueckweg = make_shared<Weg>(sRueckName, dWegLaenge, dGeschwBegr,
			bUeberholV);
//TODO написать объект
	weg->setRueckweg(rueckweg);
	rueckweg->setRueckweg(weg);
	weg->setKreuzung(zielKreuzung);
	rueckweg->setKreuzung(startKreuzung);
	startKreuzung->p_pWege.push_back(weg);
	zielKreuzung->p_pWege.push_back(rueckweg);
}

double Kreuzung::vTanken(Fahrzeug &fahrzeug) {
	double tankMenge = p_dTankstelle;
	if (tankMenge > fahrzeug.get_Tankinhalt() + tankMenge) {
		tankMenge = fahrzeug.get_Tankvolumen() - fahrzeug.get_Tankinhalt();
	}
	double diff = fahrzeug.dTanken(tankMenge);
	return p_dTankstelle -= diff;
}

void Kreuzung::vAnnahme(unique_ptr<Fahrzeug> fahrzeug) {
	vTanken(*fahrzeug);
	auto ptr = p_pWege.begin();
	ptr->get()->vAnnahme(move(fahrzeug));

}
shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg &weg) {

	vector<shared_ptr<Weg>> availableWege;

	for (const auto &wege : weg.getKreuzung()->p_pWege) {
		if (wege.get() != &weg) {
			availableWege.push_back(wege);
		}
	}

	if (availableWege.empty()) {
		std::cerr << "Fehler: Keine verfügbaren Wege außer dem eingehenden Weg."
				<< std::endl;
		// Hier können Sie je nach Anforderung einen Standardweg zurückgeben oder eine Ausnahme werfen.
		return weg.getRueckweg();
	}
	// Zufälligen Weg auswählen
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, availableWege.size() - 1);
	int randomIndex = dis(gen);

	return availableWege[randomIndex];
}
double Kreuzung::getTankstelle() {
	return p_dTankstelle;
}

//bool Kreuzung::operator < (const Kreuzung& kreuzung) const
//{
//}
