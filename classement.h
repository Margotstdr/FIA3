//
// Created by Margot Studer on 04/11/2025.
//

#ifndef FIA3_CLASSEMENT_H
#define FIA3_CLASSEMENT_H

#include "grandprix.h"
#include "pilotes.h"
#include "ecuries.h"

typedef struct Ecurie Ecuriez;
typedef struct GrandPrix GrandPrixz;
typedef struct Pilote Pilotez;


void classementCourse (GrandPrixz *grandPrix);
void classementPiloteGP (GrandPrixz *gps, int nbGrandPrix, Pilotez *pilotes, int nbPilotes);
void classementEcurie(Pilotez *pilotes, int nbPilotes, Ecuriez *ecuries, int nbEcuries);

#endif //FIA3_CLASSEMENT_H