#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cell.h"
#include "list.h"
#include "timer.h"


void Partie1(){

    // Créer une liste vide
    printf("Affichage d'une liste vide de niveau 4 :\n");
    p_d_list list = createList(4);
    displayList(list);
    printf("\n--------------------------------------------------------------------\n\n");

    // Insérer une cellule en tête de liste
    printf("Affichage de la liste avec un maillon de niveau 2 :\n");
    insertHead(list, createCell(8, 2));
    displayList(list);
    printf("\n--------------------------------------------------------------------\n\n");

    // Insérer une cellule pour qu'elle soit triee par ordre croissant
    printf("Affichage de la liste avec plusieurs maillons :\n");
    insertSorted(list, createCell(9, 3));
    insertSorted(list, createCell(2, 1));
    insertSorted(list, createCell(18, 1));
    displayList(list);
    printf("\n--------------------------------------------------------------------\n\n");

    // Afficher la liste bien allignée
    printf("Affichage de la liste allignee avec plusieurs maillons :\n");
    displayAlignedList(list);

}

void Partie2(){
    // Creer une liste avec 2^n - 1
    printf("Creation et affichage d'une liste de (2^n) - 1 valeur :\n");
    p_d_list  list = create2Squarelist(3);
    displayAlignedList(list);
    printf("\n--------------------------------------------------------------------\n\n");

    printf("On va maintenant rechercher la valeur 7 normalement puis la valeur 8 a l'aide de la dichotomie dans cette liste :\n\n");
    int val = 7;
        if (searchValueLevel0(list, val)){
            printf("La valeur %d est dans la liste\n", val);
        } else {
            printf("La valeur %d n'est pas dans la liste\n", val);
        }
    val = 8;
    if (searchValuedichotomy(list, val)){
        printf("La valeur %d est dans la liste\n", val);
    } else {
        printf("La valeur %d n'est pas dans la liste\n", val);
    }
}


void Partie2Timer(int nMax){
    for (int n = 1; n < nMax; ++n){
        srand((time(0)));
        int randomValueToSearch = rand() % ((int)pow(2, n) - 1) + 1;
        p_d_list list = create2Squarelist(n);

        startTimer();
        for (int i = 0; i <= 1000; ++i) {
            searchValueLevel0(list, randomValueToSearch);
        }
        stopTimer();
        char *milleSimple = getTimeAsString();

        startTimer();
        for (int i = 0; i <= 10000; ++i) {
            searchValueLevel0(list, randomValueToSearch);
        }
        stopTimer();
        char *dixSimple = getTimeAsString();

        startTimer();
        for (int i = 0; i <= 100000; ++i) {
            searchValueLevel0(list, randomValueToSearch);
        }
        stopTimer();
        char *centSimple = getTimeAsString();

        startTimer();
        for (int i = 0; i <= 1000; ++i) {
            searchValuedichotomy(list, randomValueToSearch);
        }
        stopTimer();
        char *milleDicho = getTimeAsString();

        startTimer();
        for (int i = 0; i <= 10000; ++i) {
            searchValuedichotomy(list, randomValueToSearch);
        }
        stopTimer();
        char *dixDicho = getTimeAsString();

        startTimer();
        for (int i = 0; i <= 100000; ++i) {
            searchValuedichotomy(list, randomValueToSearch);
        }
        stopTimer();
        char *centDicho = getTimeAsString();

        printf("n=%d | recherche classique: 1000 : %s %s %s | dichotomy %s %s %s\n", n, milleSimple, dixSimple, centSimple, milleDicho, dixDicho, centDicho);

    }

}

int main(){
    //Partie1();

    //Partie2();

    Partie2Timer(15);

}