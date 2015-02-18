/*
 * Jeu.cpp
 *
 *  Created on: 30 janv. 2015
 *      Author: Amin
 */

#include "Jeu.h"

#include <iostream>
#include <utility>

#include "Jeu/Map/Case.h"
#include "Jeu/Map/Map.h"
#include "Joueur/Action.h"
#include "Joueur/Humain/Humain.h"
#include "Joueur/Joueur.h"
#include "Pion/ImpalaJones.h"
#include "Pion/Pion.h"

using namespace std;

Jeu::Jeu() {
	// TODO Auto-generated constructor stub

}

Jeu::~Jeu() {
	// TODO Auto-generated destructor stub
}

int main(int argc, char **argv) {
	cout<<"MAP"<<endl;
	/*map.init();*/

		/*Map& ptr = Map::Instance();
		ptr.affiche();*/
		/*
		int resultat;
		cout<<"Bienvenue sur DROLE DE ZEBRE "<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"1. Jouer " << "\n" << "2. Charger une sauvegarde"<<endl;
		cin>>resultat;

		while(resultat!=1 && resultat!=2)
		{
			cout<<"Vous avez effectuer un choix incorrecte, veuillez choisir dans la liste proposee"<<endl;
			cout<<"1. Jouer " << "\n" << "2. Charger une sauvegarde"<<endl;
			cin>>resultat;
		}
		if(resultat==1){
			cout<<"Mode Jeu "<<endl;
			cout<<"1. Deux joueurs " << "\n" << "2. Jeu contre IA "<<endl;
			cin>>resultat;
			while(resultat!=1 && resultat!=2)
			{
				cout<<"Vous avez effectuer un choix incorrecte, veuillez choisir dans la liste proposee"<<endl;
				cout<<"1. Deux joueurs " << "\n" << "2. Jeu contre IA "<<endl;
				cin>>resultat;
			}
			if(resultat==1)
			{
				/*ImpalaJones impala= ImpalaJones(0,0);*/
				/*ImpalaJones impala =ImpalaJones(0,0);*/
		/*		ImpalaJones& impala = ImpalaJones::Instance();
				cout<<"Veuillez saisir le nom du premier joueur "<<endl;
				string name;
				cin>>name;
				Humain joueur1(1,name);
				cout<<"Veuillez saisir le nom du deuxime joueur "<<endl;
				cin>>name;
				Humain joueur2(2,name);
				/* Faire fonction affiche */

			/*	joueur1.affiche();
				joueur2.affiche();


				Map& map = Map::Instance();



				joueur1.getAction().deplacementImpalaPremiereFois();

				cout<<"IMPALA EST ICI : "<<impala.getC()->getX()<<"et :"<<impala.getC()->getY()<<endl;
				joueur2.getAction().choixPion(&joueur2);
				joueur2.getAction().deplacementImpala();
				cout<<"IMPALA EST ICI : "<<impala.getC()->getX()<<"et :"<<impala.getC()->getY()<<endl;
				/*cout<<"IMPALA EST ICI : "<<impala.getC()->getX()<<"et :"<<impala.getC()->getY();*/

				/*
				vector<Case*> vec = map.proposeCases(new Case(0,2,-1));

				for(Case *c : vec)
				{
					c->affiche();
				}
				cout<<endl;
				*/
		/*	}
			ptr.affiche();


		}
	*/
}

