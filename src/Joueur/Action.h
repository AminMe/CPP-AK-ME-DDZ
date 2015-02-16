/*
 * Action.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ACTION_H_
#define SRC_ACTION_H_

class Animal;
class Case;
class Joueur;
class Pion;

class Action {
public:
	Action();
	virtual ~Action();

	void update();
	/* Changement de Animal à Pion, on met case dans le deuxième caractère ? ou x et y ?  */
	// on utilisera ton [] pour récupérer la map
	bool put(Pion *a, Case c, Case impala);
	void affiche();
	void controlDeplacement(Pion * p);

	/*
    bool deplacerImpalaPossible ?
    si TRUE :
    On regarde les possibilites
    Sinon
    On le fait automatiquement jusqu'a trouver un endroit libre
    	Si aucun endroit trouver, FIN DU JEU TOUT EST FINIS

    Methode 1 : lorsque deplacement possible
    bool deplacerImpala(ImpalaJones *impala, Case c);
    Methode 2 : lorsque le deplacement n'est pas possible
    bool deplacerImpala(ImpalaJones *impala);
    */
};

#endif /* SRC_ACTION_H_ */
