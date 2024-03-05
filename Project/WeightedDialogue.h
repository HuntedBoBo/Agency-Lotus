/*
*Name: Jhon Paul Espiritu, used in Project with Agent Lotus.
*Date: 3/4/2024
*Email: jespiritu@dmacc.edu
*
* Branch off of Jacquie's Dialogue class for stat checking.
*/

#ifndef WEIGHTEDDIALOGUE_H
#define WEIGHTEDDIALOGUE_H

#include "storyChara.h"
#include "playerChara.h"
#include <string>
#include <vector>
using namespace std;

class WeightedDialogue : public Dialogue {
public:
    WeightedDialogue(vector<string> options, vector<string> successResponses, vector<string> failResponses);

    // Get the response based on the chosen option
    string getStatResponse(int option, storyChara opponent, playerChara player);

    bool isSuccessful() {
        return selectedOptionSuccess;
    }
protected:
    vector<string> failResponses;
    bool selectedOptionSuccess = false;
};

#endif // WEIGHTEDDIALOGUE_H
