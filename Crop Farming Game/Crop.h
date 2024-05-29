#ifndef CROP_H
#define CROP_H
using namespace std;

class Crop {
public:

	Crop(int h, int d, int f, int hu, bool b, bool fu);

	int getHealth();
	int getDays();
	int getFertilizer();
	int getHumidity();
	bool getBugs();
	bool getFungus();

	void setHealth(int h);
	void setDays(int d);
	void setFertilizer(int f);
	void setHumidity(int hu);
	void setBugs(bool b);
	void setFungus(bool fu);

	virtual void nextDay();
	virtual void save() = 0;
	void print();
protected:
	int health;
	int days;
	int fertilizer;
	int humidity;
	bool bugs;
	bool fungus;
};
#endif