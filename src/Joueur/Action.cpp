/*
 * Action.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Action.h"



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

bool Action::deplacementImpalaPremiereFois(ImpalaJones *impala,Case c)
{
	Map& map = Map::Instance();
	if(c.getSecteur()==-1)
	{
		impala->setC(c);
		return true;
	}
	else
	{
		int x,y;

		while(c.getSecteur()!=-1)
		{
			cout<<" Veuillez positionner impala sur une bonne case"<<endl;
			cout<< "Veuillez saisir la ligne : "<<endl;
			cin >>x;
			cout<<"Veuillez saisir la colonne : "<<endl;
			cin>>y;
			pair<int, int> index(x,y);
			c=*map[index];
		}
		return false;
	}
}

bool Action::deplacementImpala(ImpalaJones *impala)
{
	vector<Case> choix = estPossibleDeplacement(impala);
	if(choix.empty())
	{
		/* AUTOMATIQUE */
	}
	else
	{
		if(choix.size()==1)
		{
			cout<<"Il n'y a qu'une seule possibilite, Impala est placer automatiquement, c'est le tour du joueur suivant";
			impala->setC(choix[0]);
		}
		else
		{
			cout<<"Vous avez "<<choix.size()<< "possibilite pour le deplacement de Impala";
			int resultat;
			for(int i=0;i<choix.size();i++)
			{
				cout<<i+1<<". La case i: "<<choix[i].getX()<<"j: "<<choix[i].getY();
			}

			cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala";
			cin>>resultat;
			while(resultat>choix.size() || resultat<1)
			{
				cout<<"Veuiller choisir une variable correcte";
				for(int i=0;i<choix.size();i++)
				{
					cout<<i+1<<". La case i: "<<choix[i].getX()<<"j: "<<choix[i].getY();
				}
				cin>>resultat;
			}
			impala->setC(choix[resultat-1]);
		}
	}
}
vector<Case> Action::estPossibleDeplacement(ImpalaJones *impala)
{
	Map& map = Map::Instance();
	vector<Case> possibilite;
	bool dispo;
	for(int i=0;i<3;i++)
	{
		/* Impala se situe au niveau de la premiere ligne */
		if(impala->getC().getX()==0 && impala->getC().getY()>0)
		{
			if(map.getSecteur(impala->getC().getX(),impala->getC().getY()+1)==0)
			{
				dispo = caseDisponible(false,impala->getC().getX()+1);
				if(dispo)
				{
					pair<int, int> index(impala->getC().getX()+1,impala->getC().getY());
					possibilite.push_back(*map[index]);
				}
			}
			else
			{
				dispo = caseDisponible(true,impala->getC().getY()+1);
				if(dispo)
				{
					pair<int, int> index(impala->getC().getX(),impala->getC().getY()+1);
					possibilite.push_back(*map[index]);
				}
			}

		}
		/*Impala se sotue au niveau de la derniere colonne */
		else if(impala->getC().getY()==COLONNE-1 && impala->getC().getX()>0)
		{
			if(map.getSecteur(impala->getC().getX()+1,impala->getC().getY())==0)
			{
				dispo = caseDisponible(true,COLONNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-1,COLONNE-2);
					possibilite.push_back(*map[index]);
				}
			}
			else
			{
				 dispo = caseDisponible(false,impala->getC().getX()+1);
				 if(dispo)
				 {
					 pair<int, int> index(impala->getC().getX()+1,impala->getC().getY());
					 possibilite.push_back(*map[index]);
				 }

			}
		}
		/* Impala se situe au niveau de la derniere ligne */
		else if(impala->getC().getX()==LIGNE-1 && impala->getC().getX()>0)
		{
			if(map.getSecteur(impala->getC().getX(),impala->getC().getY()-1)==0)
			{
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-2,0);
					possibilite.push_back(*map[index]);
				}
			}
			else
			{
				dispo = caseDisponible(true,impala->getC().getY()-1);
				if(dispo)
				{
					pair<int, int> index(impala->getC().getX(),impala->getC().getY()-1);
					possibilite.push_back(*map[index]);
				}
			}
		}
		/* Impala se situe au niveau de la premiere colonne */
		else if(impala->getC().getX()>0 && impala->getC().getY()==0)
		{
			if(map.getSecteur(impala->getC().getX()-1,impala->getC().getY())==0)
			{
				dispo = caseDisponible(true,1);
				if(dispo)
				{
					pair<int, int> index(0,1);
					possibilite.push_back(*map[index]);
				}
			}
			else
			{
				dispo = caseDisponible(false,impala->getC().getX()-1);
				if(dispo)
				{
					pair<int, int> index(impala->getC().getX()-1,impala->getC().getY());
					possibilite.push_back(*map[index]);
				}
			}
		}
	}
	return possibilite;
}


bool Action::caseDisponible(bool etat,int x)
{
	Map& map = Map::Instance();
	if(etat)
	{
		for(int i=1;i<COLONNE-1;i++)
		{
			pair<int, int> index(i,x);
			if(!map[index]->isEstOccupe())
				return true;
		}
	}
	else
	{
		for(int i=1;i<LIGNE-1;i++)
		{
			pair<int, int> index(x,i);
			if(!map[index]->isEstOccupe())
				return true;
		}
	}
	return false;
}
