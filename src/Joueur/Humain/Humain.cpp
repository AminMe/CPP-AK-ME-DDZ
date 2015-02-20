/*
 * Humain.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Humain.h"

#include "../../Jeu/Map/Map.h"
#include "../../Jeu.h"

void Humain::play(Jeu *jeu, int tour)
{
	if(getMesAnimaux().size()==0)
		return;
	Map& map = Map::Instance();
	jeu->getJoueur()[tour]->getAction().choixPion(jeu->getJoueur()[tour],false);
	map.gainBonus(*jeu);
	map.affiche();
	jeu->getJoueur()[tour]->getAction().deplacementImpala(false);
	map.affiche();
}
