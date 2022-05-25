#include "lab5.h"
#include <iostream>

int main()
{
   circlist C1;
   bool done = false;
   do {
      char cmd = getCommand();
      done = Process(cmd, C1);
   } while (!done);

   // extra demo section 1
   std::cout << std::endl;
   std::cout << "Using copy constructor to make a copy of the list" << std::endl;
   circlist C2(C1);
   std::cout << "Stepping in the copy, see if they are in different spots after" << std::endl;
   double v;
   C2.step(v);
   std::cout << "Original:" << std::endl;
   C1.print();
   std::cout << "New copy:" << std::endl;
   C2.print();

   // extra demo section 2
   std::cout << std::endl;
   std::cout << "Using += to insert contents of original (again) into copy" << std::endl;
   C2 += C1;
   std::cout << "Original:" << std::endl;
   C1.print();
   std::cout << "Revised copy:" << std::endl;
   C2.print();

}

// constants for user commands were
//     Quit, Lookup, Help, Insert, Print, Step, Explore
char getCommand()
{
   char cmd;
   bool quit = false;
   do {
      std::cout << std::endl;
      std::cout << "Enter a command (one of ILPQSE or H for help): ";
      std::cin >> cmd;
      cmd = toupper(cmd);
      switch (cmd) {
         case Lookup:
         case Help:
         case Insert:
         case Print:
         case Step:
         case Explore:
         case Quit:
            quit = true;
            break;
         default:
            std::cerr << "That was not a valid command, please try again" << std::endl;
      }
   } while (!quit);
   return cmd;
}

// get and return an integer from the user (repeat until valid)
long getInt()
{
   long userVal = 0;
   bool quit = false;
   std::cout << "Please enter an integer" << std::endl;
   do {
      std::cin >> userVal;
      if (std::cin.fail()) {
          std::cin.clear();
          std::string junk;
          std::cin >> junk;
          std::cerr << "Error: " << junk << " is not a valid integer, please try again";
          std::cerr << std::endl;
      } else {
          quit = true;
      }
   } while (!quit);
   return userVal;
}

// get and return a real number from the user (repeat until valid)
double getValue()
{
   double userVal = 0;
   bool quit = false;
   std::cout << "Please enter a number" << std::endl;
   do {
      std::cin >> userVal;
      if (std::cin.fail()) {
          std::cin.clear();
          std::string junk;
          std::cin >> junk;
          std::cerr << "Error: " << junk << " is not a valid number, please try again";
          std::cerr << std::endl;
      } else {
          quit = true;
      }
   } while (!quit);
   return userVal;
}

// apply the given command to the circular list
// return true if it was a quit command, false otherwise
bool Process(char cmd, circlist &C)
{
   double value;
   switch (cmd) {
      case Insert:
         std::cout << "First we will get the value you wish to insert" << std::endl;
         value = getValue();
         if (C.insert(value)) {
            std::cout << "The data was successfully updated" << std::endl;
         } else {
            std::cout << "The attempted insert was unsuccessful" << std::endl;
         }
         break;

      case Lookup:
         if (C.lookup(value)) {
            std::cout << "The current data is: " << value << std::endl;
         } else {
            std::cout << "No current data" << std::endl;
         }
         break;

      case Explore:
         explore(C);
         break;

      case Step:
         if (C.step(value)) {
            std::cout << "Advanced to element " << value << std::endl;
         } else {
            std::cout << "No current elements to step through" << std::endl;
         }
         break;

      case Help:
         printMenu();
         break;

      case Print:
         C.print();
         break;

      case Quit:
         std::cout << "Bye!" << std::endl;
         return true;
         break;

      default:
         std::cerr << "Error: given invalid command to process, " << cmd << std::endl;
         break;
   }
   return false; // true results returned directly from quit case
}

void printMenu()
{
   std::cout << "The available commands are:" << std::endl;
   std::cout << "   " << Help << " to print this menu" << std::endl;
   std::cout << "   " << Insert << " to insert a value" << std::endl;
   std::cout << "   " << Print << " to print the list content" << std::endl;
   std::cout << "   " << Lookup << " to lookup the value of the current item" << std::endl;
   std::cout << "   " << Step << " to step to the next item in the list" << std::endl;
   std::cout << "   " << Explore << " to run the explore function on the list" << std::endl;
   std::cout << "   " << Quit << " to quit the program" << std::endl;
}

void explore(circlist &C)
{
   std::cout << "Demonstrating we have access to the circlist private info:" << std::endl;
   if (C.current == NULL) {
      std::cout << "The current field is null" << std::endl;
   } else {
      std::cout << "The value in the current node is " << C.current->value << std::endl;
   }
}

