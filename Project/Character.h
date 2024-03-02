#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
	int fight = 0;
	int agile = 0;
	int charisma = 0;
	int brains = 0;
public:
	// Getters
	int getFStat();
	int getAStat();
	int getCStat();
	int getBStat();
	Character();
	Character(int fight, int agile, int charisma, int brains);
};

#endif