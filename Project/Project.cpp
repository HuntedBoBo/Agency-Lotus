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
    string player_location;
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
    string ACTONE_DeereAgileS = "You do a somersault between the robot's legs before launching yourself forward.\nYou run with all your vigor, your boots sliding along the asphalt, as you avoid all the minor hazards on the road.\nLuckily, you gain a good amount of distance between you and Deere!";
    string ACTONE_DeereAgileF = "You swerve to the side and try to run past him.\nDeere moves his leg slightly, and you trip over the solid metal.\nAfter you fall to the asphalt, you hear mechanical rumbling as Deere turns and lifts you up by your clothes with his massive claw.";
    string ACTONE_DeereBrainS = "You then jump and grab onto his back plate.\nIt seems like he doesn’t have a great sense of hearing, as he doesn’t even notice you or feel you.";
    string ACTONE_DeereBrainF = "You try to dash right past him.\nUnfortunately, the second you appear in front of him he brings down his massive leg onto you. You are rendered immobile, to put it lightly.";
    string ACTONE_DeereChariS;
    string ACTONE_DeereChariF;
    vector<string> DIASUC_ACTONE_DeereEncounter{ ACTONE_DeereFightS, ACTONE_DeereAgileS };
    vector<string> DIAFAIL_ACTONE_DeereEncounter{ ACTONE_DeereFightF, ACTONE_DeereAgileF };

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
        player_location = "roads";
        cout << "The area around you is like a desert of green fields, there doesn't seem to be a soul around for miles." << endl;
        cout << "Some of the roads are paved with smooth black asphalt, and some sections are made up of milky-white gravel, with stones that stab at your feet through your shoes." << endl;
        cout << "Just as you begin to assume you're all alone, you hear a bellowing growl resembling the sound of a rockslide." << endl;
        cout << "Up ahead, you see a terrifying green vehicle with massive wheels approaching you at a remarkable speed." << endl;
        cout << "Smoke puffs out of the vehicle as you try and run the other way, but it's too late." << endl;
        cout << "The vehicle stops when in front of you, before it begins to shift with an even louder sound." << endl << endl;

        cout << "Before your eyes, the green vehicle transforms into a massive automata, with green plates of armor and piercing yellow eyes." << endl;
        cout << "The robot looks down at you." << endl;

        // ACTONE_DeereEncounter
        cout << "This hulking \"guardian\" seems to be very suspicious of your motives. What will you do? " << endl;
        WeightedDialogue DIA_ACTONE_DeereEncounter(DIAOPT_ACTONE_DeereEncounter, DIASUC_ACTONE_DeereEncounter, DIAFAIL_ACTONE_DeereEncounter);
        DIA_ACTONE_DeereEncounter.displayOptions();
        // Gets user input and gets stat response from dialogue.
        cin >> player_choice;
        string DIASTAT_ACTONE_DeereEncounter_Response = DIA_ACTONE_DeereEncounter.getStatResponse(player_choice, cac_jop, selectedCharacter);
        while (DIA_ACTONE_DeereEncounter.getSelectedOption() == -1) {
            // Posts invalid option and prompts user to try again.
            cout << DIASTAT_ACTONE_DeereEncounter_Response;
            cout << " Please try again: ";
            // Updates player choice.
            cin >> player_choice;
            DIASTAT_ACTONE_DeereEncounter_Response = DIA_ACTONE_DeereEncounter.getStatResponse(player_choice, cac_jop, selectedCharacter);
        }

        // ACTONE_DeereFight
        if (DIA_ACTONE_DeereEncounter.getSelectedOption() == 1) {
            cout << "Taking in a deep breath, you brace yourself before shouting out to the automata." << endl;
            cout << "\"If you won't let me pass, then I have no choice but to destroy you!\"" << endl << endl;
            cout << "You hear exhaust thrust out of Joptimus Deere’s pipes as he begins to move. The two of you charge at one another." << endl;
            cout << DIASTAT_ACTONE_DeereEncounter_Response;

            // If action was successful, branch off.
            if (DIA_ACTONE_DeereEncounter.isSuccessful()) {
                cout << "As you stand up you witness the robot's body begin to move again, and you take that as your cue to make your getaway." << endl;
                // Success! No return statements should be played.
                eventHandler.updateStoryCharacter(cac_jop, false, true, false, false);
            }
            // Else, game over.
            else {
                cout << "While the robot is fearsome, it doesn't mean he has no compassion.\nDeere transforms back into a tractor, and uses his plow to slowly but surely move your body back to the beginning of the roads." << endl;
                // Failure. Break for now.
                cout << "==GAME OVER!==";
                return 0;
            }
        }
        // ACTONE_DeereAgile
        else if (DIA_ACTONE_DeereEncounter.getSelectedOption() == 2) {
            cout << "In a bold move, you attempt to dash past Joptimus Deere!" << endl;
            cout << DIASTAT_ACTONE_DeereEncounter_Response;

            // ACTONE_DeereAglS2
            if (DIA_ACTONE_DeereEncounter.isSuccessful()) {
                cout << "However, you soon hear the rumbling sound again, along with a hissing whistle." << endl;
                cout << "You look over your shoulder, and see Deere in his vehicular form chasing you, much faster than you had thought!." << endl;
                cout << "In mere seconds, the tractor is right next to you!" << endl;
                cout << "You think of a crazy idea. You could try and jump onto the roof of the vehicle and hitch a ride, or maybe even take control of him! If not that, you’d just try to run faster." << endl;
                Dialogue ACTONE_DeereAglS2();
            }
            // ACTONE_DeereAgileF
            else {
                cout << "While the robot is fearsome, it doesn't mean he has no compassion.\nDeere transforms back into a tractor, and uses his plow to slowly but surely move your body back to the beginning of the roads." << endl;
                // Failure. Break for now.
                cout << "==GAME OVER!==";
                return 0;
            }
        }
    }
    // ACTONE_FieldEnt
    else if (DIA_ACTONE_Opening.getSelectedOption() == 2) {
        player_location = "maize";
        cout << "You've chosen to enter the cornfield maze." << endl;
        cout << "Good luck navigating!" << endl;
        if (rand() % 2 == 1) {
            cout << "You encounter the corn people!" << endl;
            cout << "Specifically, you meet Corny, a friendly member of the corn people." << endl;
            player_status = "safe";

            // Pseudocode for Corny encounter
            cout << "\"Well if you won’t give them to me, then I guess I’ll have to force them out of you!\"";
            cout << " You enter a fighting stance, ready to solve your problems with violence." << endl;
            cout << "You hear the tribe murmur to each other as Corny’s eyes widen." << endl;
            cout << "\"Hmph. Well, if you insist…\" A tribesperson tosses her a spear, which she points towards you." << endl;

            // ACTONE_CornyFightS
            WeightedDialogue DIA_ACTONE_CornyFightS(DIAOPT_ACTONE_CornyFightS, DIAREP_ACTONE_CornyFightS);
            DIA_ACTONE_CornyFightS.displayOptions();
            cin >> player_choice;
            string DIASTAT_ACTONE_CornyFightS_Response = DIA_ACTONE_CornyFightS.getStatResponse(player_choice, cac_corny, selectedCharacter);
            while (DIA_ACTONE_CornyFightS.getSelectedOption() == -1) {
                cout << DIASTAT_ACTONE_CornyFightS_Response;
                cout << " Please try again: ";
                cin >> player_choice;
                DIASTAT_ACTONE_CornyFightS_Response = DIA_ACTONE_CornyFightS.getStatResponse(player_choice, cac_corny, selectedCharacter);
            }

            // ACTONE_CornyFgtS2
            if (DIA_ACTONE_CornyFightS.isSuccessful()) {
                cout << "While Corny doesn’t say a word, you hear the tribespeople clamor." << endl;
                cout << "You see the corn-people’s furious faces as they step out of the stalks, flooding the area with their sheer numbers." << endl;
                cout << "It seems like you’ve utterly enraged the tribe. There’s no talking your way out of this." << endl;

                // ACTONE_CornyFgtS2Y
                // ACTONE_CornyFgtS2N
                Dialogue ACTONE_CornyFgtS2Y();
                Dialogue ACTONE_CornyFgtS2N();
            } else {
                // ACTONE_CornyFightF
                cout << "\"Well if you won’t give them to me, then I guess I’ll have to force them out of you!\"";
                cout << " You enter a fighting stance, ready to solve your problems with violence." << endl;
                cout << "You hear the tribe murmur to each other as Corny’s eyes widen." << endl;
                cout << "\"Hmph. Well, if you insist…\" A tribesperson tosses her a spear, which she points towards you." << endl;
                cout << "After a tedious duel in the claustrophobic arena, you fall to your knees, covered in bruises caused by getting jabbed by a corncob numerous times." << endl;
                cout << "You hold your chest, as the internal pain kicks in." << endl;

                // ACTONE_CornyFgtF2
                Dialogue ACTONE_CornyFgtF2();
        }
        else {
            cout << "You wander through the maze but find no one." << endl;
        }
    }

    cout << "You made it out of the " << player_location << " alive." << endl;
    cout << "==END OF ACT ONE==" << endl << endl;
    // Ends the game with NPC Statuses, if the player is successful.
    cout << "You've ended the game with the current NPC Statuses:" << endl;
    if (player_location == "roads") {
        cout << "Jopitmus Deere Status:" << endl;
        cout << (cac_jop.getFriendStatus() ? "You have seem to gain his trust.\n" : "");
        cout << (cac_jop.getEnemyStatus() ? "He now knows you're an enemy for sure.\n" : "");
        cout << (cac_jop.getTrickedStatus() ? "You have tricked him.\n" : "");
        cout << (cac_jop.getNeutralStatus() ? "He seems to be wary of you.\n" : "");
    }
    else {
        cout << "You have not met Joptimus Deere in your travels, fortunately." << endl;
    }

    return 0;
}

