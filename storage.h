//
// Created by ethan on 09/12/2023.
//

#ifndef AGENDA_STORAGE_H
#define AGENDA_STORAGE_H

// Définition des structures :

typedef struct s_contact{
    char *name;
    char *firstname;
}t_contact, *p_contact;

typedef struct s_date{
    int day;
    int month;
    int year;
}t_date, *p_date;

typedef struct s_time{
    int hours;
    int minutes;
}t_time, *p_time;

typedef struct s_appointment{
    t_date date;
    t_time time;
    t_time duration;
    char *topic;
}t_appointment, *p_appointment;

typedef struct s_agendaEntry {
    struct s_contact *contact;
    t_appointment *appointments;
    struct s_agendaEntry *next;
} t_agendaEntry, *p_agendaEntry;

// Prototypes :

char *scanString(void);

p_contact createContact(char *, char *);

p_date createDate(int day, int month, int year);

p_time createTime(int hours, int minutes);

p_appointment createAppointment(t_date date, t_time time, t_time duration, char *topic);

p_agendaEntry createAgendaEntry(p_contact contact, p_appointment appointment);


int compareDates(t_date, t_date);

#endif //AGENDA_STORAGE_H