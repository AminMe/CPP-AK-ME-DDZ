/*
 * Jeu.cpp
 *
 *  Created on: 30 janv. 2015
 *      Author: Amin
 */

#include "Jeu.h"

#include <stdio.h>
#include <iostream>
#include <string>

#include "Jeu/Map/Map.h"
#include "Joueur/Humain/Humain.h"
#include "Pion/Effrayant/Crocodile.h"
#include "Pion/Effrayant/Lion.h"
#include "Pion/Effraye/Gazelle.h"
#include "Pion/Effraye/Zebre.h"
#include "Pion/Invincible/Elephant.h"

using namespace std;

Jeu::Jeu() {
	// TODO Auto-generated constructor stub

}

Jeu::~Jeu() {
	// TODO Auto-generated destructor stub
}


int main(int argc, char **argv) {
	cout<<"Debut"<<endl;

	Map map();
	/*map.init();*/

	Map& ptr = Map::Instance();
	ptr.affiche();

	//Il faut constructeur par defaut d'animal mais avec l'heritage avec pion ca galere
	/*Animal *listeanimaux = (Animal*)calloc(5,sizeof(Animal));
	cout<<"Ok"<<endl;
	listeanimaux[0] = Crocodile("croco",NULL,map);
	listeanimaux[1] = Lion("lion",NULL,map);
	listeanimaux[2] = Elephant("elephant",NULL,map);
	listeanimaux[3] = Gazelle("gazelle",NULL,map);
	listeanimaux[4] = Zebre("zebre",NULL,map);

	Humain amin(1,"Amin",listeanimaux);

	for(int i = 0; i<5; i++)
	{
		listeanimaux[i].setJoueur(&amin);
	}
	Animal *listeanimaux2 = (Animal*)calloc(5,sizeof(Animal));
	cout<<"Ok"<<endl;
	listeanimaux2[0] = Crocodile("croco",NULL,map);
	listeanimaux2[1] = Lion("lion",NULL,map);
	listeanimaux2[2] = Elephant("elephant",NULL,map);
	listeanimaux2[3] = Gazelle("gazelle",NULL,map);
	listeanimaux2[4] = Zebre("zebre",NULL,map);

	Humain gishan(2,"Gishan",listeanimaux2);


	delete listeanimaux,listeanimaux2;
	Humain gishan(2,"Gishan",NULL);
	delete listeanimaux;
	*/
	int res;
	cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala";
	cin>>res;
	/*for(int i=1;i<j;i++)*/
	int j=3;
	while(res>j || res<1)
	{
		cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala";
		cin>>res;
	}







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
			cout<<"Veuillez saisir le nom du premier joueur "<<endl;
			string name;
			cin>>name;
			Humain joueur1(1,name);
			cout<<"Veuillez saisir le nom du deuxime joueur "<<endl;
			cin>>name;
			Humain joueur2(2,name);
			/* Faire fonction affiche */

			/*joueur1.affiche();
			joueur2.affiche();
			*/

		}




	}

}

