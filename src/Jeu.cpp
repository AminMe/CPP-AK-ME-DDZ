/*
 * Jeu.cpp
 *
 *  Created on: 30 janv. 2015
 *      Author: Amin
 */

#include "Jeu.h"
#include <string>
#include <iostream>
#include <vector>

#include "Jeu/Map/Case.h"
#include "Jeu/Map/Map.h"
#include "Joueur/Action.h"
#include "Joueur/Humain/Humain.h"
#include "Joueur/Joueur.h"
#include "Pion/ImpalaJones.h"
#include "Pion/Pion.h"


using namespace std;

int Jeu::menuConfiguration()
{
	int resultat;
    string s = "Que voulez vous faire ? \n 1. Continuer \n 2. Sauvegarder et quitter \n 3. Quitter ";
    string err = "Vous avez saisi une valeur incorrecte, veuillez saisir une valeur correcte svp\n";
    testSaisie(s,1,3,err);
    return 0;
}
int Jeu::testSaisie(string message, int min, int max, string error)
{
	cout<<message<<endl;
	int resultat=-1;
	char ligne[100];
	fgets(ligne, 100, stdin);
	bool saisiOk = sscanf(ligne,"%d",&resultat);
	if(saisiOk && (resultat<min || resultat>max))
	{
		saisiOk = false;
	}
	while(!saisiOk)
	{
		cout<<error<<endl;
		cout<<message<<endl;
		fgets(ligne, 100, stdin);
		saisiOk = sscanf(ligne,"%d",&resultat);
		if(saisiOk && (resultat<min || resultat>max))
		{
			saisiOk = false;
		}
	}
	return resultat;
}

bool Jeu::launchGame()
{
	map.affiche();

	int resultat;
	cout<<"Bienvenue sur DROLE DE ZEBRE "<<endl;
	cout<<"-----------------------------"<<endl;
	resultat = testSaisie("1. Jouer \n2. Charger une sauvegarde", 1, 2, "Vous avez effectuer un choix incorrecte, veuillez choisir dans la liste proposee");

	if(resultat==1)
	{
		cout<<"Mode Jeu "<<endl;
		resultat = testSaisie("1. Deux joueurs \n2. Jeu contre IA ", 1, 2, "Vous avez effectuer un choix incorrecte, veuillez choisir dans la liste proposee");
		if(resultat==1)
		{
			cout<<"Veuillez saisir le nom du premier joueur "<<endl;
			string name;
			cin>>name;
			Humain joueur1(1,name);
			cout<<"Veuillez saisir le nom du deuxime joueur "<<endl;
			cin>>name;
			Humain joueur2(2,name);
			addJoueur(&joueur1);
			addJoueur(&joueur2);

			joueur1.affiche();
			joueur2.affiche();

			cout<<"Joueur 1 veuillez saisir la position de l'impala"<<endl;
			joueur1.getAction().deplacementImpalaPremiereFois();
			int tour = 1;
			map.affiche();
			//menuConfiguration();
			while(!map.estComplete(*this))
			{
				joueurs[tour]->getAction().choixPion(joueurs[tour]);
				map.gainBonus(*this);
				map.affiche();
				joueurs[tour]->getAction().deplacementImpala();
				map.affiche();
			//	menuConfiguration();
				tour++;
				if(tour>=joueurs.size())
				{
					tour=0;
				}
			}

		}
		map.affiche();


	}

}






int main(int argc, char **argv) {
	cout<<"MAP"<<endl;
	Jeu j = Jeu();
	j.launchGame();
}

