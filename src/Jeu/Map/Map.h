#ifndef MAP_H_
#define MAP_H_

#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

#include "Case.h"

class Jeu;

#define LIGNE 7
#define COLONNE 8

using namespace std;

class Map {
private:
	Case **tab;
	static Map m_instance;

	/*
	 * Constructeur par defaut
	 */


		 Map& operator= (const Map& m){
		    return *this;
		 }

		 Map (const Map& m) : tab(NULL){
		    cout<<"Map::Singleton"<<endl;
		 }

public:
	static Map& Instance();

	Map()
	{
		clear();
	}


	/*
	 * Destructeur
	 */
	virtual ~Map(){
		for(int i=0;i<LIGNE;i++)
		   delete[] tab[i];
		delete[] tab;
		cout<<"Destruction d'une Map"<<endl;

		/* LIBERATION  DE LA MEMOIRE */
	}



	void clear();

	void affiche();

	Case * operator[](const std::pair<int,int>& Index)
	{
		return &tab[Index.first][Index.second];
	}
    /* solution provisoire */
	int getSecteur(int x, int y)
	{
		return tab[x][y].getSecteur();
	}

	int getColonne() const {return COLONNE;}
	int getLigne() const {return LIGNE;}


	vector<Case*> proposeCases(Case* impala);

	void gainBonus(Jeu j);
	void chercheBonus(Jeu j, int secteur);

	bool estComplete(Jeu j);
	void chercheJoueurEnMajorite(Jeu jo, int secteur);
	vector<Case*> getCaseSecteur(int secteur);
	vector<int> getListJoueur(vector<Case*> caseSecteur);
	int getPoint(vector<Case*> caseSecteur);
};

#endif /* MAP_H_ */
