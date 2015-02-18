#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_
#include <vector>
#include "../Jeu/Map/Case.h"
#include "../Jeu/Map/Map.h"
#include "../Pion/ImpalaJones.h"
#include "../Pion/Pion.h"

class Joueur;

class Action {

public:
	ImpalaJones& impala = ImpalaJones::Instance();
	Action(){}
	virtual ~Action(){}

	void update();

	bool put(Pion *a, Case* c);
	void affiche();
	void controlDeplacement(Pion * p);

	bool deplacementImpala();
	vector<Case*> estPossibleDeplacement();
	bool deplacementImpalaPremiereFois();
	/*bool deplacementImpala(ImpalaJones *impala);
	bool estPossibleDeplacement(ImpalaJones *impala);*/
	bool choixPion(Joueur * j);
	bool caseDisponible(bool etat,int x);
	Case* parcourir(int x, int y);


};

#endif /* SRC_ACTION_H_ */
