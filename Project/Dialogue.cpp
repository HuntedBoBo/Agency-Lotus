// Dialogue.cpp
#include "Dialogue.h"
#include <iostream>
using namespace std;

Dialogue::Dialogue() {
    // Initialize your dialogue options and responses here
    options = { "Fight!", "Agility!", "Charisma!", "Brains!" };
    
    responses = {
        "You used your strength!",
        "You used your quick feet!",
        "You used your charming wit!",
        "You used your mind!"
    };
}

void Dialogue::displayOptions(int fight, int agility, int charisma, int brains) {
    // Display dialogue options based on stats
    cout << "Available Options:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << "\n";
    }
}

string Dialogue::getResponse(int option) {
    // Return the response based on the chosen option
    if (option >= 1 && option <= static_cast<int>(responses.size())) {
        return responses[option - 1];
    } else {
        return "Invalid option.";
    }
}