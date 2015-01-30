/*
 * Intermediaire.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_INTERMEDIAIRE_H_
#define SRC_INTERMEDIAIRE_H_

#include "Ordinateur.h"

class Intermediaire: Ordinateur{
public:
	Intermediaire(int num, string name, Animal *mesAnimaux):Ordinateur(num,name,mesAnimaux){}
	virtual ~Intermediaire();
};

#endif /* SRC_INTERMEDIAIRE_H_ */
