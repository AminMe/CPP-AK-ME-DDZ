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

class Joueur;
using namespace std;

class Jeu;
class Animal;

class Parser {
private:
	char* name;
	string datarepertory = "../Data";

public:

	Parser(){this->name = (char*)calloc(100,sizeof(char));strcpy(name,"");}

	Parser(char* name):name(NULL)
	{
		this->name = (char*)calloc(100,sizeof(char));
		strcpy(this->name,name);
	}
	virtual ~Parser(){}

	string getName() const {
		return name;
	}

	void parse();

	void save(Jeu jeu);

	void saveJ(vector<Joueur*> listeJ,fstream *fp);

	void saveA(vector<Animal*> listeA,fstream *fp);

	void saveM(fstream *fp);
};

#endif /* SRC_SAUVEGARDE_PARSER_H_ */
