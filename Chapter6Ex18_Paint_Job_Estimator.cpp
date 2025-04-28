#include <iostream>
#include <iomanip>
#include <cmath> // For ceil
using namespace std;

// Function prototypes
int getNumberOfRooms();
double getSquareFeet(int roomNumber);
double getPaintPrice();
int calculateGallons(double totalSquareFeet);
double calculateLaborHours(double totalSquareFeet);
double calculatePaintCost(int gallons, double pricePerGallon);
double calculateLaborCharges(double laborHours);
void displayResults(int gallons, double laborHours, double paintCost, double laborCharges, double totalCost);
bool askToRepeat();

int main() {
    do {
        // Input Phase
        int rooms = getNumberOfRooms();
        double totalSquareFeet = 0.0;

        for (int i = 1; i <= rooms; i++) {
            totalSquareFeet += getSquareFeet(i);
        }

        double pricePerGallon = getPaintPrice();

        // Calculation Phase
        int gallonsNeeded = calculateGallons(totalSquareFeet);
        double laborHours = calculateLaborHours(totalSquareFeet);
        double paintCost = calculatePaintCost(gallonsNeeded, pricePerGallon);
        double laborCharges = calculateLaborCharges(laborHours);
        double totalCost = paintCost + laborCharges;

        // Output Phase
        displayResults(gallonsNeeded, laborHours, paintCost, laborCharges, totalCost);

    } while (askToRepeat());

    return 0;
}

// Get number of rooms (must be 1 or more)
int getNumberOfRooms() {
    int rooms;
    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;

    while (cin.fail() || rooms < 1) {
        cout << "ERROR: Please enter an integer 1 or greater: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> rooms;
    }
    return rooms;
}

// Get square footage for a specific room (must be 0 or more)
double getSquareFeet(int roomNumber) {
    double squareFeet;
    cout << "Enter the square feet of wall space for room " << roomNumber << ": ";
    cin >> squareFeet;

    while (cin.fail() || squareFeet < 0) {
        cout << "ERROR: Please enter a valid non-negative number: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> squareFeet;
    }
    return squareFeet;
}

// Get price per gallon of paint (must be $10.00 or more)
double getPaintPrice() {
    double price;
    cout << "Enter the price of the paint per gallon: ";
    cin >> price;

    while (cin.fail() || price < 10.00) {
        cout << "ERROR: Please enter a valid price ($10.00 or higher): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> price;
    }
    return price;
}

// Calculate number of gallons needed (round up)
int calculateGallons(double totalSquareFeet) {
    return static_cast<int>(ceil(totalSquareFeet / 110.0));
}

// Calculate hours of labor needed
double calculateLaborHours(double totalSquareFeet) {
    return (totalSquareFeet / 110.0) * 8.0;
}

// Calculate cost of paint
double calculatePaintCost(int gallons, double pricePerGallon) {
    return gallons * pricePerGallon;
}

// Calculate labor charges
double calculateLaborCharges(double laborHours) {
    const double laborRate = 25.00;
    return laborHours * laborRate;
}

// Display all the results
void displayResults(int gallons, double laborHours, double paintCost, double laborCharges, double totalCost) {
    cout << fixed << setprecision(2);
    cout << "\nPaint Job Estimate:\n";
    cout << "---------------------\n";
    cout << "Gallons of paint required: " << gallons << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of the paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCharges << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl << endl;
}

// Ask user if they want to repeat the program
bool askToRepeat() {
    char choice;
    cout << "Would you like to perform another paint estimate? (Y/N): ";
    cin >> choice;

    while (cin.fail() || (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')) {
        cout << "ERROR: Please enter Y or N: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> choice;
    }
    return (choice == 'Y' || choice == 'y');
}
