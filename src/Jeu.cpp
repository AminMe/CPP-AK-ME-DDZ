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
	Animal **listeanimaux;

	listeanimaux[0] = new Crocodile("croco",NULL,map);
	listeanimaux[1] = new Lion("lion",NULL,map);
	listeanimaux[2] = new Elephant("elephant",NULL,map);
	listeanimaux[3] = new Gazelle("gazelle",NULL,map);
	listeanimaux[4] = new Zebre("zebre",NULL,map);

	Humain amin(1,"Amin",*listeanimaux);
	cout<<"NOK"<<endl;
	for(int i = 0; i<5; i++)
	{
		cout<<"Ok "<<endl;
		listeanimaux[i]->setJoueur(&amin);
	}

	Humain gishan(2,"Gishan",NULL);

}

