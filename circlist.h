#pragma once
#include <cstddef>

// a one-way circular list of nodes, each containing a double,
//  - tracks a "current" node, which node in the list we're accessing right now
//  - supports operations to
//     - insert new nodes (being placed after the current node
//       and which then become the new current node)
//     - move from the current node to the next node
//     - print the entire list content (starts with the current node and prints
//       all the way "around" the list, stopping when it comes back to current)
//     - look up the value stored in the current node
//  - note that (since the list is circular) if there is only one node in the list
//    then its next field points back to itself

class circlist {

   private:
      // internal container type for individual nodes
      struct node {
         double value;     // any real number (no vallue restriction)
         node *next;       // pointer to the next node in the list
      };

      node* current; // the node currently being accessed in the list

   public:

      // default constructor, initializes list to empty
      circlist(): current(NULL) { }

      // copy constructor, makes the new list a duplicate of the original
      circlist(const circlist &orig);

      // move constructor, moves the original list's content to this one
      circlist(circlist &&orig);

      // destructor deletes all the nodes in the list
      ~circlist();

      // append contents to end of another, e.g. L1 += L2
      circlist& operator+=(const circlist& rhs);

      // create and insert a new node with the given data value,
      //    inserting after the current node (if any)
      //    and setting the new node as current
      bool insert(double v);

      // return the value from the current node (if any)
      // returns true if successful, false if the list was empty
      bool lookup(double &v);

      // print the list contents, starting from current
      void print();

      // advance from the current item to the next one,
      //    looks up the value in the new node
      // returns true if successful, false otherwise
      bool step(double &v);

      // allow the global explore function access to the private circlist content
      friend void explore(circlist &c);
};



