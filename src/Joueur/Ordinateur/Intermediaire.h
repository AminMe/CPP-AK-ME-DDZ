/*
 * Intermediaire.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_INTERMEDIAIRE_H_
#define SRC_INTERMEDIAIRE_H_

#include "Ordinateur.h"

class Intermediaire: public Ordinateur{
public:
	Intermediaire(int num, string name):Ordinateur(num,name){}
	~Intermediaire(){};

	void play(Jeu *jeu, int tour);

	void algo();
};

#endif /* SRC_INTERMEDIAIRE_H_ */
