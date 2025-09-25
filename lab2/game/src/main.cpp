#include "Game.h"

int main() {
    Game* game = new Game();
    game->Init();
    game->Run();
    game->Exit();
    delete game;
    return 0;
}
