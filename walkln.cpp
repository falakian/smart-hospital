#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main(){
    int choice;
    string carecard;
    List hospital;
    Patient *obj;
    bool Truee = true;
    while(Truee){
        cout << "1-add a patient \n" << "2-remove a patient \n" << "3-edit an information of patient \n" << "4-search a patient \n" << "5-remove all \n" << "6-print list of patients \n" << "7-number of Patients \n"<< "8-exit \n" << "please choose one of them: \n";
        cin >> choice;
        switch(choice){
        case 1:{
            cout << "enter a carecard number please: " << endl;
            cin >> carecard;
            int choice1;
            cout << "do you want to enter name,address,phonenumber and email??? \n" << "1-Yes \n" << "2-No \n";
            cin >> choice1;
            if(choice1 == 1){
                string name, address, phonenumber, email;
                cout << "enter a name: \n";
                cin >> name;
                cout << "enter a address: \n";
                cin >> address;
                cout << "enter a phonenumber: \n";
                cin >> phonenumber;
                cout << "enter a emailaddress: \n";
                cin >> email;
                obj = new Patient(carecard, name, address, phonenumber, email);
            }
            else{
                obj = new Patient(carecard);
            }
            if(hospital.insert(*obj)){
                cout << "add a patient is sucessfully" << endl;
            }
            else{
                cout << "patient is already existed" << endl;
            }
            break;
        }

        case 2:
            cout << "enter a carecard number please: " << endl;
            cin >> carecard;
            obj = new Patient(carecard);
            if(hospital.remove(*obj)){
                cout << "remove a patient is sucessfully" << endl;
            }
            else{
                cout << "patient is not founded" << endl;
            }
            break;
        case 3:
            cout << "enter a carecard number please: " << endl;
            cin >> carecard;
            obj = new Patient(carecard);
            if(hospital.editInf(*obj)){
                cout << "edit a patient is sucessfully" << endl;
            }
            else{
                cout << "patient is not founded" << endl;
            }
            break;
        case 4:
            cout << "enter a carecard number please: " << endl;
            cin >> carecard;
            obj = new Patient(carecard);
            if(hospital.search(*obj) != nullptr){
                cout << "patient is founded" << endl;
                cout << *(hospital.search(*obj)) << endl;
            }
            else{
                cout << "patient is not founded" << endl;
            }
            break;
        case 5:
            hospital.removeAll();
            break;

        case 6:
            if(hospital.getElementCount() != 0){
                hospital.printList();
            }
            else{
                cout << "Patient doesnt exist!!!" << endl;
            }
            break;
        case 7:
            cout << "number of patients: " << hospital.getElementCount() << endl;
            break;
        case 8:
            Truee = false;
            break;
        }


    }
    return 0;
}
