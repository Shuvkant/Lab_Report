#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Define the structure for account information
struct Account {
    int accountNumber;
    std::string lastName;
    std::string firstName;
    double totalBalance;
};

// Function to display an account's details
void displayAccount(const Account& account) {
    std::cout << "Account Number: " << account.accountNumber << std::endl;
    std::cout << "Last Name: " << account.lastName << std::endl;
    std::cout << "First Name: " << account.firstName << std::endl;
    std::cout << "Total Balance: $" << account.totalBalance << std::endl;
    std::cout << "-----------------------" << std::endl;
}

// Function to add a new account to the file
void addAccount(std::fstream& file, const Account& account) {
    file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
}

// Function to update an account in the file
void updateAccount(std::fstream& file, int accountNumber, const Account& updatedAccount) {
    Account account;
    while (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        if (account.accountNumber == accountNumber) {
            file.seekp(-static_cast<std::streamoff>(sizeof(Account)), std::ios::cur);
            file.write(reinterpret_cast<const char*>(&updatedAccount), sizeof(Account));
            break;
        }
    }
}

// Function to delete an account from the file
void deleteAccount(std::fstream& file, int accountNumber) {
    std::fstream tempFile("temp.txt", std::ios::out | std::ios::binary);
    if (!tempFile) {
        std::cerr << "Error creating temporary file." << std::endl;
        return;
    }

    Account account;
    while (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        if (account.accountNumber != accountNumber) {
            tempFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
        }
    }

    file.close();
    tempFile.close();
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    file.open("accounts.txt", std::ios::in | std::ios::out | std::ios::binary);
}

// Function to display all accounts in the file
void displayAllAccounts(std::fstream& file) {
    file.seekg(0, std::ios::beg);
    Account account;
    while (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        displayAccount(account);
    }
}

int main() {
    std::fstream file("accounts.txt", std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    int choice;
    do {
        std::cout << "1. Add Account\n2. Update Account\n3. Delete Account\n4. Display All Accounts\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    Account newAccount;
                    std::cout << "Enter Account Number: ";
                    std::cin >> newAccount.accountNumber;
                    std::cout << "Enter Last Name: ";
                    std::cin >> newAccount.lastName;
                    std::cout << "Enter First Name: ";
                    std::cin >> newAccount.firstName;
                    std::cout << "Enter Total Balance: ";
                    std::cin >> newAccount.totalBalance;
                    addAccount(file, newAccount);
                    std::cout << "Account added successfully." << std::endl;
                }
                break;
            case 2:
                {
                    int accountNumber;
                    std::cout << "Enter Account Number to Update: ";
                    std::cin >> accountNumber;
                    Account updatedAccount;
                    std::cout << "Enter Updated Account Information:" << std::endl;
                    std::cout << "Enter Last Name: ";
                    std::cin >> updatedAccount.lastName;
                    std::cout << "Enter First Name: ";
                    std::cin >> updatedAccount.firstName;
                    std::cout << "Enter Total Balance: ";
                    std::cin >> updatedAccount.totalBalance;
                    updateAccount(file, accountNumber, updatedAccount);
                    std::cout << "Account updated successfully." << std::endl;
                }
                break;
            case 3:
                {
                    int accountNumber;
                    std::cout << "Enter Account Number to Delete: ";
                    std::cin >> accountNumber;
                    deleteAccount(file, accountNumber);
                    std::cout << "Account deleted successfully." << std::endl;
                }
                break;
            case 4:
                std::cout << "All Accounts:" << std::endl;
                displayAllAccounts(file);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    file.close();
    return 0;
}
