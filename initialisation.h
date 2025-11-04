//
// Created by Margot Studer on 04/11/2025.
//

#ifndef FIA3_INITIALISATION_H
#define FIA3_INITIALISATION_H




typedef struct Pilote Pilotez;
typedef struct GrandPrix GrandPrixz;
typedef struct Ecurie Ecuriez;


void initialiserEcuries(Ecuriez **ecuries, int *nbEcuries);
void initialiserPilotes(Pilotez **pilotes, int *nbPilotes);
void initialiserGrandPrix(GrandPrixz **GPs, int *nbGP);



#endif //FIA3_INITIALISATION_H