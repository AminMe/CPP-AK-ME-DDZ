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
	virtual ~Joueur(){}

	virtual void play()=0;

	Animal* getMesAnimaux() {return mesAnimaux;}
	void setMesAnimaux(Animal* mesAnimaux) {this->mesAnimaux = mesAnimaux;}
	const string& getName() const {return name;}
	void setName(const string& name) {this->name = name;}
	int getNum() const {return num;}
	void setNum(int num) {this->num = num;}
	int getPoint() const {return point;}
	void setPoint(int point) {this->point = point;}
};

#endif /* SRC_JOUEUR_H_ */
