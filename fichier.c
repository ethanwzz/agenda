//
// Created by ethan on 12/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"

t_d_cell* createCell(int value, int level) {

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

void insertHead(p_d_list list, t_d_cell cell){
    // Vérifie si le niveau d'une cellule par rapport a celui de la liste
    if (cell.level <= list->max_level){
        // Parcours les niveaux de la cellule et créé les heads
        for (int i = 0; i < cell.level; i++) {
            cell.next[i] = list->heads[i];
            list->heads[i] = &cell;
        }
    }
    else{
        printf("Erreur : Le niveau de la cellule est supérieur au niveau maximum de la list");
        return;
    }
}