/*
 * Gazelle.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Gazelle.h"

#include "../../Jeu/Map/Case.h"
#include "../../Joueur/Joueur.h"


void Gazelle::check(Case position)
{
	if(checkAlentour(position,"Lion").size()>0)
	{
		estCache = true;
		return;
	}
}

void Gazelle::fuit()
{
	/*joueur->getMesAnimaux().push_back(this);*/
	joueur->getMesAnimaux().push_back(this);
}
