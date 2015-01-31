/*
 * Zebre.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ZEBRE_H_
#define SRC_ZEBRE_H_

#include <iostream>

#include "../../Jeu/Map/Map.h"
#include "../Animal.h"

class Zebre : public Animal{
public:
	Zebre(string nom, Joueur *joueur,Map map):Animal(nom,joueur,map){}
	virtual ~Zebre(){}
};

#endif /* SRC_ZEBRE_H_ */
