#ifndef SRC_HUMAIN_H_
#define SRC_HUMAIN_H_

#include "../Joueur.h"


class Humain: public Joueur {
public:


	Humain(int num, string name, Animal *mesAnimaux):Joueur(num,name,mesAnimaux){};
	virtual ~Humain(){};
};

#endif /* SRC_HUMAIN_H_ */
