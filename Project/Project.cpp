#include <iostream>
#include <cstdlib> // For random number generation
#include "playerChara.h"
#include "storyChara.h"
#include "Event.h"

using namespace std;

int main() {
    // Initializes all player variables.
    playerChara selectedCharacter("", 0, 0, 0, 0);
    string player_location;
    int player_choice;
    string player_status;
    Event newEvent;

    // Initializes story characters.
    storyChara cac_corny("Corny", 9, 15, 12, 11);
    storyChara cac_jop("Joptimus Deere", 17, 8, 12, 8);

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
            cout << "Invalid Character Name. Please reenter.";
        }
    }
    cout << endl;

    // Introduces a way for character to enter.
    cout << "You have two methods of entering:" << endl;
    cout << "1. Traverse the deadly open roads" << endl;
    cout << "2. Make your way through the twisting and turning massive cornfield maze" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> player_choice;

    if (player_choice == 1) {
        player_location = "open roads";
        cout << "You've chosen to traverse the deadly open roads." << endl;
        cout << "Prepare for danger!" << endl;
        if (rand() % 2 == 1) {
            cout << "You encounter Joptimus Deere, a massive tractor robot!" << endl;
            cout << "Joptimus Deere attacks!" << endl;
            player_status = "defeated";
        }
        else {
            cout << "You pass through the open roads uneventfully." << endl;
        }
    }
    else if (player_choice == 2) {
        player_location = "cornfield maze";
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

    if (player_status == "defeated") {
        cout << "Game over! You were defeated by Joptimus Deere." << endl;
    }
    else if (player_status == "safe") {
        cout << "Congratulations! You successfully met Corny and survived the cornfield maze." << endl;
    }

    return 0;
}

