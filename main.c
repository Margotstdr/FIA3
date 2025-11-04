// main.c

// 1. Include ALL your full type definitions first
#include "pilotes.h"
#include "grandprix.h"
#include "ecuries.h"

// 2. NOW, include the headers for the functions you use
#include "initialisation.h"
// ... other function headers ...

#include <stdio.h>


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

    initialiserPilotes(&pilotes, &nbPilotes);
    initialiserGrandPrix(&GPs, &nbGP);
    //afficherPilote(&pilotes, &nbPilotes);
    //supprimerPilote(&pilotes, &nbPilotes);
    //afficherPilote(&pilotes, &nbPilotes);
    //afficherGrandPrix(GPs, nbGP);
    //ajouterGrandPrix(&GPs, &nbGP);

    // Création d'un menu
    do {
        printf("========= Menu =========");
        printf("1. Gérer les pilotes\n"
               "2. Gérer les écuries\n"
               "3. Gérer les Grands Prix\n"
               "4. Voir les classements\n"
               "5. Quitter\n");
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

                            case 2:
                                ajouterPilote(&pilotes,&nbPilotes, EC, nbEC);

                            case 3:
                                printf("Entrez le nom du pilote à supprimer : ");
                                scanf("%s", nom);
                                supprimerPilote(&pilotes, &nbPilotes, nom);

                            case 4:
                                retour = 1;
                                break;

                            case 5:
                                run = 0;
                                break;
                        }
                    } while (choix < 1 || choix > 5);

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
                                // Afficher liste ecurie
                                break;

                            case 2:
                                // Ajouter ecurie
                                break;

                            case 3:
                                // supprimer ecurie
                                break;

                            case 4:
                                retour = 1;
                                break;

                            case 5:
                                run = 0;
                                break;
                        }
                    } while (choix < 1 || choix > 5);

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

                            case 2:
                                ajouterGrandPrix(&GPs, &nbGP, pilotes, nbPilotes);

                            case 3:
                                supprimerGrandPrix(&GPs, &nbGP);

                            case 4:
                                retour = 1;

                            case 5:
                                run = 0;
                        }
                    } while (choix < 1 || choix > 5);

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
                    } while (choix < 1 || choix > 5);

                case 5:
                    run = 0;
            }
        } while (choix < 1 || choix > 5);
    } while (run == 1 || menu_choisi < 1 || menu_choisi > 5);

}