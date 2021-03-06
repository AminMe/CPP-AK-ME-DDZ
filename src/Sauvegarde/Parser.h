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
	Map& map;
public:

	Parser():map(Map::Instance()){this->name = "../sauvegarde.txt";}

	Parser(string name):name(name),map(Map::Instance())
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
