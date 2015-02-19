/*
 * Crocodile.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Crocodile.h"

#include <stddef.h>

#include "../../Jeu/Map/Case.h"
#include "../Effraye/Gazelle.h"

void Crocodile::check(Case position)
{
	cout<<" JE SUIS DANS CHECK CROCODILE "<<endl;
	cout<< " POSI X : "<<position.getX() << "POSI Y :" <<position.getY()<<endl;
	vector<Case*> retour = checkAlentour(position,"Gazelle");
	vector<Case*> tmp;
	int echange;
	int caseMap;
	if(retour.size()>0)
	{
		for(Case *c : retour)
		{
			Gazelle *p = dynamic_cast<Gazelle*>(c->getPionCase());
			bool choix = false;
			/*On regarde si il y a une presence de riviere */
			if(c->getSecteur() != position.getSecteur())
			{
				if(p!=NULL && !p->isEstCache())
				{
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
			m<<"Vous avez "<<tmp.size() <<"possibilite de switch avec la case \n";
			for(int i=0;i<tmp.size();i++)
			{
				m<<i+1<<". ligne : "<<tmp.at(i)->getX()<<" colonne : "<<tmp.at(i)->getY()<<"\n";
			}



			m<<"Voulez vous effectuer un echange ?  1 : Oui --- 2 : Non"<<endl;
			echange = Jeu::testSaisie(m.str(),1,2,"Veuillez choisir soit 1(oui) soit non (2)");


			if(echange==2)
			{
				return;
			}
			else if(echange==1)
			{
				pair<int, int> index(position.getX(),position.getY());
				if(tmp.size()==1)
				{
					Animal::switchPosition(map[index],tmp.at(0));
					map.affiche();
					cout<<"Voulez vous refaire un check pour voir d'autre possibilite   1 : Oui --- 0 : Non"<<endl;
					cin>>echange;
					if(echange==1)
					{
						Animal* anim= dynamic_cast<Animal*>(map[index]->getPionCase());
						listeAnimaux.push_back(anim);
						check(*tmp.at(0));
					}
					else if(echange==0)
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
					cout<<"Veuillez selectionner la case sur laquelle vous voullez effectuer le changement"<<endl;
					cin>>caseMap;
					Animal::switchPosition(map[index],tmp.at(caseMap));
					cout<<"Voulez vous refaire un check pour voir d'autre possibilite   1 : Oui --- 0 : Non"<<endl;
					cin>>echange;
					if(echange==1)
					{
						Animal* anim= dynamic_cast<Animal*>(map[index]->getPionCase());
						listeAnimaux.push_back(anim);
						check(*tmp.at(caseMap));
					}
					else if(echange==0)
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
