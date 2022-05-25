#pragma once

#include "circlist.h"

// set of valid user commands
const char Quit = 'Q';
const char Lookup = 'L';
const char Help = 'H';
const char Insert = 'I';
const char Print = 'P';
const char Step = 'S';
const char Explore = 'E';


// get and return a valid command from the user (repeat until valid)
char getCommand();

// get and return an integer from the user (repeat until valid)
// if pos is true then it requires the user enter a value > 0
long getInt();

// get and return a real number from the user (repeat until valid)
double getValue();

// apply the given command to the circular list
// return true if it was a quit command, false otherwise
bool Process(char cmd, circlist &C);

// display the available user commands
void printMenu();

// a friend of circlist, can explore it's content
void explore(circlist &C);
