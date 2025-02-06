#include "ContactService.h"
#include <iostream>
#include <fstream>
#include <json.hpp>  // For handling JSON

using json = nlohmann::json;

ContactService::ContactService() {
    loadContactsFromFile();
}

// Load contacts from the JSON file
void ContactService::loadContactsFromFile() {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        json j;
        inputFile >> j;
        for (const auto& item : j) {
            contacts.push_back(Contact(item["contactID"], item["firstName"], item["lastName"], item["phone"], item["address"]));
        }
    }
}

// Save contacts to the JSON file
void ContactService::saveContactsToFile() {
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        json j;
        for (const auto& contact : contacts) {
            j.push_back({ {"contactID", contact.getContactID()},
                         {"firstName", contact.getFirstName()},
                         {"lastName", contact.getLastName()},
                         {"phone", contact.getPhone()},
                         {"address", contact.getAddress()} });
        }
        outputFile << j.dump(4);
    }
}

// Add a new contact to the list
void ContactService::addContact(const Contact& contact) {
    contacts.push_back(contact);
    saveContactsToFile();
}

// Delete a contact from the list
void ContactService::deleteContact(const std::string& contactID) {
    auto it = std::remove_if(contacts.begin(), contacts.end(),
        [&contactID](const Contact& contact) {
            return contact.getContactID() == contactID;
        });
    contacts.erase(it, contacts.end());
    saveContactsToFile();
}

// Update an existing contact
void ContactService::updateContact(const std::string& contactID, const std::string& firstName, const std::string& lastName, const std::string& phone, const std::string& address) {
    for (auto& contact : contacts) {
        if (contact.getContactID() == contactID) {
            contact.setFirstName(firstName);
            contact.setLastName(lastName);
            contact.setPhone(phone);
            contact.setAddress(address);
            saveContactsToFile();
            break;
        }
    }
}

// Retrieve a contact by ID
Contact ContactService::getContact(const std::string& contactID) {
    for (const auto& contact : contacts) {
        if (contact.getContactID() == contactID) {
            return contact;
        }
    }
    throw std::invalid_argument("Contact not found");
}

// Display all contacts
void ContactService::displayAllContacts() {
    if (contacts.empty()) {
        std::cout << "No contacts available.\n";
    }
    else {
        for (const auto& contact : contacts) {
            std::cout << "ID: " << contact.getContactID() << ", "
                << "Name: " << contact.getFirstName() << " " << contact.getLastName() << ", "
                << "Phone: " << contact.getPhone() << ", "
                << "Address: " << contact.getAddress() << "\n";
        }
    }
}

// Menu methods for interaction with the user

void ContactService::addContactMenu() {
    std::string contactID, firstName, lastName, phone, address;
    std::cout << "Enter contact ID: ";
    std::cin >> contactID;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter phone: ";
    std::cin >> phone;
    std::cout << "Enter address: ";
    std::cin >> address;

    Contact newContact(contactID, firstName, lastName, phone, address);
    addContact(newContact);
    std::cout << "Contact added successfully!\n";
}

void ContactService::deleteContactMenu() {
    std::string contactID;
    std::cout << "Enter contact ID to delete: ";
    std::cin >> contactID;
    deleteContact(contactID);
    std::cout << "Contact deleted successfully!\n";
}

void ContactService::updateContactMenu() {
    std::string contactID, firstName, lastName, phone, address;
    std::cout << "Enter contact ID to update: ";
    std::cin >> contactID;
    std::cout << "Enter new first name: ";
    std::cin >> firstName;
    std::cout << "Enter new last name: ";
    std::cin >> lastName;
    std::cout << "Enter new phone: ";
    std::cin >> phone;
    std::cout << "Enter new address: ";
    std::cin >> address;

    updateContact(contactID, firstName, lastName, phone, address);
    std::cout << "Contact updated successfully!\n";
}

void ContactService::searchContactMenu() {
    std::string contactID;
    std::cout << "Enter contact ID to search: ";
    std::cin >> contactID;
    try {
        Contact contact = getContact(contactID);
        std::cout << "Contact found: " << contact.getFirstName() << " " << contact.getLastName() << "\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }
}
