/*
 * Crocodile.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_CROCODILE_H_
#define SRC_CROCODILE_H_

#include <iostream>

#include "../Animal.h"

class Crocodile : public Animal {
public:
	Crocodile(Joueur *joueur,Map map):Animal("Crocodile",joueur,map,0){}
	~Crocodile(){}
};

#endif /* SRC_CROCODILE_H_ */
