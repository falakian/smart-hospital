#include <iostream>
#include <string>
#include "Node.h"


Node::Node():data(){
    this->next = nullptr;

}
Node::Node(Patient ptn){
    this->data = ptn;
    this->next = nullptr;
}
Node::~Node(){
    this->next = nullptr;
}
Patient Node::getData(){
    return data;
}
Patient& Node::getDataByReference(){
    return data;
}
Node* Node::getNext(){
    return this->next;
}
//void Node::setData(const Patient ptn){
    //this->data = ptn;
//}
void Node::setNext(Node* nxt){
    this->next = nxt;
}
