/*
 * main.cpp
 *
 *  Created on: 23 нояб. 2023 г.
 *      Author: alexp
 */

/*
 * main.cpp
 *
 *  Created on: 25 окт. 2023 г.
 *      Author: alexp
 */
#include "Fahrrad.h"
#include "PKW.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

#include <random>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#include "SimuClient.h"
#include "vertagt_aktion.h"
#include "vertagt_liste.h"

/*int main()
 {
 Fahrzeug *car1 = new Fahrzeug("LADA", 0,4);
 //cout<<car1->get_Name()<<endl;//первый с динамической памятью. Надо самим все удалять.
 //free(car1);
 Fahrzeug car2("URAL",1,5);
 //cout<<car2.get_ID()<<endl;//статическая память

 std::unique_ptr<Fahrzeug> car3 = std::make_unique<Fahrzeug>("Porsche",9,3);
 std::unique_ptr<Fahrzeug> car4 = std::make_unique<Fahrzeug>("Bentley",6,4);
 car4->set_Name("Kalinka");
 cout<<car3->get_Name()<<endl;
 cout<<car4->get_Name()<<endl;
 std::vector<std::unique_ptr<Fahrzeug>> fahrzeugVector1;
 fahrzeugVector1.push_back(move(car3));
 fahrzeugVector1.push_back(move(car4));

 std::shared_ptr<Fahrzeug> car5 = std::make_shared<Fahrzeug>("Hundai",10,5);
 cout<<car5->get_Name()<<endl;

 std::shared_ptr<Fahrzeug> car6 = std::make_shared<Fahrzeug>("Krundai",12,6);
 cout<<car6->get_Name()<<endl;
 std::vector<std::shared_ptr<Fahrzeug>> fahrzeugVector2;
 fahrzeugVector2.push_back(move(car5));//в конце дебага он прошелся в другую сторону и удалил все вектора с названием move
 fahrzeugVector2.push_back(car6);// этот вектор он не удалил!!

 car2.vKopf();
 car2.vAusgaben();cout << endl;
 car1->vAusgaben();cout << endl;
 //car4->vAusgaben();cout << endl;
 //car5->vAusgaben();cout << endl;
 //car6->vAusgaben();cout << endl;

 fahrzeugVector2.clear();
 fahrzeugVector1.clear();
 car3.reset();//удалить объекты
 car4.reset();
 car5.reset();
 car6.reset();
 //~unique_ptr(fahrzeugVector1);//деконструктор вектора...нужен ли он хрен знает
 return 0;
 };*/
// int Aufgabe_1(){
// 		std::unique_ptr<Fahrzeug> car10 = std::make_unique<Fahrzeug>("k334",30);
// 		std::unique_ptr<Fahrzeug> car11 = std::make_unique<Fahrzeug>("k335",50);
// 		std::unique_ptr<Fahrzeug> car12 = std::make_unique<Fahrzeug>("k336",60);
// 		std::vector<std::unique_ptr<Fahrzeug>> fahrzeugVector3;
// 		fahrzeugVector3.push_back(move(car10));
// 		fahrzeugVector3.push_back(move(car11));
// 		fahrzeugVector3.push_back(move(car12));

// 		for(dGlobaleZeit=0.0;dGlobaleZeit<20.0;dGlobaleZeit+=1){
// 			fahrzeugVector3[0]->vSimulieren();
// 			fahrzeugVector3[1]->vSimulieren();
// 			fahrzeugVector3[2]->vSimulieren();
// 			cout << endl;
// 			cout<<dGlobaleZeit<<" Stunden"<< endl;
// 			cout << endl;
// 			fahrzeugVector3[0]->vKopf();
// 			//fahrzeugVector3[0]->vAusgaben();cout << endl;
// 			//fahrzeugVector3[1]->vAusgaben();cout << endl;
// 			//fahrzeugVector3[2]->vAusgaben();cout << endl;
// 		};
// 		car10.reset();
// 		car11.reset();
// 		car12.reset();
// 		fahrzeugVector3.clear();
// 	return 0;
// 	};

int Aufgabe_2() {

	// std::unique_ptr<PKW> pkw10 = std::make_unique<PKW>("hrunja", 55,3);
	// std::unique_ptr<PKW> pkw11 = std::make_unique<PKW>("fignja", 55,7);
	// std::unique_ptr<PKW> pkw12 = std::make_unique<PKW>("Skorost",55,2);

	// std::unique_ptr<Fahrrad> fahrrad10 = std::make_unique<Fahrrad>("kaskad",20);
	// std::unique_ptr<Fahrrad> fahrrad11 = std::make_unique<Fahrrad>("fin",15);
	// std::unique_ptr<Fahrrad> fahrrad12 = std::make_unique<Fahrrad>("pravda",39);
	// std::vector<std::unique_ptr<Fahrrad>> fahrradVector3;
	// std::vector<std::unique_ptr<PKW>> pkwVector3;

	// fahrradVector3.push_back(move(fahrrad10));
	// fahrradVector3.push_back(move(fahrrad11));
	// fahrradVector3.push_back(move(fahrrad12));

	// pkwVector3.push_back(move(pkw10));
	// pkwVector3.push_back(move(pkw11));
	// pkwVector3.push_back(move(pkw12));

	PKW *pkw0 = new PKW("maz", 6, 120, 5);
	PKW *pkw1 = new PKW("paz", 7, 120, 7);
	PKW *pkw2 = new PKW("gaz", 8, 120, 9);

	pkw0->vKopf();
	// 3 stunde
	{
		dGlobaleZeit = 180;
		pkw0->vSimulieren();
		pkw1->vSimulieren();
		pkw2->vSimulieren();
		cout << *pkw0 << endl;
		cout << *pkw1 << endl;
		cout << *pkw2 << endl;
	}
	// tankinhalt 100%
	pkw0->vKopf();
	{
		pkw0->dTanken(100);
		pkw1->dTanken(100);
		pkw2->dTanken(100);
		// cout << "Заправлено в 0: " << pkw0->dTanken(100) << endl;
		// cout << "Заправлено в 1: " << pkw1->dTanken(100) << endl;
		// cout << "Заправлено в 2: " << pkw2->dTanken(100) << endl;
		cout << *pkw0 << endl;
		cout << *pkw1 << endl;
		cout << *pkw2 << endl;

	}
	// 6 stunde
	pkw0->vKopf();
	{
		dGlobaleZeit += 180;
		pkw0->vSimulieren();
		pkw1->vSimulieren();
		pkw2->vSimulieren();
		cout << *pkw0 << endl;
		cout << *pkw1 << endl;
		cout << *pkw2 << endl;
	}

	delete (pkw0);
	delete (pkw1);
	delete (pkw2);

	Fahrrad *fahrrad10 = new Fahrrad("kez", 3, 40);
	Fahrrad *fahrrad11 = new Fahrrad("erakez", 4, 13);
	Fahrrad *fahrrad12 = new Fahrrad("tez", 5, 120);

	fahrrad10->vKopf();
	fahrrad10->vSimulieren();
	fahrrad11->vSimulieren();
	fahrrad12->vSimulieren();

	cout << *fahrrad10 << endl;
	cout << *fahrrad11 << endl;
	cout << *fahrrad12 << endl;

	delete (fahrrad10);
	delete (fahrrad10);
	delete (fahrrad10);
	return 0;
}
;

void Aufgabe_4() {
	Weg weg("Klusstr", 100.0, Tempolimit::Landstrasse, 0); // Annahme: Konstruktor für Weg mit Name und Länge
	weg.vKopf();
	cout << weg << endl;
}
;

void Aufgabe_5() {
	unique_ptr<Fahrzeug> bmw = std::make_unique<PKW>("BMW", 1, 100, 9);
	unique_ptr<Fahrzeug> audi = std::make_unique<PKW>("Audi", 2, 50, 8);
	unique_ptr<Fahrzeug> bmx = std::make_unique<Fahrrad>("BMX", 3, 30);

	Weg weg("Klusstr", 100.0, Tempolimit::Landstrasse, 0); // Annahme: Konstruktor für Weg mit Name und Länge
//	weg.fahrzeugHinzufuegen(move(bmw));
//	weg.fahrzeugHinzufuegen(move(audi));
//	weg.fahrzeugHinzufuegen(move(bmx));
	dGlobaleZeit = 70;
	weg.vKopf();
	// Fahrzeuge auf dem Weg annehmen
	weg.vAnnahme(move(bmw)); // должен вывести 100 в p_dGesamtstrecke и das Ende des Weges
	weg.vAnnahme(move(audi), 80); // 0, das Auto kann nict mehr halten
	weg.vAnnahme(move(bmx)); //35

	cout << weg << endl;

}
;

void Aufgabe_6() {
	int f[4] = { 700, 250, 100, 250 };
//
	bInitialisiereGrafik(1000, 1000);
	bZeichneStrasse("weg11", "weg12", 25, 2, f);
	unique_ptr<Fahrzeug> bmw = std::make_unique<PKW>("BMW", 1, 100, 1);
	unique_ptr<Fahrzeug> audi = std::make_unique<PKW>("Audi", 2, 50, 8);
	unique_ptr<Fahrzeug> bmx = std::make_unique<Fahrrad>("BMX", 3, 30);

	Weg weg11("weg11", 10.0, Tempolimit::Autobahn, 0);
	Weg weg12("weg12", 10.0, Tempolimit::Autobahn, 0);
	//Weg weg21("weg21", 0, 30.0, Tempolimit::Autobahn);
	//Weg weg22("weg22", 0, 30.0, Tempolimit::Autobahn);

	weg11.vKopf();
	weg11.vAnnahme(move(bmw));// должен вывести 100 в p_dGesamtstrecke и das Ende des Weges
	weg12.vAnnahme(move(audi), 3);	// 0, das Auto kann nict mehr halten
	weg12.vAnnahme(move(bmx));	//35

//Эта симуляция нееее работает если брать время больше !!!!!
	for (dGlobaleZeit = 0; dGlobaleZeit < 1000; dGlobaleZeit += 1) {
		cout << string(130, '=') << endl;
		cout << "Simulieren Zeit: " << dGlobaleZeit << " min" << endl;
		cout << string(130, '=') << endl;
		//
		cout << weg11 << endl;
		weg11.vSimulieren();

		cout << string(130, '-') << endl;
		cout << weg12 << endl;
		weg12.vSimulieren();

		vSetzeZeit((double) dGlobaleZeit);
		vSleep(100);
	}

}
;
void Aufgabe_6a() {
	// Initialisierung des Zufallszahlengenerators
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));

	vertagt::VListe<int> vListe;

	for (int i = 0; i < 10; ++i) {
		//int randomValue = std::rand() % 10 + 1;
		static std::mt19937 device(0);
		std::uniform_int_distribution<int> dist(-1, 11);
		int zuf = dist(device);
		int randomValue = zuf;
		vListe.push_back(randomValue);
	}
	;

	// Liste vor den Aktionen ausgeben
	cout << "Liste vor den Aktionen:" << endl;

	for (const auto &element : vListe) {
		cout << element << " ";
	}
	;

	cout << endl;

	// Innerhalb einer Schleife alle Elemente > 5 mit erase() löschen
	auto it = vListe.begin();

	while (it != vListe.end()) {
		auto nextIt = next(it); // Получаем следующий итератор перед удалением текущего элемента

		if (*it > 5) {
			vListe.erase(it);
			it = nextIt;
		}

		else {
			++it;
		}
	}
	;

	// Liste nach dem Löschen ausgeben (sollte die gleiche Ausgabe wie vorher sein)

	std::cout << "Liste nach dem Löschen (ohne vAktualisieren()):" << std::endl;
	for (const auto &element : vListe) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	// vAktualisieren() auf die Liste anwenden
	vListe.vAktualisieren();

	// Liste nach dem Aktualisieren ausgeben (sollte sich geändert haben)
	std::cout << "Liste nach dem Aktualisieren:" << std::endl;
	for (const auto &element : vListe) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	// Am Anfang und am Ende der Liste zwei beliebige (verschiedene) Zahlen einfügen
	vListe.push_front(6);
	vListe.push_back(7);

	// Liste zur Kontrolle nochmal ausgeben
	std::cout << "Liste nach dem Einfügen am Anfang und am Ende:" << std::endl;
	for (const auto &element : vListe) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

}
;

void vAufgabe_7() {
	bInitialisiereGrafik(1000, 1000);

	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	int a[4] = { 680, 40, 680, 300 };
	bZeichneStrasse("W12", "W21", 40, 2, a);
	//bZeichneStrasse( "W21","W12", 40, 2, a);

	int b[12] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	bZeichneStrasse("W23a", "W32a", 115, 6, b);
	//bZeichneStrasse( "W32a","W23a", 115, 6, b);

	int c[4] = { 680, 300, 680, 570 };
	bZeichneStrasse("W23b", "W32b", 40, 2, c);
	//bZeichneStrasse( "W32b","W23b", 40, 2, c);

	int d[4] = { 680, 300, 320, 300 };
	bZeichneStrasse("W24", "W42", 55, 2, d);
	//bZeichneStrasse( "W42","W24", 55, 2, d);

	int e[10] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	bZeichneStrasse("W34", "W43", 85, 5, e);
	//bZeichneStrasse( "W43","W34", 85, 5, e);

	int g[14] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320,
			300 };
	bZeichneStrasse("W44a", "W44b", 130, 7, g);
	//bZeichneStrasse( "W44b","W44a", 130, 7, g);

	shared_ptr<Kreuzung> Kr1 = std::make_shared<Kreuzung>("Kr1", 0);
	shared_ptr<Kreuzung> Kr2 = std::make_shared<Kreuzung>("Kr2", 1000);
	shared_ptr<Kreuzung> Kr3 = std::make_shared<Kreuzung>("Kr3", 0);
	shared_ptr<Kreuzung> Kr4 = std::make_shared<Kreuzung>("Kr4", 0);

	Kr1->vVerbinde("W12", "W21", 40, Kr1, Kr2, Tempolimit::Landstrasse, 1);
	Kr2->vVerbinde("W23a", "W32a", 115, Kr2, Kr3, Tempolimit::Landstrasse, 1);
	Kr2->vVerbinde("W23b", "W32b", 40, Kr2, Kr3, Tempolimit::Landstrasse, 1);
	Kr2->vVerbinde("W24", "W42", 55, Kr2, Kr4, Tempolimit::Landstrasse, 1);
	Kr3->vVerbinde("W34", "W43", 85, Kr3, Kr4, Tempolimit::Autobahn, 1);
	Kr4->vVerbinde("W44a", "W44b", 130, Kr4, Kr4, Tempolimit::Autobahn, 1);
	unique_ptr<Fahrzeug> bmw = std::make_unique<PKW>("BMW", 1, 120, 10);
	unique_ptr<Fahrzeug> audi = std::make_unique<PKW>("Audi", 2, 110, 10);
	unique_ptr<Fahrzeug> bmx = std::make_unique<Fahrrad>("BMX", 15, 30);
	unique_ptr<Fahrzeug> bmw1 = std::make_unique<PKW>("BMW1", 1, 120, 10);
	unique_ptr<Fahrzeug> audi1 = std::make_unique<PKW>("Audi1", 2, 110, 10);
	unique_ptr<Fahrzeug> bmx1 = std::make_unique<Fahrrad>("BMX1", 15, 30);
	unique_ptr<Fahrzeug> bmw2 = std::make_unique<PKW>("BMW2", 1, 120, 10);
	unique_ptr<Fahrzeug> audi2 = std::make_unique<PKW>("Audi2", 2, 110, 10);
	unique_ptr<Fahrzeug> bmx2 = std::make_unique<Fahrrad>("BMX2", 15, 30);
	unique_ptr<Fahrzeug> bmw3 = std::make_unique<PKW>("BMW3", 1, 120, 10);
	unique_ptr<Fahrzeug> audi3 = std::make_unique<PKW>("Audi3", 2, 110, 10);
	unique_ptr<Fahrzeug> bmx3 = std::make_unique<Fahrrad>("BMX3", 15, 30);

	Kr1->vAnnahme(move(bmw));
	Kr1->vAnnahme(move(audi));
	Kr1->vAnnahme(move(bmx));
	Kr2->vAnnahme(move(bmw1));
	Kr2->vAnnahme(move(audi1));
	Kr2->vAnnahme(move(bmx1));
	Kr3->vAnnahme(move(bmw2));
	Kr3->vAnnahme(move(audi2));
	Kr3->vAnnahme(move(bmx2));
	Kr4->vAnnahme(move(bmw3));
	Kr4->vAnnahme(move(audi3));
	Kr4->vAnnahme(move(bmx3));

	for (dGlobaleZeit = 0; dGlobaleZeit < 1000; dGlobaleZeit += 1) {
		cout << string(130, '=') << endl;
		cout << "Simulieren Zeit: " << dGlobaleZeit << " min" << endl;
		cout << string(130, '=') << endl;
		//
		Kr1->vSimulieren();
		cout << string(130, '-') << endl;
		Kr2->vSimulieren();
		cout << string(130, '-') << endl;
		Kr3->vSimulieren();
		cout << string(130, '-') << endl;
		Kr4->vSimulieren();

		vSetzeZeit((double) dGlobaleZeit);
		vSleep(100);
	}

	//BeendeGrafik();
}
;

int main() {

	//Aufgabe_4();
	//Aufgabe_5();
	//Aufgabe_6();
	//Aufgabe_6a();
	vAufgabe_7();

	return 0;
}
;
