#pragma once
#include <iostream>
using namespace std;

class IntNode
{
public:
    int x;
    IntNode *next;
    IntNode();
    IntNode(int x);
};

class IntList
{
private:
    IntNode *head;
    IntNode *tail;
public:
    IntList();
    ~IntList();
    void display() const;                   //  Displays to a single line all of the int values stored in the list, each separated by a space. This function does NOT output a newline or space at the end.
    void push_front(int value);             //  Inserts a data value (within a new node) at the front end of the list.
    void pop_front();                       // Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
    bool empty() const;                     // Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
    void push_back(int value);              // Inserts a data value (within a new node) at the back end of the list.
    void clear();                           //  Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.
    IntList(const IntList &cpy);            // the copy constructor. Make sure this performs deep copy.
    IntList &operator=(const IntList &rhs); // the overloaded assignment operator. Make sure this performs deep copy.
    void insert_ordered(int value);         // Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
    void remove_duplicates();               //  Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list
    friend ostream &operator<<(ostream &out, const IntList &rhs);
};

