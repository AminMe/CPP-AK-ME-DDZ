/*
 * Animal.h
 *
 *  Created on: 20 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

#include "../Joueur/Joueur.h"

using namespace std;


class Animal {
protected:
	string nom;
	int id;
	bool estCache;
	Joueur joueur;

public:

	static int idGen;

	Animal(string nom, Joueur joueur):nom(nom), joueur(joueur), id(idGen++), estCache(false){};
	void setEstCache(bool etatAnimal);
	virtual ~Animal(){

	}

};
int Animal::idGen = 0;
#endif /* ANIMAL_H_ */
