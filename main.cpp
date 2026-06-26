#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "GroceryItem.h"

// Helper function to find if an item already exists in the vector
int findItemIndex(const std::vector<GroceryItem>& items, const std::string& name) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].getName() == name) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Core business logic: Reads the raw file data and populates a vector of objects
std::vector<GroceryItem> parseInputFile(const std::string& filename) {
    std::vector<GroceryItem> items;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file " << filename << std::endl;
        return items;
    }

    std::string itemName;
    // Read the file word by word (or line by line)
    while (inputFile >> itemName) {
        int index = findItemIndex(items, itemName);
        if (index != -1) {
            // Item exists, encapsulate data updates through the object's method
            items[index].incrementFrequency();
        } else {
            // New item, construct a new object and push to container
            items.push_back(GroceryItem(itemName, 1));
        }
    }
    inputFile.close();
    return items;
}

// Automatically backs up accumulated data to frequency.dat at startup
void generateBackupFile(const std::string& inputFilename, const std::string& backupFilename) {
    std::vector<GroceryItem> items = parseInputFile(inputFilename);
    std::ofstream outputFile(backupFilename);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create backup file." << std::endl;
        return;
    }

    for (const auto& item : items) {
        outputFile << item.getName() << " " << item.getFrequency() << std::endl;
    }
    outputFile.close();
}

// Menu Option 1: Search and print the frequency of a single item
void handleSearchOption(const std::string& filename) {
    std::vector<GroceryItem> items = parseInputFile(filename); // Live data check
    std::string target;
    std::cout << "Enter the item name you wish to search for: ";
    std::cin >> target;

    int index = findItemIndex(items, target);
    if (index != -1) {
        std::cout << target << " appears " << items[index].getFrequency() << " times.\n";
    } else {
        std::cout << target << " appears 0 times.\n";
    }
}

// Menu Option 2: Print lists of all item names and frequencies
void handlePrintListOption(const std::string& filename) {
    std::vector<GroceryItem> items = parseInputFile(filename); // Live data check
    std::cout << "\n--- Item Frequencies ---\n";
    for (const auto& item : items) {
        std::cout << std::left << std::setw(15) << item.getName() << " " << item.getFrequency() << std::endl;
    }
}

// Menu Option 3: Print text-based Histogram using asterisks
void handleHistogramOption(const std::string& filename) {
    std::vector<GroceryItem> items = parseInputFile(filename); // Live data check
    std::cout << "\n--- Item Histogram ---\n";
    for (const auto& item : items) {
        std::cout << std::left << std::setw(15) << item.getName() << " ";
        for (int i = 0; i < item.getFrequency(); ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    const std::string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
    const std::string BACKUP_FILE = "frequency.dat";

    // Requirement: Create backup file at the very start without user intervention
    generateBackupFile(INPUT_FILE, BACKUP_FILE);

    int choice = 0;
    while (choice != 4) {
        std::cout << "\n====================================\n";
        std::cout << "      Corner Grocer Tracker Menu\n";
        std::cout << "====================================\n";
        std::cout << "1. Search for an item frequency\n";
        std::cout << "2. Print overall frequencies\n";
        std::cout << "3. Print graphical histogram\n";
        std::cout << "4. Exit Program\n";
        std::cout << "Enter selection (1-4): ";

        // Basic user validation challenge
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                handleSearchOption(INPUT_FILE);
                break;
            case 2:
                handlePrintListOption(INPUT_FILE);
                break;
            case 3:
                handleHistogramOption(INPUT_FILE);
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid selection. Please choose options 1 through 4.\n";
        }
    }
    return 0;
}