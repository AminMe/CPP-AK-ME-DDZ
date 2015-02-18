/*
 * Action.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Action.h"

#include <sys/_types/_null.h>
#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <utility>

#include "../Jeu/Map/Map.h"
#include "../Pion/Animal.h"
#include "../Pion/Pion.h"
#include "Joueur.h"


bool Action::put(Pion *a, Case* c)
{
   c->setPion(a);
   return true;
}


bool Action::choixPion(Joueur * j)
{
	int resultat;
	j->affiche();
	Map& map = Map::Instance();
	cout<<"Veuillez choisir l'animal que vous voulez placer sur la map"<<endl;

	for(int i=0; i<j->getMesAnimaux().size();i++)
	{
		cout<<i<<". "<<j->getMesAnimaux().at(i)->getName()<<endl;
	}
	cin>>resultat;

	while(resultat>j->getMesAnimaux().size() || resultat<0)
	{
		cout<<"Veuiller choisir un numero correct"<<endl;
		for(int i=0; i<j->getMesAnimaux().size();i++)
		{
			cout<<i<<". "<<j->getMesAnimaux().at(i)->getName()<<endl;
		}
	}

	vector<Case*> possibilite = map.proposeCases(impala.getC());
	cout<<"Les differentes possibilite de placement du pion sont :"<<endl;

	int i=0;
	int resultat2;
	for(Case* c : possibilite)
	{
		cout<<i<<". "<< " ligne : "<< c->getX()<< " colonne : "<< c->getY()<<endl;
		i++;
	}
	cout<<"Selectionner la case "<<endl;
	cin>>resultat2;
	while(resultat2>possibilite.size() || resultat2<0)
	{
		cout<<"Veuiller selectionner un numero correspondant au proposition"<<endl;
		int i=0;
		for(Case* c : possibilite)
		{
			cout<<i<<". "<< " ligne : "<< c->getX()<< " colonne : "<< c->getY()<<endl;
			i++;
		}
		cout<<"Selectionner la case "<<endl;
		cin>>resultat2;
	}
	int idChoix = j->getMesAnimaux().at(resultat)->getId();
	vector<Animal*>::iterator it = j->getMesAnimaux().begin();

	for(int iterateur=0;iterateur<j->getMesAnimaux().size();iterateur++)
	{

		if(j->getMesAnimaux()[iterateur]->getId() == idChoix)
		{

			put(j->getMesAnimaux().at(resultat), possibilite[resultat2]);
			j->getMesAnimaux().erase(it+iterateur);
			iterateur=j->getMesAnimaux().size();
		}
	}
	return true;
}


bool Action::deplacementImpalaPremiereFois()
{
	Map& map = Map::Instance();

	int x,y;
	cout<<"Joueur 1 => choisisez une case pour poser impala"<<endl;
	cout<<"Ligne :"<<endl;
	cin >>x;
	cout<<"Colonne :"<<endl;
	cin >>y;
	pair<int, int> index(x,y);
	Case * c = map[index];
	if(c->getSecteur()==-1)
	{
		impala.setC(c);
		c->setPion(&impala);
		return true;
	}
	else
	{
		while(c->getSecteur()!=-1)
		{
			cout<<" Veuillez positionner impala sur une bonne case"<<endl;
			cout<< "Veuillez saisir la ligne : "<<endl;
			cin >>x;
			cout<<"Veuillez saisir la colonne : "<<endl;
			cin>>y;
			pair<int, int> index(x,y);
			c=map[index];
		}
		impala.setC(c);
		c->setPion(&impala);
		return false;
	}
}

bool Action::deplacementImpala()
{
	vector<Case*> choix = estPossibleDeplacement();
	if(choix.empty())
	{
		if(parcourir(impala.getC()->getX(),impala.getC()->getY()) == NULL)
		{
			cout<<"Aucune disponibilte"<<endl;
			return false;
		}
		else
		{
			Case * caseImp = parcourir(impala.getC()->getX(),impala.getC()->getY());
			impala.setC(caseImp);
			caseImp->setPion(&impala);
			return true;
		}
	}
	else
	{
		if(choix.size()==1)
		{
			cout<<"Il n'y a qu'une seule possibilite, Impala est placer automatiquement, c'est le tour du joueur suivant";
			impala.setC(choix[0]);
			choix[0]->setPion(&impala);
			return true;
		}
		else
		{
			cout<<"Vous avez "<<choix.size()<< "possibilite pour le deplacement de Impala"<<endl;
			int resultat;
			for(int i=0;i<choix.size();i++)
			{
				cout<<i+1<<". La case i: "<<choix[i]->getX()<<"j: "<<choix[i]->getY()<<endl;
			}

			cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala"<<endl;
			cin>>resultat;
			while(resultat>choix.size() || resultat<1)
			{
				cout<<"Veuiller choisir une variable correcte";
				for(int i=0;i<choix.size();i++)
				{
					cout<<i+1<<". La case i: "<<choix[i]->getX()<<"j: "<<choix[i]->getY()<<endl;
				}
				cin>>resultat;
			}
			impala.getC()->setPion(NULL);
			impala.setC(choix[resultat-1]);
			choix[resultat-1]->setPion(&impala);

			return true;
		}
	}
}
vector<Case*> Action::estPossibleDeplacement()
{
	Map& map = Map::Instance();
	vector<Case*> possibilite;
	bool dispo;
	int x = impala.getC()->getX();
	int y = impala.getC()->getY();
	for(int i=1;i<4;i++)
	{
		/* Impala se situe au niveau de la premiere ligne */
		if(x==0)
		{
			if(map.getSecteur(x,y+1)==0)
			{
				dispo = caseDisponible(false,x+1);
				if(dispo)
				{
					pair<int, int> index(x+1,y+1);
					possibilite.push_back(map[index]);
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
					possibilite.push_back(map[index]);
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
					possibilite.push_back(map[index]);
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
					 possibilite.push_back(map[index]);
				 }
				 x = x+1;

			}
		}
		/* Impala se situe au niveau de la derniere ligne */
		else if(x==LIGNE-1)
		{
			if(map.getSecteur(x,y-1)==0)
			{
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-2,0);
					possibilite.push_back(map[index]);
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
					possibilite.push_back(map[index]);
				}
				y=y-1;
			}
		}
		/* Impala se situe au niveau de la premiere colonne */
		else if(y==0)
		{
			if(map.getSecteur(x-1,y)==0)
			{
				dispo = caseDisponible(true,1);
				if(dispo)
				{
					pair<int, int> index(0,1);
					possibilite.push_back(map[index]);
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
					possibilite.push_back(map[index]);
				}
				x = x-1;
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
		for(int i=1;i<LIGNE-1;i++)
		{
			pair<int, int> index(x,i);
			if(!map[index]->isEstOccupe())
			{
				return true;
			}
		}
	}

	return false;
}

Case* Action::parcourir(int x, int y)
{
	/* Parcours du plateau */
	/* On sait qu'il y a au plus : 26 */

	Map& map = Map::Instance();
	bool dispo = false;

	for(int i=0; i<26;i++)
	{
		if(x==0)
		{
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
			if(map.getSecteur(x,y-1)==0)
			{
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
