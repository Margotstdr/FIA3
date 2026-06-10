# Projet FIA - Simulateur de Championnat de Formule 1

Application en C simulant la gestion d'un championnat de Formule 1 : pilotes, écuries, Grands Prix et classements.

## Fonctionnalités

- **Pilotes** : ajouter, supprimer, afficher la liste des pilotes avec leurs points et leur écurie
- **Écuries** : ajouter, supprimer, afficher les écuries et leurs pilotes associés
- **Grands Prix** : ajouter, supprimer, afficher les circuits avec date, horaire et nombre de tours
- **Résultats de course** : saisir les résultats d'un Grand Prix et attribuer les points automatiquement
- **Classements** : classement d'un Grand Prix, classement général des pilotes, classement des écuries

## Système de points

| Position | Points |
|----------|--------|
| 1er      | 25     |
| 2ème     | 18     |
| 3ème     | 15     |
| 4ème     | 12     |
| 5ème     | 10     |
| 6ème     | 8      |
| 7ème     | 6      |
| 8ème     | 4      |
| 9ème     | 2      |
| 10ème    | 1      |

## Compilation

```bash
cmake -B build
cmake --build build
```

Ou directement avec gcc :

```bash
gcc -o fia main.c pilotes.c ecuries.c grandprix.c initialisation.c classement.c couleurs.c
```

## Utilisation

Lancer l'exécutable et naviguer dans le menu interactif :

```
========= Menu =========
1. Gérer les pilotes
2. Gérer les écuries
3. Gérer les Grands Prix
4. Voir les classements
5. Ajouter des résultats de course
6. Quitter
```

## Structure du projet

| Fichier              | Description                              |
|----------------------|------------------------------------------|
| `main.c`             | Point d'entrée et menu principal         |
| `pilotes.c / .h`     | Gestion des pilotes                      |
| `ecuries.c / .h`     | Gestion des écuries                      |
| `grandprix.c / .h`   | Gestion des Grands Prix et résultats     |
| `classement.c / .h`  | Calcul et affichage des classements      |
| `initialisation.c / .h` | Initialisation des données            |
| `couleurs.c / .h`    | Affichage coloré dans le terminal        |
| `CMakeLists.txt`     | Configuration CMake                      |
