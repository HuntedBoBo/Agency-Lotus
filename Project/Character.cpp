#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

int Character::getFStat() {
	return fight;
}

int Character::getAStat() {
	return agile;
}

int Character::getCStat() {
	return charisma;
}

int Character::getBStat() {
	return brains;
}

Character::Character() {

}

Character::Character(int fight, int agile, int charisma, int brains) :
		fight(fight), agile(agile), charisma(charisma), brains(brains) {}