/*
*Name: Jhon Paul Espiritu, used in Project with Agent Lotus.
*Date: 2/18/2024
*Email: jespiritu@dmacc.edu
*
* Event header file for the Event class.
*/

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
	// Handles interaction in story characters and dialogue.
	void progressDialogue();
	void switchCharacter(int index);
	// Handles how characters are updated.
	void updateCharacter(storyChara chara);
private:
	std::vector<storyChara> storyCharacters;
	//vector<dialogue> dialogueList; // not implemented yet.
	playerChara currentCharacter;
};

#endif