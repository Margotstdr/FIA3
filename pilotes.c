//
// Created by Margot Studer on 04/11/2025.
//

#include "pilotes.h"

#include "grandprix.h"
#include "ecuries.h"

// 3. Standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void afficherPilote(Pilotez *pilotes, int nbPilotes) {

  if (nbPilotes == 0) {
    printf("Aucun pilote enregistré.\n");
    return;
  }

  printf("\n======= LISTE DES PILOTES =======\n");

  for (int i = 0; i < nbPilotes; i++) {
    printf("%d. %s %s :\n", i+1, pilotes[i].nom, pilotes[i].prenom);
    printf("\t\tNationalité : %s \n", pilotes[i].nationalite);
    printf("\t\tEcurie : %s \n", pilotes[i].ecurie);
    printf("\t\tPoints : %d \n", pilotes[i].points);
    printf("\t\tNumero : %d \n", pilotes[i].numero);
    printf("\t\tAge : %d \n", pilotes[i].age);

    if (pilotes[i].actif == 1) {
      printf("\t\tActif : Oui\n");
    } else {
      printf("\t\tActif : Non\n");
    }
    printf("\n------------------------------\n");
  }

  printf("\n==============================\n\n");

}

void ajouterPilote(Pilotez **pilotes, int *nbPilotes, const Ecuriez *ecurie, int nbEcuries) {

  char nom_ecurie[50];
  int ecurie_valide = 0, numero_valide = 0, rep = 0;
  int numero, age;
  char act[10];

  (*nbPilotes)++;
  Pilotez *tmp = realloc(*pilotes, (*nbPilotes) * sizeof(Pilotez));
  if (tmp == NULL) {
    printf("Erreur d'allocation mémoire.\n");
    exit(1);
  }
  *pilotes = tmp;

  printf("Nom du pilote : ");
  scanf("%s", (*pilotes)[*nbPilotes - 1].nom);

  printf("Prénom du pilote : ");
  scanf("%s", (*pilotes)[*nbPilotes - 1].prenom);

  printf("Nationalité du pilote : ");
  scanf("%s", (*pilotes)[*nbPilotes - 1].nationalite);

  //void afficher ---------------------------------;

  do {
    printf("Nom de l'écurie du pilote : ");
    scanf("%s", nom_ecurie);

    for (int i = 0; i < nbEcuries; i++) {
      if (strcmp(nom_ecurie, ecurie[i].nom) == 0) {
        strcpy((*pilotes)[*nbPilotes - 1].ecurie, nom_ecurie);
        ecurie_valide = 1;
      }
    }
    if (!ecurie_valide) {
      printf("Ecurie non existante, veuillez entrer une écurie présente dans la liste.\n");
    }
  } while (!ecurie_valide);

  (*pilotes)[*nbPilotes - 1].points = 0;

  do {
    printf("Numéro de la voiture du pilote : ");
    scanf("%d", &numero);
    for (int i = 0; i < *nbPilotes; i++) {
      if (numero == (*pilotes)[i].numero) {
        printf("Numéro déjà attribué, veuillez entrer un autre numéro.\n");
      } else if (numero>99 || numero<=0) {
        printf("Le numéro doit être compris entre 1 et 99, veuillez entrer un numéro valide.\n");
      } else {
        (*pilotes)[*nbPilotes - 1].numero = numero;
        numero_valide = 1;
      }
    }
  } while (!numero_valide);

  do {
    printf("Age du pilote : ");
    scanf("%d", &age);
    if (age > 50 || age < 18) {
      printf("Le pilote doit avoir minimum 18 ans et maximum 50 ans pour participer.\n");
    } else {
      (*pilotes)[*nbPilotes - 1].age = age;
    }
  } while (age > 50 || age < 18);

  do {
    printf("Le Grand Prix est-il actif ?");
    scanf("%s", act);
    // remplace la réponse en lettres minuscules
    for (int i = 0; act[i]; i++) {
      act[i] = tolower(act[i]);
    }
    if (strcmp(act, "oui") == 0) {
      (*pilotes)[*nbPilotes - 1].actif = 1;
      rep = 1;
    } else if (strcmp(act, "non") == 0) {
      (*pilotes)[*nbPilotes - 1].actif = 0;
      rep = 1;
    }
  } while (!rep);
}

void supprimerPilote (Pilotez **pilotes, int *nbPilotes) {
  int found = 0;
  char nom[50];
  char nom_pilote[50];

  do {
    printf("Entrez le nom du pilote à supprimer : ");
    scanf("%s", nom);

    for (int i = 0; nom[i]; i++) {
      nom[i] = tolower(nom[i]);
    }

    for (int i = 0; i < *nbPilotes; i++) {

      strcpy(nom_pilote, (*pilotes)[i].nom);

      for (int k = 0; nom_pilote[k]; k++) {
        nom_pilote[k] = tolower(nom_pilote[k]);
      }

      if (strcmp(nom, nom_pilote) == 0) {

        for (int j = i+1; j < *nbPilotes - 1; j++) {
          (*pilotes)[j] = (*pilotes)[j - 1];
        }

        (*nbPilotes)--;
        Pilotez *tmp = realloc(*pilotes, (*nbPilotes) * sizeof(Pilotez));
        if (tmp == NULL && nbPilotes > 0) {
          printf("Erreur d'allocation memoire.\n");
        }

        printf("\n%s %s à été supprimé de la liste.\n", (*pilotes)[i].nom, (*pilotes)[i].prenom);
        *pilotes = tmp;
        found = 1;
      } else {
        printf("\nAucun pilote trouvé avec le nom : %s.\n", nom);
      }
    }
  } while (!found);
}

void majPoints(Pilotez *pilotes, int nbPilotes, GrandPrixz *GPs, int nbGP, char nom_circuit[]) {
  for (int i = 0; i < nbGP; i++) {
    if (strcmp(nom_circuit, GPs[i].nomCircuit) == 0) {
      for (int j = 0; j < GPs[i].nombreResultats; j++) {
        for (int k = 0; k < nbPilotes; k++) {
          if (strcmp(GPs[i].resultats[j].nomPilote, pilotes[k].nom) == 0) {
            pilotes[k].points += GPs[i].resultats[j].pointsObtenus;
          } else {
            printf("Pilote non trouvé.\n");
          }
        }
      }
    } else {
      printf("Circuit non trouvé.\n");
    }
  }
}