#ifndef PLAYERCHARA_H
#define PLAYERCHARA_H

#include <string>
#include "Character.h"

/// <summary>
/// Derived class of Character, serves as a representation 
/// </summary>
class playerChara : public Character {
private:
	std::string playerName;
public:
	void setFStat(int stat);
	void setAStat(int stat);
	void setCStat(int stat);
	void setBStat(int stat);

	std::string getPlayerName();
	playerChara();
	playerChara(std::string name, int fight, int agile, int charisma, int brains);
};

#endif
