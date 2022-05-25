# Simple ics calendar
A simple calendar that functions using only an ICS file.

i'm using the libical library to interact with the ICS files, so make sure to install it before using it

## you can read about libical here:
https://github.com/libical/libical 

## and how to install it here: 
https://github.com/libical/libical/blob/3.0/Install.txt

## Build:
You can build the program using "make" not sure if it will work. the code is pretty sketchy right now 

# The ideia 
The idea is to have a fully functional calendar that only needs one file to store all your events. Using the iCalendar format I hope to be able to export all your prior events without any hiccups. the purpose of only using an ICS file is that then you will be able to synchronize your events using a program like Syncthing.

## you can read about Syncthing here:
https://github.com/syncthing/syncthing
