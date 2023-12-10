//
// Created by ethan on 05/12/2023.
//
/*
#include <stdlib.h>
#include "3cell.h"

p_d_cell createCell(p_agendaEntry value) {

    p_d_cell newCell = (p_d_cell) malloc(sizeof(t_d_cell));
    if (newCell == NULL) {
        //Si malloc echoue
        return NULL;
    }

    newCell->value = value;
    //newCell->level = level;
    newCell->next = (p_d_cell *) malloc(sizeof(p_d_cell));

    // Boucle qui créé le nombre de next selon le level
    for (int i = 0; i < 4; i++) {
        newCell->next[i] = NULL;
    }
    return newCell;
}*/
