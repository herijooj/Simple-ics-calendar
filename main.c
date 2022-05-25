// c libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// libcal libraries
#include "libical/ical.h"

// calendar header
#include "calendar.h"

// main function
int main(int argc, char** argv) {
    
    // create the calendar with the given file
    calendar* cal = new_calendar_from_file("sample.ics");

    // print the events
    print_events(cal);

    // free the calendar
    free_calendar(cal);

    return 0;
}
