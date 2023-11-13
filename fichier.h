//
// Created by ethan on 12/11/2023.
//

#ifndef AGENDA_FICHIER_H
#define AGENDA_FICHIER_H

typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;
} t_d_cell, *p_d_cell;

typedef struct s_d_list
{
    int max_level;
    t_d_cell *head;
} t_d_list, *p_d_list;

p_d_cell createCell(int value, int level);

p_d_list createList(int max_level)



#endif //AGENDA_FICHIER_H
