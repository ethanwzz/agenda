//
// Created by ethan on 12/11/2023.
//

#include <stdlib.h>
#include "fichier.h"

t_d_cell* createCell(int valeur, int level){
    t_d_cell* newCell = (t_d_cell*)malloc(sizeof(t_d_cell));
    if (newCell == NULL){
        //Si malloc echoue
        return NULL;
    }

    newCell->value = valeur;
    newCell->next_0 = NULL;
    newCell->next_1 = NULL;

    return newCell;
}
//test