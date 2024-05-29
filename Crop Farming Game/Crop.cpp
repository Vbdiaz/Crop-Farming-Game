#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Crop.h"

using namespace std;

Crop::Crop(int h, int d, int f, int hu, bool b, bool fu)
{
	health = h;
	days = d;
	fertilizer = f;
	humidity = hu;
	bugs = b;
	fungus = fu;
}

int Crop::getHealth() { return health; }
int Crop::getDays() { return days; }
int Crop::getFertilizer() { return fertilizer; }
int Crop::getHumidity() { return humidity; }
bool Crop::getBugs() { return bugs; }
bool Crop::getFungus() { return fungus; }

void Crop::setHealth(int h) { health = h; }
void Crop::setDays(int d) { days = d; }
void Crop::setFertilizer(int f) { fertilizer = f; }
void Crop::setHumidity(int hu) { humidity = hu; }
void Crop::setBugs(bool b) { bugs = b; }
void Crop::setFungus(bool fu) { fungus = fu; }

void Crop::nextDay() {
	int temp = 0;
	srand(time(0));
	temp = (rand() % 15) + 1;
	if (temp == 6 || temp == 9) {
		if (bugs == false && fungus == false) {
			fungus = true;
		}
	}
	else if (temp == 1 || temp == 5) {
		if (fungus == false && bugs == false) {
			bugs = true;
		}
	}
	if (bugs == true) {
		health -= 12;
	}
	else if (fungus == true) {
		health -= 12;
	}
}

void Crop::print()
{
	cout << endl << "*********************************" << endl;
	cout << setw(((34 - 5) / 2) + 5) << "DAY " << (10 - days) << endl;
	if (days > 9) {
		cout << "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}
	else if (days > 8 && days < 10) {
		cout << "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "       \\|//\\|/\\|/,\\|/|/|// " << endl
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}
	else if (days > 6 && days < 9) {
		cout << "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "       \\|/ \\|/\\|/  \{{{}}/  " << endl
			<< "       \\|/ \\|/\\|/ \\|~Y~//  " << endl
			<< "       \\|//\\|/\\|/,\\|/|/|// " << endl
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}

	else if (days > 5 && days < 7) {
		cout << "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "       \\|/ \\|/~Y~ \\|,,,|/  " << endl
			<< "       \\|/ \\|/\\|/  \{{{}}/  " << endl
			<< "       \\|/ \\|/\\|/ \\|~Y~//  " << endl
			<< "       \\|//\\|/\\|/,\\|/|/|// " << endl
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}
	else if (days > 3 && days < 6) {
		cout << "" << endl
			<< "" << endl
			<< "" << endl
			<< "" << endl
			<< "       ~Y~ \\|{{}}}\\|/  Y  " << endl
			<< "       \\|/ \\|/~Y~ \\|,,,|/  " << endl
			<< "       \\|/ \\|/\\|/  \{{{}}/  " << endl
			<< "       \\|/ \\|/\\|/ \\|~Y~//  " << endl
			<< "       \\|//\\|/\\|/,\\|/|/|// " << endl
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}
	else if (days > 0 && days < 4) {
		cout << "" << endl
			<< "" << endl
			<< "" << endl
			<< "      {{}}} |/,,, ~Y~{{}}} " << endl
			<< "       ~Y~ \\|{{}}}\\|/  Y  " << endl
			<< "       \\|/ \\|/~Y~ \\|,,,|/  " << endl
			<< "       \\|/ \\|/\\|/  \{{{}}/  " << endl
			<< "       \\|/ \\|/\\|/ \\|~Y~//  " << endl
			<< "       \\|//\\|/\\|/,\\|/|/|// " << endl
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}
	else if (days == 0) {
		cout << "           ,,,              " << endl
			<< "          {{{}}   ,,,      " << endl
			<< "       ,,, ~Y~   {{{}},,,  " << endl
			<< "      {{}}} |/,,, ~Y~{{}}} " << endl
			<< "       ~Y~ \\|{{}}}\\|/  Y  " << endl
			<< "       \\|/ \\|/~Y~ \\|,,,|/  " << endl
			<< "       \\|/ \\|/\\|/  \{{{}}/  " << endl
			<< "       \\|/ \\|/\\|/ \\|~Y~//  " << endl
			<< "       \\|//\\|/\\|/,\\|/|/|// " << endl
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	}
	cout << setw(((34 - 11) / 2) + 11) << "CROP STATS" << endl;
	cout << "Health: " << health << endl;
	cout << "Fertilizer level: " << fertilizer << " ppm" << endl;
	cout << "Humidity level: " << humidity << "%" << endl;
	cout << "Days left: " << days << endl;
	if (fungus == true && days != 1)
		cout << "UH-OH we have a fungus infestation!" << endl;
	if (bugs == true && days != 1)
		cout << "UH-OH bugs are eating your crops!" << endl;
}