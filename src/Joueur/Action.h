/*
 * Action.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_
#include "../Joueur/Joueur.h"
#include "../Jeu/Map/Case.h"
#include "../Pion/Animal.h"
#include "../Pion/Pion.h"
class Action {
public:
	Action();
	virtual ~Action();

	void update();
	void controlAction(Joueur j);
	void put(Animal a, Case c);
	void affiche();
	void controlDeplacement(Pion p);
};

#endif /* SRC_ACTION_H_ */
