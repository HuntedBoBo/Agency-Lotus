#ifndef PLAYERCHARA_H
#define PLAYERCHARA_H

#include <string>
#include "Character.h"

class playerChara : public Character {
private:
	std::string playerName;
public:
	std::string getPlayerName();
	playerChara();
	playerChara(std::string name, int fight, int agile, int charisma, int brains);
};

#endif
