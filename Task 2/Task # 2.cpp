#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact {
public:
    string firstName;
    string lastName;
    string phoneNumber;
};


void addContact(vector<Contact> &contacts) {
    Contact newContact;
    cout << "Enter first name: ";
    getline(cin, newContact.firstName);
    
    cout << "Enter last name: ";
    getline(cin, newContact.lastName);

    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);

    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}


void viewContacts(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display." << endl;
        return;
    }

    cout << "List of Contacts:" << endl;
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". " << contacts[i].firstName << " " << contacts[i].lastName 
             << " - " << contacts[i].phoneNumber << endl;
    }
}


void deleteContact(vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts to delete." << endl;
        return;
    }

    int index;
    cout << "Enter the number of the contact to delete: ";
    while (!(cin >> index) || index < 1 || index > contacts.size()) {
        
        cout << "Invalid contact number. Please enter a valid number: ";
    }

    contacts.erase(contacts.begin() + index - 1);
    cout << "Contact deleted successfully!" << endl;
}

int main() {
    vector<Contact> contacts; // Vector to store contacts
    int choice; 

    do {
        
        cout << "\nContact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        // Validate input for menu choice
        while (!(cin >> choice) || choice < 1 || choice > 4) {

            cout << "Wrong input. Please enter a number between 1 and 4: ";
        }

        cin.ignore(); 

        switch (choice) {
            case 1:
                addContact(contacts); // Calling the function to add contact
                break;
            case 2:
                viewContacts(contacts); // Calling the function to view contacts
                break;
            case 3:
                deleteContact(contacts); // Calling the function to delete contact
                break;
            case 4:
                cout << "Exiting the program" << endl; // Use to exit the message
                break;
            default:
                cout << "Wrong choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
