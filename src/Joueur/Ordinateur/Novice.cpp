/*
 * Novice.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Novice.h"

#include "../../Jeu/Map/Map.h"
#include "../../Jeu.h"


void Novice::play(Jeu *jeu, int tour)
{
	if(getMesAnimaux().size()==0)
			return;
	Map& map = Map::Instance();
	jeu->getJoueur()[tour]->getAction().choixPion(jeu->getJoueur()[tour],true);
	map.gainBonus(*jeu);
	jeu->getJoueur()[tour]->getAction().deplacementImpala(true);
}

void Novice::algo()
{

}


