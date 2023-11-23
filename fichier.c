//
// Created by ethan on 12/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"

p_d_cell createCell(int value, int level) {

    p_d_cell newCell = (p_d_cell) malloc(sizeof(t_d_cell));
    if (newCell == NULL) {
        //Si malloc echoue
        return NULL;
    }

    newCell->value = value;
    newCell->level = level;
    newCell->next = (p_d_cell *) malloc(level * sizeof(p_d_cell));

    // Boucle qui créé le nombre de next selon le level
    for (int i = 0; i < level; i++) {
        newCell->next[i] = NULL;
    }

    return newCell;
}


p_d_list createList(int max_level){
    p_d_list newList = (p_d_list)malloc(sizeof(t_d_list));
    newList->max_level = max_level;
    newList->heads = (p_d_cell*) malloc(max_level * sizeof(p_d_cell));

    // Boucle qui créé le nombre de head correspondant au level max
    for (int i = 0; i < max_level; i++) {
        newList->heads[i] = NULL;
    }

    return newList;
}

void insertHead(p_d_list list, p_d_cell cell){
    // Vérifie si le niveau d'une cellule par rapport a celui de la liste
    if (cell->level <= list->max_level){
        // Parcours les niveaux de la cellule et créé les heads
        for (int i = 0; i < cell->level; i++) {
            cell->next[i] = list->heads[i];
            list->heads[i] = cell;
        }
    }
    else{
        printf("Erreur : Le niveau de la cellule est supérieur au niveau maximum de la list");
        return;
    }
}


void insertSorted(p_d_list list, t_d_cell cell) {
    if (cell.level <= list->max_level) {
        int currentLevel = cell.level - 1;

        // Recherche de la position d'insertion optimale dans chaque niveau
        while (currentLevel >= 0 && (list->heads[currentLevel] == NULL || list->heads[currentLevel]->value <= cell.value)) {
            // Tant que la tête est NULL ou la valeur est inférieure ou égale à la valeur de la cellule, descendre d'un niveau
            while (list->heads[currentLevel] != NULL && list->heads[currentLevel]->next[currentLevel] != NULL && list->heads[currentLevel]->next[currentLevel]->value < cell.value) {
                // Descendre d'un niveau si la cellule suivante existe et sa valeur est inférieure à la valeur de la cellule
                list->heads[currentLevel] = list->heads[currentLevel]->next[currentLevel];
            }
            currentLevel--;
        }

        // Insertion de la cellule à la position trouvée dans chaque niveau
        for (int i = 0; i <= cell.level - 1; i++) {
            cell.next[i] = list->heads[i]->next[i];
            list->heads[i]->next[i] = &cell;
        }
    } else {
        printf("Erreur : Le niveau de la cellule est supérieur à celui de la liste");
    }
}

//Fonction d'affichage :

void displayCell(p_d_cell cell) {
    if (cell == NULL) {
        printf("NULL\n");
    } else {
        for (int i = 0; i < cell->level - 1; i++) {
            if (cell->next[i] != NULL){
                printf("[%d|@-]-->", cell->value);
            } else {
                printf("[%d|@-]-->NULL", cell->value);
            }
        }
    }
}

void displayList(p_d_list list){
    for (int i = 0; i < list->max_level; i++){
        printf("[list head_%d @-]-->", i);
        displayCell(list->heads[i]);
        printf("\n");
    }
}

void displayLevelList(p_d_list list, int level){
    if (level > list->max_level | level < 0){
        printf("Le niveau demande n'est pas valable");
    } else {
        printf("[list head_%d @-]-->", level-1);
        displayCell(list->heads[level-1]);
    }

}
