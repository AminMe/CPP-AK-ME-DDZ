#ifndef SRC_HUMAIN_H_
#define SRC_HUMAIN_H_

#include "../Joueur.h"


class Humain: public Joueur {
public:

	Humain(int num, string name):Joueur(num,name){};
	~Humain(){};

	void play(Jeu *jeu, int tour);

};

#endif /* SRC_HUMAIN_H_ */
