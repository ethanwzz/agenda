//
// Created by ethan on 12/11/2023.
//

#ifndef AGENDA_FICHIER_H
#define AGENDA_FICHIER_H

typedef struct s_d_cell
{
    int value;
    struct s_d_cell *next_0;
    struct s_d_cell *next_1;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell *head_0;
    t_d_cell *head_1;
} t_d_list;

t_d_cell* createCell(int valeur, int level);

#endif //AGENDA_FICHIER_H
