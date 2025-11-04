//
// Created by Margot Studer on 04/11/2025.
//

#include "ecuries.h"
#include "pilotes.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ajouterEcurie(Ecuriez **ecuries, int *nbEcuries) { //nbEcuries le nombre d'écuries ecuries
    // on augmente la taille du tableau d'une case
     *ecuries = realloc(*ecuries, (*nbEcuries + 1) * sizeof(Ecuriez));
     if (*ecuries == NULL) {
         printf("Erreur de réallocation mémoire.\n");
         exit(1);
     }

     Ecuriez nouvelleEcurie;

     printf("\n--- Ajouter une nouvelle écurie ---\n");
     printf("Nom de l'écurie : ");
     scanf(" %[^\n]", nouvelleEcurie.nom);

     printf("Pays : ");
     scanf(" %[^\n]", nouvelleEcurie.pays);

     printf("Année de création : ");
     scanf("%d", &nouvelleEcurie.anneeCreation);

     printf("Directeur : ");
     scanf(" %[^\n]", nouvelleEcurie.directeur);

     nouvelleEcurie.points = 0;
     nouvelleEcurie.actif = 1;

     // Ajout à la fin du tableau de notre nouvelle écurie
     (*ecuries)[*nbEcuries] = nouvelleEcurie;
     (*nbEcuries)++;
     printf("Écurie ajoutée avec succès ");
}

void majPointsEcurie(Ecuriez *ecurie, char nom[], Pilotez *pilotes, int nbPilotes) {
    for (int i = 0; i < nbPilotes; i++) {
        if (strcmp(nom, pilotes[i].ecurie) == 0) {
            ecurie->points += pilotes[i].points;
        }
    }
     //dans cette fonction on va simplement copier les valeurs des pilotes 1
     // et 2 puis en faire l'addition !
}

void supprimerEcurie (Ecuriez **ecuries, int *nbEcuries, char nom[], Pilotez **pilotes, int *nbPilotes){

    for(int i =0; i<(*nbEcuries);i++) {
        if (strcmp(nom, (*pilotes)[i].ecurie)==0){
            supprimerPilote(&(*pilotes), &(*nbPilotes), (*pilotes)[i].nom);
        }
        //on décale les écuries suivantes en écrasant les données de l'écurie à supprimer
        for (int j = i+1; j < *nbEcuries - 1; j++) {
            (*ecuries)[j] = (*ecuries)[j - 1];
        }
    }

     //on réduit la taille du tableau --> nbEcuries. Donc il faut "réallouer" un nouvelle espace
     //mémoire plus petit
     (*nbEcuries)--;
     *ecuries = realloc(*ecuries, (*nbEcuries)*(sizeof(Ecuriez)));

     //on vérifie que l'allocation a bien marché
     if((*ecuries) ==NULL && nbEcuries>0){
         perror("Erreur realloc"); //equivalent du try/except en Python ! --> va renvoyer
         exit(EXIT_FAILURE); // renvoie 1 si ça réussi - 0 si ça n'a pas marché
     }
}

void afficherEcurie (Ecuriez *ecurie, int nbEcuries, Pilotez *pilotes, int nbPilotes, char nom[]){

    char p[2][50];
    int pts[2];
     //cas de base : s'il n'y a pas de pilotes donc actif=0, alors pas d'écurie
     if(nbEcuries ==0){
         printf("Aucune écurie sur la piste.");
     }
     for(int i =0; i<(nbEcuries);i++){
         if (strcmp(ecurie[i].nom, nom)==0) {
             Ecuriez oneEcurie = ecurie[i];

             for (int j = i+1; j <nbPilotes; j++) {
                 if (strcmp(ecurie[i].nom, pilotes[j].nom)==0) {
                     for (int k = 0; k < sizeof(p); k++) {
                         strcpy(p[k], pilotes[j].nom);
                         pts[k] = pilotes[j].points;
                     }
                 }
             }

             if(oneEcurie.actif ==0){
                 printf("[%d] %s (INACTIVE)\n\n", i + 1, oneEcurie.nom); //on numérote les écuries à partir
                 //de 1 (i+1)
                 continue;
             }
             printf("[%d] Nom : %s\n", i + 1, oneEcurie.nom);
             printf("    Pays : %s\n",  oneEcurie.pays);
             printf("    Année de création : %d\n", oneEcurie.anneeCreation);
             printf("    Directeur : %s\n", oneEcurie.directeur);
             printf("    Points : %d\n", oneEcurie.points);
             printf("    Pilote 1 : %s (%d pts)\n", p[0], pts[0]);
             printf("    Pilote 2 : %s (%d pts)\n", p[1], pts[1]);
             printf("---------------------------------------\n");
         }
     }
}

