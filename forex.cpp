#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;

struct Currency {
    string code;
    double rateToINR;
};

Currency currencies[10] = {
    {"USD", 83.0},
    {"EUR", 90.0},
    {"GBP", 105.0},
    {"JPY", 0.55},
    {"AUD", 55.0},
    {"CAD", 60.0},
    {"CHF", 92.0},
    {"CNY", 11.5},
    {"SGD", 61.0},
    {"INR", 1.0}
};


string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

int findCurrency(string code) {
    for(int i = 0; i < 10; i++) {
        if(currencies[i].code == code)
            return i;
    }
    return -1;
}

void showRates() {
    cout << "\n--- Current Exchange Rates (Base: INR) ---\n";
    for(int i = 0; i < 10; i++) {
        cout << "1 " << currencies[i].code 
             << " = " << currencies[i].rateToINR 
             << " INR\n";
    }
}

void updateRate() {
    string code;
    double newRate;

    cout << "Enter currency code to update: ";
    cin >> code;
    code = toUpperCase(code);

    if(code == "INR") {
        cout << "INR is base currency. Its rate cannot be changed!\n";
        return;
    }

    int index = findCurrency(code);

    if(index != -1) {
        cout << "Enter new rate (1 " << code << " = ? INR): ";
        cin >> newRate;

        if(newRate <= 0) {
            cout << "Invalid rate!\n";
            return;
        }

        currencies[index].rateToINR = newRate;
        cout << "Rate updated successfully!\n";
    } else {
        cout << "Currency not found!\n";
    }
}

void saveTransaction(string from, string to, double amount, double result) {
    ofstream file("transactions.txt", ios::app);

    time_t now = time(0);
    string dt = ctime(&now);

    file << "Date: " << dt;
    file << "From: " << from << "\n";
    file << "To: " << to << "\n";
    file << "Amount: " << amount << "\n";
    file << "Converted Amount: " << result << "\n";
    file << "----------------------------------\n";

    file.close();
}

void convertCurrency() {
    string from, to;
    double amount;

    cout << "Enter FROM currency code: ";
    cin >> from;
    from = toUpperCase(from);

    cout << "Enter TO currency code: ";
    cin >> to;
    to = toUpperCase(to);

    int fromIndex = findCurrency(from);
    int toIndex = findCurrency(to);

    if(fromIndex == -1 || toIndex == -1) {
        cout << "Invalid currency code!\n";
        return;
    }

    cout << "Enter amount: ";
    cin >> amount;

    if(amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }

    
    double amountInINR = amount * currencies[fromIndex].rateToINR;
    double result = amountInINR / currencies[toIndex].rateToINR;

    cout << "\n" << amount << " " << from 
         << " = " << result << " " << to << "\n";

    saveTransaction(from, to, amount, result);
    cout << "Transaction saved successfully!\n";
}

void viewTransactions() {
    ifstream file("transactions.txt");
    string line;

    if(!file) {
        cout << "No transaction history found!\n";
        return;
    }

    cout << "\n--- Transaction History ---\n";
    while(getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Forex Simulation System =====\n";
        cout << "1. Show Exchange Rates\n";
        cout << "2. Update Exchange Rate\n";
        cout << "3. Convert Currency\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: showRates(); break;
            case 2: updateRate(); break;
            case 3: convertCurrency(); break;
            case 4: viewTransactions(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}