#ifndef TEMPOLIMIT_H
#define TEMPOLIMIT_H
#pragma once
// Aufzählungsklasse für die verschiedenen Tempolimit-Kategorien
enum class Tempolimit {
	Innerorts = 50, Landstrasse = 100, Autobahn = -1 // -1 als Konvention für unbegrenztes Tempolimit
};
#endif // TEMPOLIMIT_H
