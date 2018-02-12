//
//  main.cpp
//  C'est plus c'est moins
//
//  Created by Killian Delorme on 12/02/2018.
//  Copyright © 2018 Killian Delorme. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;
void regles();
void jeu(char prenom[]);
void PlusOuMoins(int nbEntrer, int nbMystere, bool *boucle, int nbCoups);

int main()
{
    srand(time(NULL));
    char *OuirecommenceOuNon;
    OuirecommenceOuNon = new char[100];
    
    cout << "Bonjour et bienvenue dans le jeu du C'est plus C'est moins " << endl;
    cout << "Entrez votre prenom s'il vous plait" << endl;
    char *prenom;
    prenom = new char[10000];
    cin >> prenom;
    
    cout << "Ok " << prenom << " On va pouvoir commencer la partie !!! " << endl;
    do
    {
        cout << "-----------------------C'est plus c'est moins---------------------------------" << endl;
        cout << "1.Vous connaissez les regles de ce jeu?" << endl;
        cout << "Entrez oui ou non" << endl;
        char OuiOuNon[5];
        cin >> OuiOuNon;
        if(strcmp (OuiOuNon, "oui") == 0 || strcmp (OuiOuNon, "OUI") == 0)
        {
            cout << "Ok on va pouvoir commencer !!!" << endl;
            jeu(prenom);
            
        }
        else if(strcmp(OuiOuNon, "non") == 0 || strcmp(OuiOuNon, "NON") == 0)
        {
            cout << "Ok voici les regles :" << endl;
            regles();
            jeu(prenom);
        }
        else
        {
            cout << "Vous vous etes trompé..." << endl;
        }
        cout << "Voulez vous recommencer?" << endl;
        cout << "Entrez oui ou non" << endl;
        cin >> OuirecommenceOuNon;
        system("cls");
    }while( strcmp(OuirecommenceOuNon, "oui") == 0 || strcmp(OuirecommenceOuNon, "OUI") == 0);
    delete[] prenom;
    delete[] OuirecommenceOuNon;
    
    
    return 0;
}

void regles()
{
    cout << "Les regles sont: " << endl;
    cout << "L'ordinateur va choisir un nombre Mystere pour l'instant en 0 et 100" << endl;
    cout << "Vous devez entrer le nombre mystere" << endl;
}

void  jeu(char prenom[])
{
    int nbCoups = 0, MAX = 0;
    const int MIN = 0;
    cout << "Choisissez le niveau de la difficulté" << endl;
    cout << "1. De 0 a 100" << endl;
    cout << "2. De 0 a 1000" << endl;
    cout << "3. De 0 a 10 000" << endl;
    int choixDiff;
    cin >> choixDiff;
    if(choixDiff == 1)
    {
        MAX = 100;
    }
    else if(choixDiff == 2)
    {
        MAX = 1000;
    }
    else if(choixDiff == 3)
    {
        MAX = 10000;
    }
    else
    {
        MAX = 100; // on choisis un nombre par "défaut"
    }
    
    
    bool boucle = false;
    int nbMystere = (rand () % (MAX - MIN + 1)) + MIN;
    cout << "Le jeu commence!" << endl;
    while(boucle == false)
    {
        
        cout << prenom << " Entrez un nombre entre " << MIN << " et " << MAX << endl;
        int nbEntrer;
        cin >> nbEntrer;
        nbCoups++;
        PlusOuMoins(nbEntrer, nbMystere, &boucle, nbCoups);
    }
}

void PlusOuMoins(int nbEntrer, int nbMystere, bool *boucle, int nbCoups)
{
    if(nbEntrer < nbMystere)
    {
        cout << "Je suis desolé mais c'est Plus" << endl;
    }
    else if(nbEntrer > nbMystere)
    {
        cout << "Je suis desolé mais c'est Moins" << endl;
    }
    else
    {
        cout << "Bravo vous avez trouver le nombre mystere en : "<< nbCoups <<" coup(s) !" << endl;
        *boucle = true;
    }
}
