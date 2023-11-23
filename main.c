#include <stdio.h>
#include "fichier.h"

int main(){
    p_d_list list = createList(3);
    displayList(list);

    insertHead(list, createCell(4, 2));
    printf("Apres insertion :\n");

    displayList(list);

    printf("Affichage d'un niveau particulier\n");
    displayLevelList(list, 3);
    printf("test de fin\n");
};