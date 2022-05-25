// c libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// libcal libraries
#include "libical/ical.h"

// calendar header
#include "calendar.h"

// calendar functions

// Creates an new calendar, and returns a calendar struct
calendar*  new_calendar_from_file(char* filename) {
    // allocate memory for the calendar
    calendar* cal = malloc(sizeof(calendar));

    // open the file
    FILE* file = fopen(filename, "r");

    // read the file
    char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
    fread(buffer, sizeof(char), BUFFER_SIZE, file);

    // close the file
    fclose(file);

    // create the calendar
    cal->cal = icalcomponent_new_from_string(buffer);

    // free the buffer
    free(buffer);

    // return the calendar
    return cal;
}

// Frees the calendar struct and all its components
void free_calendar(calendar* cal) {
    icalcomponent_free(cal->cal);
    free(cal);
}

// insert an event into the calendar
void insert_event(calendar* cal, char* event_name, char* event_description, char* event_location, char* event_start, char* event_end) {
    // create the event
    icalcomponent* event = icalcomponent_new(ICAL_VEVENT_COMPONENT);
    icalcomponent_add_property(event, icalproperty_new_summary(event_name));
    icalcomponent_add_property(event, icalproperty_new_description(event_description));
    icalcomponent_add_property(event, icalproperty_new_location(event_location));
    icalcomponent_add_property(event, icalproperty_new_dtstart(icaltime_from_string(event_start)));
    icalcomponent_add_property(event, icalproperty_new_dtend(icaltime_from_string(event_end)));
    icalcomponent_add_component(cal->cal, event);
}

// remove an event from the calendar
void remove_event(calendar* cal, char* event_name) {
    // get the event
    icalcomponent* event = icalcomponent_get_first_component(cal->cal, ICAL_VEVENT_COMPONENT);
    while (event != NULL) {
        // get the summary
        icalproperty* summary = icalcomponent_get_first_property(event, ICAL_SUMMARY_PROPERTY);
        char* summary_value = icalproperty_get_value_as_string(summary);

        // check if the summary matches
        if (strcmp(summary_value, event_name) == 0) {
            // remove the event
            icalcomponent_remove_component(cal->cal, event);
            break;
        }

        // get the next event
        event = icalcomponent_get_next_component(cal->cal, ICAL_VEVENT_COMPONENT);
    }
}

// print the events
void print_events(calendar* cal) {
    // get the event
    icalcomponent* event = icalcomponent_get_first_component(cal->cal, ICAL_VEVENT_COMPONENT);
    while (event != NULL) {
        // get the summary
        icalproperty* summary = icalcomponent_get_first_property(event, ICAL_SUMMARY_PROPERTY);
        char* summary_value = icalproperty_get_value_as_string(summary);

        // get the description
        icalproperty* description = icalcomponent_get_first_property(event, ICAL_DESCRIPTION_PROPERTY);
        char* description_value = icalproperty_get_value_as_string(description);

        // get the location
        icalproperty* location = icalcomponent_get_first_property(event, ICAL_LOCATION_PROPERTY);
        char* location_value = icalproperty_get_value_as_string(location);

        // get the start time
        icalproperty* start = icalcomponent_get_first_property(event, ICAL_DTSTART_PROPERTY);
        char* start_value = icaltime_as_ical_string(icalproperty_get_dtstart(start));

        // get the end time
        icalproperty* end = icalcomponent_get_first_property(event, ICAL_DTEND_PROPERTY);
        char* end_value = icaltime_as_ical_string(icalproperty_get_dtend(end));

        // print the event
        printf("Event: %s\n", summary_value);
        printf("Description: %s\n", description_value);
        printf("Location: %s\n", location_value);
        printf("Start: %s\n", start_value);
        printf("End: %s\n", end_value);

        // get the next event
        event = icalcomponent_get_next_component(cal->cal, ICAL_VEVENT_COMPONENT);
    }
}