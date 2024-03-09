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

    // Initializes story characters. CHARASELECT_BLURB
    storyChara cac_corny("Corny", 10, 16, 12, 10);
    storyChara cac_jop("Joptimus Deere", 17, 10, 12, 13);

    // Initializes dialogue options and responses
    // ACTONE_Opening
    vector<string> DIAOPT_ACTONE_Opening{ "Long, dangerous roads that surround the area", "A twisting, maze-like field of maize" };
    vector<string> DIAREP_ACTONE_Opening{ "You begin your journey walking along the seemingly endless roads.", "You begin your journey pushing aside stalks to find the path ahead." };
    vector<string> DIAOPT_ACTONE_DeereEncounter{ "Challenge him to a battle!", "Make a run for it!", "Pretend to leave!", "Explain yourself!"};
    vector<string> DIAOPT_ACTONE_CornyEncounter{ "Challenge her to a duel!", "Grab her and run!", "Trade her some junk!", "Make a genuine offer!" };
    vector<string> DIAOPT_ACTONE_PARAM_YESNO{ "Yes", "No" };

    #pragma region "Joptimus Deere"

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

        // ACTONE_DeereAglS2
        vector<string> DIAREP_ACTONE_DeereAglS2{ "You leap to the side and manage to grab hold of the roof!", "Putting all energy into your legs, you speed up and attempt to outrun the vehicle." };
        // ACTONE_DeereAglF2
        vector<string> DIAREP_ACTONE_DeereAglF2{ "Humiliated by your failed escape attempt, you decide to be honest to the robot.", "Despite the fact that you are now quite helpless, your ego still doesn't allow you to come clean." };
        // ACTONE_DeereBrnS2
        vector<string> DIAREP_ACTONE_DeereBrnS2{ "You hold onto Deere as he switches forms, and manage to swing yourself downward to get into the driver's seat!", "As Deere switches forms, you hold on for dear life and in turn find yourself grasping onto the roof of the tractor." };

    #pragma endregion "Joptimus Deere"

    #pragma region "Corny"
        // ACTONE_CornyEncounter
        string ACTONE_CornyFightS = "After a tedious duel in the claustrophobic arena, Corny's spear had been flung into the air as she falls onto the ground, bruised up and exhausted.\nShe gives you a glare.";
        string ACTONE_CornyFightF = "After a tedious duel in the claustrophobic arena, you fall to your knees, covered in bruises caused by getting jabbed by a corncob numerous times.\nYou hold your chest, as the internal pain kicks in.";
        string ACTONE_CornyAgileS = "Saying nothing, you rush towards Corny before grabbing her by the waist and continue to run!\nYou enter the maze again and run as fast as your legs can take you.";
        string ACTONE_CornyAgileF = "Both of you hit the grass with a thud. You see her glaring at you with a dumbfounded look.";
        string ACTONE_CornyBrainS = "Out comes a very rusty old coin, that you show off to Corny and her people.\"This is an ancient talisman from my homeland...it's called a 'penny,' and it brings amazing luck and fortune to those who carry it!\"";
        string ACTONE_CornyBrainF = "Out comes one of your old forks, that you show off to Corny and her people.\"This is a traditional instrument from my homeland...it's called a 'fork,' and makes eating so much easier!\"";
        string ACTONE_CornyChariS = "\"I have nothing. I'm poor, and I desperately try to get by every day without starving. I thought that I could find treasure in the land of Iowa and bring back riches...\"";
        string ACTONE_CornyChariF = "\"I don't have any riches. I thought that I could find treasure in the land of Iowa, return to my homeland and become wealthy beyond my years...\"";
        vector<string> DIASUC_ACTONE_CornyEncounter{ ACTONE_CornyFightS, ACTONE_CornyAgileS, ACTONE_CornyBrainS, ACTONE_CornyChariS };
        vector<string> DIAFAIL_ACTONE_CornyEncounter{ ACTONE_CornyFightF, ACTONE_CornyAgileF, ACTONE_CornyBrainF, ACTONE_CornyChariF };

        // ACTONE_CornyFight
        vector<string> DIAREP_ACTONE_CornyFgtS2{ "You convert all your fear into energy and run as fast as you can back into the maze. Despite constantly thinking that they're catching up to you, you actually somehow find yourself at the end of the maze.", "You can't even ready yourself before the tribespeople surround you and you're bonked on the head with a cob, then jabbed in the back with another." };
        vector<string> DIAREP_ACTONE_CornyFgtF2{ "With your ego bruised as well as your body, you spit back at her.", "You decide to be the bigger person and stay quiet. Instead, you rise to your knees and bow to her, respectfully." };
        // ACTONE_CornyAgile
        vector<string> DIAREP_ACTONE_CornyAglS2{ "You crouch down to Corny's level and look at her. ", "You crouch down to Corny's level and help her back up. She takes your silence as a signal to get moving, so she proceeds to lead you out of the maze." };
        // ACTONE_CornyBrain
        vector<string> DIAREP_ACTONE_CornyBrnF2{ "Cornered, you decide to come clean. \"I'm sorry, I tried to trick you...the truth is...\" You take a deep breath.", "Not willing to expose yourself, you decide to double down." };
        // ACTONE_CornyChari
        vector<string> DIAREP_ACTONE_CornyChariF2{ "After you nod your head, you aren't given a second to react before Corny snaps her fingers with a 'pop.'", "\"Well, it's your funeral.\" Corny says before snapping her fingers with a 'pop.'" };
    #pragma endregion "Corny"

    #pragma region "Introduction"
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
                selectedCharacter = playerChara("Johnny", 20, 12, 12, 6);
            }
            else if (player_choice == 4) {
                selectedCharacter = playerChara("Jacquelyn", 5, 16, 12, 15);
            }
            else {
                cout << "Invalid Character. Please reenter: ";
                cin >> player_choice;
            }
        }
        cout << endl;

        // ACTONE_Opening
        cout << "The strange land of Iowa has been forever shrouded in mystery." << endl;
        cout << "Tales of strange people, creatures and places have been passed down in your family for years." << endl;
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
    #pragma endregion "Introduction"

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
        cout << "\"I am called Joptimus Deere, and I serve as the guardian of these ancient roads. State your business in Iowa, or leave at once.\"" << endl;

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
            cout << "You hear exhaust thrust out of Joptimus Deere's pipes as he begins to move. The two of you charge at one another." << endl;
            cout << DIASTAT_ACTONE_DeereEncounter_Response;

            // If action was successful, branch off.
            if (DIA_ACTONE_DeereEncounter.isSuccessful()) {
                cout << "As you stand up you witness the robot's body begin to move again, and you take that as your cue to make your getaway." << endl;
                cout << "After a few more hours of walking, you finally make it to the road's end." << endl;
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
                cout << "You look over your shoulder, and see Deere in his vehicular form chasing you, much faster than you had thought!" << endl;
                cout << "In mere seconds, the tractor is right next to you!" << endl;
                cout << "You think of a crazy idea. You could try and jump onto the roof of the vehicle and hitch a ride, or maybe even take control of him! If not that, you'd just try to run faster." << endl;
                Dialogue DIA_ACTONE_DeereAglS2(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_DeereAglS2);
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
                    cout << "For a second you think that you're successful, until you see the shadow of a massive object behind you." << endl;
                    cout << "Deere has equipped himself with a ginormous plow, and before you can even think about escaping it you are scooped up with the plow and then flung high into the stratosphere." << endl;
                    cout << "When you land, not only are all your bones broken, but you're as far from Iowa as can be." << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }
            }
            // ACTONE_DeereAglF2
            else {
                cout << "\"Once again, state your business here.\"" << endl;
                cout << "Looks like you have no choice here but to say something. Will you tell the truth of your intentions?" << endl;
                Dialogue ACTONE_DeereAglF2(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_DeereAglF2);
                ACTONE_DeereAglF2.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << ACTONE_DeereAglF2.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (ACTONE_DeereAglF2.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << ACTONE_DeereAglF2.getResponse(player_choice);
                }

                // ACTONE_DeereAglF2Y
                if (ACTONE_DeereAglF2.getSelectedOption() == 1) {
                    cout << "\"I'm looking to enter the land of Iowa to find treasure, 'cause I'm poor and have barely a penny to my name...\"" << endl;
                    cout << "After your lament, Deere lowers you." << endl << endl;
                    cout << "\"I see. You are a struggling soul who only wants to achieve happiness in life...if that is the case, then allow me to assist you.\"" << endl;
                    cout << "He raises you up again before moving you over to his shoulder. Joptimus deere proceeds to take you to your destination!" << endl;
                    eventHandler.updateStoryCharacter(cac_jop, false, false, false, true);
                }
                // ACTONE_DeereAglF2N
                else if (ACTONE_DeereAglF2.getSelectedOption() == 2) {
                    cout << "\"Uh...I live here, actually...in Iowa...so I just want to...\"" << endl;
                    cout << "Deere's exhaust pipes fume with smoke." << endl;
                    cout << "\"Do not lie. A true Iowan would never try to pull off such a cowardly scheme...if you cannot be truthful, then begone!\"" << endl;
                    cout << "He roars, and his arm rotates at an inhuman speed before tossing you into the distance, far beyond the roads." << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }

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
                Dialogue ACTONE_DeereBrnS2(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_DeereBrnS2);
                ACTONE_DeereBrnS2.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << ACTONE_DeereBrnS2.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (ACTONE_DeereBrnS2.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << ACTONE_DeereBrnS2.getResponse(player_choice);
                }

                // ACTONE_DeereBrnS2Y
                if (ACTONE_DeereBrnS2.getSelectedOption() == 1) {
                    cout << "Taking hold of the wheel and slamming down the pedal, you have taken control of the guardian of the roads!" << endl << endl;
                    cout << "With Deere going at max speed, you find yourself at the road's end in no time. You tuck and roll out of the tractor and onto the grass, and look back up." << endl;
                    cout << "Deere transforms back into an automata, but instead of going after you, he simply nods his head. It seems like you have earned his respect now." << endl;
                    eventHandler.updateStoryCharacter(cac_jop, false, false, false, true);
                }
                // ACTONE_DeereBrnS2N
                else if (ACTONE_DeereBrnS2.getSelectedOption() == 2) {
                    cout << "He begins to move at an astonishing speed, and as you try to raise your body up, the wind and exhaust blasts into your face!" << endl;
                    cout << "Your body can't withstand the force for very long, and once your hands slip, you go flying back!" << endl;
                    cout << "The sheer acceleration causes you to tumble backwards all the way to the very beginning of the roads. Unfortunately, your body is in no shape to keep moving." << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }
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
        cout << "The earthy scent of soil and the sweet scent of corn overwhelm your senses." << endl;
        cout << "You turn left, you turn right, you even find yourself backtracking your steps after finding dead ends." << endl;
        cout << "There doesn't seem to be anybody else in this maize maze, but you sometimes hear the stalks rustling. You aren't sure if it's real or just paranoia." << endl;
        cout << "Eventually the rustling becomes too much, and you decide to rush into the corn to follow the sound." << endl;
        cout << "After emerging from the tall stalks, you find an open area in the field. When you take a few steps forward, suddenly humanoid figures emerge from the walls of the maze." << endl;
        cout << "You only catch a glimpse of yellow face-paint and corn husk loincloths before you are charged with a corncob spear." << endl << endl;

        cout << "Just as you are convinced this is the end, the corn people stop. In front of you stands another member of the tribe, more youthful and decorated." << endl;
        cout << "She blocks her people from attacking before turning to face you." << endl;
        cout << "\"Hey there! I'm Corny, and this is where my tribe resides. It looks like you're trying to get out of the cornfield. I know this maze like the back of my hand, so I'll show you the way out...well, not without something in return, of course.\"" << endl;

        // ACTONE_CornyEncounter
        cout << "It seems like this corn-girl is adamant not to give out her knowledge for free. What will you do? " << endl;
        WeightedDialogue ACTONE_CornyEncounter(DIAOPT_ACTONE_CornyEncounter, DIASUC_ACTONE_CornyEncounter, DIAFAIL_ACTONE_CornyEncounter);
        ACTONE_CornyEncounter.displayOptions();
        // Gets user input and gets stat response from dialogue.
        cin >> player_choice;
        string DIASTAT_ACTONE_CornyEncounter_Response = ACTONE_CornyEncounter.getStatResponse(player_choice, cac_corny, selectedCharacter);
        while (ACTONE_CornyEncounter.getSelectedOption() == -1) {
            // Posts invalid option and prompts user to try again.
            cout << DIASTAT_ACTONE_CornyEncounter_Response;
            cout << " Please try again: ";
            // Updates player choice.
            cin >> player_choice;
            DIASTAT_ACTONE_CornyEncounter_Response = ACTONE_CornyEncounter.getStatResponse(player_choice, cac_corny, selectedCharacter);
        }

        // ACTONE_CornyFight
        if (ACTONE_CornyEncounter.getSelectedOption() == 1) {
            cout << "\"Well if you won't give them to me, then I guess I'll have to force them out of you!\" You enter a fighting stance, ready to solve your problems with violence." << endl;
            cout << "You hear the tribe murmur to each other as Corny's eyes widen." << endl << endl;
            cout << "\"Hmph. Well, if you insist...\" A tribesperson tosses her a spear, which she points towards you." << endl;
            cout << DIASTAT_ACTONE_CornyEncounter_Response;

            // DIA_ACTONE_CornyFgtS2
            if (ACTONE_CornyEncounter.isSuccessful()) {
                cout << "While Corny doesn't say a word, you hear the tribespeople clamor. You see the corn-people's furious faces as they step out of the stalks, flooding the area with their sheer numbers." << endl;
                cout << "It seems like you've utterly enraged the tribe. There's no talking your way out of this. You can stay and try to fight them off, or you can run.\nWill you try to escape?" << endl;
                Dialogue DIA_ACTONE_CornyFgtS2(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_CornyFgtS2);
                DIA_ACTONE_CornyFgtS2.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << DIA_ACTONE_CornyFgtS2.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (DIA_ACTONE_CornyFgtS2.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << DIA_ACTONE_CornyFgtS2.getResponse(player_choice);
                }

                // ACTONE_CornyFgtS2Y
                if (DIA_ACTONE_CornyFgtS2.getSelectedOption() == 1) {
                    cout << "Before proceeding, you look back and see the corn stalks rustling as the tribe stops chasing you." << endl;
                    cout << "Even though now you're safe, you can't help but feel like you've made a lot of new enemies." << endl << endl;
                    eventHandler.updateStoryCharacter(cac_corny, false, true, false, false);
                }
                // ACTONE_CornyFgtS2N
                else if (DIA_ACTONE_CornyFgtS2.getSelectedOption() == 2) {
                    cout << "After you fall unconscious from the blows, they hoist up your body and throw you out of the field." << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }
            }
            // DIA_ACTONE_CornyFgtF2
            else {
                cout << "Corny has a big grin on her face. She laughs as her tribe cheers." << endl;
                cout << "\"This is what you get for trying to fight your way out of this, you idiot! I wasn't even using a good cob, moron!\"" << endl;
                cout << "She laughs, mocking you. As frustration bubbles up inside, you feel like retaliating." << endl;
                Dialogue DIA_ACTONE_CornyFgtF2(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_CornyFgtF2);
                DIA_ACTONE_CornyFgtF2.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << DIA_ACTONE_CornyFgtF2.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (DIA_ACTONE_CornyFgtF2.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << DIA_ACTONE_CornyFgtF2.getResponse(player_choice);
                }

                // ACTONE_CornyFgtS2Y
                if (DIA_ACTONE_CornyFgtF2.getSelectedOption() == 1) {
                    cout << "\"Shut up, you field-dwelling hick! Quit laughing at me or I'll knock the corn out of your head!\"" << endl;
                    cout << "Corny goes quiet and you hear the tribespeople gasp and mutter amongst each other. After a few tense moments they emerge from the stalks, weapons ready." << endl;
                    cout << "You're pummeled into the ground by the enraged tribe!" << endl;
                    cout << "After you fall unconscious from the blows, they hoist up your body and throw you out of the field." << endl << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }
                // ACTONE_CornyFgtS2N
                else if (DIA_ACTONE_CornyFgtF2.getSelectedOption() == 2) {
                    cout << "\"I admit defeat. Please, have mercy on me...\"" << endl;
                    cout << "Corny looks taken aback, and shuts up. The tribespeople murmur amongst themselves." << endl;
                    cout << "\"You're actually showing...respect...I've never seen an outsider do that before!\" She says, astonished. \"I'm sorry for mocking you.\" Corny helps you stand up." << endl;
                    cout << "\"You don't realize how much I respect your integrity. In fact, I'll go and show you the way out.\"" << endl;
                    cout << "You, Corny, and a few members of the tribe then peruse through the maze. When finally at the exit, Corny speaks to you again." << endl;
                    cout << "\"Consider me and my people your allies. If you face any hardships out there, know that we will come to your aid.\"" << endl;
                    cout << "She smiles at you. You say your goodbyes before exiting the maze with  newfound confidence." << endl;
                    eventHandler.updateStoryCharacter(cac_corny, true, false, false, false);
                }
            }
        }
        // ACTONE_CornyAgile
        else if (ACTONE_CornyEncounter.getSelectedOption() == 2) {
            cout << "You panic. You can't think of a single thing to offer her, but it seems like she's going to be the only thing that can get you out of here." << endl;
            cout << "Taking a deep breath, you decide to take drastic measures." << endl;
            cout << DIASTAT_ACTONE_CornyEncounter_Response;

            // ACTONE_CornyAgileS
            if (ACTONE_CornyEncounter.isSuccessful()) {
                cout << "\"What the?! Let go...!\" She protests, but you're too focused on escaping the crowd of angry tribespeople chasing you." << endl;
                cout << "Eventually the mob loses your trail, and you stop, exhausted. You drop Corny and she sits on the ground." << endl;
                cout << "\"Okay, okay!\" She groans. \"I'll show you the way out! Just let me go back!\"" << endl;
                cout << "Looking at her stressed-out face, you feel a little guilty. While you accept the directions, you come up with an idea to make it up to her. Will you try and give her something in return?" << endl;
                Dialogue DIA_ACTONE_CornyAgileS(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_CornyAglS2);
                DIA_ACTONE_CornyAgileS.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << DIA_ACTONE_CornyAgileS.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (DIA_ACTONE_CornyAgileS.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << DIA_ACTONE_CornyAgileS.getResponse(player_choice);
                }

                // ACTONE_DeereAglS2Y
                if (DIA_ACTONE_CornyAgileS.getSelectedOption() == 1) {
                    cout << "\"I'm sorry. I had nothing to offer you, so I just did the first thing that came to mind...\"" << endl;
                    cout << "You say with an apologetic expression, before helping her stand." << endl;
                    cout << "\"The truth is, I came to this land to seek treasure and riches. So to make it up to you, I will share what I find with your tribe once I return.\"" << endl;
                    cout << "Corny is shocked at your sudden offer, but nods her head." << endl;
                    cout << "After she leads you to the maze's exit, she gives you a smile before turning around and disappearing into the stalks. You leave with a bittersweet feeling in your heart." << endl;
                    eventHandler.updateStoryCharacter(cac_corny, false, false, false, true);
                }
                // ACTONE_DeereAglS2N
                else if (DIA_ACTONE_CornyAgileS.getSelectedOption() == 2) {
                    cout << "After you get to the exit, she rushes back into the stalks without saying a word. You leave with a guilty feeling in your heart." << endl;
                    eventHandler.updateStoryCharacter(cac_corny, false, true, false, false);
                }
            }
            // ACTONE_DeereAglF2
            else {
                cout << "Before you can say a word, you hear the tribe's enraged shouting." << endl;
                cout << "You then feel a hard corn cob bonk you on the head, then on your back. Soon you're being absolutely pummeled by cobs, as the corn-people completely mob you!" << endl << endl;
                cout << "After you fall unconscious from the blows, they hoist up your body and throw you out of the cornfield." << endl;
                cout << "==GAME OVER!==";
                return 0;
            }
        }
        // ACTONE_CornyBrain
        else if (ACTONE_CornyEncounter.getSelectedOption() == 3) {
            cout << "You pause for a second, not knowing if you have anything to even offer in return. An idea comes to you, and you take out your satchel and rummage through it." << endl;
            cout << DIASTAT_ACTONE_CornyEncounter_Response;

            // ACTONE_CornyBrnS2
            if (ACTONE_CornyEncounter.isSuccessful()) {
                cout << "Corny is awestruck, as she takes the coin from your hand." << endl;
                cout << "\"This is...amazing! There's nothing like this to be found anywhere in Iowa!\" She smiles brightly at you. \"I can feel the fortune already! Okay traveler, I'll show you the way out of here.\"" << endl;
                cout << "Corny leads you out of the field, and after you exchange thanks and goodbyes, she returns to her people." << endl;
                eventHandler.updateStoryCharacter(cac_corny, false, false, true, false);
            }
            // ACTONE_CornyBrnF2
            else {
                cout << "For a split second you think you've tricked her, but you see her face drop into a scowl." << endl;
                cout << "\"What is this? Of course we know what forks are! How dare you insult my intelligence like this!\"" << endl;
                cout << "Some tribe members step out from the stalks, spears pointed in your direction." << endl;
                cout << "\"Do you legitimately have nothing of value to offer? What are you, some kind of impoverished cretin? Explain!\"" << endl;
                cout << "You're surrounded, and it looks like the only thing you can do is tell the truth. If not, you don't know what might happen...will you be honest with her?" << endl;
                Dialogue ACTONE_CornyBrnF2(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_CornyBrnF2);
                ACTONE_CornyBrnF2.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << ACTONE_CornyBrnF2.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (ACTONE_CornyBrnF2.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << ACTONE_CornyBrnF2.getResponse(player_choice);
                }

                // ACTONE_CornyBrnF2Y
                if (ACTONE_CornyBrnF2.getSelectedOption() == 1) {
                    cout << "\"I have nothing. I'm poor, and I desperately try to get by every day without starving. I thought that I could find treasure in the land of Iowa and bring back riches...\"" << endl;
                    cout << "You see Corny's eyes widen and she scratches her head. \"Oh...I wasn't actually expecting you to tell the truth...uh...\"" << endl;
                    cout << "The tribespeople murmur to each other. Corny thinks for a moment, then crosses her arms. 'We don't get a lot of outsiders that admit their mistakes. I thought honesty was an Iowa-only thing...";
                    cout << "but since you've shown me otherwise, I'll show you the way out.\" Corny smiles at you." << endl;
                    cout << "You, Corny, and a few members of the tribe then peruse through the maze. When you finally arrive at the exit, Corny speaks to you again." << endl << endl;
                    cout << "\"Consider me and my people your allies. If you face any hardships out there, know that we will come to your aid.\"" << endl;
                    cout << "She smiles at you. You say your goodbyes before exiting the maze with  newfound confidence." << endl;
                    eventHandler.updateStoryCharacter(cac_corny, true, false, false, false);
                }
                // ACTONE_CornyBrnF2N
                else if (ACTONE_CornyBrnF2.getSelectedOption() == 2) {
                    cout << "\"Uh, no! This fork is different from any other in existence! It was crafted with-\"" << endl;
                    cout << "\"Just shut up!\" Corny shouted. \"I think we've all had enough of this. Get out of our field!\"" << endl << endl;
                    cout << "Before you can even say anything, the tribespeople emerge from the corn stalks and surround you. They lift you up with their collective strength and march at an electric speed straight out of the field." << endl;
                    cout << "You are then thrown on the ground outside of the field, clearly not welcome anymore." << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }
            }
        }
        // ACTONE_CornyChari
        else if (ACTONE_CornyEncounter.getSelectedOption() == 4) {
            cout << "You take a deep breath, knowing you have nothing of value on your person. Taking a step forward, you try to come clean to Corny." << endl;
            cout << DIASTAT_ACTONE_CornyEncounter_Response;

            // ACTONE_CornyChariS2
            if (ACTONE_CornyEncounter.isSuccessful()) {
                cout << "Noticing the tribespeople lowering their weapons and whispering to one another, the area gets quieter. You see Corny's expression soften." << endl;
                cout << "\"I see...you have no choice but to struggle against what the world throws at you. My people also have to fight to survive every day in this maize.\"";
                cout << "She approaches you and places a hand on your shoulder.";
                cout << "\"We hate to see kind souls suffer. I will gladly show you the way to Iowa...\"" << endl;
                cout << "You, Corny, and a few members of the tribe then peruse through the maze. When you finally arrive at the exit, Corny speaks to you again." << endl << endl;
                cout << "\"Consider me and my people your allies. If you face any hardships out there, know that we will come to your aid.\"" << endl;
                cout << "She smiles at you. You say your goodbyes before exiting the maze with newfound confidence." << endl;
                eventHandler.updateStoryCharacter(cac_corny, true, false, false, false);
            }
            // ACTONE_CornyChariF2
            else {
                cout << "The area grows tenser. You hear the tribespeople chatter between each other." << endl;
                cout << "Corny crosses her arms and glares at you. \"How am I supposed to believe you? For all I know, you'll ravage this land like the ones that came before you.\"" << endl;
                cout << "Tribespeople began to emerge from the stalks, their weapons readied. Corny closes her eyes, and thinks for a second." << endl << endl;
                cout << "\"If you want to prove that you deserve the wealth you crave, then make an agreement with us. If you swear to never desecrate this land, if you can devote yourself to the corn, then we will give you something to assist you on your journey.\" Corny pauses, then speaks up again." << endl;
                cout << "\"Also, you need to share some of the treasure you find with us. Those are the rules.\"" << endl;
                cout << "Will you accept Corny's proposal?" << endl;
                Dialogue ACTONE_CornyChariF2(DIAOPT_ACTONE_PARAM_YESNO, DIAREP_ACTONE_CornyChariF2);
                ACTONE_CornyChariF2.displayOptions();

                // Then responses are inputted by the user.
                cin >> player_choice;
                cout << ACTONE_CornyChariF2.getResponse(player_choice);
                // Incase the user inputs an invalid option.
                while (ACTONE_CornyChariF2.getSelectedOption() == -1) {
                    cout << " Please try again: ";
                    cin >> player_choice;
                    cout << ACTONE_CornyChariF2.getResponse(player_choice);
                }

                // ACTONE_CornyChariF2Y
                if (ACTONE_CornyChariF2.getSelectedOption() == 1) {
                    cout << "The tribespeople emerge from the field once more and surround you, before grabbing you and forcing you to sit." << endl;
                    cout << "Corny approaches you with a cup of a black substance. She digs her thumb in it before smearing a few stripes of it on your face." << endl;
                    cout << "\"This is a traditional external potion my people use as war paint. It will enhance your movement, making you faster. Use this gift wisely, and don't break our promise.\"";
                    cout << "After this, you, Corny, and a few members of the tribe then peruse through the maze. When finally at the exit, Corny speaks to you again." << endl;
                    cout << "\"Good luck out there. If you ever need assistance, we will try to come to your aid.\"" << endl;
                    cout << "You leave the maze with a rather uneasy feeling." << endl;
                    eventHandler.updateStoryCharacter(cac_corny, false, false, false, true);

                    // Enhances agility from war paint.
                    eventHandler.updatePlayerCharacter(selectedCharacter, -1, selectedCharacter.getAStat() + 3, -1, -1);
                    cout << eventHandler.getLogs();
                }
                // ACTONE_CornyChariF2N
                else if (ACTONE_CornyChariF2.getSelectedOption() == 2) {
                    cout << "The tribespeople emerge from the corn stalks and surround you. They lift you up with their collective strength and march at an electric speed straight out of the field." << endl;
                    cout << "You are then thrown on the ground outside of the field, clearly not welcome anymore." << endl;
                    cout << "==GAME OVER!==";
                    return 0;
                }
            }
        }
    }

    // End of act 1
    cout << "\nAnd with that, you have successfully entered the Land of Iowa!" << endl;
    cout << "The road ahead of you holds many terrifying and treacherous perils, but now that you've gotten this far you have no intention of turning back now." << endl;
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
    if (player_location == "maize") {
        cout << "Corny Status:" << endl;
        cout << (cac_corny.getFriendStatus() ? "You have seem to gain her trust.\n" : "");
        cout << (cac_corny.getEnemyStatus() ? "You have angered Corny and her tribe.\n" : "");
        cout << (cac_corny.getTrickedStatus() ? "You have tricked her.\n" : "");
        cout << (cac_corny.getNeutralStatus() ? "You have made a deal with Corny and her Tribe.\n" : "");
    }
    else {
        cout << "You have not met Corny or her tribe in your travels, fortunately." << endl;
    }

    return 0;
}

