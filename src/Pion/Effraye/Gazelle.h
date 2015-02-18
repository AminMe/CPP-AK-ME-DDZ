/*
 * Gazelle.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_GAZELLE_H_
#define SRC_GAZELLE_H_

#include "../Animal.h"

class Gazelle : public Animal {
public:
	Gazelle(Joueur *joueur):Animal("Gazelle",joueur,2){}
	~Gazelle(){}
	void fuit();
	void check(Case position);
};

#endif /* SRC_GAZELLE_H_ */
