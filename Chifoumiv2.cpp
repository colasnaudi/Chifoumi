/*
    Programme : Chifoumi (v2)
    But : Jeu de chifoumi contre la machine avec le choix de quitter dès la saisi de la figure choisi.
    Date de dernière modification : 15 Septembre 2021
    Auteur : C.Naudi
    Remarques : Version 2 du chifoumi.
*/

#include<iostream>
using namespace std;

int randomMinMax(int min, int max);

int main (){
    // Déclaration des variables
    char choixJoueur;
    char choixMachine;
    int scoreMachine = 0;
    int scoreJoueur = 0;
    int nbreAleatoire;
    string figureJoueur;
    string figureMachine;

    //Afficher les règles
    cout << "C H I F O U M I" << endl;
    cout << "---------------" << endl;
    cout << endl;
    cout << "Vous (joueur1) jouerez contre la machine (joueur2)." << endl;
    cout << "Le jeu est compose de manches." << endl;
    cout << "Vous pourrez arreter quand vous le souhaitez. La question vous sera posee dans chaque manche." << endl;
    cout << endl;
    cout << "Dans une manche, chaque joueur choisit une figure : CISEAU, FEUILLE, PIERRE." << endl;
    cout << "Le CISEAU bat la FEUILLE, qui bat la PIERRE, qui bat le CISEAU." << endl;
    cout << "Le joueur ayant choisi la figure gagnante gagne un point." << endl;
    cout << "Pas de point en cas d'egalite." << endl;
    cout << endl;
    cout << endl;

    //Tant que le joueur n'a pas choisi de quitter on continue à jouer
    while (true)
    {
        cout << "Nouvelle manche :" <<endl;
        //Choix de l'utilisateur avec verif
        do
        {
            //Demande de saisie de la figure ou quitter
            cout << "   Choisissez une figure ou Quittez : (C)iseau   (P)ierre   (F)euille   ou (Q)uitter : ";
            cin >> choixJoueur;
        }while (!((choixJoueur == 'p') || (choixJoueur == 'P') || (choixJoueur == 'f') || (choixJoueur == 'F') || (choixJoueur == 'c')|| (choixJoueur == 'C') || (choixJoueur == 'q') || (choixJoueur == 'Q')));

        //Si choixJoueur est égale à quitter alors on break
        if ((choixJoueur == 'q') || (choixJoueur == 'Q'))
        {
            break;
        }
        
        //Attribution de la figure jouée à figureJoueur pour l'afficher dans le résultat
        switch (choixJoueur)
        {
        case 'f':
            figureJoueur = "feuille";
            break;
        case 'F':
            figureJoueur = "feuille";
            break;
        case 'p':
            figureJoueur = "pierre";
            break;
        case 'P':
            figureJoueur = "pierre";
            break;
        case 'c':
            figureJoueur = "ciseau";
            break;
        case 'C':
            figureJoueur = "ciseau";
            break;
        }

        //Choix Machine aleatoire
        srand(time(NULL)); // INITIALISATION DU GENERATEUR DE NBRE ALEATOIRE RAND

        //Generation du nombre aleatoire
        nbreAleatoire = randomMinMax (1,4);

        //Attribution de la figure jouée par la machine par rapport au chiffre aleatoire
        switch (nbreAleatoire)
        {
        case 1:
            choixMachine = 'c';
            figureMachine = "ciseau";
            break;
        case 2:
            choixMachine = 'f';
            figureMachine = "feuille";
            break;
        case 3:
            choixMachine = 'p';
            figureMachine = "pierre";
            break;
        }

        //Comparaison entre choix machine et choix joueur pour attribuer le point au gagnant
        if ((choixMachine == 'c' && choixJoueur == 'f') || (choixMachine == 'f' && choixJoueur == 'p') || (choixMachine == 'p' && choixJoueur == 'c'))
        {
            scoreMachine++;
        }
        else if ((choixMachine == 'c' && choixJoueur == 'F') || (choixMachine == 'f' && choixJoueur == 'P') || (choixMachine == 'p' && choixJoueur == 'C'))
        {
            scoreMachine++;
        }
        else if ((choixMachine == 'c' && choixJoueur == 'p') || (choixMachine == 'f' && choixJoueur == 'c') || (choixMachine == 'p' && choixJoueur == 'f'))
        {
            scoreJoueur++;
        }
        else if ((choixMachine == 'c' && choixJoueur == 'P') || (choixMachine == 'f' && choixJoueur == 'C') || (choixMachine == 'p' && choixJoueur == 'F'))
        {
            scoreJoueur++;
        }

        //Affichage du score
        cout << endl;
        cout << "   joueur1 (vous) : " << figureJoueur << ", " << scoreJoueur<< endl;
        cout << "   joueur2        : " << figureMachine << ", " << scoreMachine<< endl;
        cout << endl;
        
    }

    //Message de fin du jeu
    cout << endl;
    cout <<"Fin du jeu, au revoir." <<endl;
    

    return 0;
}

int randomMinMax (int min, int max){
    return rand()%(max-min) + min;
}