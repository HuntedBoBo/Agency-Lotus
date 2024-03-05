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
    void displayOptions();

    // Get the response based on the chosen option
    string getResponse(int option);

    // Gets option parameter
    int getSelectedOption() {
        return selectedOption;
    }
protected:
    // Add more options and responses as needed
    vector<string> options;
    vector<string> responses;

    // Parameter for checking dialogue option.
    int selectedOption = -1;
};

#endif // DIALOGUE_H
