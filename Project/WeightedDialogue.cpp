/*
*Name: Jhon Paul Espiritu, used in Project with Agent Lotus.
*Date: 3/4/2024
*Email: jespiritu@dmacc.edu
*
* Branch off of Jacquie's Dialogue class for stat checking.
*/
#include "Dialogue.h"
#include "storyChara.h"
#include "playerChara.h"
#include "WeightedDialogue.h"
#include <iostream>
using namespace std;

WeightedDialogue::WeightedDialogue(vector<string> options, vector<string> successResponses, vector<string> failResponses) {
	this->options = options;
	this->responses = successResponses;
	this->failResponses = failResponses;
}

/// <summary>
/// Gets responses based off stats, hardcoded as there are four stats. (Will do for the project we currently have right now.)
/// </summary>
/// <param name="option">Option selected.</param>
/// <param name="opponent">Opponent's stats</param>
/// <param name="player">Player's stats</param>
/// <returns></returns>
string WeightedDialogue::getStatResponse(int option, storyChara opponent, playerChara player) {
    // Return the response based on the chosen option
    selectedOption = option;
    // Hardcoded values, cannot be above four or below one.
    if ((option > 4) || (option <= 0)) {
        selectedOption = -1;
        return "Invalid option.";
    }

    // Messy way to handle things, but will do. Options are in favor of the player.
    int opponentStat;
    int playerStat;
    switch (option) {
    // 1. Fight
    case 1:
        opponentStat = opponent.getFStat();
        playerStat = player.getFStat();
        break;
    // 2. Agile
    case 2:
        opponentStat = opponent.getAStat();
        playerStat = player.getAStat();
        break;
    // 3. Brains
    case 3:
        opponentStat = opponent.getBStat();
        playerStat = player.getBStat();
        break;
    // 4. Charisma
    case 4:
        opponentStat = opponent.getCStat();
        playerStat = player.getCStat();
        break;
    // Invalid Option. Player wins.
    default:
        opponentStat = 0;
        playerStat = 0;
        break;
    }

    // Returns success or fail responses, based on player.
    if (playerStat >= opponentStat) {
        selectedOptionSuccess = true;
        return responses[option - 1] + "\n\n";
    }
    else {
        selectedOptionSuccess = false;
        return failResponses[option - 1] + "\n\n";
    }
}