/*
 * Jeu.cpp
 *
 *  Created on: 30 janv. 2015
 *      Author: Amin
 */

#include "Jeu.h"



using namespace std;

Jeu::Jeu() {
	// TODO Auto-generated constructor stub

}

Jeu::~Jeu() {
	// TODO Auto-generated destructor stub
}


int main(int argc, char **argv) {

	/*string message = "   o  ";
	cout<<"------------";cout<<"------------";
	cout<<endl<<"|";cout<<"          |";cout<<"          |";
	cout<<endl;
	cout<<"|  ";cout<<message;cout<<"  |";cout<<"  ";cout<<message;cout<<"  |";
	cout<<endl;
	cout<<"|";cout<<"          |";cout<<"          |";
	cout<<endl;
	cout<<"------------";cout<<"------------";
	cout<<endl;*/


	/*
	 *
	string message = "   o  ";
	cout<<"------------";
	cout<<endl<<"|";cout<<"          |"<<endl;
	cout<<"|  ";cout<<message;cout<<"  |";
	cout<<endl<<"|";cout<<"          |";
	cout<<endl<<"------------"<<endl;
	 */
	cout<<"Debut"<<endl;

	/*map.init();*/

	Map& ptr = Map::Instance();
	ptr.affiche();

	//Il faut constructeur par defaut d'animal mais avec l'heritage avec pion ca galere
	/*Animal *listeanimaux = (Animal*)calloc(5,sizeof(Animal));
	cout<<"Ok"<<endl;
	listeanimaux[0] = Crocodile("croco",NULL,map);
	listeanimaux[1] = Lion("lion",NULL,map);
	listeanimaux[2] = Elephant("elephant",NULL,map);
	listeanimaux[3] = Gazelle("gazelle",NULL,map);
	listeanimaux[4] = Zebre("zebre",NULL,map);

	Humain amin(1,"Amin",listeanimaux);

	for(int i = 0; i<5; i++)
	{
		listeanimaux[i].setJoueur(&amin);
	}
	Animal *listeanimaux2 = (Animal*)calloc(5,sizeof(Animal));
	cout<<"Ok"<<endl;
	listeanimaux2[0] = Crocodile("croco",NULL,map);
	listeanimaux2[1] = Lion("lion",NULL,map);
	listeanimaux2[2] = Elephant("elephant",NULL,map);
	listeanimaux2[3] = Gazelle("gazelle",NULL,map);
	listeanimaux2[4] = Zebre("zebre",NULL,map);

	Humain gishan(2,"Gishan",listeanimaux2);


	delete listeanimaux,listeanimaux2;
	Humain gishan(2,"Gishan",NULL);
	delete listeanimaux;
	*/
	int res;
	cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala";
	cin>>res;
	/*for(int i=1;i<j;i++)*/
	int j=3;
	while(res>j || res<1)
	{
		cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala";
		cin>>res;
	}







	int resultat;
	cout<<"Bienvenue sur DROLE DE ZEBRE "<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<"1. Jouer " << "\n" << "2. Charger une sauvegarde"<<endl;
	cin>>resultat;

	while(resultat!=1 && resultat!=2)
	{
		cout<<"Vous avez effectuer un choix incorrecte, veuillez choisir dans la liste proposee"<<endl;
		cout<<"1. Jouer " << "\n" << "2. Charger une sauvegarde"<<endl;
		cin>>resultat;
	}
	if(resultat==1){
		cout<<"Mode Jeu "<<endl;
		cout<<"1. Deux joueurs " << "\n" << "2. Jeu contre IA "<<endl;
		cin>>resultat;
		while(resultat!=1 && resultat!=2)
		{
			cout<<"Vous avez effectuer un choix incorrecte, veuillez choisir dans la liste proposee"<<endl;
			cout<<"1. Deux joueurs " << "\n" << "2. Jeu contre IA "<<endl;
			cin>>resultat;
		}
		if(resultat==1)
		{
			/*ImpalaJones impala= ImpalaJones(0,0);*/
			ImpalaJones impala =ImpalaJones(0,0);
			cout<<"Veuillez saisir le nom du premier joueur "<<endl;
			string name;
			cin>>name;
			Humain joueur1(1,name);
			cout<<"Veuillez saisir le nom du deuxime joueur "<<endl;
			cin>>name;
			Humain joueur2(2,name);
			/* Faire fonction affiche */

			joueur1.affiche();
			joueur2.affiche();
			int x,y;
			cout<<"Joueur 1 => choisisez une case pour poser impala"<<endl;
			cout<<"Ligne :"<<endl;
			cin >>x;
			cout<<"Colonne :"<<endl;
			cin >>y;

			Map& map = Map::Instance();
			pair<int, int> index(x,y);
			joueur1.getAction().deplacementImpalaPremiereFois(&impala,*map[index]);

			cout<<"IMPALA EST ICI : "<<impala.getC()->getX()<<"et :"<<impala.getC()->getY()<<endl;
			joueur2.getAction().deplacementImpala(&impala);
			cout<<"IMPALA EST ICI : "<<impala.getC()->getX()<<"et :"<<impala.getC()->getY()<<endl;
			/*cout<<"IMPALA EST ICI : "<<impala.getC()->getX()<<"et :"<<impala.getC()->getY();*/

			/*
			vector<Case*> vec = map.proposeCases(new Case(0,2,-1));

			for(Case *c : vec)
			{
				c->affiche();
			}
			cout<<endl;
			*/
		}
		ptr.affiche();


	}

}

