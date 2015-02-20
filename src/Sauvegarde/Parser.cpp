/*
 * XML.cpp
 *
 *  Created on: 18 févr. 2015
 *      Author: Amin
 */

#include "Parser.h"

#include <fstream>
#include <string>
#include <utility>

#include "../Jeu/Map/Case.h"
#include "../Jeu/Map/Map.h"
#include "../Jeu.h"
#include "../Joueur/Joueur.h"
#include "../Joueur/Humain/Humain.h"
#include "../Joueur/Ordinateur/Intermediaire.h"
#include "../Joueur/Ordinateur/Novice.h"
#include "../Pion/Animal.h"
#include "../Pion/Effraye/Zebre.h"
#include "../Pion/Effraye/Gazelle.h"
#include "../Pion/Effrayant/Crocodile.h"
#include "../Pion/Effrayant/Lion.h"
#include "../Pion/Invincible/Elephant.h"



#include "../Pion/ImpalaJones.h"
#include "../Pion/Pion.h"

#include <sstream>

using namespace std;

#define DELIM_L_ANIMAUX_D "DEBUT_LISTE_ANIMAUX"
#define DELIM_L_ANIMAUX_F "FIN_LISTE_ANIMAUX"

#define DELIM_JOUEUR_D "DEBUT"
#define DELIM_JOUEUR_F "FIN"

#define DELIM_ANIMAL_D "DEBUT_ANIMAL"
#define DELIM_ANIMAL_F "FIN_ANIMAL"

#define DELIM_TOUR_D "DEBUT_TOUR"
#define DELIM_TOUR_F "FIN_TOUR"

#define J_HUMAIN 1
#define J_NOVICE 2
#define J_INTERMEDIAIRE 3

void Parser::parse(Jeu *jeu)
{
	cout<<"Ouverture du fichier"<<endl;
	fstream fp(name, fstream::out | fstream::in );

	if(!fp.is_open())
	{
		fp.open("../sauvegarde.txt", fstream::out | fstream::in);
		if(!fp.is_open())
		{
			cout<<"Le fichier que vous tentez de charger est inexistant"<<endl;
			cout<<"Veuillez redemarrer le jeu"<<endl;
			return;
		}
	}

	string line = "";

	bool initCase = false;
	bool initJoueur = false;
	bool initAnimal = false;

	Joueur *jcourant = NULL;
	Animal *acourant = NULL;
	Case *ccourant = NULL;

	/*
	 * LOAD DE ANIMAL
	 */
	string nameA = "";
	string idA = "";
	string estCache = "";
	string valA = "0";

	/*
	 * LOAD DE JOUEUR
	 */
	string nameJ = "";
	string id = "-1";
	string categorie = "-1";
	string bonus = "0";
	string x,y;

	string pion = "";

	bool tourTrouve = false;

	string hashtag = "";
	int cpt = 0;
	if(fp.is_open())
	{
		while(fp>>line)
		{
				/*
				 * RESET
				 */
			if(!initCase)
			{
				/**/
				ccourant = new Case(0,0,0);
			}
			if(!initJoueur)
			{
				/**/
				jcourant = new Humain(-1,"ErreurJ");

			}
			if(!initAnimal)
			{
				acourant = new Crocodile(jcourant);
			}

			if(tourTrouve)
			{
				jeu->setTour(atoi(line.c_str()));
				tourTrouve = false;
			}

			if(line[0]=='|')
			{
				initCase = true;
				stringstream linestream(line);
				string data;
				getline(linestream, data, '|');  // read up-to the first tab (discard t
				string car1, car2, car3, car4;
				linestream>>car1;

				string position = car1;

				std::string delimiter = "|";
				size_t pos = 0;
				std::string token;
				while ((pos = position.find(delimiter)) != std::string::npos) {
					token = position.substr(0, pos);
					x = token;
					position.erase(0, pos + delimiter.length());
				}
				y = position;

				/*
				 *
				 * - Le secteur ainsi que le nom du pion et #NC ne sera connu qu'apres -
				 *
				 * |0|0 0 NULL #NC
				 * Conversion de string=>int
				 *
				 * new Case(0,0,0,NULL) => #NC inutile dans ce cas
				 *
				 * |1|7 -1 Impala Jones #I
				 *
				 * new Case(1,7,-1,NULL)
				 * impala.setCase(nouvelle)
				 * nouvelle.setPion(impala)
				 *
				 * |2|6 4 Gazelle #NC 2
				 *
				 * pareille sauf qu'ici on va faire gazelle.setJoueur(getJoueur(2,jeu))
				 * et faut push_back dans la liste animaux la gazelle
				 */
			}
			else if(line[0]=='#')
			{
				cpt = 0;
				ccourant = new Case();
				hashtag = line;
				initCase = false;
			}
			else if(line==DELIM_JOUEUR_D)
			{
				cpt = -1;
				/*
				 * Creation d'un joueur
				 */
				initJoueur = true;
			}
			else if(line==DELIM_JOUEUR_F)
			{
				/*
				 * Fin de la creation du joueur courant
				 */

				initJoueur = false;
				initAnimal = false;
			}
			else if(line==DELIM_ANIMAL_D)
			{
				cpt = -1;
				/*
				 * Creation d'un animal => ajout a la liste du joueur courant
				 */
				initAnimal = true;
			}
			else if(line==DELIM_ANIMAL_F)
			{
				/*
				 * Fin de la creation de l'animal
				 */

				if(nameA=="Gazelle")
				{
					acourant = new Gazelle(jcourant);
				}
				else if(nameA== "Zebre")
				{
					acourant = new Zebre(jcourant);
				}
				else if(nameA== "Elephant")
				{
					acourant = new Elephant(jcourant);
				}
				else if(nameA== "Lion")
				{
					acourant = new Lion(jcourant);
				}
				else if(nameA== "Crocodile")
				{
					acourant = new Crocodile(jcourant);
				}
				else{
					acourant = NULL;
					//cout<<"Animal : "<<nameA<<" non reconnu dans le parser"<<endl;
				}

				if(acourant!=NULL)
				{
					acourant->setValeur(atoi(valA.c_str()));
					acourant->setId(atoi(idA.c_str()));
					Animal* copie(acourant);
					jcourant->getMesAnimaux().push_back(copie);
				}

				initAnimal = false;
			}
			else if(line==DELIM_TOUR_D)
			{
				tourTrouve = true;
			}
			/*Ajout de ce else if*/
			else if(line==DELIM_TOUR_F)
			{
				tourTrouve = false;
			}
			else if(line!=DELIM_L_ANIMAUX_F)
			{

				if(initJoueur)
				{

					if(initJoueur && !initAnimal)
					{

						/*
						 * On init le joueur
						 */
						// ID
						if(cpt==0)
						{
							cout<<"ID joueur ____ "<<line<<endl;
							id = line;
						}
						//Nom
						else if(cpt==1)
						{
							nameJ = line;
							cout<<"Nom joueur ____ "<<nameJ<<endl;
						}
						//Bonus
						else if(cpt==2)
						{
							bonus = line;
							cout<<"Bonus joueur ____ "<<bonus<<endl;
						}
						//Categorie
						else if(cpt==3)
						{
							categorie = line;
							int cat = atoi(categorie.c_str());
							switch(cat)
							{
							case J_HUMAIN:
								jcourant = new Humain(atoi(id.c_str()),nameJ);
								break;
							case J_INTERMEDIAIRE:
								jcourant = new Intermediaire(atoi(id.c_str()),nameJ);
								break;
							case J_NOVICE:
								jcourant = new Novice(atoi(id.c_str()),nameJ);
								break;
							default:
								jcourant = new Humain(atoi(id.c_str()),nameJ);
							}
							if(jcourant!=NULL)
							{
								jcourant->setBonus(atoi(bonus.c_str()));
								jcourant->getMesAnimaux().clear();
								Joueur *copie(jcourant);
								jeu->addJoueur(copie);
							}
						}
					}
					else if(initAnimal)
					{
						//ID
						if(cpt==0)
						{
							idA = line;
						}
						//Nom
						else if(cpt==1)
						{
							nameA = line;
						}
						//EstCache ?
						else if(cpt==2)
						{
							estCache = line;
						}
						//Valeur
						else if(cpt==3)
						{
							valA = line;
							//cpt = 0;
						}

					}
				}
				else if(initCase)
				{
					pion = line;

				}
				else
				{

					if(hashtag!="")
					{
						initCase = false;
						pair<int, int> index(atoi(x.c_str()),atoi(y.c_str()));


						if(pion!="")
						{

							if(pion=="ImpalaJones")
							{
								ImpalaJones& impala = ImpalaJones::Instance();
								impala.setC(map[index]);
								map[index]->setPion(&impala);
							}
							else
							{
								//------- /!!!!\ ici c'est -1 car si on a id = 1 => correspond au joueur 0
								//Joueur* jo = jeu->getJoueur()[atoi(line.c_str())-1];


								if(pion=="Gazelle")
								{
									map[index]->setPion(new Gazelle(jeu->getJoueur()[atoi(line.c_str())-1]));
								}
								else if(pion== "Zebre")
								{
									map[index]->setPion(new Zebre(jeu->getJoueur()[atoi(line.c_str())-1]));
								}
								else if(pion== "Elephant")
								{
									map[index]->setPion(new Elephant(jeu->getJoueur()[atoi(line.c_str())-1]));
								}
								else if(pion== "Lion")
								{
									map[index]->setPion(new Lion(jeu->getJoueur()[atoi(line.c_str())-1]));
								}
								else if(pion== "Crocodile")
								{
									map[index]->setPion(new Crocodile(jeu->getJoueur()[atoi(line.c_str())-1]));
								}
								Pion* pion = map[index]->getPionCase();
								if(pion!=NULL)
								{
									Animal *surCarte = dynamic_cast<Animal*>(pion);
									if(surCarte==NULL)
									{
										return;
									}
									if(hashtag=="#NC")
									{
										surCarte->setEstCache(false);
										/*
										 *
										 * SWITCH
										 * seVal
										 */
									}
									else if(hashtag=="#C")
									{
										surCarte->setEstCache(true);
										surCarte->setValeur(0);
									}
								}
							}
						}

					}
				}
			}
			cpt++;
		}
	}

	map.affiche();

	for(Joueur*nouv : jeu->getJoueur())
	{
		cout<<"Chargement du joueur :";
		nouv->affiche();
		cout<<endl;
	}
	fp.close();
}

void Parser::save(Jeu jeu)
{
	cout<<"Creation du fichier"<<endl;
	fstream fp(name, fstream::out | fstream::in | fstream::trunc );

	saveJ(jeu.getJoueur(),&fp);
	saveM(&fp);

	fp<<DELIM_TOUR_D<<endl;
	fp<<jeu.getTour()<<endl;
	fp<<DELIM_TOUR_F<<endl;

	fp.close();

}
/*
 * Pour sauvegarder seulement la map
 */
void Parser::saveM(fstream *fp)
{
	Map &map = Map::Instance();


	for(int i = 0;i<LIGNE;i++)
	{
		for(int j = 0; j<COLONNE; j++)
		{
			pair<int, int> index(i,j);
			/*
			 * Sauvegarde sous le format (1,2) Gazelle #C
			 * Ou 						 (1,1) NULL #NC
			 */
			*fp<<"|"<<i<<"|"<<j<<" ";
			Animal *p = dynamic_cast<Animal*>(map[index]->getPionCase());
			if(p==NULL)
			{
				ImpalaJones *i = dynamic_cast<ImpalaJones*>(map[index]->getPionCase());

				if(i==NULL)
				{
					*fp<<"NULL #NC";
				}
				else
				{
					*fp<<"ImpalaJones"<<" #I";
				}
				*fp<<" -1 ";
			}
			else
			{
				string categorie = "NC";
				if(p->isEstCache())
				{
					categorie = "C";
				}
				*fp<<p->getName()<<" #"<<categorie<<" "<<p->getJoueur()->getNum()<<" ";
			}
		}
		*fp<<endl;
	}
}

void Parser::saveJ(vector<Joueur*> listeJ,fstream *fp)
{
	if(listeJ.size()==0)
		return;
	for(Joueur *joueur : listeJ)
	{
		/*
		 * id Nom bonus J_HUMAIN ou J_NOVICE ...
		 * Animal 1
		 * Animal 2
		 */
		int categorie = J_HUMAIN;

		Novice *n = dynamic_cast<Novice*>(joueur);
		if(n==NULL)
		{
			Intermediaire *i = dynamic_cast<Intermediaire*>(joueur);
			if(i!=NULL)
			{
				categorie = J_INTERMEDIAIRE;
			}
		}
		else
		{
			categorie = J_NOVICE;
		}
		*fp<<DELIM_JOUEUR_D<<endl;
		*fp<<joueur->getNum()<<" "<<joueur->getName()<<" "<<joueur->getBonus()<<" "<<categorie<<endl;
		saveA(joueur->getMesAnimaux(),fp);
		*fp<<DELIM_JOUEUR_F<<endl;
	}
}

void Parser::saveA(vector<Animal*> listeA,fstream *fp)
{
	cout<<"Size = "<<listeA.size()<<endl;
	if(listeA.size()==0)
			return;
	*fp<<DELIM_L_ANIMAUX_D<<endl;
	for(Animal *animal : listeA)
	{
		/*
		 * id Nom estCache valeur
		 */
		*fp<<DELIM_ANIMAL_D<<endl;
		*fp<<animal->getId()<<" "<<animal->getName()<<" "<<animal->isEstCache()<<" "<<animal->getValeur()<<endl;
		*fp<<DELIM_ANIMAL_F<<endl;
	}
	*fp<<DELIM_L_ANIMAUX_F<<endl;
}
