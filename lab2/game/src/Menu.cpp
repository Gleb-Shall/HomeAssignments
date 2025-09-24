#include "Menu.h"
#include "Player.h"
#include <iostream>

void Menu::ShowMain() {
    std::cout << "=== MAIN MENU ===" << std::endl;
    std::cout << "1. Play" << std::endl;
    std::cout << "2. Inventory" << std::endl;
    std::cout << "3. Statistics" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose option: ";
}

void Menu::ShowInventory() {
    std::cout << "=== INVENTORY ===" << std::endl;
    std::cout << "Player items will be displayed here" << std::endl;
}

void Menu::ShowStats() {
    std::cout << "=== STATISTICS ===" << std::endl;
    std::cout << "Player characteristics will be displayed here" << std::endl;
}

void Menu::HandleInput() {
    std::cout << "Processing input..." << std::endl;
}

void Menu::ExitMenu() {
    std::cout << "Exiting menu." << std::endl;
}

void Menu::ShowBattleMenu() {
    std::cout << "=== BATTLE MENU ===" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Defend" << std::endl;
    std::cout << "3. Use item" << std::endl;
    std::cout << "4. Run away" << std::endl;
    std::cout << "Choose action: ";
}

void Menu::ShowShopMenu() {
    std::cout << "=== SHOP ===" << std::endl;
    std::cout << "1. View goods" << std::endl;
    std::cout << "2. Buy" << std::endl;
    std::cout << "3. Sell" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose option: ";
}
