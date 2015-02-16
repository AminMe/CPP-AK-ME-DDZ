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

#include "../Jeu/Map/Map.h"
#include "../Pion/Effrayant/Crocodile.h"
#include "../Pion/Effrayant/Lion.h"
#include "../Pion/Effraye/Gazelle.h"
#include "../Pion/Effraye/Zebre.h"
#include "../Pion/Invincible/Elephant.h"


class Animal;

using namespace std;

class Joueur {

protected:
	int num;
	string name;
	vector<Animal*> mesAnimaux;
	int point;

public:

	Joueur(int num, string name):num(num),name(name),point(0)
    {
		Map& map = Map::Instance();

		for(int i=0;i<6;i++)
		{
			mesAnimaux.push_back(new Gazelle(this,map));
		}

		for(int i=0;i<5;i++)
		{
			mesAnimaux.push_back(new Zebre(this,map));
		}

		mesAnimaux.push_back(new Elephant(this,map));
		mesAnimaux.push_back(new Lion(this,map));

		for(int i=0; i<2;i++)
		{
			mesAnimaux.push_back(new Crocodile(this,map));
		}
	}

	virtual ~Joueur(){};

	virtual void play()=0;

	const string& getName() const {
		return name;
	}
	void setName(const string& name) {
		this->name = name;
	}
	int getNum() const {
		return num;
	}
	void setNum(int num) {
		this->num = num;
	}
	int getPoint() const {
		return point;
	}
	void setPoint(int point) {
		this->point = point;
	}
};

#endif /* SRC_JOUEUR_H_ */
