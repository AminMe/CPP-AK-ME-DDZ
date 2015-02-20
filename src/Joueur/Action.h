#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_

#include <vector>

#include "../Jeu/Map/Case.h"
#include "../Pion/ImpalaJones.h"

class Joueur;

class Action {

public:
	ImpalaJones& impala;

	Action():impala(ImpalaJones::Instance()){}
	virtual ~Action(){}


	bool put(Pion *a, Case* c);
	void controlDeplacement(Pion * p);

	bool deplacementImpala(bool robot);
	vector<Case*> estPossibleDeplacement();
	bool deplacementImpalaPremiereFois();
	/*bool deplacementImpala(ImpalaJones *impala);
	bool estPossibleDeplacement(ImpalaJones *impala);*/
	bool choixPion(Joueur * j,bool robot);
	bool caseDisponible(bool etat,int x);
	Case* parcourir(int x, int y);
	static int testSaisiBis(string message, string val);


};
int tirage_entier(int a,int b);
inline bool isInteger(const std::string & s);
#endif /* SRC_ACTION_H_ */
