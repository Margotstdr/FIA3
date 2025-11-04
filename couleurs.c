//
// Created by Margot Studer on 04/11/2025.
//

#include "couleurs.h"

#include <string.h>

const char* couleurEcurie(const char *ecurie) {
    if (strcmp(ecurie, "Ferrari") == 0) {
        return "\033[1;31m"; // Rouge
    } else if (strcmp(ecurie, "Mercedes") == 0) {
        return "\033[1;32m"; // Vert
    } else if (strcmp(ecurie, "Red Bull") == 0 || strcmp(ecurie, "RedBull") == 0) {
        return "\033[1;34m"; // Bleu
    } else if (strcmp(ecurie, "McLaren") == 0) {
        return "\033[1;33m"; // Jaune / Orange
    } else if (strcmp(ecurie, "Alpine") == 0) {
        return "\033[1;36m"; // Cyan
    } else {
        return "\033[0m";    // Par défaut (blanc)
    }
}