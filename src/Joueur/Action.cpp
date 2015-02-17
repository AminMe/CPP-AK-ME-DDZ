/*
 * Action.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Action.h"

#include "../Jeu/Map/Case.h"
#include "../Jeu/Map/Map.h"

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

/*bool Action::deplacementImpala(ImpalaJones *impala)
{
	bool possible = estPossibleDeplacement(impala);
	if(possible)
	{
		std::cout<< "Vous avez le choix entre la case positio"<<;
	}
	else
	{

	}
}

Case* Action::estPossibleDeplacement(ImpalaJones *impala)
{
	Map& map = Map::Instance();
	Case possibilite[3];
	bool dispo;
	for(int i=0;i<3;i++)
	{
		if(impala->getC().getX()==0 && impala->getC().getY()>0)
		{
			if(map.getSecteur(impala->getC().getX(),impala->getC().getY()+1)==0)
			{

				dispo = caseDisponible(false,impala->getC().getX()+1);
				if(dispo)
				{

					possibilite[i] = map[impala->getC().getX()+1][impala->getC().getY()>0];
				}

			}
			else
			{

				dispo = caseDisponible(true,impala->getC().getY()+1);
				if(dispo)
				{
					possibilite[i] = map[impala->getC().getX()][impala->getC().getY()+1];

				}
			}

		}
		else if(impala->getC().getY()==COLONNE-1 && impala->getC().getX()>0)
		{
			if(map.getSecteur(impala->getC().getX()+1,impala->getC().getY())==0)
			{
				dispo = caseDisponible(true,COLONNE-2);
				if(dispo)
				{
					possibilite[i] =  map[LIGNE-1][COLONNE-2];
				}
			}
			else
			{
				 dispo = caseDisponible(false,impala->getC().getX()+1);
				 if(dispo)
				 {
					 possibilite[i] =  map[impala->getC().getX()+1][impala->getC().getY()];
				 }

			}
		}
		else if(impala->getC().getX()==LIGNE-1 && impala->getC().getX()>0)
		{
			if(map.getSecteur(impala->getC().getX(),impala->getC().getY()-1)==0)
			{
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					possibilite[i] =  map[LIGNE-2][0];
				}
			}
			else
			{
				dispo = caseDisponible(false,impala->getC().getY()-1);
				if(dispo)
				{
				}
			}
		}
		else if(impala->getC().getX()>0 && impala->getC().getX()==0)
		{
			if(map.getSecteur(impala->getC().getX(),impala->getC().getY()+1)==0)
			{

			}
			else
			{

			dispo = caseDisponible(false,impala->getC().getY());
			if(dispo)
			{

			}
		}
		}
	}
}*/

/*bool Action::caseDisponible(bool etat,int x)
{
	Map& map = Map::Instance();
	if(etat)
	{
		for(int i=1;i<COLONNE-1;i++)
		{
			if(!map.getTab()[i][x].isEstOccupe())
				return true;
		}
	}
	else
	{
		for(int i=1;i<LIGNE-1;i++)
		{
			if(!map.getTab()[x][i].isEstOccupe())
				return true;
		}
	}
	return false;
}*/
