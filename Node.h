#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include <string>
#include "Patient.h"
using namespace std;
//this class is node of linked list
class Node{
private:
    Patient data;
    Node *next;
public:
    //this is default constructor
    Node();
    //this is Parameterized constructor
    Node(Patient ptn);
    //this is destructor
    ~Node();
    //this function returns Node's data
    Patient getData();
    //this function returns a reference of Node's data
    Patient& getDataByReference();
    //this function returns Node's next
    Node* getNext();
    //this function sets Node's next
    void setNext(Node* nxt);
};


#endif // NODE_H_INCLUDED
