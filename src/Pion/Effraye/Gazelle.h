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
	Gazelle(string nom, Joueur *joueur,Map map):Animal(nom,joueur,map){}
	virtual ~Gazelle(){}
};

#endif /* SRC_GAZELLE_H_ */
