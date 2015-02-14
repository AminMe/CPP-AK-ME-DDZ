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
#include "Pion/Animal.h"

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

	int *p = NULL;

	//Il faut constructeur par defaut d'animal mais avec l'heritage avec pion ca galere
	Animal *listeanimaux;


	Humain amin(1,"Amin",NULL);

	Humain gishan(2,"Gishan",NULL);

}

