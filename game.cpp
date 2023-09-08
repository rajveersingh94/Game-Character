//Name-Rajveer Singh
//Course-CS-355
//Assignment-3
//Date-09/01/2023
//Program Description-We will create a C++ class named GameCharacter that represents a character in a
//video game.
#include "GameCharacterAdvanced.h"
#include <iostream>
using namespace std;

int main() {
    GameCharacter char1("Jatt", 100, 20, 10);
    GameCharacter char2("Raja", 80, 30, 5);
    GameCharacter char3("Wazir", 90, 25, 15);

    
    char1.attack(char2);
    char2.attack(char1);
    char1.attack(char2);

    // Display results
    cout << "Character 1:\n" << char1 << "\n";
    cout << "Character 2:\n" << char2 << "\n";

    // Compare character health
    if (char1 > char2) {
        cout << "Character 1 is stronger."<<endl;
    } else if (char1 < char2) {
        cout << "Character 2 is stronger."<<endl;
    } else {
        cout << "Both characters have equal health."<<endl;
    }

    // Combine characters
    GameCharacter combinedCharacter = char1 + char3;
    cout << "Combined Character:"<<endl << combinedCharacter << endl;

    // Save and load character details
    char1.saveToFile("character1.txt");
    GameCharacter loadedCharacter("Empty", 0, 0, 0);
    loadedCharacter.loadFromFile("character1.txt");
    cout << "Loaded Character:\n" << loadedCharacter << endl;

    return 0;
}
