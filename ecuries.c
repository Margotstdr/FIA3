//
// Created by Margot Studer on 04/11/2025.
//

#include "ecuries.h"
#include "pilotes.h"


#include <stdio.h>
#include <stdlib.h>


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

void majPointsEcurie(Ecuriez *ecurie) {
         ecurie->points = ecurie->p1.points + ecurie->p2.points;
     //dans cette fonction on va simplement copier les valeurs des pilotes 1
     // et 2 puis en faire l'addition !
}

void supprimerEcurie (Ecuriez **ecuries, int *nbEcuries, int index){
     if(index <0 || index >= *nbEcuries){
         printf("Indice écurie invalide\n");
         return;
     }
     //on commence par l'état des pilotes
     (*ecuries)[index].p1.actif = 0;
     (*ecuries)[index].p2.actif = 0;

     //on décale les écuries suivantes en écrasant les données de l'écurie à supprimer
     for(int i = index; i< *nbEcuries -1; i++){
         (*ecuries)[i] = (*ecuries)[*nbEcuries+1];
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

void afficherEcurie (Ecuriez *ecurie, int *nbEcuries){
     //cas de base : s'il n'y a pas de pilotes donc actif=0, alors pas d'écurie
     if(*nbEcuries ==0){
         printf("Aucune écurie sur la piste.");
     }
     for(int i =0; i<(*nbEcuries);i++){
         Ecuriez oneEcurie = ecurie[i];

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
         printf("    Pilote 1 : %s (%d pts)\n", oneEcurie.p1.nom, oneEcurie.p1.points);
         printf("    Pilote 2 : %s (%d pts)\n", oneEcurie.p2.nom, oneEcurie.p2.points);
         printf("---------------------------------------\n");
     }
}

