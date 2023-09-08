//Name-Rajveer Singh
//Course-CS-355
//Assignment-3
//Date-09/01/2023
//Program Description-We will create a C++ class named GameCharacter that represents a character in a
//video game.

#include "GameCharacterAdvanced.h"
#include <fstream>
using namespace std;

/*
Constructor initializes a GameCharacter object with the provided parameters.
- name: Character's name
- maxHealth: Maximum health points
- attackPoints: Attack points
- defensePoints: Defense points
*/

GameCharacter::GameCharacter(const string& name, int maxHealth, int attackPoints, int defensePoints)
    : name(name), maxHealth(maxHealth), healthPoints(maxHealth), attackPoints(attackPoints), defensePoints(defensePoints), isAlive(true) {}
/*
Function name-getName
Function description-Getter for the character's name
Return Value-name
*/
string GameCharacter::getName() const {
    return name;
}
/*
Function name-getMaxHealth
Function description-Getter for the character's maximum health points
Return Value-maxHealth
*/
int GameCharacter::getMaxHealth() const {
    return maxHealth;
}
/*
Function name-getHealthPoints
Function description-Getter for the character's current health points
Return Value-healthPoints
*/
int GameCharacter::getHealthPoints() const {
    return healthPoints;
}
/*
Function name-getAttackPoints
Function description-Getter for the character's attack points
Return Value-points
*/
int GameCharacter::getAttackPoints() const {
    return attackPoints;
}
/*
Function name-getDefensePoints
Function description-Getter for the character's defense points
Return Value-points
*/
int GameCharacter::getDefensePoints() const {
    return defensePoints;
}
/*
Function name-getIsAlive
Function description-Getter for the character's alive status
Return Value-staus of character
*/
bool GameCharacter::getIsAlive() const {
    return isAlive;
}
/*
Function name-takeDamage
Function description-Function to reduce the character's health points when they take damage
Return Value
*/
void GameCharacter::takeDamage(int damage) {
    healthPoints -= damage;
    if (healthPoints <= 0) {
        healthPoints = 0;
        isAlive = false;
    }
}
/*
Function name-attack
Function description-Function for a character to attack another character
Return Value-none
*/
void GameCharacter::attack(GameCharacter& target) {
    int damage = attackPoints - target.getDefensePoints();
    if (damage > 0) {
        target.takeDamage(damage);
    }
}
/*
Function name
Function description-Overloaded addition operator to combine two characters
Return Value-charater
*/
GameCharacter GameCharacter::operator+(const GameCharacter& other) {
    GameCharacter newCharacter(name + "_" + other.name, (maxHealth + other.maxHealth) / 2, (attackPoints + other.attackPoints) / 2, (defensePoints + other.defensePoints) / 2);
    return newCharacter;
}
/*
Function name
Function description-Overloaded greater than operator to compare character health
Return Value-heathpoints
*/
bool GameCharacter::operator>(const GameCharacter& other) {
    return healthPoints > other.healthPoints;
}
/*
Function name
Function description-Overloaded less than operator to compare character health
Return Value-heathpoints
*/
bool GameCharacter::operator<(const GameCharacter& other) {
    return healthPoints < other.healthPoints;
}
/*
Function description-Overloaded stream insertion operator to display character information
*/
ostream& operator<<(ostream& os, const GameCharacter& character) {
    os << "Name: " << character.name << endl;
    os << "Max Health: " << character.maxHealth << endl;
    os << "Health Points: " << character.healthPoints << endl;
    os << "Attack Points: " << character.attackPoints << endl;
    os << "Defense Points: " << character.defensePoints << endl;
    os << "Is Alive: " << (character.isAlive ? "Yes" : "No") << endl;
    return os;
}
/*
Function name-saveToFile
Function description-Function to save character details to a file
Return Value-none
*/
void GameCharacter::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << name << endl;
        file << maxHealth << endl;
        file << healthPoints << endl;
        file << attackPoints << endl;
        file << defensePoints << endl;
        file << isAlive << endl;
        file.close();
    }
}
/*
Function name-loadFromFile
Function description-Function to load character details from a file
Return Value-none
*/
void GameCharacter::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        getline(file, name);
        file >> maxHealth;
        file >> healthPoints;
        file >> attackPoints;
        file >> defensePoints;
        file >> isAlive;
        file.close();
    }
}
