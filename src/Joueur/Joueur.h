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
#include <vector>

#include "../Pion/Effrayant/Crocodile.h"
#include "../Pion/Effrayant/Lion.h"
#include "../Pion/Effraye/Gazelle.h"
#include "../Pion/Effraye/Zebre.h"


#include "../Pion/Animal.h"

using namespace std;

class Joueur{

protected:
	int num;
	string name;
	vector<Animal*> mesAnimaux;
	/*Animal *mesAnimaux;*/
	int point;
	/* Chnagement de *mesAnimaux à Vecteur*/

public:

	Joueur(int num, string name):num(num),name(name),point(0)
    {
		/* C'est mieux de faire un Vector ou pas ? */
		/* Et comme ça on peut directement initialiser chaque liste ici*/
		Map map(15,15);
		mesAnimaux.push_back(new Lion(this,map));
		mesAnimaux.push_back(new Crocodile(this,map));
		for(int i=0;i<6;i++)
		{
			mesAnimaux.push_back(new Gazelle(this,map));
		}
		for(int i=0;i<5;i++)
		{
			mesAnimaux.push_back(new Zebre(this,map));
		}

	}

	virtual ~Joueur(){};

	virtual void play()=0;

	const string& getName() const {return name;}
	void setName(const string& name) {this->name = name;}
	int getNum() const {return num;}
	void setNum(int num) {this->num = num;}
	int getPoint() const {return point;}
	void setPoint(int point) {this->point = point;}
};

#endif /* SRC_JOUEUR_H_ */
