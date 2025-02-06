#ifndef CONTACTSERVICE_H
#define CONTACTSERVICE_H

#include <vector>
#include "Contact.h"
#include <string>
#include <iostream>
#include <fstream>
#include <json.hpp>  // Include the json library for JSON parsing

class ContactService {
public:
    // Constructor
    ContactService();

    // Methods
    void loadContactsFromFile();
    void saveContactsToFile();
    void addContact(const Contact& contact);
    void deleteContact(const std::string& contactID);
    void updateContact(const std::string& contactID, const std::string& firstName, const std::string& lastName, const std::string& phone, const std::string& address);
    Contact getContact(const std::string& contactID);
    void displayAllContacts();
    void addContactMenu();
    void deleteContactMenu();
    void updateContactMenu();
    void searchContactMenu();

private:
    std::vector<Contact> contacts;
    const std::string fileName = "contacts.json";
};

#endif // CONTACTSERVICE_H
