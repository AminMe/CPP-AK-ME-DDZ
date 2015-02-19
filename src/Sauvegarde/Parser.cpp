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
#include "../Joueur/Ordinateur/Intermediaire.h"
#include "../Joueur/Ordinateur/Novice.h"
#include "../Pion/Animal.h"
#include "../Pion/ImpalaJones.h"
#include "../Pion/Pion.h"

#include <sstream>

using namespace std;

#define J_HUMAIN 1
#define J_NOVICE 2
#define J_INTERMEDIAIRE 3

void Parser::parse()
{
	cout<<"Ouverture du fichier"<<endl;
	fstream fp("sauvegarde.txt", fstream::out | fstream::in );
	string line = "";
	if(fp.is_open())
	{
		while(fp>>line)
		{
			//cout<<line<<endl;
			if(line[0]=='|')
			{
				stringstream linestream(line);
				string data;
				getline(linestream, data, '|');  // read up-to the first tab (discard t
				string car1, car2, car3, car4;
				linestream>>car1;

				/*string data2 = car1.substr(1, car1.find("|"));


				stringstream linestream2(car1);
				getline(linestream2, data2, '|');  // read up-to the first tab (discard t
				linestream2>>car2;

				cout<<"Line = "<<"["<<car1<<"]"<<endl;
				cout<<"Car2 = "<<"["<<car2<<"]"<<endl;
				cout<<"Data = "<<"["<<data2<<"]"<<endl;*/
				//cout<<"Line = "<<"["<<car1<<"]"<<endl;

				string position = car1;
				string x,y;
				std::string delimiter = "|";
				size_t pos = 0;
				std::string token;
				while ((pos = position.find(delimiter)) != std::string::npos) {
					token = position.substr(0, pos);
					//std::cout << token << std::endl;
					x = token;
					position.erase(0, pos + delimiter.length());
				}
				y = position;

				cout<<"Case : "<<x<<","<<y<<endl;
			}
		}
	}
	fp.close();
}

void Parser::save(Jeu jeu)
{
	cout<<"Creation du fichier"<<endl;
	fstream fp("sauvegarde.txt", fstream::out | fstream::in | fstream::trunc );

	saveJ(jeu.getJoueur(),&fp);
	saveM(&fp);
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
			*fp<<"|"<<i<<"|"<<j<<" "<<map[index]->getSecteur()<<" ";
			Animal *p = dynamic_cast<Animal*>(map[index]->getPionCase());
			if(p==NULL)
			{
				ImpalaJones *i = dynamic_cast<ImpalaJones*>(map[index]->getPionCase());

				if(i==NULL)
				{
					*fp<<"NULL #NC ";
				}
				else
				{
					*fp<<i->getName()<<" #I";
				}
			}
			else
			{
				string categorie = "NC";
				if(p->isEstCache())
				{
					categorie = "C";
				}
				*fp<<p->getName()<<" #"<<categorie<<" ";
			}
			*fp<<" "<<map[index]->getTabRiviere()[RIVIERE_GAUCHE]<<" "<<map[index]->getTabRiviere()[RIVIERE_DROITE]<<" "<<map[index]->getTabRiviere()[RIVIERE_HAUT]<<" "<<map[index]->getTabRiviere()[RIVIERE_BAS]<<" ";
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
		*fp<<"DEBUT"<<endl;
		*fp<<joueur->getNum()<<" "<<joueur->getName()<<" "<<joueur->getBonus()<<" "<<categorie<<endl;
		saveA(joueur->getMesAnimaux(),fp);
		*fp<<"FIN"<<endl;
	}
}

void Parser::saveA(vector<Animal*> listeA,fstream *fp)
{
	cout<<"Size = "<<listeA.size()<<endl;
	if(listeA.size()==0)
			return;
	*fp<<"DEBUT_ANIMAL"<<endl;
	for(Animal *animal : listeA)
	{
		/*
		 * id Nom estCache valeur
		 */
		*fp<<animal->getId()<<" "<<animal->getName()<<" "<<animal->isEstCache()<<" "<<animal->getValeur()<<endl;
	}
	*fp<<"FIN_ANIMAL"<<endl;
}
