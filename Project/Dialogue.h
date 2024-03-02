#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
#include <vector>
using namespace std;

class Dialogue {
public:
    Dialogue();  // Constructor
    Dialogue(vector<string> options, vector<string> responses);

    // Display the available dialogue options based on stats
    void displayOptions(int fight, int agility, int charisma, int brains);

    // Get the response based on the chosen option
    string getResponse(int option);

private:
    // Add more options and responses as needed
    vector<string> options;
    vector<string> responses;

    // Parameter for checking dialogue option.
    int selectedOption;
};

#endif // DIALOGUE_H
