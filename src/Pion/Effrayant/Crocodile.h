/*
 * Crocodile.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_CROCODILE_H_
#define SRC_CROCODILE_H_

#include <iostream>
#include <vector>
#include "../Animal.h"


class Crocodile : public Animal {
public:
	vector<Animal*> listeAnimaux;
	Crocodile(Joueur *joueur):Animal("Crocodile",joueur,0){}
	~Crocodile(){}

	void check(Case position);
};

#endif /* SRC_CROCODILE_H_ */
