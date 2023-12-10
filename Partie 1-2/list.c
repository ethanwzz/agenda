//
// Created by ethan on 05/12/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "list.h"


p_d_list createList(int max_level){
    p_d_list newList = (p_d_list)malloc(sizeof(t_d_list));
    newList->max_level = max_level;
    newList->heads = (p_d_cell*) malloc(max_level * sizeof(p_d_cell));

    // Boucle qui créé le nombre de head correspondant au level max
    for (int i = 0; i < max_level; i++) {
        newList->heads[i] = NULL;
    }

    return newList;
}

void insertHead(p_d_list list, p_d_cell cell) {
    // Vérifie si le niveau d'une cellule par rapport à celui de la liste
    if (cell->level <= list->max_level) {
        // Parcours les niveaux de la cellule et créé les heads
        for (int i = 0; i < cell->level; i++) {
            cell->next[i] = list->heads[i];
        }
        for (int i = 0; i < cell->level; i++){
            list->heads[i] = cell;
        }
    } else {
        printf("Erreur : Le niveau de la cellule est supérieur au niveau maximum de la liste\n");
        return;
    }
}



void insertSorted(p_d_list list, p_d_cell cell) {
    if (cell->level <= list->max_level) {
        for (int i = 0; i < cell->level; i++) {
            p_d_cell current = list->heads[i];
            p_d_cell previous = NULL;

            while (current != NULL && current->value < cell->value) {
                previous = current;
                current = current->next[i];
            }

            if (previous != NULL) {
                previous->next[i] = cell;
            } else {
                list->heads[i] = cell;
            }

            cell->next[i] = current;
        }
    } else {
        printf("Erreur : Le niveau de la cellule est superieur a celui de la liste");
    }
}


p_d_list create2Squarelist(int n) {
    p_d_list list = createList(n);
    int number_of_cell = (int)pow(2, n) - 1;
    for (int i = 0; i < n; i++){
        for (int y = (int)pow(2, i); y <= number_of_cell; y+= (int)pow(2, i + 1)){
            insertSorted(list, createCell(y, i+1));
        }
    }
    return list;
}


int searchValueLevel0(p_d_list list, int value) {
    p_d_cell browse_cell = list->heads[0];

    while (browse_cell != NULL){
        if (browse_cell->value == value) {
            return 1;
        } else {
            browse_cell = browse_cell->next[0];
        }
    }
    return 0;
}


int searchValuedichotomy(p_d_list list, int value) {
    int level = list->max_level - 1;
    p_d_cell current = list->heads[level];
    p_d_cell previous = current;

    while (level >= 0) {
        // Parcours du niveau actuel
        while (current != NULL) {
            if (current->value == value) {
                // La valeur a été trouvée
                return 1;
            } else if (current->value > value) {
                // La valeur est supérieure, on passe au niveau inférieur
                break;
            }

            previous = current;
            current = current->next[level];
        }

        // Passage au niveau inférieur
        --level;

        if (level >= 0) {
            if (previous != NULL){
                current = previous->next[level];
            } else {
                current = list->heads[level];
            }
        }
    }

    // La valeur n'a pas été trouvée
    return 0;
}





//------------------------------------------------------------------------------------------//

// Fonctions d'affichages :

void displayLevelList(p_d_list list, int level){
    if (level < list->max_level){
        p_d_cell temp = NULL;
        printf("[list head_%d @-]-->", level);
        if (list->heads[level] != NULL) {
            temp = list->heads[level];
            while (temp != NULL) {
                printf("[%d|@-]-->", temp->value);
                temp = temp->next[level];
            }
            printf("NULL");
        }
        else
            printf("NULL");
    } else
        printf("Le niveau demande n'existe pas");
}



void displayList(p_d_list list){
    for (int i = 0; i < list->max_level; i++){
        displayLevelList(list, i);
        printf("\n");
    }
}

// Fonction pour imprimer un caractère plusieurs fois
void print_n_times_char(char c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
}

// Fonction pour calculer le nombre de chiffres dans un entier
int nb_digits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}


void displayLevelAlignedList(p_d_list list, int level){
    p_d_cell temp = NULL;
    p_d_cell level_0 = NULL;
    printf("[list head_%d @-]--", level);
    temp = list->heads[level];
    level_0 = list->heads[0];
    while (level_0 != NULL) {
        if (temp != level_0 || temp == NULL) {
            print_n_times_char('-', nb_digits(level_0->value)+9);
            level_0 = level_0->next[0];
        }
        else {
            printf(">[ %d|@-]--", temp->value);
            temp = temp->next[level];
            level_0 = level_0->next[0];
        }
    }
    printf(">NULL");

}

void displayAlignedList(p_d_list list){
    for (int i = 0; i < list->max_level; ++i) {
        displayLevelAlignedList(list, i);
        printf("\n");
    }
}