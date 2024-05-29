#include <iostream>
#include <fstream>

#include "Corn.h"

using namespace std;

Corn::Corn() : Crop(100, 9, 1500, 80, false, false) {}

void Corn::water() 
{
	humidity += 10;
	if (humidity > 100)
		humidity = 100;
}
void Corn::fertilize() 
{
	fertilizer += 500;
}
void Corn::fungusTreatment()
{
	fungus = false;
}
void Corn::insectTreatment()
{
	bugs = false;
}

void Corn::nextDay()
{
	Crop::nextDay();
	humidity -= 5;
	fertilizer -= 300;
	if (humidity < 70 || humidity > 90){
		health -= 10;
	    if (humidity < 0)
			humidity = 0;
	}
	if (fertilizer < 750 || fertilizer > 2000) {
		health -= 8;
		if (fertilizer < 0)
			fertilizer = 0;
	}
	days--;
}
void Corn::save()
{
	ofstream savedFile;

	savedFile.open("SavedFile.txt");

	savedFile << 'c' << endl
		<< health << endl
		<< days << endl
		<< fertilizer << endl
		<< humidity << endl
		<< bugs << endl
		<< fungus << endl;
	savedFile.close();
}