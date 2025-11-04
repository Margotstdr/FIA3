//
// Created by Margot Studer on 04/11/2025.
//

#include "classement.h"


#include "pilotes.h"
#include "ecuries.h"
#include "grandprix.h"
#include <stdio.h>
#include <string.h>

//// A FINIR
void classementCourse(GrandPrixz *GPs, int nbGP, char nom[]) {//on donne le classement général d'UNE seule course

    for (int k = 0; k < nbGP; k++) {
        if (strcmp(GPs[k].nomCircuit, nom) == 0) {
            if (GPs[k].resultats == NULL || GPs->nombreResultats == 0) {//on vérifie bien que la liste de grand Prix n'est pas vide
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
                    printf("%2d. %-15s %-15s | %-12s | Temps : %-10s | Points : %2d\n",
                           resCourse.position, resCourse.prenomPilote, resCourse.nomPilote, resCourse.nationalite,
                           resCourse.tempsRealise, resCourse.pointsObtenus);
                }
            }
        }
    }
}

////////// a finir
void classementPiloteGP (Pilotez *pilotes, int nbPilotes) {

    for (int i = 0; i < nbPilotes; i++) {
        if (pilotes == NULL) return;
        //on va chercher le pilote correspondant dans le tableau Pilote
        for (int k = 0; k < nbPilotes; k++) {
            //Tri du tableau resultats par position croissante (1er, 2e, 3e, etc.)
            for (int j = i + 1; j < nbPilotes; j++) {
                if (pilotes[i].points > pilotes[j].points) {//tri à bulle
                    ResultatsCourse temp = GPs[k].resultats[i];
                    GPs[k].resultats[i] = GPs[k].resultats[j];
                    GPs[k].resultats[j] = temp;
                }//donc par exemple si [i] est à la pos 5 et [j] à la pos 4
            }//on va switch la place de i et j
        }


            //on affiche le classement
            for (int i = 0; i < pilotes[i].points; i++) {
                printf("%2d. %-15s %-15s | %-12s | Temps : %-10s | Points : %2d\n",
                       resCourse.position, resCourse.prenomPilote, resCourse.nomPilote, resCourse.nationalite,
                       resCourse.tempsRealise, resCourse.pointsObtenus);
            }
        }
    }
}


/////// A REFAIRE (avec char nom[])
void classementEcurie(Pilotez *pilotes, int nbPilotes, Ecuriez *ecuries, int nbEcuries) {
    if (pilotes == NULL || ecuries == NULL) return;

    //remise à zéro des points des écuries
    for (int i = 0; i < nbEcuries; i++) {
        ecuries[i].points = 0;
    }

    //addition des points des pilotes à leur écurie
    for (int i = 0; i < nbPilotes; i++) {
        if (!pilotes[i].actif) continue;

        for (int j = 0; j < nbEcuries; j++) {
            if (strcmp(pilotes[i].ecurie, ecuries[j].nom) == 0) {//on utilise strcmp pour checker que ce soit bien le bons noms
                ecuries[j].points += pilotes[i].points;
                break;
            }
        }
    }

    //tri des écuries par points décroissants
    for (int i = 0; i < nbEcuries - 1; i++) {
        for (int j = i + 1; j < nbEcuries; j++) {
            if (ecuries[i].points < ecuries[j].points) {//petit tri à bulle comme dans les fonctions d'en haut
                Ecuriez temp = ecuries[i];
                ecuries[i] = ecuries[j];
                ecuries[j] = temp;
            }
        }
    }

    //et on affiche le classement
    printf("\n=== Classement Constructeurs ===\n");
    for (int i = 0; i < nbEcuries; i++) {
        printf("%2d. %-20s | Pays : %-15s | Points : %3d\n",
               i + 1,
               ecuries[i].nom,
               ecuries[i].pays,
               ecuries[i].points);
    }
}
