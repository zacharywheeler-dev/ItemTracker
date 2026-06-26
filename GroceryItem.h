#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>

class GroceryItem {
private:
    std::string name;
    int frequency;

public:
    // Default constructor
    GroceryItem();

    // Parameterized constructor
    GroceryItem(const std::string& itemName, int itemFrequency = 1);

    // Getters and Setters
    std::string getName() const;
    int getFrequency() const;
    void incrementFrequency();
    void setFrequency(int newFrequency);
};

#endif // GROCERYITEM_H