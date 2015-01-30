/*
 * Ordinateur.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ORDINATEUR_H_
#define SRC_ORDINATEUR_H_

#include "../Joueur.h"

class Ordinateur:Joueur {
public:
	Ordinateur(int num, string name, Animal *mesAnimaux):Joueur(num,name,mesAnimaux){}
	virtual ~Ordinateur(){}
};

#endif /* SRC_ORDINATEUR_H_ */
