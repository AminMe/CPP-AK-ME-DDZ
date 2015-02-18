/*
 * Crocodile.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Crocodile.h"

#include <stddef.h>
#include <vector>

#include "../../Jeu/Map/Case.h"
#include "../Effraye/Gazelle.h"

void Crocodile::check(Case position)
{
	vector<Case*> retour = checkAlentour(position,"Gazelle");

	if(retour.size()>0)
	{
		for(Case *c : retour)
		{
			Gazelle *p = dynamic_cast<Gazelle*>(c->getPionCase());
			bool choix = false;
			if(p!=NULL && !p->estCache)
			{
				cout<<"Souhaitez vous changez la position entre : ";
				cin>>choix;
			}
			if(choix)
			{
				Animal::switchPosition(this,p);
			}

		}
	}
}
