#include <iostream>
#include <cstdlib> // For random number generation
#include "Dialogue.h"
#include "WeightedDialogue.h"
#include "playerChara.h"
#include "storyChara.h"
#include "Event.h"

using namespace std;

int main() {
    // Initializes all player variables.
    playerChara selectedCharacter("", 0, 0, 0, 0);
    int player_choice;
    string player_status;
    // Initializes Event class incase characters need changing
    Event eventHandler;

    // Initializes story characters.
    storyChara cac_corny("Corny", 9, 15, 12, 11);
    storyChara cac_jop("Joptimus Deere", 17, 8, 12, 8);

    // Initializes dialogue options and responses
    // ACTONE_Opening
    vector<string> DIAOPT_ACTONE_Opening{ "Long, dangerous roads that surround the area", "A twisting, maze-like field of maize" };
    vector<string> DIAREP_ACTONE_Opening{ "You begin your journey walking along the seemingly endless roads.", "You begin your journey pushing aside stalks to find the path ahead." };
    vector<string> DIAOPT_ACTONE_DeereEncounter{ "Challenge him to a battle!", "Make a run for it!", "Pretend to leave!", "Explain yourself!"};
    // ACTONE_DeereEncounter
    string ACTONE_DeereFightS = "By the end of the battle, you are exhausted, sitting down on the pavement.\nBefore you is a pile of green metal, dented beyond belief, smoke rising from its parts.\nYou have somehow found yourself the victor of this hectic battle.";
    string ACTONE_DeereFightF = "The battle ends fast.\nDeere simply lifted his arm and brought it down onto you with the force of a thousand angry farmers.\nAs a result you lay on the asphalt, most of your bones broken, leaving you immobile.";
    vector<string> DIASUC_ACTONE_DeereEncounter{ ACTONE_DeereFightS };
    vector<string> DIAFAIL_ACTONE_DeereEncounter{ ACTONE_DeereFightF };

    // Introduces user and prompts them to select character.
    cout << "Welcome to the Land of Iowa!" << endl;
    cout << "Please select your character: " << endl;
    cout << "1. Carlisle - A level-headed, passionate adventurer who’s a bit out of shape." << endl;
    cout << "2. Bimblo - Very smart, but quite clumsy." << endl;
    cout << "3. Johnny - Expert fighter, is likable but on the simpler side mentally." << endl;
    cout << "4. Jacquelyn - Fast and quick-witted, with a pretty weak constitution." << endl;
    cin >> player_choice;

    // Initializes character
    while (selectedCharacter.getPlayerName() == "") {
        if (player_choice == 1) {
            selectedCharacter = playerChara("Carlise", 10, 9, 13, 17);
        }
        else if (player_choice == 2) {
            selectedCharacter = playerChara("Bimblo", 12, 6, 18, 9);
        }
        else if (player_choice == 3) {
            selectedCharacter = playerChara("Johnny", 18, 12, 6, 12);
        }
        else if (player_choice == 4) {
            selectedCharacter = playerChara("Carlise", 5, 16, 15, 12);
        }
        else {
            cout << "Invalid Character. Please reenter: ";
            cin >> player_choice;
        }
    }
    cout << endl;

    // ACTONE_Opening
    cout << "The strange land of Iowa has been forever shrouded in mystery." << endl;
    cout << "Tales of strange people, creatures and places have been passed down in your family for years.";
    cout << "There is a legend that has sparked your interest, one of a building with a roof of pure gold located in the heart of Iowa, Damoyen." << endl;
    cout << "After having enough of struggling to get by, you decide to go on a dangerous quest to search for the gold-domed tower, hoping to retrieve the gold and bask in riches upon your return." << endl << endl;
    cout << "Getting into Iowa is a difficult endeavor, however." << endl;
    Dialogue DIA_ACTONE_Opening(DIAOPT_ACTONE_Opening, DIAREP_ACTONE_Opening);
    DIA_ACTONE_Opening.displayOptions();
    cout << "Enter your choice (1 or 2): ";
    cin >> player_choice;
    cout << DIA_ACTONE_Opening.getResponse(player_choice);
    while (DIA_ACTONE_Opening.getSelectedOption() == -1) {
        cout << " Please try again: ";
        cin >> player_choice;
        cout << DIA_ACTONE_Opening.getResponse(player_choice);
    }

    // ACTONE_RoadEnt
    if (DIA_ACTONE_Opening.getSelectedOption() == 1) {
        cout << "The area around you is like a desert of green fields, there doesn't seem to be a soul around for miles." << endl;
        cout << "Some of the roads are paved with smooth black asphalt, and some sections are made up of milky-white gravel, with stones that stab at your feet through your shoes." << endl;
        cout << "Just as you begin to assume you're all alone, you hear a bellowing growl resembling the sound of a rockslide." << endl;
        cout << "Up ahead, you see a terrifying green vehicle with massive wheels approaching you at a remarkable speed." << endl;
        cout << "Smoke puffs out of the vehicle as you try and run the other way, but it's too late." << endl;
        cout << "The vehicle stops when in front of you, before it begins to shift with an even louder sound." << endl << endl;

        cout << "Before your eyes, the green vehicle transforms into a massive automata, with green plates of armor and piercing yellow eyes." << endl;
        cout << "The robot looks down at you." << endl;

        // ACTONE_DeereEncounter
        cout << "This hulking “guardian” seems to be very suspicious of your motives. What will you do? " << endl;
        WeightedDialogue DIA_ACTONE_DeereEncounter(DIAOPT_ACTONE_DeereEncounter, DIASUC_ACTONE_DeereEncounter, DIAFAIL_ACTONE_DeereEncounter);
        DIA_ACTONE_DeereEncounter.displayOptions();
        cin >> player_choice;
        string DIASTAT_ACTONE_DeereEncounter_Response = DIA_ACTONE_DeereEncounter.getStatResponse(player_choice, cac_jop, selectedCharacter);
        while (DIA_ACTONE_DeereEncounter.getSelectedOption() == -1) {
            cout << " Please try again: ";
            cin >> player_choice;
            DIASTAT_ACTONE_DeereEncounter_Response = DIA_ACTONE_DeereEncounter.getStatResponse(player_choice, cac_jop, selectedCharacter);
        }

        // ACTONE_DeereFight
        if (DIA_ACTONE_DeereEncounter.getSelectedOption() == 1) {
            cout << "Taking in a deep breath, you brace yourself before shouting out to the automata." << endl;
            cout << "“If you won’t let me pass, then I have no choice but to destroy you!”" << endl << endl;
            cout << "You hear exhaust thrust out of Joptimus Deere’s pipes as he begins to move. The two of you charge at one another." << endl;
            cout << DIASTAT_ACTONE_DeereEncounter_Response << endl;

            if (DIA_ACTONE_DeereEncounter.isSuccessful()) {
                // Success! Break for now.
                return 0;
            }
            else {
                // Failure. Break for now.
                return 0;
            }
        }
    }
    // ACTONE_FieldEnt
    else if (DIA_ACTONE_Opening.getSelectedOption() == 2) {
        cout << "You've chosen to enter the cornfield maze." << endl;
        cout << "Good luck navigating!" << endl;
        if (rand() % 2 == 1) {
            cout << "You encounter the corn people!" << endl;
            cout << "Specifically, you meet Corny, a friendly member of the corn people." << endl;
            player_status = "safe";
        }
        else {
            cout << "You wander through the maze but find no one." << endl;
        }
    }

    return 0;
}

