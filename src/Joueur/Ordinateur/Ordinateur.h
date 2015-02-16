/*
 * Ordinateur.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ORDINATEUR_H_
#define SRC_ORDINATEUR_H_

#include <iostream>

#include "../Joueur.h"


using namespace std;

class Ordinateur: public Joueur {

public:
	Ordinateur(int num, string name):Joueur(num,name){}
	virtual ~Ordinateur(){};

	virtual void algo()=0;

	virtual void play()=0;
};

#endif /* SRC_ORDINATEUR_H_ */
