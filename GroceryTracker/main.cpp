#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <limits>

using namespace std;

// Class definition to handle item tracking logic
class GroceryTracker {
private:
    // Map to store the item name as the key and its frequency as the value
    map<string, int> itemFrequencies;

    // Helper method to load data from the input file
    void loadData(const string& inputFile) {
        ifstream inFS(inputFile);
        string item;

        if (!inFS.is_open()) {
            cout << "Error: Could not open input file " << inputFile << endl;
            return;
        }

        // Read each word from the file and increment its count in the map
        while (inFS >> item) {
            itemFrequencies[item]++;
        }
        inFS.close();
    }

    // Helper method to backup data to frequency.dat
    void backupData(const string& outputFile) {
        ofstream outFS(outputFile);

        if (!outFS.is_open()) {
            cout << "Error: Could not open backup file " << outputFile << endl;
            return;
        }

        // Iterate through the map and write to the backup file
        for (auto const& pair : itemFrequencies) {
            outFS << pair.first << " " << pair.second << endl;
        }
        outFS.close();
    }

public:
    // Constructor initializes the tracker by loading and backing up data
    GroceryTracker(const string& inputFile, const string& backupFile) {
        loadData(inputFile);
        backupData(backupFile);
    }

    // Option 1: Search for a specific item's frequency
    void printItemFrequency(string item) {
        // Capitalize the first letter to match file format (e.g., "apples" -> "Apples")
        if (!item.empty()) {
            item[0] = toupper(item[0]);
            for (size_t i = 1; i < item.length(); ++i) {
                item[i] = tolower(item[i]);
            }
        }

        if (itemFrequencies.count(item)) {
            cout << "\n" << item << " were purchased " << itemFrequencies[item] << " times today." << endl;
        }
        else {
            cout << "\n" << item << " were not purchased today." << endl;
        }
    }

    // Option 2: Print a list of all items and their frequencies
    void printAllFrequencies() {
        cout << "\n--- All Item Frequencies ---" << endl;
        for (auto const& pair : itemFrequencies) {
            cout << pair.first << " " << pair.second << endl;
        }
        cout << "----------------------------\n" << endl;
    }

    // Option 3: Print a text-based histogram
    void printHistogram() {
        cout << "\n--- Item Frequency Histogram ---" << endl;
        for (auto const& pair : itemFrequencies) {
            // Set width for neat alignment
            cout << setw(15) << left << pair.first << " ";
            // Print an asterisk for each occurrence
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
        cout << "--------------------------------\n" << endl;
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\n========== CORNER GROCER MENU ==========" << endl;
    cout << "1. Search for an item's frequency" << endl;
    cout << "2. Print all items and frequencies" << endl;
    cout << "3. Print histogram of item frequencies" << endl;
    cout << "4. Exit program" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Initialize the tracker, which automatically reads the input and creates the backup
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice = 0;
    string searchItem;

    while (choice != 4) {
        displayMenu();
        cin >> choice;

        // Input Validation: Check if the user entered a non-integer
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "\nInvalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter the item you wish to search for: ";
            cin >> searchItem;
            tracker.printItemFrequency(searchItem);
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "\nExiting program. Have a great day!" << endl;
            break;
        default:
            cout << "\nInvalid choice. Please select an option from 1 to 4." << endl;
            break;
        }
    }

    return 0;
}