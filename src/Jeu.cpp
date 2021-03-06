#include "Jeu.h"

#include <vector>

#include <cstdio>

#include "Joueur/Action.h"
#include "Joueur/Humain/Humain.h"
#include "Joueur/Ordinateur/Novice.h"
#include "Sauvegarde/Parser.h"


using namespace std;

int Jeu::menuConfiguration()
{
    string s = "Que voulez vous faire ? \n 1. Continuer \n 2. Sauvegarder et quitter \n 3. Quitter ";
    string err = "Vous avez saisi une valeur incorrecte, veuillez saisir une valeur correcte svp\n";
    return testSaisie(s,1,3,err);
}
int Jeu::testSaisie(string message, int min, int max, string error)
{
	cout<<message<<endl;
	string resultat="";
	cin>>resultat;
	int saisiOk = atoi(resultat.c_str());

	if(saisiOk<min || saisiOk>max)
	{
		saisiOk = 0;
	}
	while(saisiOk==0)
	{
		cout<<error<<endl;
		cout<<message<<endl;
		cin>>resultat;
		saisiOk = atoi(resultat.c_str());

		if(saisiOk<min || saisiOk>max)
		{
			saisiOk = 0;
		}

	}
	return saisiOk;
}

bool Jeu::launchGame()
{
	srand(time(NULL));
	map.affiche();
	string nomFichier = "../Data/sauvegarde.txt";
	int resultat;
	cout<<"Bienvenue sur DROLE DE ZEBRE "<<endl;
	cout<<"-----------------------------"<<endl;
	resultat = testSaisie("1. Jouer \n2. Charger une sauvegarde", 1, 2, "Vous avez effectue(e) un choix incorrecte, veuillez choisir dans la liste proposee");

	if(resultat==1)
	{
		cout<<"Mode Jeu "<<endl;
		resultat = testSaisie("1. Deux joueurs \n2. Jeu contre IA ", 1, 2, "Vous avez effectue(e) un choix incorrecte, veuillez choisir dans la liste proposee");

		cout<<"Veuillez saisir le nom du premier joueur (Humain) "<<endl;
		string name;
		cin>>name;

		Joueur* joueur1 = NULL;
		joueur1 = new Humain(1,name);
		cout<<"Veuillez saisir le nom du deuxieme joueur (Humain ou Robot)"<<endl;

		do
		{
			cin>>name;

			if(name==joueur1->getName())
			{
				cout<<"Saisir un nom different du joueur precedent !"<<endl;
			}
		}
		while(name==joueur1->getName());

		Joueur* joueur2 = NULL;

		if(resultat==1)
		{
			joueur2 = new Humain(2,name);
		}
		else if(resultat==2)
		{
			joueur2 = new Novice(2,name);
		}
		else
		{
			//Inutile mais roue de secours
			joueur2 = new Humain(2,name);
		}

		addJoueur(joueur1);
		addJoueur(joueur2);

		joueur1->affiche();
		joueur2->affiche();

		cout<<"Joueur : " << joueur1->getName() <<" veuillez saisir la position de l'impala"<<endl;
		joueur1->getAction().deplacementImpalaPremiereFois();
		map.affiche();
		int ok = menuConfiguration();

		if(ok==2)
		{
			cout<<"Sauvegarde en cours ..."<<endl;
			Parser xml(nomFichier);
			xml.save(*this);
			cout<<"Sauvegarde terminee"<<endl;


			cout<<"Fin du jeu"<<endl;
			return 0;
		}

		else if(ok==3)
		{
			cout<<"Fin du jeu"<<endl;
			return 0;
		}
		while(!map.estComplete(*this) && ok==1)
		{
			cout<<"###########################"<<endl;
			cout<<"Tour du joueur :  "<<this->tour+1<<"  "<<joueurs[tour]->getName()<<endl;
			cout<<"###########################"<<endl;
			joueurs[tour]->play(this,tour);
			if(!joueurs[tour]->isEstRobot())
			{
				ok = menuConfiguration();

				if(ok==2)
				{
					tour++;
					if(tour>=joueurs.size())
					{
						tour=0;
					}
					cout<<"Sauvegarde en cours ..."<<endl;
					Parser xml(nomFichier);
					xml.save(*this);
					cout<<"Sauvegarde terminee"<<endl;
					cout<<"Fin du jeu"<<endl;
					return 0;
				}
				else if(ok==3)
				{
					cout<<"Fin du jeu"<<endl;
					return 0;
				}
			}
			tour++;
			if(tour>=joueurs.size())
			{
				tour=0;
			}
			map.affiche();
		}

		afficherResultat();

	}
	else
	{
		Parser xml(nomFichier);
		xml.parse(this);
		int ok = 1;
		if(joueurs.size()==0)
		{
			cout<<"Aucun joueur trouve (sauvegarde indisponible)"<<endl;
			cout<<"Veuillez redemarrer le jeu et choisir une nouvelle partie OU continuer"<<endl;
			return 0;
		}

		while(!map.estComplete(*this) && ok==1)
		{
			cout<<"###########################"<<endl;
			cout<<"Tour du joueur :  "<<this->tour+1<<"   "<<joueurs[tour]->getName()<<endl;
			cout<<"###########################"<<endl;

			joueurs[tour]->play(this,tour);

			if(!joueurs[tour]->isEstRobot())
			{
				ok = menuConfiguration();

				if(ok==2)
				{
					tour++;
					if(tour>=joueurs.size())
					{
						tour=0;
					}
					cout<<"Sauvegarde en cours ..."<<endl;
					Parser xml(nomFichier);
					xml.save(*this);
					cout<<"Sauvegarde terminee"<<endl;


					cout<<"Fin du jeu"<<endl;
					return 0;
				}
				else if(ok==3)
				{
					cout<<"Fin du jeu"<<endl;
					return 0;
				}
			}
			tour++;
			if(tour>=joueurs.size())
			{
				tour=0;
			}
			map.affiche();
		}

		afficherResultat();
	}
	return 0;
}

void Jeu::afficherResultat()
{
	int cptgagnant = 0;
	int pointMax = 0;
	cout<<endl<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;

	cout<<"TABLEAU DE SCORE"<<endl;
	for(int i = 0; i<joueurs.size();i++)
	{
		if(joueurs[i]->getBonus())
		{
			cout<<"Point du Joueur (a gagne BONUS) : "<<joueurs[i]->getName()<<" "<<joueurs[i]->getPoint()<<endl;
		}
		else
		{
			cout<<"Point du Joueur : "<<joueurs[i]->getName()<<" "<<joueurs[i]->getPoint()<<endl;
		}
		if(pointMax<joueurs[i]->getPoint())
		{
			pointMax = joueurs[i]->getPoint();
			cptgagnant = i;
		}


	}
	cout<<"Le gagnant est "<<joueurs[cptgagnant]->getName()<<" :)"<<endl;

	for(int i = 0; i<joueurs.size();i++)
	{
		if(i!=cptgagnant)
		{
			cout<<"Dommage :( "<<joueurs[i]->getName()<<" vous gagnerez surement la prochaine fois"<<endl;
		}
	}

	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;
}

int main(int argc, char **argv) {

	int continuer = 1;

	do
	{
		Jeu j = Jeu();
		Map& map = Map::Instance();
		map.clear();

		j.launchGame();
		continuer = Jeu::testSaisie("Voulez vous rejouer ou continuer ? : 1 --- OUI | 2 --- NON",1,2,"Erreur : saisir 1 ou 2");
	}
	while(continuer==1);
}

