#include "GroceryItem.h"

// Initialize default values
GroceryItem::GroceryItem() : name(""), frequency(0) {}

// Initialize with name and default frequency of 1
GroceryItem::GroceryItem(const std::string& itemName, int itemFrequency)
    : name(itemName), frequency(itemFrequency) {}

std::string GroceryItem::getName() const {
    return name;
}

int GroceryItem::getFrequency() const {
    return frequency;
}

// Dynamically increment frequency when duplicates are found
void GroceryItem::incrementFrequency() {
    frequency++;
}

void GroceryItem::setFrequency(int newFrequency) {
    frequency = newFrequency;
}