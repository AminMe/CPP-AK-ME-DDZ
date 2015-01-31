/*
 * Elephant.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ELEPHANT_H_
#define SRC_ELEPHANT_H_

#include "../../Jeu/Map/Map.h"
#include "../Animal.h"

class Elephant: public Animal {
public:
	Elephant(string nom, Joueur *joueur, Map map):Animal(nom,joueur,map){}
	virtual ~Elephant(){}
};

#endif /* SRC_ELEPHANT_H_ */
