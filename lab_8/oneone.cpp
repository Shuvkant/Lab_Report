#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

struct DepartmentStore {
    string name;
    vector<Product> products;
    
    void generateInvoice() {
        cout << "Department Store: " << name << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(15) << "Product" << setw(10) << "Price" << setw(10) << "Quantity" << setw(12) << "Total" << endl;
        cout << "-----------------------------------" << endl;
        
        double grandTotal = 0.0;
        
        for (const auto& product : products) {
            double total = product.price * product.quantity;
            grandTotal += total;
            
            cout << left << setw(15) << product.name << setw(10) << fixed << setprecision(2) << product.price
                 << setw(10) << product.quantity << setw(12) << total << endl;
        }
        
        cout << "-----------------------------------" << endl;
        cout << right << setw(36) << "Grand Total: " << setw(12) << fixed << setprecision(2) << grandTotal << endl;
    }
};

int main() {
    DepartmentStore store;
    store.name = "My Department Store";
    
    store.products.push_back({"Product 1", 10.50, 2});
    store.products.push_back({"Product 2", 15.25, 3});
    store.products.push_back({"Product 3", 7.80, 1});
    
    store.generateInvoice();
    
    return 0;
}