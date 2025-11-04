// main.c

// 1. Include ALL your full type definitions first
#include "pilotes.h"
#include "grandprix.h"
#include "ecuries.h"

// 2. NOW, include the headers for the functions you use
#include "initialisation.h"
// ... other function headers ...

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "classement.h"
#include "couleurs.h"

// Déclaration anticipée de l'appelant des résultats
void lancerSaisieResultats(GrandPrixz *GPs, int nbGP, Pilotez *pilotes, int nbPilotes);


// **********************************************
// * Fonction d'aide pour lancer la saisie des résultats *
// **********************************************

void lancerSaisieResultats(GrandPrixz *GPs, int nbGP, Pilotez *pilotes, int nbPilotes) {
    char nom_gp_saisi[50];
    int gp_found = 0;

    if (nbGP == 0) {
        printf("Aucun Grand Prix n'est enregistré pour saisir des résultats.\n");
        return;
    }

    // Logique de recherche du GP avec do-while (votre besoin initial)
    do {
        printf("\nEntrez le nom EXACT du Grand Prix pour la saisie des résultats (ou 'annuler') : ");
        if (scanf("%s", nom_gp_saisi) != 1) return;

        if (strcmp(nom_gp_saisi, "annuler") == 0) return;

        gp_found = 0;
        for (int i = 0; i < nbGP; i++) {
            // Ici, vous pourriez vouloir comparer en ignorant la casse (utiliser tolower/strcmp)
            if (strcmp(nom_gp_saisi, GPs[i].nomCircuit) == 0) {
                gp_found = 1;
                break;
            }
        }

        if (!gp_found) {
            printf("Grand Prix '%s' non trouvé. Veuillez réessayer.\n", nom_gp_saisi);
        }
    } while (!gp_found);

    // Une fois que le nom est trouvé et validé, on appelle la fonction
    // C'est ici que l'ancienne fonction ajouterResultatsCourse est appelée avec toute la logique de tri et de points
    ajouterResultatsCourse(GPs, nbGP, nom_gp_saisi, pilotes, nbPilotes);
}

int main() {

    Pilotez *pilotes = NULL;
    int nbPilotes = 0;
    GrandPrixz *GPs = NULL;
    int nbGP = 0;
    Ecuriez *EC = NULL;
    int nbEC = 0;
    int menu_choisi = 0;
    int choix = 0;
    int run = 1;
    int retour = 0;
    char nom[50];
    int correct = 0;

    initialiserPilotes(&pilotes, &nbPilotes);
    initialiserGrandPrix(&GPs, &nbGP);
    initialiserEcuries(&EC, &nbEC);

    // Création d'un menu
    do {
        printf("========= Menu =========");
        printf("1. Gérer les pilotes\n"
               "2. Gérer les écuries\n"
               "3. Gérer les Grands Prix\n"
               "4. Voir les classements\n"
               "5. Ajouter des résultats de course\n"
               "6. Quitter\n");
        printf("Entrez le numéro qui correspond à ce que vous voulez faire : ");
        scanf("%d", &menu_choisi);
        do {
            switch (menu_choisi) {

                case 1:
                    do {
                        printf("==== Pilotes ====");
                        printf("1. Afficher la liste\n"
                               "2. Ajouter un pilote\n"
                               "3. Supprimer un pilote\n"
                               "4. Retour\n"
                               "5. Quitter\n");
                        printf("Entrez le numéro qui correspond à ce que vous voulez faire : ");
                        scanf("%d", &choix);
                        switch (choix) {
                            case 1:
                                afficherPilote(pilotes, nbPilotes);
                                break;

                            case 2:
                                ajouterPilote(&pilotes,&nbPilotes, EC, nbEC);
                                break;

                            case 3:
                                printf("Entrez le nom du pilote à supprimer : ");
                                scanf("%s", nom);
                                supprimerPilote(&pilotes, &nbPilotes, nom);
                                break;

                            case 4:
                                retour = 1;
                                break;

                            case 5:
                                run = 0;
                                break;

                            default:
                                printf("Ce choix n'est pas valable.");
                                break;
                        }
                        if (retour == 1 || run == 0) break;
                    } while (choix < 1 || choix > 5);

                    if (run == 0) return 0;
                    if (retour == 1) break;
                    retour = 0;
                    break;

                case 2:
                    do {
                        printf("==== Ecuries ====");
                        printf("1. Afficher la liste\n"
                               "2. Ajouter une écurie\n"
                               "3. Supprimer une écurie\n"
                               "4. Retour\n"
                               "5. Quitter\n");
                        printf("Entrez le numéro qui correspond à ce que vous voulez faire : ");
                        scanf("%d", &choix);
                        switch (choix) {

                            case 1:
                                afficherEcurie(EC, nbEC, pilotes, nbPilotes);
                                break;

                            case 2:
                                ajouterEcurie(&EC, &nbEC);
                                break;

                            case 3:
                                printf("Entrez le nom de l'écurie à supprimer : ");
                                scanf("%s", nom);
                                do {
                                    for (int i = 0; i < nbEC; i++) {
                                        if (strcmp(EC[i].nom,nom) == 0) {
                                            correct = 1;
                                            supprimerEcurie(&EC, &nbEC, nom, &pilotes, &nbPilotes);
                                        } else {
                                            printf("Ecurie non trouvée.");
                                        }
                                    }
                                } while (!correct);
                                break;

                            case 4:
                                retour = 1;
                                break;

                            case 5:
                                run = 0;
                                break;

                            default:
                                printf("Ce choix n'est pas valable.");
                                break;
                        }
                        if (retour == 1 || run == 0) break;
                    } while (choix < 1 || choix > 5);

                    if (run == 0) return 0;
                    if (retour == 1) break;
                    retour = 0;
                    break;

                case 3:
                    do {
                        printf("==== Grands Prix ====");
                        printf("1. Afficher la liste\n"
                               "2. Ajouter un Grand Prix\n"
                               "3. Supprimer un Grand Prix\n"
                               "4. Retour\n"
                               "5. Quitter\n");
                        printf("Entrez le numéro qui correspond à ce que vous voulez faire : ");
                        scanf("%d", &choix);
                        switch (choix) {

                            case 1:
                                afficherGrandPrix(GPs, nbGP);
                                break;

                            case 2:
                                ajouterGrandPrix(&GPs, &nbGP, pilotes, nbPilotes);
                                break;

                            case 3:
                                supprimerGrandPrix(&GPs, &nbGP);
                                break;

                            case 4:
                                retour = 1;
                                break;

                            case 5:
                                run = 0;
                                break;

                            default:
                                printf("Ce choix n'est pas valable.");
                                break;
                        }
                        if (retour == 1 || run == 0) break;
                    } while (choix < 1 || choix > 5);

                    if (run == 0) return 0;
                    if (retour == 1) break;
                    retour = 0;
                    break;

                case 4:
                    do {
                        printf("==== Classements ====");
                        printf("1. Classement d'un Grand Prix\n"
                               "2. Classement des pilotes\n"
                               "3. Classement des écuries\n"
                               "4. Retour\n"
                               "5. Quitter\n");
                        printf("Entrez le numéro qui correspond à ce que vous voulez faire : ");
                        scanf("%d", &choix);
                        switch (choix) {

                            case 1:
                                printf("Entrez le nom de du Grand Prix dont vous voulez voir le classement : ");
                                scanf("%s", nom);
                                do {
                                    for (int i = 0; i < nbGP; i++) {
                                        if (strcmp(GPs[i].nomCircuit,nom) == 0) {
                                            correct = 1;
                                            classementCourse(GPs, nbGP, nom);
                                        } else {
                                            printf("Grand prix non trouvé.");
                                        }
                                    }
                                } while (!correct);

                                break;

                            case 2:
                                classementPilote(pilotes, nbPilotes);
                                break;

                            case 3:
                                classementEcurie(pilotes, nbPilotes, EC, nbEC);
                                break;

                            case 4:
                                retour = 1;
                                break;

                            case 5:
                                run = 0;
                                break;

                            default:
                                printf("Ce choix n'est pas valable.");
                                break;
                        }
                        if (retour == 1 || run == 0) break;
                    } while (choix < 1 || choix > 5);

                    if (run == 0) return 0;
                    if (retour == 1) break;
                    retour = 0;
                    break;

                case 5:
                    printf("Entrez le nom de du Grand Prix dont vous voulez ajouter des résultats : ");
                    scanf("%s", nom);
                    do {
                        for (int i = 0; i < nbGP; i++) {
                            if (strcmp(GPs[i].nomCircuit,nom) == 0) {
                                correct = 1;
                                ajouterResultatsCourse(GPs, nbGP, nom, pilotes, nbPilotes);
                            } else {
                                printf("Grand prix non trouvé.");
                            }
                        }
                    } while (!correct);

                    break;


                case 6:
                    run = 0;
                    break;

                default:
                    printf("Ce choix n'est pas valable.");
                    break;
            }
        } while (choix < 1 || choix > 6);
    } while (run == 1 || menu_choisi < 1 || menu_choisi > 5);

    free(pilotes);
    free(GPs);
    free(EC);

    return 0;

}
