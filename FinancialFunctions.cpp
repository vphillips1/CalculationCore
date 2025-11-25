//
//  FinancialFunctions.cpp
//  Cis200 Project - 2
//

#include "FinancialFunctions.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

const string OUTPUT_FILENAME = "calculated-financial.txt";

static const string kDataFileName = "uncalculated-financial.txt";
static constexpr int kColsPerRow = 6;

static bool getRow(const vector<double>& params, int rowNumber, double& P, double& rPercent, double& tYears, double& nPerYear, double& col5, double& ATarget) {
    if (rowNumber < 1) return false;
    size_t start = static_cast<size_t>((rowNumber - 1) * kColsPerRow);
    if (start + kColsPerRow > params.size()) return false;

    P         = params[start + 0];
    rPercent  = params[start + 1];
    tYears    = params[start + 2];
    nPerYear  = params[start + 3];
    col5      = params[start + 4];
    ATarget   = params[start + 5];
    return true;
}

bool loadData(vector<double> &params) {
    params.clear();

    ifstream in(kDataFileName);
    if (!in) {
        cerr << "ERROR: Could not open file: " << kDataFileName << endl;
        return false;
    }

    double value;
    while (in >> value) {
        params.push_back(value);
    }

    if (params.empty()) {
        cerr << "[ERROR] No data read from file: " << kDataFileName << endl;
        return false;
    }

    if (params.size() % kColsPerRow != 0) {
        cerr << "[WARNING] Data count (" << params.size()
             << ") is not a multiple of " << kColsPerRow
             << ". Some values may be ignored by row-based operations." << endl;
    }

    cout << "[INFO] Loaded " << (params.size() / kColsPerRow) << " row(s) from " << kDataFileName << endl;
    return true;
}

void displayAvailableRows(const vector<double> &params) {
    cout << "\nAvailable Rows:" << endl;
    size_t totalRows = params.size() / kColsPerRow;
    if (totalRows == 0) {
        cout << "  (No rows loaded)" << endl;
        return;
    }

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < totalRows; ++i) {
        size_t idx = i * kColsPerRow;
        cout << "Row " << (i + 1) << ": "
             << params[idx + 0] << " "
             << params[idx + 1] << " "
             << params[idx + 2] << " "
             << params[idx + 3] << " "
             << params[idx + 4] << " "
             << params[idx + 5] << endl;
    }
}

static void appendLine(ofstream& out, const string& s) {
    out << s << '\n';
}

void calculateSimpleInterest(const vector<double> &params, int rowNumber) {
    double P, rPercent, t, n, col5, ATarget;
    if (!getRow(params, rowNumber, P, rPercent, t, n, col5, ATarget)) {
        cerr << "ERROR: Invalid row number." << endl;
        return;
    }

    double r = rPercent / 100.0;
    double I = P * r * t;
    double A = P + I;

    cout << fixed << setprecision(2);
    cout << "\n[Simple Interest] Row " << rowNumber << endl;
    cout << "Principal (P): $" << P << endl;
    cout << "Rate (r): " << rPercent << "% per year" << endl;
    cout << "Time (t): " << t << " years" << endl;
    cout << "Interest (I = P*r*t): $" << I << endl;
    cout << "Amount (A = P + I): $" << A << endl;

    ofstream out(OUTPUT_FILENAME, ios::app);
    if (!out) {
        cerr << "[ERROR] Could not open " << OUTPUT_FILENAME << " for writing." << endl;
        return;
    }
    out << fixed << setprecision(2);
    appendLine(out, "ROW " + to_string(rowNumber) + " [SIMPLE INTEREST]");
    appendLine(out, "Principal: $" + to_string(P) + " | Rate: " + to_string(rPercent) + "% | Time: " + to_string(t) + "yr");
    appendLine(out, "RESULT -> Interest: $" + to_string(I) + " | Total: $" + to_string(A));
    appendLine(out, "---------------------------------------------------");
    cout << "[Saved to " << OUTPUT_FILENAME << "]" << endl;
}

void calculateCompoundInterest(const vector<double> &params, int rowNumber) {
    double P, rPercent, t, n, col5, ATarget;
    if (!getRow(params, rowNumber, P, rPercent, t, n, col5, ATarget)) {
        cerr << "[ERROR] Invalid row number." << endl;
        return;
    }

    if (n <= 0) {
        cerr << "[ERROR] Compounds per year (n) must be > 0." << endl;
        return;
    }

    double r = rPercent / 100.0;
    double A = P * pow(1.0 + r / n, n * t);
    double CI = A - P;

    cout << fixed << setprecision(2);
    cout << "\n[Compound Interest] Row " << rowNumber << endl;
    cout << "Principal (P): $" << P << endl;
    cout << "Rate (r): " << rPercent << "% per year" << endl;
    cout << "Time (t): " << t << " years" << endl;
    cout << "Compounds per year (n): " << n << endl;
    cout << "Amount (A = P*(1 + r/n)^(n*t)): $" << A << endl;

    ofstream out(OUTPUT_FILENAME, ios::app);
    if (!out) {
        cerr << "[ERROR] Could not open " << OUTPUT_FILENAME << " for writing." << endl;
        return;
    }
    out << fixed << setprecision(2);
    appendLine(out, "ROW " + to_string(rowNumber) + " [COMPOUND INTEREST]");
    appendLine(out, "Principal: $" + to_string(P) + " | Rate: " + to_string(rPercent) + "% | Compounds/Yr: " + to_string(n));
    appendLine(out, "RESULT -> Interest: $" + to_string(CI) + " | Maturity: $" + to_string(A));
    appendLine(out, "---------------------------------------------------");
    cout << "[Saved to " << OUTPUT_FILENAME << "]" << endl;
}

void calculateRateOfReturn(const vector<double> &params, int rowNumber) {
    double P, rPercent, t, n, col5, ATarget;
    if (!getRow(params, rowNumber, P, rPercent, t, n, col5, ATarget)) {
        cerr << "[ERROR] Invalid row number." << endl;
        return;
    }

    if (P <= 0.0) {
        cerr << "[ERROR] Principal (P) must be > 0." << endl;
        return;
    }
    if (t <= 0.0) {
        cerr << "[ERROR] Time (t) must be > 0." << endl;
        return;
    }
    if (ATarget <= 0.0) {
        cerr << "[ERROR] Target/Future Value (A) must be > 0 (column 6)." << endl;
        return;
    }

    double r = pow(ATarget / P, 1.0 / t) - 1.0;
    double rPct = r * 100.0;

    cout << fixed << setprecision(4);
    cout << "\n[Annual Rate of Return] Row " << rowNumber << endl;
    cout << "Principal (P): $" << P << endl;
    cout << "Target Amount (A): $" << ATarget << endl;
    cout << "Time (t): " << t << " years" << endl;
    cout << "Annual Rate of Return (r): " << rPct << "% per year" << endl;

    // ios:app means io stream operator, append file. It keeps the existing file the same then adds on to it.
    ofstream out(OUTPUT_FILENAME, ios::app);
    if (!out) {
        cerr << "[ERROR] Could not open " << OUTPUT_FILENAME << " for writing." << endl;
        return;
    }
    out << fixed << setprecision(2);
    appendLine(out, "ROW " + to_string(rowNumber) + " [RATE OF RETURN]");
    appendLine(out, "Start: $" + to_string(P) + " | End: $" + to_string(ATarget) + " | Time: " + to_string(t) + "yr");
    out << setprecision(4);
    appendLine(out, "RESULT -> Annual Rate of Return: " + to_string(rPct) + "%");
    out << setprecision(2);
    appendLine(out, "---------------------------------------------------");
    cout << "[Saved to " << OUTPUT_FILENAME << "]" << endl;
}
