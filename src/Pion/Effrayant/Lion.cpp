/*
 * Lion.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Lion.h"

#include <stddef.h>
#include <utility>
#include <vector>

#include "../../Jeu/Map/Case.h"
#include "../../Jeu/Map/Map.h"
#include "../Effraye/Gazelle.h"
#include "../Effraye/Zebre.h"

void Lion::check(Case position)
{
	vector<Case*> retour = checkAlentour(position,"Gazelle");
	if(retour.size()>0)
	{
		for(Case *c : retour)
		{
			Gazelle *p = dynamic_cast<Gazelle*>(c->getPionCase());
			if(p!=NULL && !p->isEstCache())
			{
				p->fuit(*c);
			}
		}
	}
	retour = checkAlentour(position,"Zebre");
	if(retour.size()>0)
	{
		for(Case *c : retour)
		{
			Zebre *p = dynamic_cast<Zebre*>(c->getPionCase());
			if(p!=NULL && !p->isEstCache())
			{
				p->setEstCache(true);
				p->setValeur(0);
			}
		}
	}
}
