#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_
#include <vector>
#include "../Jeu/Map/Case.h"
#include "../Jeu/Map/Map.h"
#include "../Pion/ImpalaJones.h"
#include "../Pion/Pion.h"
class ImpalaJones;

class Action {

public:
	Action();
	virtual ~Action();

	void update();

	bool put(Pion *a, Case c, Case impala);
	void affiche();
	void controlDeplacement(Pion * p);

	bool deplacementImpala(ImpalaJones *impala);
	vector<Case> estPossibleDeplacement(ImpalaJones *impala);
	bool deplacementImpalaPremiereFois(ImpalaJones *impala, Case c);
	/*bool deplacementImpala(ImpalaJones *impala);
	bool estPossibleDeplacement(ImpalaJones *impala);*/
	bool caseDisponible(bool etat,int x);
	Case* parcourir(int x, int y);


};

#endif /* SRC_ACTION_H_ */
