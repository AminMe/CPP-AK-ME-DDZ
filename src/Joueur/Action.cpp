/*
 * Action.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Action.h"

#include "../Jeu/Map/Case.h"

Action::Action() {
	// TODO Auto-generated constructor stub

}

Action::~Action() {
	// TODO Auto-generated destructor stub

}

bool Action::put(Pion *a, Case c, Case impala)
{
	if(!c.isEstOccupe())
	{
	   if(impala.getX()>0 && c.getX()==impala.getX())
	   {
		   c.setPion(a);
		   return true;
	   }
	   else if(impala.getY()>0  && c.getY()==impala.getY())
	   {
		   c.setPion(a);
		   return true;
	   }
	}

	return false;
}
