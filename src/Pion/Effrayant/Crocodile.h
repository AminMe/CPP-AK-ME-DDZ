/*
 * Crocodile.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_CROCODILE_H_
#define SRC_CROCODILE_H_

#include "../Animal.h"

class Crocodile : public Animal {
public:
	Crocodile(string nom, Joueur *joueur,Map map):Animal(nom,joueur,map){}
	virtual ~Crocodile(){}
};

#endif /* SRC_CROCODILE_H_ */
