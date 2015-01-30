/*
 * Map.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef MAP_H_
#define MAP_H_
#include "Case.h"

#define TAILLE 15

using namespace std;
class Map {
private:

	Case tab[TAILLE][TAILLE];
public:

	/*
	 * Constructeur par defaut
	 */
	Map(){}

	/*
	 * Destructeur
	 */
	virtual ~Map(){cout<<"Destruction d'une Map"<<endl;}

	void init();

	void affiche();
};

#endif /* MAP_H_ */
