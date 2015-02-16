/*
 * Lion.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_LION_H_
#define SRC_LION_H_

#include <iostream>

#include "../Animal.h"

class Lion : public Animal {
public:
	Lion(Joueur *joueur,Map map):Animal("Lion",joueur,map,1){}
	~Lion(){}

	void check(Case position);
};

#endif /* SRC_LION_H_ */
