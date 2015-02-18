/*
 * Case.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Case.h"

#include <sstream>
#include <utility>

#include "../../Joueur/Joueur.h"
#include "../../Pion/Animal.h"
#include "../../Pion/Pion.h"
#include "Map.h"

using namespace std;

void Case::affiche()
{
	if(secteur==-1){
		cout<<"       o       ";
	}
	else if((x==0 && y==0) || (x==0 && y==COLONNE-1) || (x==LIGNE-1 && y==0) || (x==LIGNE-1 && y==COLONNE-1))
	{
		cout<<" --------> ";
	}
	else{
		cout<<"Case : "<<getX()<<","<<getY()<<" s ="<<secteur;
	}
}

string Case::getAffiche()
{
	string message = "";

	if(secteur==-1){
		/*
		 * if(impala.getCase().x = this->x ....) -> return "    o     "; else return "          ";
		 */
		return "    o     ";
	}
	else if((x==0 && y==0) || (x==0 && y==COLONNE-1) || (x==LIGNE-1 && y==0) || (x==LIGNE-1 && y==COLONNE-1))
	{
		return "    ->    ";
	}
	else
	{
		//message = "("+"a"+","+getY()+") s ="+secteur;
		ostringstream m;
		Map& map = Map::Instance();
		pair<int, int> index(getI(),getJ());

		Animal *p = dynamic_cast<Animal*>(map[index]->pionCase);
		if (p == NULL)
		{
			m<<"          ";
		}
		else
		{
			if(p->isEstCache())
			{
				m<<"   ("<<p->getJoueur()->getNum()<<","<<p->getName()[0]<<p->getName()[1]<<") #C ";
			}
			else
			{
				m<<"   ("<<p->getJoueur()->getNum()<<","<<p->getName()[0]<<p->getName()[1]<<")  ";
			}
		}

		message = m.str();
	}
	return message;
}

void Case::setTab(int position, bool valeur)
{
	tabRiviere[position] = valeur;
}

void Case::setPion(Pion *p){

	if(p!=NULL && pionCase==NULL){

		pionCase = p;

		estOccupe=true;
	}
}

Pion* Case::getPionCase() const
{
	return pionCase;
}
