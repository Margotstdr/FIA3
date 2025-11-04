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
};

typedef struct Ecurie Ecuriez;

void ajouterEcurie(Ecuriez **ecuries, int *nbEcuries);  //nbEcuries le nombre d'écuries ecuries
void majPointsEcurie(Ecuriez *ecurie, char nom[], Pilotez *pilotes, int nbPilotes);
void supprimerEcurie (Ecuriez **ecuries, int *nbEcuries, char nom[], Pilotez **pilotes, int *nbPilotes);
void afficherEcurie (Ecuriez *ecurie, int nbEcuries, Pilotez *pilotes, int nbPilotes);


#endif //FIA3_ECURIES_H