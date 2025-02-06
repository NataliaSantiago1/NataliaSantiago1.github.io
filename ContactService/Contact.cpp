#include "Contact.h"

// Default Constructor
Contact::Contact()
    : contactID(""), firstName(""), lastName(""), phone(""), address("") {
}

// Parameterized Constructor
Contact::Contact(std::string contactID, std::string firstName, std::string lastName, std::string phone, std::string address) {
    if (contactID.empty() || contactID.length() > 10)
        throw std::invalid_argument("Invalid contact ID");
    if (firstName.empty() || firstName.length() > 10)
        throw std::invalid_argument("Invalid first name");
    if (lastName.empty() || lastName.length() > 10)
        throw std::invalid_argument("Invalid last name");
    if (phone.empty() || phone.length() != 10)
        throw std::invalid_argument("Invalid phone number");
    if (address.empty() || address.length() > 30)
        throw std::invalid_argument("Invalid address");

    this->contactID = contactID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->phone = phone;
    this->address = address;
}

// Getters
std::string Contact::getContactID() const { return contactID; }
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getPhone() const { return phone; }
std::string Contact::getAddress() const { return address; }

// Setters
void Contact::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Contact::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Contact::setPhone(const std::string& phone) { this->phone = phone; }
void Contact::setAddress(const std::string& address) { this->address = address; }
