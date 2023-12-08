//
// Created by ethan on 05/12/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "cell.h"
#include "list.h"

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


// Fonctions d'affichages :

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
