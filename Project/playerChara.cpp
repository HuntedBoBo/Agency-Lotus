#include <iostream>
#include <string>
#include "playerChara.h"

using namespace std;

string playerChara::getPlayerName() {
	return playerName;
}

void playerChara::setFStat(int stat) {
	fight = stat;
}

void playerChara::setAStat(int stat) {
	agile = stat;
}

void playerChara::setCStat(int stat) {
	charisma = stat;
}

void playerChara::setBStat(int stat) {
	brains = stat;
}

playerChara::playerChara() {

}

playerChara::playerChara(string name, int fight, int agile, int charisma, int brains) :
	playerName(name), Character(fight, agile, charisma, brains) { }