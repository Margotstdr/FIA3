//
// Created by Margot Studer on 04/11/2025.
//

#ifndef FIA3_PILOTES_H
#define FIA3_PILOTES_H

//#include "pilotes.h"
//#include "grandprix.h"
//#include "ecuries.h"
typedef struct Ecurie Ecuriez;
typedef struct GrandPrix GrandPrixz;





struct Pilote{
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char ecurie[50];
    int points;
    int numero;
    int age;
    int actif;
};
typedef struct Pilote Pilotez;




void afficherPilote(Pilotez *pilotes, int nbPilotes);
void ajouterPilote(Pilotez **pilotes, int *nbPilotes, const Ecuriez *ecurie, int nbEcuries);
void supprimerPilote(Pilotez **pilotes, int *nbPilotes, char nom[]);
void majPoints(Pilotez *pilotes, int nbPilotes, GrandPrixz *GPS, int nbGP, char nom_circuit[]);


#endif //FIA3_PILOTES_H