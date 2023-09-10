#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// Define a struct to represent an item in the invoice
struct InvoiceItem {
    std::string name;
    int quantity;
    double price;
};

// Function to generate and display the bill invoice
void generateInvoice(const std::vector<InvoiceItem>& items) {
    // Set up the header
    std::cout << std::left << std::setw(20) << "Item Name" << std::setw(10) << "Quantity" << std::setw(10) << "Price" << std::setw(15) << "Total" << std::endl;
    std::cout << std::setfill('-') << std::setw(55) << "" << std::setfill(' ') << std::endl;

    // Calculate and display the items and totals
    double totalAmount = 0.0;
    for (const auto& item : items) {
        double itemTotal = item.quantity * item.price;
        std::cout << std::left << std::setw(20) << item.name << std::setw(10) << item.quantity << std::fixed << std::setprecision(2) << std::setw(10) << item.price << std::setw(15) << itemTotal << std::endl;
        totalAmount += itemTotal;
    }

    // Display the total amount
    std::cout << std::setfill('-') << std::setw(55) << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(45) << "Total Amount" << std::fixed << std::setprecision(2) << std::setw(10) << totalAmount << std::endl;
}

int main() {
    // Create sample invoice items
    std::vector<InvoiceItem> items;
    items.push_back({"Item 1", 3, 10.50});
    items.push_back({"Item 2", 2, 25.75});
    items.push_back({"Item 3", 5, 5.99});

    // Display the bill invoice with different formatting
    std::cout << "Default Formatting:" << std::endl;
    generateInvoice(items);

    std::cout << "\nUsing Fixed Notation:" << std::endl;
    std::cout << std::fixed;
    generateInvoice(items);

    std::cout << "\nUsing Scientific Notation:" << std::endl;
    std::cout << std::scientific;
    generateInvoice(items);

    return 0;
}
