/*
 * Joueur.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_JOUEUR_H_
#define SRC_JOUEUR_H_
#include "Personne.h"
#include "Animal.h"
class Joueur:Personne {
public:
	Joueur();
	virtual ~Joueur();

private:
	Animal *mesAnimaux;
};

#endif /* SRC_JOUEUR_H_ */
