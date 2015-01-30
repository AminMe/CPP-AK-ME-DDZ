/*
 * Action.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_

class Animal;
class Case;
class Joueur;
class Pion;

class Action {
public:
	Action();
	virtual ~Action();

	void update();
	void controlAction(Joueur *j);
	void put(Animal * a, Case c);
	void affiche();
	void controlDeplacement(Pion * p);
};

#endif /* SRC_ACTION_H_ */
