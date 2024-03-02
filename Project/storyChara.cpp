#include <iostream>
#include <string>
#include "storyChara.h"

using namespace std;

/// <summary>
/// The story character's name.
/// </summary>
string storyChara::getCharaName() {
	return charaName;
}

// Getters
bool storyChara::getFriendStatus() {
	return isFriend;
}

bool storyChara::getEnemyStatus() {
	return isEnemy;
}

bool storyChara::getTrickedStatus() {
	return isTricked;
}

bool storyChara::getNeutralStatus() {
	return isNeutral;
}

// Setters
void storyChara::setFriendStatus(bool isFriend) {
	this->isFriend = isFriend;
}

void storyChara::setEnemyStatus(bool isEnemy) {
	this->isEnemy = isEnemy;
}

void storyChara::setTrickedStatus(bool isTricked) {
	this->isTricked = isTricked;
}

void storyChara::setNeutralStatus(bool isNeutral) {
	this->isNeutral = isNeutral;
}

storyChara::storyChara() {

}

/// <summary>
/// Creates a new storyChara object with a name, fight, agility, charisma, and brains stat.
/// </summary>
storyChara::storyChara(string name, int fight, int agile, int charisma, int brains) :
	charaName(name), Character(fight, agile, charisma, brains) { }