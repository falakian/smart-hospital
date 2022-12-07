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
bool List::remove(const Patient& toBeRemoved){
    if(head == nullptr){
        cout << "cant delete!!!" << endl;
        return false;
    }
    Node* nd = new Node(toBeRemoved);
    Node* tmpb;
    Node* tmp = this->head;
    while(tmp != nullptr){
        if(tmp->getData() == nd->getData()){
            break;
        }
        tmpb = tmp;
        tmp = tmp->getNext();
    }
    Node *komaki;
    if(tmp == head){
        komaki = head->getNext();
        head->setNext(nullptr);
        head = komaki;
    }
    else{
        komaki = tmpb->getNext()->getNext();
        tmpb->getNext()->setNext(nullptr);
        tmpb->setNext(komaki);
    }
    this->elementCount--;
    return true;
}
Patient* List::search(const Patient& target){
    Node* nd = new Node(target);
    Node* tmp = this->head;
    while(tmp != nullptr){
        if(tmp->getData() == nd->getData()){
            break;
        }
        tmp = tmp->getNext();
    }
    Patient *pt = new Patient(tmp->getData());
    return pt;
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
