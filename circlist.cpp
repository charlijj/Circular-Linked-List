/*
Jasper Charlinski
658366497
*/

#include "circlist.h"
#include <iostream>


circlist::~circlist(){

    if (current != NULL) {

        node * tmpNode = current;

        do 
        {
            node * n = tmpNode;
            tmpNode = tmpNode->next;
            delete n;
    
        }while (tmpNode != current);
    }

    return;
}


circlist::circlist(const circlist &orig)
{

    
    if (orig.current != NULL)
    {
        node * tmpNode = orig.current;

        // Node to be made the new current
        node * newCurrent = new node;
        newCurrent->value = tmpNode->value;
        newCurrent->next = newCurrent;
        current = newCurrent;

        // For each node in the original list
        tmpNode = tmpNode->next;
        while (tmpNode != orig.current)
        {
            // Make a new node
            node * newNode = new node;
            // Copy the value over
            newNode->value = tmpNode->value;
            tmpNode = tmpNode->next;
            newNode->next = current;
            // Set new node as currant
            newCurrent->next = newNode;
            newCurrent = newNode;
        }

    }
    else
    {
        std::cerr << "Error: Cannot copy list since list is empty" << std::endl;
    }

}


circlist::circlist(circlist &&orig)
{
    current = orig.current;
    orig.current = NULL;
}

circlist& circlist::operator+=(const circlist& rhs)
{

    if (rhs.current != NULL)
    {
         // New list to store revised copy
        circlist NewC;

        node * tmpNode = rhs.current;

        // For each element in the rhs list
        do
        {
            // Insert a new node with the rhs's current value
            insert(tmpNode->value);

            tmpNode = tmpNode->next;


        }while(tmpNode != rhs.current);
        

        return * this;

    }
    else
    {
        std::cerr << "Error: Cannot append list since list is empty" << std::endl;
        return * this;
    }
}


bool circlist::insert(double v)
{
    node * n = new node;

    if (n == NULL)
    {
        return false;
    }
    // If list is empty
    if (current == NULL)
    {
        current = n;
        n->next = current;
        current->next = n;
        n->value = v;
        return true;
    }
    else
    {
        n->next = current->next;
        current->next = n;
        current = n;
        n->value = v;
        return true;
    }
}


bool circlist::lookup(double &v)
{
    if (current != NULL)
    {
        v = current->value;
        return true;
    }

    return false;
}


void circlist::print()
{

    if (current == NULL)
    {
        std::cout << "List is empty" << std::endl;
       
    }

    else
    {
         node * tmpNode = current;

        do
        {
            std::cout << current->value << std::endl;
            current = current->next;

        }while (current != tmpNode); 
    }

}


bool circlist::step(double &v)
{
    if (current != NULL)
    {
        current = current->next;

        if (lookup(v))
        {
            return true;
        }
    }

    return false;
}

