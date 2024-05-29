#ifndef CORN_H
#define CORN_H

#include "Crop.h"

using namespace std;

class Corn : public Crop {
public:
	Corn();

	void water();
	void fertilize();
	void fungusTreatment();
	void insectTreatment();

	void nextDay() override;
	void save() override;
};
#endif