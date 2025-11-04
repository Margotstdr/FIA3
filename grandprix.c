//
// Created by Margot Studer on 04/11/2025.
//

#include "grandprix.h"
#include "pilotes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void afficherGrandPrix(GrandPrixz *GPs, int nbGP) {

    if (nbGP == 0) {
        printf("Aucun Grand Prix enregistré.\n");
        return;
    }

    printf("\n====== LISTE DES GRANDS PRIX ======\n");

    for (int i = 0; i < nbGP; i++) {
        printf("Grand Prix %d : \n", i + 1);
        printf("\tNom du circuit : %s\n", GPs[i].nomCircuit);
        printf("\tPays : %s\n", GPs[i].pays);
        printf("\tNombre de tours : %d\n", GPs[i].nombreTours);
        printf("\tDate : le %d/%d/%d à %d:%d\n",
            GPs[i].date.jour, GPs[i].date.mois, GPs[i].date.annee,
            GPs[i].horaire.heure, GPs[i].horaire.minute);
        printf("\tNombre de coureurs : %d\n", GPs[i].nombreResultats);

        if (GPs[i].actif == 1) {
            printf("\tActif : Oui\n");
        } else {
            printf("\tActif : Non\n");
        }

        printf("\n------------------------------\n");
    }

    printf("\n==============================\n\n");

}

void ajouterGrandPrix(GrandPrixz **GPs, int *nbGP, Pilotez *pilotes, int nbPilotes) {

    (*nbGP)++;
    GrandPrixz *tmp = realloc(*GPs,(*nbGP)*sizeof(GrandPrixz));
    if (tmp == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    *GPs = tmp;
    char res[10];
    char act[10];
    int existant = 1;
    int tours, jour, mois, annee, heure, minute, coureurs;
    int valide = 0, date_valide = 0, heure_valide = 0, coureurs_valide = 0, rep = 0;

    do {
        char nom[50];
        printf("Nom du circuit : ");
        scanf("%s", nom);
        for (int i = 0; i < *nbGP; i++) {
            if (strcmp(nom,(*GPs)[i].nomCircuit) == 0) {    // Vérifie si le circuit à déjà été ajouté
                printf("Circuit déjà ajouté à la saison. Veuillez ajouter un autre Grand Prix.\n");
            } else {
                strcpy(nom,(*GPs)[*nbGP - 1].nomCircuit);
                existant = 0;
            }
        }
    } while (existant != 0);

    printf("Pays du Grand Prix : ");
    scanf("%s", (*GPs)[*nbGP - 1].pays);

    do {
        printf("Nombre de tours : ");
        scanf("%d", &tours);
        if (tours>100 || tours<0) {
            printf("Le nombre de tours doit être compris entre 10 et 100.\n");
        } else {
            (*GPs)[*nbGP - 1].nombreTours = tours;
            valide = 1;
        }
    } while (valide == 0);

    do {
        printf("Entrez la date de la course (jj/mm/aaaa) : ");
        scanf("%d/%d/%d", &jour, &mois, &annee);
        if (jour>31 || jour<=0 || mois>12 || mois<=0 || annee<1900 || annee>2100) {
            printf("Date invalide, veuillez entrer une autre date.\n");
        } else {
            switch (mois) {
                case 4:
                case 6:
                case 9:
                case 11:
                    if (jour>30) {
                        printf("Ce mois n'a que 30 jours. Veuillez entrer une date valide.\n");
                        break;
                    }
                case 2:
                    if (((annee%4==1 && annee%100==0) || annee%400==1) && jour>29) {
                        printf("Cette année n'est pas bissextile, le mois de février contient seulement 28 jours. Veuillez entrer une date correcte.\n");
                        break;
                    }
                default:
                    break;
            }
            (*GPs)[*nbGP - 1].date.jour = jour;
            (*GPs)[*nbGP - 1].date.mois = mois;
            (*GPs)[*nbGP - 1].date.annee = annee;
            date_valide = 1;
        }
    } while (date_valide==0);

    do {
        printf("Horaire (hh:mm) : ");
        scanf("%d:%d", &heure, &minute);
        if (heure>24 || heure<0 || minute>60 || minute<0) {
            printf("Horaire invalide. Veuillez entrer un horaire valide.\n");
        }  else {
            (*GPs)[*nbGP - 1].horaire.heure = heure;
            (*GPs)[*nbGP - 1].horaire.minute = minute;
            heure_valide = 1;
        }
    } while (!heure_valide);

    do {
        printf("Combien de coureurs y'a-t-il ?");
        scanf("%d", &coureurs);
        if (coureurs<0 || coureurs > 20) {
            printf("Nombre de coureurs invalide, veuillez réessayer.\n");
        } else {
            (*GPs)[*nbGP - 1].nombreResultats = coureurs;
            coureurs_valide = 1;
        }
    } while (!coureurs_valide);


    printf("Les résultats sont-ils sortis ?");
    scanf("%s", res);

    // remplace la réponse en lettres minuscules
    for (int i = 0; res[i]; i++) {
        res[i] = tolower(res[i]);
    }

    if (strcmp(res, "oui") == 0) {
        ajouterResultatsCourse(*GPs, *nbGP, (*GPs)[*nbGP - 1].nomCircuit, pilotes, nbPilotes);
    }

    do {
        printf("Le Grand Prix est-il actif ?");
        scanf("%s", act);
        // remplace la réponse en lettres minuscules
        for (int i = 0; act[i]; i++) {
            act[i] = tolower(act[i]);
        }
        if (strcmp(act, "oui") == 0) {
            (*GPs)[*nbGP - 1].actif = 1;
            rep = 1;
        } else if (strcmp(act, "non") == 0) {
            (*GPs)[*nbGP - 1].actif = 0;
            rep = 1;
        }
    } while (!rep);
}

void supprimerGrandPrix(GrandPrixz **GPs, int *nbGP) {
    int found = 0;
    char nom[50];
    char nom_circ[50];

    do {
        printf("Entrez le nom du circuit à supprimer : ");
        scanf("%s", nom);

        // remplace la réponse en lettres minuscules
        for (int i = 0; nom[i]; i++) {
            nom[i] = tolower(nom[i]);
        }

        for (int i = 0; i < *nbGP; i++) {

            strcpy(nom_circ, (*GPs)[i].nomCircuit);

            for (int k = 0; nom_circ[k]; k++) {
                nom_circ[k] = tolower(nom_circ[k]); // après avoir récupéré le nom du circuit, je le mets en minuscule
            }

            if (strcmp(nom,nom_circ) == 0) { // je compare les deux noms en minuscule

                for (int j = 0; j < *nbGP; j++) {
                    (*GPs[j] = (*GPs)[j - 1]);
                }
                (*nbGP)--;

                GrandPrixz *tmp = realloc(*GPs,(*nbGP) * sizeof(GrandPrixz));
                if (tmp == NULL && nbGP > 0) {
                    printf("Erreur d'allocation mémoire.\n");
                }

                printf("\n‰s à été supprimé.");
                *GPs = tmp;
                found = 1;
            } else {
                printf("Aucun Grand Prix trouvé avec le nom : %s. Veuillez réessayer.\n", nom);
            }
        }
    } while (!found);
}


void ajouterResultatsCourse(GrandPrixz *GPs, int nbGP, char nom[], Pilotez *pilotes, int nbPilotes) {

    for (int i = 0; i < nbGP; i++) {
        if (strcmp(nom,GPs[i].nomCircuit) == 0) {

            ResultatsCourse resultats;

            for (int k = 0; k < GPs->nombreResultats; k++) {

                int existe = 0;

                do {
                    printf("Entrez le nom du pilote : ");
                    scanf("%s", resultats.nomPilote);

                    for (int j = 0; j < nbPilotes; j++) {
                        if (strcmp(resultats.nomPilote, pilotes[j].nom) == 0) {
                            strcpy(resultats.prenomPilote, pilotes[j].prenom);
                            strcpy(resultats.nationalite, pilotes[j].nationalite);
                            existe = 1;
                        }
                    }
                    if (existe == 0) {
                        printf("Erreur : ce pilote n’existe pas dans la liste. Réessayez.\n");
                    }
                } while (!existe);

                printf("Entrez son temps réalisé (format h:mm:ss.sss) : ");
                scanf("%s", resultats.tempsRealise);


                resultats.position = 0;
                resultats.pointsObtenus = 0;

                GPs[i].resultats[k] = resultats;
            }
        }
    }
}