#ifndef WHEAT_H
#define WHEAT_H
#include "Crop.h"

using namespace std;

class Wheat : public Crop {
public:
	Wheat();

	void water();
	void fertilize();
	void fungusTreatment();
	void insectTreatment();

	void nextDay() override;
	void save() override;
};
#endif