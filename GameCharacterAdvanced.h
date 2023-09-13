//Name-Rajveer Singh
//Course-CS-355
//Assignment-3
//Date-09/01/2023
//Program Description-We will create a C++ class named GameCharacter that represents a character in a
//video game.
#ifndef GAMECHARACTERADVANCED_H
#define GAMECHARACTERADVANCED_H

#include <iostream>
#include <string>
using namespace std;
class GameCharacter {
private:
    string name;
    int maxHealth;
    int healthPoints;
    int attackPoints;
    int defensePoints;
    bool isAlive;
    time_t lastSaveTime;

public:
    GameCharacter(const string& name, int maxHealth, int attackPoints, int defensePoints);
    
    string getName() const;
    int getMaxHealth() const;
    int getHealthPoints() const;
    int getAttackPoints() const;
    int getDefensePoints() const;
    bool getIsAlive() const;
    
    void takeDamage(int damage);
    void attack(GameCharacter& target);

    GameCharacter operator+(const GameCharacter& other);
    bool operator>(const GameCharacter& other);
    bool operator<(const GameCharacter& other);
    
    friend ostream& operator<<(ostream& os, const GameCharacter& character);
    
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    void displayDateTimeOfLastSave() const;
    void displayTimeSinceLastSave() const;
};

#endif
