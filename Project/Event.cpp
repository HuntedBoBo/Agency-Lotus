/*
*Name: Jhon Paul Espiritu, used in Project with Agent Lotus.
*Date: 2/18/2024
*Email: jespiritu@dmacc.edu
*
* Event class that is used to progress through the many situations of the story.
*/

#include <vector>
#include <string>
#include "playerChara.h"
#include "storyChara.h"
#include "Event.h"

using namespace std;

/// <summary>
/// Updates story character on their status with the player.
/// </summary>
/// <param name="chara">Story chara to be changed.</param>
/// <param name="isFriend">Friend status of story chara.</param>
/// <param name="isEnemy">Enemy status of story chara.</param>
/// <param name="isTricked">Tricked status of story chara.</param>
/// <param name="isNeutral">Neutral status of story chara.</param>
void Event::updateStoryCharacter(storyChara& chara, bool isFriend, bool isEnemy, bool isTricked, bool isNeutral) {
	// If friend status is different, set chara's friend status and then add it to logs.
	if (chara.getFriendStatus() != isFriend) {
		chara.setFriendStatus(isFriend);
		logOfChanges.push_back(chara.getCharaName() + " friend status was changed to " + (isFriend ? "true." : " false."));
	}

	// If enemy status is different, set chara's friend status and then add it to logs.
	if (chara.getEnemyStatus() != isEnemy) {
		chara.setEnemyStatus(isEnemy);
		logOfChanges.push_back(chara.getCharaName() + " enemy status was changed to " + (isEnemy ? "true." : " false."));
	}

	// If friend status is different, set chara's friend status and then add it to logs.
	if (chara.getTrickedStatus() != isTricked) {
		chara.setTrickedStatus(isTricked);
		logOfChanges.push_back(chara.getCharaName() + " tricked status was changed to " + (isTricked ? "true." : " false."));
	}

	// If friend status is different, set chara's friend status and then add it to logs.
	if (chara.getNeutralStatus() != isNeutral) {
		chara.setNeutralStatus(isNeutral);
		logOfChanges.push_back(chara.getCharaName() + " neutral status was changed to " + (isNeutral ? "true." : " false."));
	}
}

/// <summary>
/// Updates player character depending on their stats (-1 default, meaning change no value).
/// </summary>
/// <param name="chara">Player character that needs to be changed.</param>
/// <param name="fight">Character's fight stat to be changed.</param>
/// <param name="agile">Character's agile stat to be changed.</param>
/// <param name="charisma">Character's charisma stat to be changed.</param>
/// <param name="brains">Character's brains stat to be changed.</param>
void Event::updatePlayerCharacter(playerChara& chara, int fight = -1, int agile = -1, int charisma =-1, int brains = -1) {
	// If fight is not the default value, change it.
	if (fight != -1) {
		logOfChanges.push_back(chara.getPlayerName() + "'s fight stat was changed from " + to_string(chara.getFStat()) + " to " + to_string(fight));
		chara.setFStat(fight);
	}
	
	// If fight is not the default value, change it.
	if (agile != -1) {
		logOfChanges.push_back(chara.getPlayerName() + "'s agile stat was changed from " + to_string(chara.getAStat()) + " to " + to_string(agile));
		chara.setAStat(agile);
	}

	// If fight is not the default value, change it.
	if (charisma != -1) {
		logOfChanges.push_back(chara.getPlayerName() + "'s charisma stat was changed from " + to_string(chara.getCStat()) + " to " + to_string(charisma));
		chara.setCStat(charisma);
	}

	// If fight is not the default value, change it.
	if (brains != -1) {
		logOfChanges.push_back(chara.getPlayerName() + "'s brains stat was changed from " + to_string(chara.getBStat()) + " to " + to_string(brains));
		chara.setBStat(brains);
	}
}

/// <summary>
/// Gets a log of changes that have been made from updates.
/// </summary>
/// <returns>String value listing changes.</returns>
string Event::getLogs() {
	// Creates a return value and an iterator.
	int i = 0;
	string returnString;

	// Iterates through log of changes and concatenates it to returnString.
	for (const auto& s : logOfChanges) {
		returnString += logOfChanges.at(i) + "\n";
		i++;
	}

	return returnString;
}