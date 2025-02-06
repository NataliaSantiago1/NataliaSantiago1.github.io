#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <stdexcept>  // For std::invalid_argument

class Contact {
public:
    // Default constructor
    Contact();

    // Parameterized constructor
    Contact(std::string contactID, std::string firstName, std::string lastName, std::string phone, std::string address);

    // Getters
    std::string getContactID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhone() const;
    std::string getAddress() const;

    // Setters
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPhone(const std::string& phone);
    void setAddress(const std::string& address);

private:
    std::string contactID;
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::string address;
};

#endif // CONTACT_H
