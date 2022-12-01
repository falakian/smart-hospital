#include <iostream>
#include <string>
#include "List.h"
List::List(){
    this->head = nullptr;
    this->elementCount = 0;
    this->capacity = 1000;
}
int List::getElementCount() const{
    return this->elementCount;
}
bool List::insert(const Patient& newElement){
    Node *nd = new Node(newElement);
    if(this->head == nullptr){
        this->head = nd;
        this->elementCount++;
        return true;
    }
    int len = 0;
    Node* tmpb;
    Node *tmp = head;
    while(tmp != nullptr){
        if(tmp->getData() == nd->getData()){
            return false;
        }
        if(nd->getData() > tmp->getData()){
            break;
        }
        len++;
        tmpb = tmp;
        tmp = tmp->getNext();
    }
    Node *komaki;
    if(len == 0){
        komaki = head;
        head = nd;
        nd->setNext(komaki);
    }
    else{
        komaki = tmpb->getNext();
        tmpb->setNext(nd);
        nd->setNext(komaki);
    }
    this->elementCount++;
    return true;

}
void List::printList(){
    if(this->head == nullptr){
        cout << "List is empty!!!!!" << endl;
        return;
    }
    Node *tmp = head;
    while(tmp != nullptr){
        cout << tmp->getData() << endl;
        tmp = tmp->getNext();
    }
    return;
}
List::~List(){

}
