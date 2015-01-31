/*
 * Lion.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_LION_H_
#define SRC_LION_H_

#include "../Animal.h"

class Lion : public Animal {
public:
	Lion(string nom, Joueur *joueur,Map map):Animal(nom,joueur,map){}
	virtual ~Lion(){}
};

#endif /* SRC_LION_H_ */
