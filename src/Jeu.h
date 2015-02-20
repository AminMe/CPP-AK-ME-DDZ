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
	int tour;
	Map& map;
	ImpalaJones& impala;
public:


	Jeu():tour(1),map(Map::Instance()),impala(ImpalaJones::Instance()){}
	virtual ~Jeu(){}


	void addJoueur(Joueur* j) {joueurs.push_back(j);}
	vector<Joueur*>& getJoueur(){return this->joueurs;}
	bool launchGame();
	static int testSaisie(string message, int min, int max, string error);
	static int menuConfiguration();

	int getTour() const {
		return tour;
	}

	void setTour(int tour) {
		this->tour = tour;
	}
};

#endif /* SRC_JEU_H_ */
