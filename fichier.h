//
// Created by ethan on 12/11/2023.
//

#ifndef AGENDA_FICHIER_H
#define AGENDA_FICHIER_H

// Structures :

typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;
} t_d_cell, *p_d_cell;

typedef struct s_d_list
{
    int max_level;
    t_d_cell **heads;
} t_d_list, *p_d_list;

//Prototype des fonctions :

p_d_cell createCell(int, int);

p_d_list createList(int);

void insertHead(p_d_list, p_d_cell);

void insertSorted(p_d_list, t_d_cell);

void displayCell(p_d_cell);

void displayList(p_d_list);

void displayLevelList(p_d_list list, int level);


#endif //AGENDA_FICHIER_H
