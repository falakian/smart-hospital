/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Author: (For you to fill)
 * Date: (For you to fill)
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the care card number which is set to "0000000000".
Patient::Patient() {
    this->CareCard = "0000000000";
    this->address = "to be entered";
    this->email = "to be entered";
    this->Name = "to be entered";
    this->phoneNum = "to be entered";


// You need to complete this method.

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
    if(aCareCard.size() == 10){
        this->CareCard = aCareCard;
    }
    else{
        this->CareCard = "0000000000";
    }
    this->address = "to be entered";
    this->email = "to be entered";
    this->Name = "to be entered";
    this->phoneNum = "to be entered";


// You need to complete this method.

}
Patient::Patient(const Patient& obj){
    this->CareCard = obj.CareCard;
    this->address = obj.address;
    this->email = obj.email;
    this->Name = obj.Name;
    this->phoneNum = obj.phoneNum;
}

// All other parameterized constructors -> You need to implement these methods.

// Getters and setters -> You need to implement these methods.
string Patient::getName() const{
    return this->Name;
}
string Patient::getAddress() const{
    return this->address;
}
string Patient::getPhone() const{
    return this->phoneNum;
}
string Patient::getEmail() const{
    return this->email;
}
string Patient::getCareCard() const{
    return this->CareCard;
}

void Patient::setName(const string aName){
    this->Name = aName;
}
void Patient::setAddress(const string anAddress){
    this->address = anAddress;
}
void Patient::setPhone(const string aPhone){
    this->phoneNum = aPhone;
}
void Patient::setEmail(const string anEmail){
    this->email = anEmail;
}


// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {

	// Compare both Patient objects
	return this->CareCard == rhs.getCareCard();

} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {

	// Compare both Patient objects
	return this->CareCard > rhs.getCareCard();

} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is < the care card
//              number of "rhs" Patient object.
bool Patient::operator < (const Patient & rhs) {

	// Compare both Patient objects
	return this->CareCard < rhs.getCareCard();

} // end of operator <

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {

	os << p.CareCard << " - Patient: " << p.Name << ", "
	   << p.address << ", " << p.phoneNum << ", " << p.email << endl;

	return os;

} // end of operator<<

// end of Patient.cpp
