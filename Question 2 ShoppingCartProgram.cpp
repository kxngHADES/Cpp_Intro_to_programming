#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase. To make it so that the users input is case insensitive for items
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return tolower(c); }); 
    return lowerStr;
}

int main() {
    // 1. Initialize Program Data
    map<string, double> items = {
        {"apple", 3.0},
        {"banana", 2.0},
        {"orange", 4.0},
        {"milk", 10.0},
        {"bread", 15.0}
    };

    const double discount_threshold = 200.0;
    const double discount_rate = 0.05;
    vector<pair<string, int>> cart; // Vector to store item name and quantity

    // 2. Prompt User for Input
    string firstName, surname;
    cout << "Enter your first name: ";
    getline(cin, firstName);
    cout << "Enter your surname: ";
    getline(cin, surname);

    cout << "Available items:\n";
    for (const auto& item : items) {
        cout << item.first << " - R" << item.second << endl;
    }

    // 3. Select item and Quantity
    string itemName;
    int quantity;
    char addMore;

    do {
        cout << "Enter the item you want to purchase: ";
        getline(cin, itemName);

        // Convert user input to lowercase
        itemName = toLowerCase(itemName);

        if (items.find(itemName) == items.end()) {
            cout << "Item not found. Please select from the available items.\n";
            continue; // Skip to the next loop iteration
        }

        cout << "Enter quantity: ";
        cin >> quantity;
        cin.ignore(); // Ignore the newline character after integer input

        if (quantity <= 0) {
            cout << "Quantity must be positive. Please enter again.\n";
            continue; // Skip to the next loop iteration
        }

        cart.push_back(make_pair(itemName, quantity));

        cout << "Do you want to add another item? (y/n): ";
        cin >> addMore;
        cin.ignore(); // Ignore the newline character
    } while (addMore == 'y' || addMore == 'Y');

    // 4. Calculate Total Cost
    double total = 0.0;

    for (const auto& entry : cart) {
        string name = entry.first;
        int qty = entry.second;
        total += items[name] * qty;
    }

    // 5. Apply Discount IF requirement is met
    double discountAmount = 0.0;
    double finalAmount;

    if (total > discount_threshold) {
        discountAmount = total * discount_rate;
        finalAmount = total - discountAmount;
    }
    else {
        finalAmount = total;
    }

    // 6. Output Final Bill
    cout << fixed << setprecision(2); // Set precision for currency
    cout << "\n--- Final Bill ---\n";
    cout << "Customer Name: " << firstName << " " << surname << endl;
    cout << "Items Purchased:\n";
    for (const auto& entry : cart) {
        cout << entry.first << " x " << entry.second << " - R" << items[entry.first] * entry.second << endl;
    }
    cout << "Total Cost: R" << total << endl;
    cout << "Discount Amount: R" << discountAmount << endl;
    cout << "Final Amount: R" << finalAmount << endl;

    // 7. Save Bill to Text File with date
    // Get current date
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t); // Use localtime_s to get the current time safely

    // Create date string in the format YYYY-MM-DD
    stringstream dateStream;
    dateStream << (now.tm_year + 1900) << "-"
        << setw(2) << setfill('0') << (now.tm_mon + 1) << "-"
        << setw(2) << setfill('0') << now.tm_mday;

    string date = dateStream.str();

    // Format the filename as name-surname-date.txt
    string filename = firstName + "-" + surname + "-" + date + ".txt";

    ofstream billFile(filename, ios::app);
    if (billFile.is_open()) {
        billFile << "Customer Name: " << firstName << " " << surname << endl;
        billFile << "Items Purchased:\n";
        for (const auto& entry : cart) {
            billFile << entry.first << " x " << entry.second << " - R" << items[entry.first] * entry.second << endl;
        }
        billFile << "Total Cost: R" << total << endl;
        billFile << "Discount Amount: R" << discountAmount << endl;
        billFile << "Final Amount: R" << finalAmount << endl;
        billFile << "-------------------------\n";
        billFile.close();
    }
    else {
        cout << "Unable to open file for writing.\n";
    }

}
