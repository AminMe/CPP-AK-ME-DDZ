/*
 * Personne.h
 *
 *  Created on: 20 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>

using namespace std;

class Personne {
protected:
	int num;
	string name;
public:

	Personne();
	Personne(int numero,string name):num(numero),name(name){};
	virtual ~Personne();

	int getNum(){ return num;}
	string getName(){ return name;}
};

#endif /* PERSONNE_H_ */
