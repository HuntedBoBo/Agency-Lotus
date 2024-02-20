#include <iostream>
#include <string>
#include "playerChara.h"

using namespace std;

string playerChara::getPlayerName() {
	return playerName;
}

playerChara::playerChara() {

}

playerChara::playerChara(string name, int fight, int agile, int charisma, int brains) :
	playerName(name), Character(fight, agile, charisma, brains) { }