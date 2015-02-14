/*
 * Jeu.cpp
 *
 *  Created on: 30 janv. 2015
 *      Author: Amin
 */

#include "Jeu.h"

#include <stdio.h>
#include <iostream>

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

	Map map(15,15);
	map.init();
	map.affiche();

	//Il faut constructeur par defaut d'animal mais avec l'heritage avec pion ca galere
	Animal *listeanimaux = (Animal*)calloc(5,sizeof(Animal));
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

	Humain gishan(2,"Gishan",NULL);

}

