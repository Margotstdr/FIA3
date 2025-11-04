//
// Created by Margot Studer on 04/11/2025.
//

#ifndef FIA3_GRANDPRIX_H
#define FIA3_GRANDPRIX_H

typedef struct Pilote Pilotez;




typedef struct {
    int jour;
    int mois;
    int annee;
}Date;

typedef struct {
    int heure;
    int minute;
} Heure;

typedef struct {
    char nomPilote[50];
    char prenomPilote[50];
    char nationalite[50];
    int position;
    char tempsRealise[20];
    int pointsObtenus;
} ResultatsCourse;


struct GrandPrix{
    char nomCircuit[50];
    char pays[50];
    int nombreTours;
    Date date;
    Heure horaire;
    ResultatsCourse resultats[20];     // Tableau pour stocker les résultats des pilotes
    int nombreResultats;
    int actif;
};
typedef struct GrandPrix GrandPrixz;




void afficherGrandPrix(GrandPrixz *GPs, int nbGP);

void ajouterGrandPrix(GrandPrixz **GPs, int *nbGP, Pilotez *pilotes, int nbPilotes);


void supprimerGrandPrix(GrandPrixz **GPs, int *nbGP);
void ajouterResultatsCourse(GrandPrixz *GPs, int nbGP, char nom[], Pilotez *pilotes, int nbPilotes);






#endif //FIA3_GRANDPRIX_H