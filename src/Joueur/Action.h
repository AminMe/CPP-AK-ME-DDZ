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
	/* Changement de Animal à Pion, on met case dans le deuxième caractère ? ou x et y ?  */
	// on utilisera ton [] pour récupérer la map
	void put(Pion &a, Case &c);
	void affiche();
	void controlDeplacement(Pion * p);

<<<<<<< HEAD
=======
	void controlDeplacement(Pion * p);
>>>>>>> refs/remotes/origin/master
};

#endif /* SRC_ACTION_H_ */
