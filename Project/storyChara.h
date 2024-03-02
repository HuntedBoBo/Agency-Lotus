#ifndef STORYCHARA_H
#define STORYCHARA_H

#include <string>
#include "Character.h"

class storyChara : public Character {
private:
	std::string charaName;
	bool isFriend = false;
	bool isEnemy = false;
	bool isTricked = false;
	bool isNeutral = false;
public:
	// Getter for friend status.
	bool getFriendStatus();
	bool getEnemyStatus();
	bool getTrickedStatus();
	bool getNeutralStatus();

	// Setter for friend status.
	void setFriendStatus(bool isFriend);
	void setEnemyStatus(bool isEnemy);
	void setTrickedStatus(bool isTricked);
	void setNeutralStatus(bool isNeutral);

	std::string getCharaName();
	storyChara();
	storyChara(std::string name, int fight, int agile, int charisma, int brains);
};

#endif