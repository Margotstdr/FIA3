//
// Created by Margot Studer on 04/11/2025.
//

#include "initialisation.h"

#include "pilotes.h"
#include "grandprix.h"
#include "ecuries.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void initialiserEcuries(Ecuriez **ecuries, int *nbEcuries) {
    // Initialisation des écuries
    Ecuriez initEcuries[5] = {{"Red Bull Racing", "Autriche", 0, 2005, "Christian Horner", 1},
                         {"Scuderia Ferrari", "Italie", 0, 1950, "Frédéric Vasseur", 1},
                         {"Mercedes-AMG", "Allemagne", 0, 2010, "Toto Wolff", 1},
                         {"McLaren Racing", "Royaume-Uni", 0, 1966, "Andrea Stella", 1},
                         {"Aston Martin","Royaume-Uni", 0, 2021, "Mike Krack", 1} };
    *nbEcuries = 5;

    *ecuries = malloc(*nbEcuries * sizeof(Ecuriez));

    if (*ecuries == NULL) {
        printf("Erreur d'allocation mémoire pour les écuries.\n");
        exit(1);
    }

    for (int i = 0; i < *nbEcuries; i++) {
        (*ecuries)[i] = initEcuries[i];
    }
}

// Initialisation des pilotes
void initialiserPilotes(Pilotez **pilotes, int *nbPilotes) {

    // Tableau temporaire pour initialisation
    Pilotez initPilotes[10] = {
        {"Verstappen", "Max", "Pays-Bas", "Red Bull Racing", 0, 1, 27, 1},
        {"Perez", "Sergio", "Mexique", "Red Bull Racing", 0, 11, 34, 1},
        {"Leclerc", "Charles", "Monaco","Scuderia Ferrari", 0, 16, 27, 1},
        {"Sainz","Carlos", "Espagne", "Scuderia Ferrari", 0, 55,30, 1},
        {"Hamilton", "Lewis", "Royaume-Uni", "Mercedes-AMG", 0, 44, 39, 1},
        {"Russell", "George", "Royaume-Uni", "Mercedes-AMG", 0, 63, 26, 1},
        {"Norris", "Lando", "Royaume-Uni", "McLaren Racing", 0, 4, 25, 1},
        {"Piastri", "Oscar", "Australie", "McLaren Racing", 0, 81, 23, 1},
        {"Alonso", "Fernando", "Espagne", "Aston Martin", 0, 14, 43, 1},
        {"Stroll", "Lance", "Canada", "Aston Martin", 0, 18, 26, 1}
    };

    *nbPilotes = 10;

    // Alloue dynamiquement assez d'espace pour contenir 10 structures pilotes
    *pilotes = malloc(*nbPilotes * sizeof(Pilotez));

    if (*pilotes == NULL) {
        printf("Erreur d'allocation mémoire pour les pilotes.\n");
        exit(1);
    }

    for (int i = 0; i < *nbPilotes; i++) {
        (*pilotes)[i] = initPilotes[i];
    }
}

void initialiserGrandPrix(GrandPrixz **GPs, int *nbGP) {
    //Initialisation d'un Grand_Prix avec résultats
    // GP1
    GrandPrixz gp1;
    strcpy(gp1.nomCircuit, "Circuit de Monaco");
    strcpy(gp1.pays, "Monaco");
    gp1.nombreTours = 78;
    gp1.date = (Date){26, 5, 2024};
    gp1.horaire = (Heure){15, 00};
    gp1.nombreResultats = 10;
    gp1.actif = 1;

    // Résultats du Grand_Prix (exemple pour les 10 premières positions)
    ResultatsCourse resultatsGP1[10] = {
        {"Verstappen", "Max", "Pays-Bas", 1, "1:44:12.456", 25},
        {"Leclerc", "Charles", "Monaco", 2, "1:44:18.234", 18},
        {"Hamilton","Lewis", "Royaume-Uni", 3, "1:44:25.678", 15},
        {"Norris", "Lando", "Royaume-Uni", 4, "1:44:32.123", 12},
        {"Sainz", "Carlos", "Espagne", 5, "1:44:39.456", 10},
        {"Russell", "George", "Royaume-Uni", 6, "1:44:45.789", 8},
        {"Perez", "Sergio", "Mexique", 7, "1:44:52.234", 6},
        {"Alonso", "Fernando", "Espagne", 8, "1:44:58.567", 4},
        {"Piastri", "Oscar", "Australie", 9, "1:45:04.890", 2},
        {"Stroll", "Lance", "Canada", 10, "1:45:11.123", 1} };

    // Copie des résultats dans la structure GrandPrix
    for(int i = 0; i< 10; i++) {
        gp1.resultats[i] = resultatsGP1[i];
    }

    //GP2
    GrandPrixz gp2;
    strcpy(gp2.nomCircuit, "Circuit de Gilles-Villeneuve");
    strcpy(gp2.pays, "Canada");
    gp2.nombreTours = 70;
    gp2.date = (Date){15, 6, 2025};
    gp2.horaire = (Heure){14, 00};
    gp2.nombreResultats = 10;
    gp2.actif = 1;

    // Résultats du Grand_Prix (exemple pour les 10 premières positions)
    ResultatsCourse resultats[10] = {
        {"Russell", "George", "Royaume-Uni", 1, "1:31:52.688", 25},
       {"Verstappen", "Max", "Pays-Bas", 2, "1:31:52.916", 18},
       {"Piastri", "Oscar", "Australie", 3, "1:31:54.797", 15},
       {"Leclerc", "Charles", "Monaco", 4, "1:31:56.130", 12},
       {"Hamilton","Lewis", "Royaume-Uni", 5, "1:32:03.401", 10},
       {"Alonso", "Fernando", "Espagne", 6, "1:31:03.660", 8},
       {"Sainz", "Carlos", "Espagne", 7, "1:33:39.456", 6},
       {"Norris", "Lando", "Royaume-Uni", 8, "1:34:32.123", 4},
       {"Stroll", "Lance", "Canada", 9, "1:35:11.123", 2},
       {"Perez", "Sergio", "Mexique", 10, "1:35:52.234", 1}};

    // Copie des résultats dans la structure GrandPrix
    for(int i = 0; i< 10; i++) {
        gp2.resultats[i] = resultats[i];
    }

    //GP3
    GrandPrixz gp3;
    strcpy(gp3.nomCircuit, "Circuit de Silverstone");
    strcpy(gp3.pays, "Grande-Bretagne");
    gp3.nombreTours = 52;
    gp3.date = (Date){06, 7, 2025};
    gp3.horaire = (Heure){15, 00};
    gp3.nombreResultats = 10;
    gp3.actif = 1;

    ResultatsCourse resultatsGP3[10] = {
        {"Norris", "Lando", "Royaume-Uni", 1, "1:37:15.735", 25},
        {"Piastri", "Oscar", "Australie", 2, "1:37:22.547", 18},
        {"Hamilton","Lewis", "Royaume-Uni", 3, "1:37:55.547", 15},
        {"Verstappen", "Max", "Pays-Bas", 4, "1:38:12.516", 12},
        {"Stroll", "Lance", "Canada", 5, "1:38:17.138", 10},
        {"Alonso", "Fernando", "Espagne", 6, "1:38:54.165", 8},
        {"Russell", "George", "Royaume-Uni", 7, "1:39:28.158", 6},
        {"Sainz", "Carlos", "Espagne", 8, "1:40:48.175", 4},
        {"Leclerc", "Charles", "Monaco", 9, "1:40:59.729", 2},
        {"Perez", "Sergio", "Mexique", 10, "1:41:24.926", 1}};

    // Copie des résultats dans la structure GrandPrix
    for(int i = 0; i< 10; i++) {
        gp2.resultats[i] = resultatsGP3[i];
    }

    // Allocation dynamique
    *nbGP = 3;
    *GPs = malloc(*nbGP * sizeof(GrandPrixz));

    if (*GPs == NULL) {
        printf("Erreur d'allocation mémoire pour les Grands Prix.\n");
        exit(1);
    }

    // Copie des GP dans le tableau dynamique
    (*GPs)[0] = gp1;
    (*GPs)[1] = gp2;
    (*GPs)[2] = gp3;

}
