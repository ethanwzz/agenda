//
// Created by ethan on 05/12/2023.
//

#ifndef AGENDA_LIST_H
#define AGENDA_LIST_H
#include "cell.h"

// Structures :

typedef struct s_d_list
{
    int max_level;
    t_d_cell **heads;
} t_d_list, *p_d_list;

// Prototype des fonctions :

p_d_list createList(int);

void insertHead(p_d_list, p_d_cell);

void insertSorted(p_d_list, p_d_cell);

p_d_list create2squaredlist(int);

int searchValueLevel0(p_d_list list, int value);

int searchValuedichotomy(p_d_list list, int value);

void displayList(p_d_list);

void displayLevelList(p_d_list list, int level);

void displayAlignedList(p_d_list);

void displayLevelAlignedList(p_d_list list, int level);

#endif //AGENDA_LIST_H
