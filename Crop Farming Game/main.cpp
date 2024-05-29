#include <iostream>
#include <fstream>
#include <iomanip>

#include "Corn.h"
#include "Wheat.h"

using namespace std;

int main() {
	//Declare variables and objects
	Corn* corn = new Corn();
	Wheat* wheat = new Wheat();
	char gameSelection = 'x';
	char cropSelection = 'x';
	char decision = 'x';
	char result = 'l';
	
	// GAME SELECTION BETWEEN NEW OR SAVED
	cout << "==================================================" << endl

		<< setw((34 / 2) + 16) << "WELCOME FARMER!" << endl << endl
		<< setw((35 / 2) + 15) << "Game Selection" << endl << endl
		<< "Load New Game (n) or Load Saved File (s): ";
	cin >> gameSelection;
	cout << endl;

	while (gameSelection != 's' && gameSelection != 'n') {
		cout << "That is an invalid option farmer!" << endl
			<< "Let's try that again: ";
		cin >> gameSelection;
		cout << endl;
	}


	//IF SAVED FILE CHOSEN
	if (gameSelection == 's') {
		int health;
		int days;
		int fertilizer;
		int humidity;
		bool bugs;
		bool fungus;


		ifstream savedFile;

		savedFile.open("SavedFile.txt");

		if (!savedFile.is_open()) {
			cout << "File Not Found!" << endl;
			exit(-1);
		}

		savedFile >> cropSelection;

		if (cropSelection != 'c' && cropSelection != 'w') {
			cout << "No saved crop!";
			exit(-1);
		}

		savedFile >> health >> days >> fertilizer >> humidity >> bugs >> fungus;
		cout << "variables " << bugs << fungus << endl;
		if (cropSelection == 'c') {
			corn->setHealth(health);
			corn->setDays(days);
			corn->setFertilizer(fertilizer);
			corn->setHumidity(humidity);
			corn->setBugs(bugs);
			corn->setFungus(fungus);
		}
		else if (cropSelection == 'w') {
			wheat->setHealth(health);
			wheat->setDays(days);
			wheat->setFertilizer(fertilizer);
			wheat->setHumidity(humidity);
			wheat->setBugs(bugs);
			wheat->setFungus(fungus);
		}
	}//IF NEW GAME IS CHOSEN
	else {
		cout << "==================================================" << endl
			<< setw((41 / 2) + 9) << "New Game" << endl << endl
			<< setw((35 / 2) + 15) << "Crop Selection" << endl << endl
			<< "Corn (c) or Wheat (w): ";
		cin >> cropSelection;
		cout << endl;
		while (cropSelection != 'c' && cropSelection != 'w') {
			cout << "That is an invalid option farmer!" << endl
				<< "Let's try that again: ";
			cin >> cropSelection;
			cout << endl;
		}
	}
	
	//GAME LOOP
	cout << "===================================================================" << endl;
	cout << setw((51 / 2) + 9) << "Tutorial" << endl << endl;
	if (cropSelection == 'c') {
		cout << setw((27 / 2) + 41) << "Howdy! Remember this when planting corn!" << endl << endl
			<< "1. You can only do one task per day." << endl
			<< "2. Keep humidity between 70% and 90% press (w) to water." << endl
			<< "3. Keep fertilizer between 750 and 2000 ppm press (f) to fertilize." << endl
			<< "4. In case of a fungus use (t) to treat your crops." << endl
			<< "5. In case of a bug infestation press (b) to treat your crops." << endl
			<< "6. Remember to press (s) to save and quit the game!" << endl;
		cout << "===================================================================" << endl;
		while (corn->getHealth() > 0) {
			corn->print();
			cout << endl << "What will we be doing today? ";
			cin >> decision;
			while (decision != 'w' && decision != 'f' && decision != 't' && decision != 'b' && decision != 's') {
				cout << "That is an invalid option farmer!" << endl
					<< "Let's try that again: ";
				cin >> decision;
				cout << endl;
			}
			if (decision == 'w')
				corn->water();
			else if (decision == 'f')
				corn->fertilize();
			else if (decision == 't')
				corn->fungusTreatment();
			else if (decision == 'b')
				corn->insectTreatment();
			else if (decision == 's') {
				corn->save();
				cout << endl << "File saved. Come back soon farmer!" << endl;
				return 0;
			}
			if (corn->getDays() == 0) {
				result = 'w';
				break;
			}
			corn->nextDay();
		}
	}
	else if (cropSelection == 'w') {
		cout << setw((26 / 2) + 42) << "Howdy! Remember this when planting wheat!" << endl << endl
			<< "1. You can only do one task per day." << endl
			<< "2. Keep humidity between 25% and 40% press (w) to water." << endl
			<< "3. Keep fertilizer between 600 and 1000 ppm press (f) to fertilize." << endl
			<< "4. In case of a fungus press (t) to treat your crops." << endl
			<< "5. In case of a bug infestation press (b) to treat your crops." << endl
			<< "6. Remember to press (s) to save and quit the game!" << endl;
		cout << "===================================================================" << endl;
		while (wheat->getHealth() > 0) {
			wheat->print();
			cout << endl << "What will we be doing today? ";
			cin >> decision;
			while (decision != 'w' && decision != 'f' && decision != 't' && decision != 'b' && decision != 's') {
				cout << "That is an invalid option farmer!" << endl
					<< "Let's try that again: ";
				cin >> decision;
				cout << endl;
			}
			if (decision == 'w')
				wheat->water();
			else if (decision == 'f')
				wheat->fertilize();
			else if (decision == 't')
				wheat->fungusTreatment();
			else if (decision == 'b')
				wheat->insectTreatment();
			else if (decision == 's') {
				wheat->save();
				cout << "File saved. Come back soon farmer!" << endl;
				return 0;
			}
			if (wheat->getDays() == 0) {
				result = 'w';
				break;
			}
			wheat->nextDay();
		}
	}

	cout << endl << "*********************************" << endl;

	//OUTPUT IF USER WINS OR LOSE
	if (result == 'w') {
		cout << endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
		cout << setw(((40 - 9) / 2) + 9) << "YOU WIN!" << endl << endl
			<< " HOORAY Farmer! Harvest season is here!" << endl
			<< setw(((40 - 13) / 2) + 13) << "We are RICH!" << endl << endl
			<< ",,,,,,,,,,,,,,,,,,,$$$$" << endl
			<< ",,,,,,,,,,,$$$$$$$$$$$$$$$$$" << endl
			<< ",,,,,,,,,$$$$$$$$$$$$$$$$$$$$$$" << endl
			<< ",,,,,,,,$$$$$$$,,,,$$$$,,,$$$$$$$$" << endl
			<< ",,,,,,,$$$$$$,,,,,$$$$,,,,,,$$$$$$$" << endl
			<< ",,,,,,$$$$$$,,,,,,$$$$,,,,,,,$$$$$$" << endl
			<< ",,,,,,$$$$$$,,,,,,$$$$" << endl
			<< ",,,,,,$$$$$$,,,,,,,$$$$" << endl
			<< ",,,,,,,$$$$$$,,,,,,$$$$" << endl
			<< ",,,,,,,,$$$$$$$$,,,$$$$" << endl
			<< ",,,,,,,,,$$$$$$$$$$$$$$$" << endl
			<< ",,,,,,,,,,,$$$$$$$$$$$$$$$$" << endl
			<< ",,,,,,,,,,,,,,,$$$$$$$$$$$$$$$$" << endl
			<< ",,,,,,,,,,,,,,,,,,$$$$,$$$$$$$$$" << endl
			<< ",,,,,,,,,,,,,,,,,,$$$$,,,,$$$$$$$$" << endl
			<< ",,,,,,,,,,,,,,,,, $$$$,,,,,,$$$$$$$" << endl
			<< ",,,,,,,,,,,,,,,,,,$$$$,,,,,,,$$$$$$$" << endl
			<< ",,,,$$$$$$$,,,,,,,,$$$$,,,,,,,$$$$$$" << endl
			<< ",,,,,$$$$$$,,,,,,,$$$$,,,,,,,$$$$$$$" << endl
			<< ",,,,,,$$$$$$$,,,,,$$$$,,,,,,,$$$$$$$" << endl
			<< ",,,,,,,$$$$$$$$,,,$$$$,,,,,,$$$$$$$" << endl
			<< ",,,,,,,,,,$$$$$$$$$$$$$$$$$$$$$$$$" << endl
			<< ",,,,,,,,,,,,,$$$$$$$$$$$$$$$$$$$" << endl
			<< ",,,,,,,,,,,,,,,,,,$$$$$$$$" << endl;
		cout << endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	}
	else {
		cout << endl << "00000000000000000000000000000" << endl;
		cout << endl << setw(((30 - 11) / 2) + 11) << "GAME OVER!" << endl << endl
			<< setw(((30 - 27) / 2) + 27) << "Our crops are dead farmer!" << endl
			<< setw(((30 - 17) / 2) + 17) << "We are done for." << endl << endl
			<< "        .----------." << endl
			<< "       /            \\" << endl
			<< "      |              |" << endl
			<< "      |,  .-.  .-.  ,|" << endl
			<< "      | )(__/  \\__)( |" << endl
			<< "      |/     /\\     \\|" << endl
			<< "      (_     ^^     _)" << endl
			<< "       \\__|IIIIII|__/" << endl
			<< "        | \\IIIIII/ |" << endl
			<< "        \\          /" << endl
			<< "         \\--------/" << endl;
		cout << "00000000000000000000000000000" << endl;
	}
	

	return 0;
}
