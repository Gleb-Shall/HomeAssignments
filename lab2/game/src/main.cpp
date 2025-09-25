/**
 * @file main.cpp
 * @brief Main entry point for the RPG game
 * @author Gleb Shikunov
 */

#include "Game.h"

/**
 * @brief Main function
 * @return Exit status code
 * 
 * Entry point of the application. Creates a new game instance,
 * initializes it, runs the main game loop, and cleans up resources.
 */
int main() {
    Game* game = new Game();
    game->Init();
    game->Run();
    game->Exit();
    delete game;
    return 0;
}
