/*
 * Zebre.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Zebre.h"

void Zebre::check(Case position)
{
	if(checkAlentour(position,"Lion").size()>0)
	{
		this->estCache = true;
		this->valeur=0;/*Le zebre ne rapporte plus de pion s'il est caché*/
		return;
	}

}
