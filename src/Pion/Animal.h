#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

#include "Pion.h"

class Joueur;

using namespace std;

class Animal : Pion {
protected:
	string nom;
	int id;
	Joueur *joueur;
	bool estCache;
public:

	static int idGen;

	Animal(string nom, Joueur *joueur):nom(nom),id(idGen++),joueur(joueur), estCache(false){};

	virtual ~Animal(){};
    void setEstCache(bool etatAnimal);


};
int Animal::idGen = 0;
#endif /* ANIMAL_H_ */
