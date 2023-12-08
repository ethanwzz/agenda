//
// Created by ethan on 05/12/2023.
//

#ifndef AGENDA_CELL_H
#define AGENDA_CELL_H

// Structures :

typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;
} t_d_cell, *p_d_cell;

// Protype des fonctions :

p_d_cell createCell(int, int);

void displayCell(p_d_cell);

#endif //AGENDA_CELL_H
