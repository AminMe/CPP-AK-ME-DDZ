#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <vector>

#include "../Jeu/Map/Case.h"
#include "Pion.h"

class Joueur;

using namespace std;
class Animal: public Pion {
private:
	static int idGen;
protected:
	int id;
	Joueur *joueur;
	bool estCache;
	int valeur;
public:

	Animal(string name, Joueur *joueur, int val) :Pion(name, -1, -1), id(idGen++),
												joueur(joueur), estCache(false), valeur(val) {
	}

	Animal(const Animal* copie):id(copie->id),joueur(copie->joueur),estCache(copie->estCache),valeur(copie->valeur){}

	virtual ~Animal() {
	}

	void setEstCache(bool etatAnimal) {
		estCache = etatAnimal;
		if(estCache)
		{
			valeur = 0;
		}
	}

	void setId(int id)
	{
		this->id = id;
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

	void setJoueur(Joueur *joueur) {
		this->joueur = joueur;
	}

	Animal& operator =(const Animal& other) // copy assignment
	{
		return *this;
	}

	vector<Case*> checkAlentour(Case position,string animalRecherche);

	static void switchPosition(Case *first,Case *second);

	virtual void check(Case position)=0;

	int getValeur() const {
		return valeur;
	}

	void setValeur(int valeur) {
		this->valeur = valeur;
	}
};

#endif /* ANIMAL_H_ */
