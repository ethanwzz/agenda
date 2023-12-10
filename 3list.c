//
// Created by ethan on 10/12/2023.
//
/*
#include "3list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



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


int compareContacts(p_agendaEntry contact1, p_agendaEntry contact2) {
    // Concaténer les noms et prénoms pour obtenir la chaîne "nom_prenom"
    char fullname1[256];
    char fullname2[256];

    snprintf(fullname1, sizeof(fullname1), "%s_%s",
             contact1->contact->name, contact1->contact->firstname);
    snprintf(fullname2, sizeof(fullname2), "%s_%s",
             contact2->contact->name, contact2->contact->firstname);

    // Convertir les chaînes en minuscules
    for (int i = 0; fullname1[i]; i++) {
        fullname1[i] = tolower(fullname1[i]);
    }

    for (int i = 0; fullname2[i]; i++) {
        fullname2[i] = tolower(fullname2[i]);
    }

    // Utiliser strcmp pour la comparaison lexicographique
    return strcmp(fullname1, fullname2);
}


// Insérer une cellule dans l'ordre alphabétique des noms de famille
void insertInOrder(p_agendaEntry *agenda, p_agendaEntry newEntry) {
    if (*agenda == NULL || compareContacts(newEntry, *agenda) < 0) {
        // Insérer au début de la liste ou si la nouvelle entrée vient avant la première
        newEntry->next = *agenda;
        *agenda = newEntry;
    } else {
        p_agendaEntry current = *agenda;

        // Trouver l'endroit où insérer la nouvelle entrée
        while (current->next != NULL && compareContacts(newEntry, current->next) >= 0) {
            current = current->next;
        }

        // Insérer la nouvelle entrée
        newEntry->next = current->next;
        current->next = newEntry;
    }
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


void displayLevelAlignedList(p_d_list list, int level) {
    p_d_cell temp = NULL;
    p_d_cell level_0 = NULL;
    printf("[list head_%d @-]--", level);
    temp = list->heads[level];
    level_0 = list->heads[0];
    while (level_0 != NULL) {
        if (temp != level_0 || temp == NULL) {
            print_n_times_char('-', strlen(level_0->value->contact->name) + 9);
            level_0 = level_0->next[0];
        } else {
            printf(">[ %s|@-]--", temp->value->contact->name);
            temp = temp->next[level];
            level_0 = level_0->next[0];
        }
    }
    printf(">NULL");
}


void displayAlignedList(p_d_list list) {
    for (int i = 0; i < list->max_level; ++i) {
        displayLevelAlignedList(list, i);
        printf("\n");
    }
}
*/