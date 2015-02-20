/*
 * Crocodile.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Crocodile.h"

#include <stddef.h>
#include <sstream>

#include "../../Jeu/Map/Case.h"
#include "../../Jeu.h"
#include "../Effraye/Gazelle.h"

void Crocodile::check(Case position)
{
	vector<Case*> retour = checkAlentour(position,"Gazelle");
	vector<Case*> tmp;
	int echange;
	int caseMap;
	cout<<"je suis dans le check "<<endl;

	if(this->joueur->isEstRobot())
	{
		return;
	}

	if(retour.size()>0)
	{

		for(Case *c : retour)
		{
			Gazelle *p = dynamic_cast<Gazelle*>(c->getPionCase());
			/*On regarde si il y a une presence de riviere */
			if(c->getSecteur() != position.getSecteur())
			{
				if(p!=NULL && !p->isEstCache())
				{
					/* on ajoute au niveau du vector temporaire les cases qui nous interessent vraiment */
					tmp.push_back(c);
				}
			}
		}

		if(!tmp.empty())
		{
			Map& map = Map::Instance();
			map.affiche();
			ostringstream m;
			int echange;
			m<<"Vous avez "<<tmp.size() <<" possibilite de switch avec la case \n";
			for(int i=0;i<tmp.size();i++)
			{
				m<<i+1<<". ligne : "<<tmp.at(i)->getX()<<" colonne : "<<tmp.at(i)->getY()<<"\n";
			}
			m<<"Voulez vous effectuer un echange ?  1 : Oui --- 2 : Non\n";
			echange = Jeu::testSaisie(m.str(),1,2,"Veuillez choisir soit 1(oui) soit non (2)\n");

			if(echange==2)
			{
				return;
			}
			else if(echange==1)
			{
				pair<int, int> index(position.getX(),position.getY());
				/* Il n'y a qu'une seule possibilite */
				if(tmp.size()==1)
				{
					cout<<"Il n'y a qu'une seule possibilite, l'echange se fait tout seul \n";
					Animal::switchPosition(map[index],tmp.at(0));
					map.affiche();
					echange = Jeu::testSaisie("Voulez vous refaire un check pour voir d'autre possibilite   1 : Oui --- 2 : Non\n",
							1,2,"Veuillez choisir soit 1(oui) soit non (2)\n");
					if(echange==1)
					{
						Animal* anim= dynamic_cast<Animal*>(map[index]->getPionCase());
						listeAnimaux.push_back(anim);
						check(*tmp.at(0));
					}
					else if(echange==2)
					{

						for(int i=0;i<listeAnimaux.size();i++)
						{
							if(listeAnimaux.at(i)!=NULL)
							{
								if(listeAnimaux.at(i)->getName()=="Gazelle")
								{
									listeAnimaux.at(i)->check(listeAnimaux.at(i)->getC());
								}
							}
						}
						listeAnimaux.clear();
						return;
					}
				}
				else
				{
					/* Plusieurs possibilite */
					ostringstream m1;
					m1<<"Vous avez "<<tmp.size() <<" possibilite de switch avec la case \n";
					for(int i=0;i<tmp.size();i++)
					{
						m1<<i+1<<". ligne : "<<tmp.at(i)->getX()<<" colonne : "<<tmp.at(i)->getY()<<"\n";
					}

					m1<<"Veuillez selectionner la case sur laquelle vous voullez effectuer le changement";
					caseMap = Jeu::testSaisie(m1.str(),1,tmp.size(),"Veuillez choisir un nombre correcte\n");


					Animal::switchPosition(map[index],tmp.at(caseMap-1));
					echange = Jeu::testSaisie("Voulez vous refaire un check pour voir d'autre possibilite   1 : Oui --- 2 : Non\n",1,2,"Veuillez choisir soit 1(oui) soit non (2)\n");
					if(echange==1)
					{
						Animal* anim= dynamic_cast<Animal*>(map[index]->getPionCase());
						listeAnimaux.push_back(anim);
						check(*tmp.at(caseMap-1));
					}
					else if(echange==2)
					{
						for(int i=0;i<listeAnimaux.size();i++)
						{
							if(listeAnimaux.at(i)!=NULL)
							{
								if(listeAnimaux.at(i)->getName()=="Gazelle")
								{
									listeAnimaux.at(i)->check(listeAnimaux.at(i)->getC());
								}
							}
						}
						listeAnimaux.clear();
						return;
					}
				}

			}
		}
	}
}
