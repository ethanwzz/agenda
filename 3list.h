//
// Created by ethan on 05/12/2023.
//
/*
#ifndef AGENDA_LIST_H
#define AGENDA_LIST_H
#include "3cell.h"
#include "storage.h"

// Structures :

typedef struct s_d_list
{
    int max_level;
    t_d_cell **heads;
} t_d_list, *p_d_list;

// Prototype des fonctions :

p_d_list createList(int);

int compareContacts(p_agendaEntry, p_agendaEntry);

void insertSorted(p_d_list, p_d_cell);

int searchValueLevel0(p_d_list list, int value);

int searchValuedichotomy(p_d_list list, int value);

void displayAlignedList(p_d_list);

void displayLevelAlignedList(p_d_list list, int level);

#endif //AGENDA_LIST_H
*/