#ifndef CALENDARLIBRARY_H
#define CALENDARLIBRARY_H
// c libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// libcal, the librarie used to interact with ics files
#include <libical/ical.h>

/*----------------- Defines -----------------*/
// buffer size
#define BUFFER_SIZE 1024

/*----------------- Structs -----------------*/
// calendar struct
typedef struct calendar {
    icalcomponent *cal;
} calendar;

/*----------- calendar functions -----------*/

// New calendar from file
calendar* new_calendar_from_file(char* filename);

// Frees the calendar struct and all its components
void free_calendar(calendar* cal);

// insert an event into the calendar
void insert_event(calendar* cal, char* event_name, char* event_description, char* event_location, char* event_start, char* event_end);

// remove an event from the calendar
void remove_event(calendar* cal, char* event_name);

// print the events
void print_events(calendar* cal);

#endif /* !CALENDARLIBRARY_H */