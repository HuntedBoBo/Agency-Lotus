/*
*Name: Jhon Paul Espiritu, used in Project with Agent Lotus.
*Date: 2/18/2024
*Email: jespiritu@dmacc.edu
*
* Event header file for the Event class.
*/

#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <string>

/// <summary>
/// Event class that updates characters and logs changes.
/// </summary>
class Event {
public:
	// Handles how characters are updated.
	void updateStoryCharacter(storyChara& chara, bool isFriend, bool isEnemy, bool isTricked, bool isNeutral);
	void updatePlayerCharacter(playerChara& chara, int fight, int agile, int charisma, int brains);

	std::string getLogs();
private:
	int eventParameter;
	std::vector<std::string> logOfChanges;
	std::vector<storyChara> storyCharacters;
	playerChara currentCharacter;
};

#endif