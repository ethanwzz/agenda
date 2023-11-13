//
// Created by ethan on 12/11/2023.
//

#include <stdlib.h>
#include "fichier.h"

t_d_cell* createCell(int value, int level){
    int i;

    p_d_cell newCell = (t_d_cell*)malloc(sizeof(t_d_cell));
    if (newCell == NULL){
        //Si malloc echoue
        return NULL;
    }

    newCell->value = value;
    newCell->level = level;
    newCell->next = (p_d_cell*)malloc(sizeof(p_d_cell));

    for (i = 0; i < newCell->level; i++){
        newCell->next[i] = NULL;
    }

    return newCell;
}