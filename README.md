# Forex Simulation System (C++)

A menu-driven Currency Exchange and Forex Simulation system developed in C++.  
This project simulates real-world forex operations including currency rate management, exchange calculation, and transaction logging using file handling.

---

## Project Overview

The Forex Simulation System is a console-based application that allows users to:

- View exchange rates
- Update currency rates (except base currency)
- Convert one currency into another
- Store transaction history in a file
- View past transaction records

The system uses INR (Indian Rupee) as the base currency for internal calculations.

---

## Features

### 1. Currency Rate Management

- Predefined 10 international currencies.
- Exchange rates stored relative to INR.
- Users can update exchange rates manually.
- Base currency (INR) is protected from modification.
- Input is case-insensitive (e.g., usd, Usd, USD are all valid).

### 2. Currency Exchange Calculation

- Converts between any two supported currencies.
- Uses INR as an internal bridge currency.
- Validates currency codes.
- Validates positive input amount.
- Ensures accurate conversion logic.

### 3. Transaction Logging

- Every conversion is saved to a file named `transactions.txt`
- Stored details include:
  - Date and time
  - Source currency
  - Target currency
  - Entered amount
  - Converted amount
- Users can view complete transaction history.

---

## Supported Currencies

The system currently supports the following currencies:

- USD (US Dollar)
- EUR (Euro)
- GBP (British Pound)
- JPY (Japanese Yen)
- AUD (Australian Dollar)
- CAD (Canadian Dollar)
- CHF (Swiss Franc)
- CNY (Chinese Yuan)
- SGD (Singapore Dollar)
- INR (Indian Rupee – Base Currency)

---

## Conversion Logic

The system uses INR as a base currency for internal computation.

### Conversion Formula

**Step 1: Convert source currency to INR**
amountInINR = amount × rateToINR


**Step 2: Convert INR to target currency**


result = amountInINR ÷ rateToINR


This ensures that any currency can be exchanged with any other supported currency.

---

## File Handling

The application uses:

- `ofstream` for writing transaction data
- `ifstream` for reading transaction history

Transactions are appended to the file to preserve history across program executions.

---

## Code Structure

### Headers Used

- `<iostream>` – Input and output operations  
- `<fstream>` – File handling  
- `<ctime>` – Date and time logging  
- `<algorithm>` – Used for `transform()` function  

### Key Components

- `struct Currency` – Stores currency code and rate  
- `toUpperCase()` – Makes input case-insensitive  
- `findCurrency()` – Searches currency in array  
- `showRates()` – Displays all exchange rates  
- `updateRate()` – Updates exchange rate  
- `convertCurrency()` – Performs currency conversion  
- `saveTransaction()` – Logs transaction into file  
- `viewTransactions()` – Displays transaction history  
- `main()` – Menu-driven control flow  

---

## How to Compile and Run

### Using g++

Compile:


g++ forex.cpp -o forex


Run (Linux/Mac):


./forex


Run (Windows):


forex.exe


---

## Example Usage

1. Select option `3` (Convert Currency)
2. Enter source currency (e.g., USD)
3. Enter target currency (e.g., EUR)
4. Enter amount
5. Conversion result is displayed and saved automatically

---

## Validation and Error Handling

- Invalid currency codes are rejected.
- Negative or zero amounts are rejected.
- Base currency (INR) cannot be modified.
- File existence is checked before reading.

---

## Conclusion

This project successfully simulates a basic Forex Exchange System using core C++ concepts including structures, arrays, file handling, input validation, and menu-driven programming.

It is suitable for academic case studies related to currency exchange and financial system simulations.

---

**Made by Daksh Ranjan Srivastava**
