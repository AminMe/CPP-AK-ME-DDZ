/*
 * Personne.h
 *
 *  Created on: 20 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include "Animal.h"

using namespace std;

class Personne {
public:
	int num;
	Animal * mesAnimaux;

	Personne(int numero):num(numero), mesAnimaux(NULL){};

	int setAnimaux(Animal *animal);
	virtual ~Personne();
};

#endif /* PERSONNE_H_ */
