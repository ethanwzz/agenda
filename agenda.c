//
// Created by ethan on 10/12/2023.
//

#include "agenda.h"

// Fonction pour sécuriser l'entrée d'une valeur entre une valeur minimale et maximale
int secureInput(int minValue, int maxValue) {
    int userInput;

    do {
        printf("Veuillez entrer une valeur entre %d et %d : ", minValue, maxValue);
        scanf("%d", &userInput);

        // Nettoyer le tampon d'entrée en cas d'entrée invalide
        while (getchar() != '\n');

        // Vérifier si l'entrée est dans la plage autorisée
        if (userInput < minValue || userInput > maxValue) {
            printf("Entrée invalide. La valeur doit être entre %d et %d.\n", minValue, maxValue);
        }

    } while (userInput < minValue || userInput > maxValue);

    return userInput;
}

