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
    storyChara cac_corny("Corny", 9, 15, 11, 12);
    storyChara cac_jop("Joptimus Deere", 17, 8, 8, 12);

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
    string ACTONE_DeereBrainS = "You then jump and grab onto his back plate. It seems like he doesn't have a great sense of hearing, as he doesn't even notice you or feel you.";
    string ACTONE_DeereBrainF = "You try to dash right past him.\nUnfortunately, the second you appear in front of him he brings down his massive leg onto you. You are rendered immobile, to put it lightly.";
    string ACTONE_DeereChariS = "You hear the robot's parts shifting a little, as it somehow seems to soften its demeanor.\nThe robot nods his head.";
    string ACTONE_DeereChariF = "You hear the robot's parts shifting a little, as if he's becoming defensive.";
    vector<string> DIASUC_ACTONE_DeereEncounter{ ACTONE_DeereFightS, ACTONE_DeereAgileS, ACTONE_DeereBrainS, ACTONE_DeereChariS };
    vector<string> DIAFAIL_ACTONE_DeereEncounter{ ACTONE_DeereFightF, ACTONE_DeereAgileF, ACTONE_DeereBrainF, ACTONE_DeereChariF };

    // ACTONE_DeereAgl
    vector<string> DIAOPT_ACTONE_DeereAgl{ "Yes", "No" };
    vector<string> DIAREP_ACTONE_DeereAgl{ "You leap to the side and manage to grab hold of the roof!", "Putting all energy into your legs, you speed up and attempt to outrun the vehicle." };

    // Introduces user and prompts them to select character.
    cout << "Welcome to the Land of Iowa!" << endl;
    cout << "Please select your character: " << endl;
    cout << "1. Carlisle - A level-headed, passionate adventurer who's a bit out of shape." << endl;
    cout << "2. Bimblo - Very smart, but quite clumsy." << endl;
    cout << "3. Johnny - Expert fighter, is likable but on the simpler side mentally." << endl;
    cout << "4. Jacquelyn - Fast and quick-witted, with a pretty weak constitution." << endl;
    cin >> player_choice;

    // Initializes character
    while (selectedCharacter.getPlayerName() == "") {
        if (player_choice == 1) {
            selectedCharacter = playerChara("Carlise", 10, 9, 17, 13);
        }
        else if (player_choice == 2) {
            selectedCharacter = playerChara("Bimblo", 12, 6, 9, 18);
        }
        else if (player_choice == 3) {
            selectedCharacter = playerChara("Johnny", 20, 12, 7, 6);
        }
        else if (player_choice == 4) {
            selectedCharacter = playerChara("Carlise", 5, 16, 12, 15);
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
    // Dialogue class is created and options are displayed to the user.
    Dialogue DIA_ACTONE_Opening(DIAOPT_ACTONE_Opening, DIAREP_ACTONE_Opening);
    DIA_ACTONE_Opening.displayOptions();
    cout << "Enter your choice (1 or 2): ";

    // Then responses are inputted by the user.
    cin >> player_choice;
    cout << DIA_ACTONE_Opening.getResponse(player_choice);
    // Incase the user inputs an invalid option.
    while (DIA_ACTONE_Opening.getSelectedOption() == -1) {
        cout << " Please try again: ";
        cin >> player_choice;
        cout << DIA_ACTONE_Opening.getResponse(player_choice);
    }

    // Afterwards, the parameter is gotten from the Dialogue class itself to select which branch it should take.
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
                cout << "You think of a crazy idea. You could try and jump onto the roof of the vehicle and hitch a ride, or maybe even take control of him! If not that, you'd just try to run faster." << endl;
                Dialogue DIA_ACTONE_DeereAglS2(DIAOPT_ACTONE_DeereAgl, DIAREP_ACTONE_DeereAgl);
                DIA_ACTONE_DeereAglS2.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << DIA_ACTONE_DeereAglS2.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (DIA_ACTONE_DeereAglS2.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << DIA_ACTONE_DeereAglS2.getResponse(player_choice);
                }

                // ACTONE_DeereAglS2Y
                if (DIA_ACTONE_DeereAglS2.getSelectedOption() == 1) {
                    cout << "Despite coughing as the exhaust blows in your face, you swing yourself downward and find yourself in the driver's seat!" << endl;
                    cout << "Taking hold of the wheel and slamming down the pedal, you have taken control of the guardian of the roads!" << endl << endl;
                    cout << "With Deere going at max speed, you find yourself at the road's end in no time. You tuck and roll out of the tractor and onto the grass, and look back up." << endl;
                    cout << "Deere transforms back into an automata, but instead of going after you, he simply nods his head. It seems like you have earned his respect now." << endl;
                    eventHandler.updateStoryCharacter(cac_jop, false, false, false, true);
                }
                // ACTONE_DeereAglS2N
                else if (DIA_ACTONE_DeereAglS2.getSelectedOption() == 2) {
                    cout << "Putting all energy into your legs, you speed up and attempt to outrun the vehicle. For a second you think that you're successful, until you see the shadow of a massive object behind you." << endl;
                    cout << "Deere has equipped himself with a ginormous plow, and before you can even think about escaping it you are scooped up with the plow and then flung high into the stratosphere." << endl;
                    cout << "When you land, not only are all your bones broken, but you’re as far from Iowa as can be." << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }
            }
            // ACTONE_DeereAglF2
            else {
                cout << "\"Once again, state your business here.\"" << endl;
                cout << "Looks like you have no choice here but to say something. Will you tell the truth of your intentions?" << endl;
                Dialogue ACTONE_DeereAglF2();
                // Unimplemented
            }
        }
        // ACTONE_DeereBrain
        else if (DIA_ACTONE_DeereEncounter.getSelectedOption() == 3) {
            cout << "\"Oh, sorry, I went the wrong way. I'll be off, then!\"" << endl;
            cout << "You try to trick the automata by turning around as if you were leaving the roads. He seems confused at first, but soon you hear his parts shift as he turns around as well." << endl;
            cout << "Once you're sure he has his back turned, you pivot forward again and sprint towards Deere! ";
            cout << DIASTAT_ACTONE_DeereEncounter_Response;

            // ACTONE_DeereBrnS2
            if (DIA_ACTONE_DeereEncounter.isSuccessful()) {
                cout << "Now that you're hitching a ride on the robot, you think all will go smoothly and you'll be able to get some distance in." << endl;
                cout << "Unfortunately, you can feel the metal shifting under you. It seems like he will transform back into a tractor again." << endl;
                cout << "You think of something, you can try and take control of him by climbing into the vehicle, but if not you will have no other option but to get on the top." << endl;
                Dialogue ACTONE_DeereBrnS2(DIAOPT_ACTONE_DeereAgl, DIAREP_ACTONE_DeereAgl);
                // Unimplemented
            }
            else {
                cout << "While the robot is fearsome, it doesn't mean he has no compassion.\nDeere transforms back into a tractor, and uses his plow to slowly but surely move your body back to the beginning of the roads." << endl;
                // Failure. Break for now.
                cout << "==GAME OVER!==";
                return 0;
            }
        }
        // ACTONE_DeereChari
        else if (DIA_ACTONE_DeereEncounter.getSelectedOption() == 4) {
            cout << "Steeling your nerves, you decide to be upfront about your motives." << endl;
            cout << "\"I'm looking to enter the land of Iowa. I'd like to seek treasure, so I can improve my life and escape poverty.\"" << endl;
            cout << DIASTAT_ACTONE_DeereEncounter_Response;

            // ACTONE_DeereCharS2
            if (DIA_ACTONE_DeereEncounter.isSuccessful()) {
                cout << "\"You seem like a genuine soul. I trust you to treat the land with respect as you work towards your goal. Here, let me assist you...\"" << endl;
                cout << "Deere kneels down, offering his claw. You sit down on his hand and he lifts you to his shoulder. Joptimus Deere proceeds to take you to your destination!" << endl;
                eventHandler.updateStoryCharacter(cac_jop, true, false, false, false);
            }
            else {
                cout << "\"I have witnessed many ill-mannered invaders like you enter this land only to desecrate the land and exploit its bounties. You seem far from trustworthy.\"" << endl;
                cout << "The automata leans down, and before you can escape, he grabs you by your clothes with his massive metal claw and brings you up to his face." << endl;
                cout << "\"Begone, greedy pest!\" He roars, and his arm rotates at an inhuman speed before tossing you into the distance, far beyond the roads." << endl;
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
        }
        else {
            cout << "You wander through the maze but find no one." << endl;
        }
    }

    // End of act 1
    cout << "And with that, you have successfully entered the Land of Iowa!" << endl;
    cout << "The road ahead of you holds many terrifying and treacherous perils, but now that you’ve gotten this far you have no intention of turning back now." << endl;
    cout << "==END OF ACT ONE==" << endl << endl;
    // Ends the game with NPC Statuses, if the player is successful.
    cout << "You've ended the game with the current NPC Statuses:" << endl;
    if (player_location == "roads") {
        cout << "Jopitmus Deere Status:" << endl;
        cout << (cac_jop.getFriendStatus() ? "You have seem to gain his trust.\n" : "");
        cout << (cac_jop.getEnemyStatus() ? "He now knows you're an enemy for sure.\n" : "");
        cout << (cac_jop.getTrickedStatus() ? "You have tricked him.\n" : "");
        cout << (cac_jop.getNeutralStatus() ? "He'll keep an eye on you.\n" : "");
    }
    else {
        cout << "You have not met Joptimus Deere in your travels, fortunately." << endl;
    }

    return 0;
}

