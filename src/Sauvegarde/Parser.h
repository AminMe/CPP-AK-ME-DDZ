/*
 * XML.h
 *
 *  Created on: 18 févr. 2015
 *      Author: Amin
 */

#ifndef SRC_SAUVEGARDE_PARSER_H_
#define SRC_SAUVEGARDE_PARSER_H_

#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>

#include "../Jeu/Map/Map.h"

class Joueur;
using namespace std;

class Jeu;
class Animal;

class Parser {
private:
	string name;
	string datarepertory = "../Data";

public:
	Map& map = Map::Instance();
	Parser(){this->name = "sauvegarde.xml";}

	Parser(string name):name(name)
	{
	}
	virtual ~Parser(){}

	string getName() const {
		return name;
	}

	void parse(Jeu *jeu);

	void save(Jeu jeu);

	void saveJ(vector<Joueur*> listeJ,fstream *fp);

	void saveA(vector<Animal*> listeA,fstream *fp);

	void saveM(fstream *fp);
};

#endif /* SRC_SAUVEGARDE_PARSER_H_ */
