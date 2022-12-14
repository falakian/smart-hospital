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
    if(tmp == nullptr){
        return false;
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
    if(tmp == nullptr){
        return nullptr;
    }
    Patient *pt = new Patient(tmp->getData());
    return pt;
}
bool List::editInf(const Patient& target){
    Node* nd = new Node(target);
    Node* tmp = this->head;
    while(tmp != nullptr){
        if(tmp->getData() == nd->getData()){
            break;
        }
        tmp = tmp->getNext();
    }
    if(tmp == nullptr){
        return false;
    }
    int n;
    string s;
    bool isTrue = true;
    while(isTrue){
        cout << "1-change name \n" << "2-change address \n" << "3-change phonenumber \n" << "4-change emailaddress \n" << "5-exit \n" << "please choose one of them \n";
        cin >> n;
        switch(n){
        case 1:
            cout << "enter a new name: \n";
            cin >> s;
            tmp->getDataByReference().setName(s);
            break;
        case 2:
            cout << "enter a new address: \n";
            cin >> s;
            tmp->getDataByReference().setAddress(s);
            break;
        case 3:
            cout << "enter a new phonenumber: \n";
            cin >> s;
            tmp->getDataByReference().setPhone(s);
            break;
        case 4:
            cout << "enter a new emailaddress: \n";
            cin >> s;
            tmp->getDataByReference().setEmail(s);
            break;
        case 5:
            isTrue = false;
            break;
        }
    }
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
void List::removeAll(){
    Node* komaki;
    Node* tmp = this->head;
    while(tmp != nullptr){
        komaki = tmp->getNext();
        delete tmp;
        tmp = komaki;
    }
    this->elementCount = 0;
}
List::~List(){
    Node* tmp = this->head;
    while (tmp != nullptr) {
        Node* tmp2 = tmp->getNext();
        delete tmp;
        tmp = nullptr;
        tmp = tmp2;
    }
}
