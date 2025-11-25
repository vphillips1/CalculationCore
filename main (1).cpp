//
//  main.cpp
//  Cis200 Project - 2
//
//  Created by Bre'Anna Johnston on 11/19/25.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "FinancialFunctions.h"

using namespace std;

// Function Prototypes
bool loadData(vector<double> &params);
void displayAvailableRows(const vector<double> &params);
void calculateSimpleInterest(const vector<double> &params, int rowNumber);
void calculateCompoundInterest(const vector<double> &params, int rowNumber);
void calculateRateOfReturn(const vector<double> &params, int rowNumber);

int main() {
    int calcChoice;
    int rowChoice;
    vector<double> financialParams;
    
    // Load the specific file
    if (!loadData(financialParams)) {
        return 1;
    }
    
    // Calculate how many rows of data we actually have
    int totalRows = financialParams.size() / 6;

    do {
        cout << "\n-----------------------------------------" << endl;
        cout << "   FINANCIAL CALCULATOR" << endl;
        cout << "   File: 'uncalculated-financial.txt'" << endl;
        cout << "1. Calculate Simple Interest" << endl;
        cout << "2. Calculate Compound Interest" << endl;
        cout << "3. Calculate Annual Rate of Return" << endl;
        cout << "4. Reload File Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Select Calculation Type (1-5): ";
        cin >> calcChoice;

        if (calcChoice == 5) break;
        if (calcChoice == 4)
        {
            loadData(financialParams);
            totalRows = financialParams.size() / 6; // Update row count
            continue;
        }
        if (calcChoice < 1 || calcChoice > 5) {
            cout << "Invalid choice." << endl;
            continue;
        }

        // Show file data
        displayAvailableRows(financialParams);
        
        cout << "\nWhich row do you want to calculate? (1-" << totalRows << "): ";
        cin >> rowChoice;

        // Check if row exists
        if (rowChoice < 1 || rowChoice > totalRows) {
            cout << "[ERROR] Invalid Row Number. Please try again." << endl;
        } else {
            // Perform the specific calculation on the specific row
            switch (calcChoice) {
                case 1:
                    calculateSimpleInterest(financialParams, rowChoice);
                    break;
                case 2:
                    calculateCompoundInterest(financialParams, rowChoice);
                    break;
                case 3:
                    calculateRateOfReturn(financialParams, rowChoice);
                    break;
            }
        }

    } while (calcChoice != 5);

    return 0;
}


