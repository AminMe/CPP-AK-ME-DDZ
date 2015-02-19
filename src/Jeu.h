/*
 * Jeu.h
 *
 *  Created on: 30 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_JEU_H_
#define SRC_JEU_H_

#include <iostream>
#include <vector>

#include "Jeu/Map/Map.h"
#include "Joueur/Joueur.h"
#include "Pion/ImpalaJones.h"

using namespace std;

class Jeu {

private:
	vector<Joueur*> joueurs;

public:
	Map& map = Map::Instance();
	ImpalaJones& impala = ImpalaJones::Instance();

	Jeu(){}
	virtual ~Jeu(){}

	void init();

	bool isFinished();
	int countNbAnimalLeft();
	void addJoueur(Joueur* j) {joueurs.push_back(j);}
	vector<Joueur*>& getJoueur(){return this->joueurs;}
	bool launchGame();
	void loadXML(string name);
	static int testSaisie(string message, int min, int max, string error);
	static int menuConfiguration();
};

#endif /* SRC_JEU_H_ */
