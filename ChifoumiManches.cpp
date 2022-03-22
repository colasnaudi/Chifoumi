/*
    Programme : ChifoumiManches
    But : Jeu de chifoumi contre la machine avec saisie du nombre de manches et arrêt dès que la dernière manche est terminée
    Date de dernière modification : 15 Septembre 2021
    Auteur : C.Naudi
    Remarques : Version améliorée du chifoumi.
*/

#include<iostream>
#include <unistd.h>
using namespace std;

int randomMinMax(int min, int max);

int main (){

    ///////////////////////////
    ///V A R I A B L E S

    // Déclaration des variables
    char choixJoueur;
    char choixMachine;
    int scoreMachine = 0;
    int scoreJoueur = 0;
    int nbManches;
    int compteurManches = 0;
    string figureJoueur;
    string figureMachine;

    ///////////////////////////
    ///T R A I T E M E N T S

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

    //Demande de saisie du nombre de manches à jouer
    do{
        cout << "Combien de manches voulez-vous jouer ? ";
        cin >> nbManches;
    }while (!(nbManches > 0));
    
    //Tant que compteurManches n'est pas égal au nombre de manches nbManches saisi on joue une nouvelle manche
    do
    {
        cout << "Nouvelle manche "<< compteurManches+1 << "/" << nbManches <<":" <<endl;

        //Choix de du joueur avec verif
        do
        {
            //Demande de saisie de la figure ou quitter
            cout << "   Choisissez une figure : (C)iseau   (P)ierre   (F)euille : ";
            cin >> choixJoueur;
        }while (!((choixJoueur == 'p') || (choixJoueur == 'P') || (choixJoueur == 'f') || (choixJoueur == 'F') || (choixJoueur == 'c')|| (choixJoueur == 'C')));

        //Attribution de la figure à figureJoueur pour l'afficher dans le résultat
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
        int nbreAleatoire;
        nbreAleatoire = randomMinMax (1,4);

        //Attribution de la figure à la machine par rapport au chiffre aleatoire
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

        //Comparaison entre choix machine et choix joueur pour ajouter les points au gagnant
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
        cout << "   joueur2        : " << figureMachine << ", " << scoreMachine<<endl;
        cout <<endl;
        compteurManches++;

        //Si le nombre de manche total est atteint on enlève le délai pour afficher le message de fin
        if(compteurManches!=nbManches)
        {
            usleep(300000);
        }
    }while (compteurManches != nbManches);

    //Affichage du gagnant
    if (scoreJoueur > scoreMachine)
    {
        cout << "Vous avez gagné !"<< endl;
    }
    else if (scoreMachine == scoreJoueur)
    {
        cout << "Egalité" << endl;
    }
    else 
    {
        cout << "La machine a gagné." << endl;
    }

    //Message de fin du jeu
    cout <<"Fin du jeu, au revoir." <<endl;
    

    return 0;
}

int randomMinMax (int min, int max){
    return rand()%(max-min) + min;
}