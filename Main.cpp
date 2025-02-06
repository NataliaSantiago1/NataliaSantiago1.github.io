#include <iostream>
#include "ContactService.h"

int main() {
    ContactService contactService;
    int choice;

    do {
        std::cout << "\n===== Contact Management System =====\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Delete Contact\n";
        std::cout << "3. Update Contact\n";
        std::cout << "4. Search Contact\n";
        std::cout << "5. Show All Contacts\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            contactService.addContactMenu();
            break;
        case 2:
            contactService.deleteContactMenu();
            break;
        case 3:
            contactService.updateContactMenu();
            break;
        case 4:
            contactService.searchContactMenu();
            break;
        case 5:
            contactService.displayAllContacts();
            break;
        case 6:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
