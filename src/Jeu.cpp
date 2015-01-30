/*
 * Jeu.cpp
 *
 *  Created on: 30 janv. 2015
 *      Author: Amin
 */

#include "Jeu.h"
#include "../src/Jeu/Map/Map.h"
#include <iostream>
#include <stdio.h>

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

}

