//
// Created by ethan on 09/12/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "storage.h"


// Fonction pour saisir une chaîne de caractères dynamique depuis l'entrée standard
char *scanString(void) {
    int bufferSize = 10;
    char *buffer = (char *)malloc(bufferSize);

    int index = 0;
    char caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
        if (index == bufferSize - 1) {
            bufferSize *= 2;
            buffer = realloc(buffer, bufferSize);
        }
        buffer[index++] = caractere;
    }

    buffer[index] = '\0';

    return buffer;
}

// Fonction pour créer un contact
p_contact createContact(char *name, char *firstname) {
    p_contact newContact = malloc(sizeof(t_contact));

    // Allouer de la mémoire pour les chaînes de caractères
    newContact->name = strdup(name);
    newContact->firstname = strdup(firstname);

    if (newContact->name == NULL || newContact->firstname == NULL) {
        fprintf(stderr, "Erreur, il faut remplir un nom et un prénom\n");
        exit(EXIT_FAILURE);
    }

    return newContact;
}

p_date createDate(int day, int month, int year) {
    p_date newDate = malloc(sizeof(t_date));

    newDate->day = day;
    newDate->month = month;
    newDate->year = year;

    return newDate;
}

p_time createTime(int hours, int minutes) {
    p_time newTime = malloc(sizeof(t_time));

    newTime->hours = hours;
    newTime->minutes = minutes;

    return newTime;
}

p_appointment createAppointment(t_date date, t_time time, t_time duration, char *topic){
    p_appointment newAppointment = malloc(sizeof(t_appointment));

    newAppointment->date = date;
    newAppointment->time = time;
    newAppointment->duration = duration;
    newAppointment->topic = topic;

    return newAppointment;
}

p_agendaEntry createAgendaEntry(p_contact contact, p_appointment appointment){
    p_agendaEntry newEntry = (p_agendaEntry)malloc(sizeof(t_agendaEntry));

    newEntry->contact = contact;
    newEntry->appointments = appointment;
    newEntry->next = NULL;

    return newEntry;
}

int compareDates(t_date date, t_date other) {
    if (date.year != other.year) {
        return date.year > other.year;
    }
    if (date.month != other.month) {
        return date.month > other.month;
    }
    return date.day > other.day;
}
