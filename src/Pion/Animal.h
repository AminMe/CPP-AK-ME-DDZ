#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

#include "Pion.h"

class Joueur;

using namespace std;

class Animal : public Pion {
protected:
	int id;
	Joueur *joueur;
	bool estCache;
public:

	static int idGen;

	Animal(string name, Joueur *joueur, Map map):Pion(name,-1,-1,map),id(idGen++),joueur(joueur), estCache(false){}

	virtual ~Animal(){}

	void setEstCache(bool etatAnimal){
    	estCache = etatAnimal;
    }

	bool isEstCache() const {
		return estCache;
	}

	int getId() const {
		return id;
	}

	Joueur* getJoueur() const {
		return joueur;
	}
};
int Animal::idGen = 0;
#endif /* ANIMAL_H_ */
