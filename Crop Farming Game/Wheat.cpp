#include <iostream>
#include <fstream>

#include "Wheat.h"

using namespace std;

Wheat::Wheat() : Crop(100, 9, 800, 33, false, false) {}

void Wheat::water()
{
	humidity += 10;
	if (humidity > 100)
		humidity = 100;
}
void Wheat::fertilize()
{
	fertilizer += 500;
}
void Wheat::fungusTreatment()
{
	fungus = false;
}
void Wheat::insectTreatment()
{
	bugs = false;
}

void Wheat::nextDay()
{
	Crop::nextDay();
	humidity -= 5;
	fertilizer -= 200;
	if (humidity < 25 || humidity > 40) {
		health -= 8;
		if (humidity < 0)
			humidity = 0;
	}
	if (fertilizer < 600 || fertilizer > 1000) {
		health -= 5;
		if (fertilizer < 0)
			fertilizer = 0;
	}
	days--;
}
void Wheat::save()
{
	ofstream savedFile;

	savedFile.open("SavedFile.txt");

	savedFile << 'w' << endl
		<< health << endl
		<< days << endl
		<< fertilizer << endl
		<< humidity << endl
		<< bugs << endl
		<< fungus << endl;
	savedFile.close();
}
