#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include <string>
#include "Patient.h"
using namespace std;
class Node{
private:
    Patient data;
    Node *next;
public:
    Node();
    Node(Patient ptn);
    ~Node();
    Patient getData();
    Node* getNext();
    //void setData(const Patient ptn);
    void setNext(Node* nxt);
};


#endif // NODE_H_INCLUDED
