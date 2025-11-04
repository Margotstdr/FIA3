//
// Created by Margot Studer on 04/11/2025.
//

#ifndef FIA3_ECURIES_H
#define FIA3_ECURIES_H


typedef struct Pilote Pilotez;

struct Ecurie{
    char nom[50];
    char pays[50];
    int points;
    int anneeCreation;
    char directeur[50];
    int actif;
    Pilotez *p1;
    Pilotez *p2;
};

typedef struct Ecurie Ecuriez;

void ajouterEcurie(Ecuriez **ecuries, int *nbEcuries);  //nbEcuries le nombre d'écuries ecuries
void majPointsEcurie(Ecuriez *ecurie);
void supprimerEcurie (Ecuriez **ecuries, int *nbEcuries, int index);
void afficherEcurie (Ecuriez *ecurie, int *nbEcuries);


#endif //FIA3_ECURIES_H