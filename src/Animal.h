/*
 * Animal.h
 *
 *  Created on: 20 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
#include "Personne.h"

using namespace std;


virtual class Animal {
public:
	string nom;
	static int idGen;
	int id;
	Personne personne;
	Animal(string nom, Personne personne):nom(nom), personne(personne), id(idGen++){};

	virtual ~Animal(){

	}

};
int Animal::idGen = 0;
#endif /* ANIMAL_H_ */
