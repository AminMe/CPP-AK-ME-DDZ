/*
 * Joueur.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_JOUEUR_H_
#define SRC_JOUEUR_H_
#include <iostream>
#include <string>

using namespace std;

class Animal;

class Joueur{

protected:
	int num;
	string name;
	Animal *mesAnimaux;
	int point;

public:
	Joueur(int num, string name, Animal *mesAnimaux):num(num),name(name),mesAnimaux(mesAnimaux),point(0){}
	virtual ~Joueur();
	int getPoint() const {return point;}
	virtual void play()=0;


};

#endif /* SRC_JOUEUR_H_ */
