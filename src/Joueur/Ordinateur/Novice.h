/*
 * Novice.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_NOVICE_H_
#define SRC_NOVICE_H_


#include "Ordinateur.h"

class Novice : public Ordinateur{
public:
	Novice(int num, string name):Ordinateur(num,name){}
	~Novice(){};

	void play(Jeu *jeu, int tour);
	void algo();
};

#endif /* SRC_NOVICE_H_ */
