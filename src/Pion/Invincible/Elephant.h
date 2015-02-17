/*
 * Elephant.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ELEPHANT_H_
#define SRC_ELEPHANT_H_

#include "../Animal.h"

class Elephant: public Animal {
public:
	Elephant(Joueur *joueur):Animal("Elephant",joueur,5){}
	~Elephant(){}
	void check(Case position);
};

#endif /* SRC_ELEPHANT_H_ */
