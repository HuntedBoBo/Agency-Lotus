#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
	int fight;
	int agile;
	int charisma;
	int brains;
public:
	int getFStat();
	int getAStat();
	int getCStat();
	int getBStat();
	Character();
	Character(int fight, int agile, int charisma, int brains);
};

class storyChara : public Character {
private:
	std::string charaName;
public:
	//statuses for NPC's
	bool isFriend;
	bool isEnemy;
	bool isTricked;
	bool isNuetral;
};

#endif