//
// Created by Margot Studer on 04/11/2025.
//

#include "classement.h"


#include "pilotes.h"
#include "ecuries.h"
#include "grandprix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "couleurs.h"

void classementCourse(GrandPrixz *GPs, int nbGP, char nom[]) {//on donne le classement général d'UNE seule course

    for (int k = 0; k < nbGP; k++) {
        if (strcmp(GPs[k].nomCircuit, nom) == 0) {
            if (GPs[k].nombreResultats == 0) {//on vérifie bien que la liste de grand Prix n'est pas vide
                printf("Aucun résultat disponible pour ce Grand Prix.\n");
            } else {
                printf("\n=== Classement du Grand Prix de %s (%s) ===\n",
                    GPs[k].nomCircuit, GPs[k].pays);
                printf("Nombre de tours : %d\n\n", GPs[k].nombreTours);

                //Tri du tableau resultats par position croissante (1er, 2e, 3e, etc.)
                for (int i = 0; i < GPs[k].nombreResultats - 1; i++) { //on utilise les flèches puisque c'est une structure qui pointe vers une autre structure
                    for (int j = i + 1; j < GPs[k].nombreResultats; j++) {
                        if (GPs[k].resultats[i].position > GPs[k].resultats[j].position) {//tri à bulle
                            ResultatsCourse temp = GPs[k].resultats[i];
                            GPs[k].resultats[i] = GPs[k].resultats[j];
                            GPs[k].resultats[j] = temp;
                        }//donc par exemple si [i] est à la pos 5 et [j] à la pos 4
                    }//on va switch la place de i et j
                }

                //on affiche le classement
                for (int i = 0; i < GPs[k].nombreResultats; i++) {
                    ResultatsCourse resCourse = GPs[k].resultats[i];
                    printf("%s%2d. %-15s %-15s (%-10s) | %-12s | Temps : %-10s | Points : %2d%s\n",
                           couleurEcurie(resCourse.ecurie),
                           resCourse.position,
                           resCourse.prenomPilote,
                           resCourse.nomPilote,
                           resCourse.ecurie,
                           resCourse.nationalite,
                           resCourse.tempsRealise,
                           resCourse.pointsObtenus,
                           RESET);
                }
                break;
            }
        }
    }
}

////////// a finir
void classementPilote (Pilotez *pilotes, int nbPilotes) {


    if (pilotes == NULL || nbPilotes == 0) {
        printf("Aucun pilote à classer.\n");
        return;
    }

    // 2. Création d'une copie temporaire
    // On alloue de la mémoire pour un NOUVEAU tableau
    Pilotez *pilotesTries = malloc(nbPilotes * sizeof(Pilotez));
    if (pilotesTries == NULL) {
        printf("Erreur critique : impossible d'allouer la mémoire pour le tri.\n");
        return;
    }

    // On copie les données de 'pilotes' vers 'pilotesTries'
    memcpy(pilotesTries, pilotes, nbPilotes * sizeof(Pilotez));

    // 3. Tri du tableau COPIÉ (Tri à bulle)
    // On trie par ordre DÉCROISSANT (le plus de points en premier)
    for (int i = 0; i < nbPilotes - 1; i++) {
        for (int j = i + 1; j < nbPilotes; j++) {

            // On travaille uniquement sur la copie : 'pilotesTries'
            if (pilotesTries[i].points < pilotesTries[j].points) {

                // On échange les structures entières dans la copie
                Pilotez temp = pilotesTries[i];
                pilotesTries[i] = pilotesTries[j];
                pilotesTries[j] = temp;
            }
        }
    }

    // 4. Affichage du classement (en lisant la copie triée)
    printf("\n=== Classement Général des Pilotes ===\n\n");
    for (int i = 0; i < nbPilotes; i++) {
        printf("%2d. %-15s %-15s | %-12s | Points : %3d\n",
               i + 1,
               pilotesTries[i].prenom,
               pilotesTries[i].nom,
               pilotesTries[i].nationalite,
               pilotesTries[i].points);
    }

    // 5. Libération de la mémoire
    // Très important : on libère la mémoire allouée pour la copie
    free(pilotesTries);
}



void classementEcurie(Pilotez *pilotes, int nbPilotes, Ecuriez *ecuries, int nbEcuries) {
    // 1. Vérifications initiales
    if (pilotes == NULL || ecuries == NULL || nbPilotes == 0 || nbEcuries == 0) {
        printf("Données insuffisantes pour le classement des écuries.\n");
        return;
    }

    // 2. Création d'une copie temporaire des écuries
    Ecuriez *ecuriesClassement = malloc(nbEcuries * sizeof(Ecuriez));
    if (ecuriesClassement == NULL) {
        printf("Erreur critique : impossible d'allouer la mémoire pour le classement.\n");
        return;
    }
    // On copie la structure (nom, pays...) de 'ecuries' vers 'ecuriesClassement'
    memcpy(ecuriesClassement, ecuries, nbEcuries * sizeof(Ecuriez));


    // 3. Remise à zéro des points SUR LA COPIE
    for (int i = 0; i < nbEcuries; i++) {
        ecuriesClassement[i].points = 0;
    }

    // 4. Addition des points des pilotes à leur écurie SUR LA COPIE
    for (int i = 0; i < nbPilotes; i++) {
        if (!pilotes[i].actif) continue;

        for (int j = 0; j < nbEcuries; j++) {
            // On compare le nom de l'écurie du pilote avec le nom dans notre COPIE
            if (strcmp(pilotes[i].ecurie, ecuriesClassement[j].nom) == 0) {
                ecuriesClassement[j].points += pilotes[i].points;
                break; // Pilote trouvé, on passe au pilote suivant
            }
        }
    }

    // 5. Tri des écuries (de la COPIE) par points décroissants
    for (int i = 0; i < nbEcuries - 1; i++) {
        for (int j = i + 1; j < nbEcuries; j++) {
            if (ecuriesClassement[i].points < ecuriesClassement[j].points) {
                Ecuriez temp = ecuriesClassement[i];
                ecuriesClassement[i] = ecuriesClassement[j];
                ecuriesClassement[j] = temp;
            }
        }
    }

    // 6. Et on affiche le classement (depuis la COPIE)
    printf("\n=== Classement Constructeurs ===\n");
    for (int i = 0; i < nbEcuries; i++) {
        printf("%s%2d. %-20s | Pays : %-15s | Points : %3d%s\n",
               couleurEcurie(ecuriesClassement[i].nom),
               i + 1,
               ecuriesClassement[i].nom,
               ecuriesClassement[i].pays,
               ecuriesClassement[i].points,
               RESET);
    }

    // 7. Libération de la mémoire
    free(ecuriesClassement);
}
