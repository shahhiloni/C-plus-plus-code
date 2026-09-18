#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Character Class to handle both Player and Monsters
class Character {
public:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;

    Character(std::string n, int hp, int atk) {
        name = n;
        health = hp;
        maxHealth = hp;
        attackPower = atk;
    }

    bool isAlive() {
        return health > 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        std::cout << name << " takes " << damage << " damage! (HP: " << health << "/" << maxHealth << ")\n";
    }

    int attack() {
        // Adds a little bit of randomness to the attack power
        int variation = (rand() % 5) - 2; // -2 to +2
        int finalDamage = attackPower + variation;
        if (finalDamage < 1) finalDamage = 1;
        return finalDamage;
    }
};

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "--- Welcome to the C++ Dungeon Crawler! ---\n\n";
    std::cout << "Enter your hero's name: ";
    std::string playerName;
    std::getline(std::cin, playerName);

    // Initialize characters
    Character player(playerName, 100, 15);
    Character goblin("Goblin Grunt", 50, 10);

    std::cout << "\nAn angry " << goblin.name << " lunges out of the shadows!\n";

    // The Main Game / Battle Loop
    while (player.isAlive() && goblin.isAlive()) {
        std::cout << "\n====================================\n";
        std::cout << "What do you want to do?\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Heal (Restores 25 HP)\n";
        std::cout << "Choose an option (1-2): ";
        
        int choice;
        std::cin >> choice;

        std::cout << "\n";

        // Player's Turn
        if (choice == 1) {
            std::cout << player.name << " swings their sword!\n";
            int damageDealt = player.attack();
            goblin.takeDamage(damageDealt);
        } 
        else if (choice == 2) {
            player.health += 25;
            if (player.health > player.maxHealth) player.health = player.maxHealth;
            std::cout << player.name << " drinks a potion! (HP: " << player.health << "/" << player.maxHealth << ")\n";
        } 
        else {
            std::cout << "Invalid choice! You stumble and miss your turn.\n";
        }

        // Check if monster died
        if (!goblin.isAlive()) {
            std::cout << "\nVictory! You defeated the " << goblin.name << "!\n";
            break;
        }

        // Monster's Turn
        std::cout << "\nThe " << goblin.name << " strikes back!\n";
        int damageReceived = goblin.attack();
        player.takeDamage(damageReceived);

        // Check if player died
        if (!player.isAlive()) {
            std::cout << "\nDefeat! " << player.name << " perished in the dungeon...\n";
        }
    }

    std::cout << "\n--- Game Over ---\n";
    return 0;
}
