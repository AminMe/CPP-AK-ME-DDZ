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
		impala->setC(c);
		return false;
	}
}

bool Action::deplacementImpala(ImpalaJones *impala)
{
	vector<Case> choix = estPossibleDeplacement(impala);
	if(choix.empty())
	{
		if(parcourir(impala->getC()->getX(),impala->getC()->getY()) == NULL)
		{
			cout<<"Aucune disponibilte"<<endl;
			return false;
		}
		else
		{
			impala->setC(*parcourir(impala->getC()->getX(),impala->getC()->getY()));
		}
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
			cout<<"Vous avez "<<choix.size()<< "possibilite pour le deplacement de Impala"<<endl;
			int resultat;
			for(int i=0;i<choix.size();i++)
			{
				cout<<i+1<<". La case i: "<<choix[i].getX()<<"j: "<<choix[i].getY();
			}

			cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala"<<endl;
			cin>>resultat;
			while(resultat>choix.size() || resultat<1)
			{
				cout<<"Veuiller choisir une variable correcte";
				for(int i=0;i<choix.size();i++)
				{
					cout<<i+1<<". La case i: "<<choix[i].getX()<<"j: "<<choix[i].getY()<<endl;
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
	int x = impala->getC()->getX();
	int y = impala->getC()->getY();
	for(int i=1;i<4;i++)
	{
		cout<<"boucle for"<<endl;
		/* Impala se situe au niveau de la premiere ligne */
		if(x==0)
		{
			cout<<"PREMIERE LIGNE"<<endl;
			if(map.getSecteur(x,y+1)==0)
			{
				cout<<"il y a bine un GROS 0"<<endl;
				cout<<"bug ici"<<endl;
				dispo = caseDisponible(false,x+1);
				cout<<"je passe pas"<<endl;
				if(dispo)
				{
					pair<int, int> index(x+1,y+1);
					possibilite.push_back(*map[index]);
				}
				x=x+1;
				y=y+1;
			}
			else
			{
				dispo = caseDisponible(true,y+1);
				if(dispo)
				{
					pair<int, int> index(x,y+1);
					possibilite.push_back(*map[index]);
				}
				y=y+1;
			}

		}
		/*Impala se sotue au niveau de la derniere colonne */
		else if(y==COLONNE-1)
		{
			cout<<"DERNIERE COLONNE"<<endl;
			if(map.getSecteur(x+1,y)==0)
			{
				dispo = caseDisponible(true,COLONNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-1,COLONNE-2);
					possibilite.push_back(*map[index]);
				}
				x = LIGNE-1;
				y = COLONNE-2;
			}
			else
			{
				 dispo = caseDisponible(false,x+1);
				 if(dispo)
				 {
					 pair<int, int> index(x+1,y);
					 possibilite.push_back(*map[index]);
				 }
				 x = x+1;

			}
		}
		/* Impala se situe au niveau de la derniere ligne */
		else if(x==LIGNE-1)
		{
			cout<<"derniere LIGNE"<<endl;
			if(map.getSecteur(x,y-1)==0)
			{
				cout<<"0 ICI"<<endl;
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-2,0);
					possibilite.push_back(*map[index]);
				}
				x = LIGNE-2;
				y = 0;
			}
			else
			{
				dispo = caseDisponible(true,y-1);
				if(dispo)
				{
					pair<int, int> index(x,y-1);
					possibilite.push_back(*map[index]);
				}
				y=y-1;
			}
		}
		/* Impala se situe au niveau de la premiere colonne */
		else if(y==0)
		{
			cout<<"PREMIERE COLONNE"<<endl;
			if(map.getSecteur(x-1,y)==0)
			{
				dispo = caseDisponible(true,1);
				if(dispo)
				{
					pair<int, int> index(0,1);
					possibilite.push_back(*map[index]);
				}
				x=0;
				y=1;
			}
			else
			{
				dispo = caseDisponible(false,x-1);
				if(dispo)
				{
					pair<int, int> index(x-1,y);
					possibilite.push_back(*map[index]);
				}
				x = x-1;
			}
		}
	}
	return possibilite;
}


bool Action::caseDisponible(bool etat,int x)
{
	cout<<"je suis ici"<<x<<endl;
	Map& map = Map::Instance();
	if(etat)
	{
		cout<<"TRUE"<<endl;
		for(int i=1;i<COLONNE-1;i++)
		{
			pair<int, int> index(i,x);
			if(!map[index]->isEstOccupe())
				return true;
		}
	}
	else
	{
		cout<<"FALSE1"<<endl;
		for(int i=1;i<LIGNE-1;i++)
		{
			pair<int, int> index(x,i);
			if(!map[index]->isEstOccupe())
				{
					cout<<"il y a une case de libre"<<endl;return true;
				}
		}
	}

	return false;
}

Case* Action::parcourir(int x, int y)
{
	/* Parcours du plateau */
	/* On sait qu'il y a au plus : 26 */
	int xBis = x;
	int yBis = y;
	Map& map = Map::Instance();
	bool dispo = false;

	for(int i=0; i<26;i++)
	{
		if(x==0)
		{
			cout<<"PREMIERE LIGNE"<<endl;
			if(map.getSecteur(x,y+1)==0)
			{

				dispo = caseDisponible(false,x+1);
				if(dispo)
				{
					pair<int, int> index(x+1,y+1);
					return map[index];
				}
				x=x+1;
				y=y+1;
			}
			else
			{
				dispo = caseDisponible(true,y+1);
				if(dispo)
				{
					pair<int, int> index(x,y+1);
					return map[index];
				}
				y=y+1;
			}

		}
				/*Impala se sotue au niveau de la derniere colonne */
		else if(y==COLONNE-1)
		{
			if(map.getSecteur(x+1,y)==0)
			{
				dispo = caseDisponible(true,COLONNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-1,COLONNE-2);
					return map[index];
				}
				x = LIGNE-1;
				y = COLONNE-2;
			}
			else
			{
				 dispo = caseDisponible(false,x+1);
				 if(dispo)
				 {
					 pair<int, int> index(x+1,y);
					 return map[index];
				 }
				 x = x+1;
			}
		}
		/* Impala se situe au niveau de la derniere ligne */
		else if(x==LIGNE-1)
		{
			cout<<"derniere LIGNE"<<endl;
			if(map.getSecteur(x,y-1)==0)
			{
				cout<<"0 ICI"<<endl;
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-2,0);
					return map[index];
				}
				x = LIGNE-2;
				y = 0;
			}
			else
			{
				dispo = caseDisponible(true,y-1);
				if(dispo)
				{
					pair<int, int> index(x,y-1);
					return map[index];
				}
				y=y-1;
			}
		}
		/* Impala se situe au niveau de la premiere colonne */
		else if(y==0)
		{
			cout<<"PREMIERE COLONNE"<<endl;
			if(map.getSecteur(x-1,y)==0)
			{
				dispo = caseDisponible(true,1);
				if(dispo)
				{
					pair<int, int> index(0,1);
					return map[index];
				}
				x=0;
				y=1;
			}
			else
			{
				dispo = caseDisponible(false,x-1);
				if(dispo)
				{
					pair<int, int> index(x-1,y);
					return map[index];
				}
				x = x-1;
			}
		}
	}
	return NULL;
}
