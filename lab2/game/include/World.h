#pragma once
#include <vector>
#include <iostream>
#include "Utils.h"
#include "MapTile.h"

class World {
public:
    World() : width(10), height(10), playerX(0), playerY(0), enemyX(-1), enemyY(-1), enemyPresent(false), npcX(0), npcY(5), merchantX(0), merchantY(5), hasMerchant(false), secondNPCX(-1), secondNPCY(-1), hasSecondNPC(false), dragonX(-1), dragonY(-1), hasDragon(false), dragonDefeated(false) {
        grid.resize(height, std::vector<MapTile>(width));
    }
    void Generate() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                grid[y][x].SetType('.');
                grid[y][x].SetWalkable(true);
                grid[y][x].SetOccupied(false);
            }
        }
        grid[playerY][playerX].SetType('P');
        grid[playerY][playerX].SetOccupied(true);
        // no enemies at start
        grid[npcY][npcX].SetType('N');
        grid[npcY][npcX].SetOccupied(true); // нельзя зайти на клетку NPC
        // no merchant at start; appears after quest completion
    }
    void Draw() {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                std::cout << grid[y][x].GetType();
            }
            std::cout << '\n';
        }
    }
    void Update() {}
    MapTile* GetTile(int x, int y) {
        if (x < 0 || y < 0 || x >= width || y >= height) return nullptr;
        return &grid[y][x];
    }
    bool MovePlayer(int dx, int dy) {
        int nx = playerX + dx;
        int ny = playerY + dy;
        if (nx < 0 || ny < 0 || nx >= width || ny >= height) return false;
        if (!grid[ny][nx].IsWalkable()) return false;
        grid[playerY][playerX].SetType('.');
        grid[playerY][playerX].SetOccupied(false);
        playerX = nx; playerY = ny;
        grid[playerY][playerX].SetType('P');
        grid[playerY][playerX].SetOccupied(true);
        return true;
    }
    bool MoveEnemyTowardPlayer() {
        int dx = 0, dy = 0;
        if (enemyX < playerX) dx = 1; else if (enemyX > playerX) dx = -1;
        if (enemyY < playerY) dy = 1; else if (enemyY > playerY) dy = -1;
        int nx = enemyX + dx;
        int ny = enemyY + dy;
        if (nx < 0 || ny < 0 || nx >= width || ny >= height) return false;
        if (!grid[ny][nx].IsWalkable()) return false;
        // avoid stepping onto NPC/M
        if ((nx == npcX && ny == npcY) || (hasMerchant && nx == merchantX && ny == merchantY)) return false;
        grid[enemyY][enemyX].SetType('.');
        grid[enemyY][enemyX].SetOccupied(false);
        enemyX = nx; enemyY = ny;
        grid[enemyY][enemyX].SetType('E');
        grid[enemyY][enemyX].SetOccupied(true);
        return true;
    }
    bool MoveEnemyRandom() {
        static const int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        for (int i = 0; i < 4; ++i) {
            int nx = enemyX + dirs[i][0];
            int ny = enemyY + dirs[i][1];
            if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            if (!grid[ny][nx].IsWalkable()) continue;
            if ((nx == npcX && ny == npcY) || (hasMerchant && nx == merchantX && ny == merchantY)) continue;
            grid[enemyY][enemyX].SetType('.');
            grid[enemyY][enemyX].SetOccupied(false);
            enemyX = nx; enemyY = ny;
            grid[enemyY][enemyX].SetType('E');
            grid[enemyY][enemyX].SetOccupied(true);
            return true;
        }
        return false;
    }
    int DistToEnemy() const { if (!enemyPresent) return 9999; return std::max(std::abs(playerX - enemyX), std::abs(playerY - enemyY)); }
    int GetPlayerX() const { return playerX; }
    int GetPlayerY() const { return playerY; }
    int GetEnemyX() const { return enemyX; }
    int GetEnemyY() const { return enemyY; }
    void SetEnemyPos(int x, int y) { enemyX = x; enemyY = y; }
    bool HasEnemy() const { return enemyPresent; }
    bool IsNearEnemy() const { return enemyPresent && std::abs(playerX - enemyX) <= 2 && std::abs(playerY - enemyY) <= 2; }
    bool IsAtNPC() const { return playerX == npcX && playerY == npcY; }
    bool IsAtMerchant() const { return playerX == merchantX && playerY == merchantY; }
    bool IsNearNPC() const { return std::max(std::abs(playerX - npcX), std::abs(playerY - npcY)) <= 1; }
    bool IsNearMerchant() const { return hasMerchant && std::max(std::abs(playerX - merchantX), std::abs(playerY - merchantY)) <= 1; }
    int GetNPCX() const { return npcX; }
    int GetNPCY() const { return npcY; }
    int GetMerchantX() const { return merchantX; }
    int GetMerchantY() const { return merchantY; }
    bool HasMerchant() const { return hasMerchant; }
    void ActivateMerchantAtNPC() {
        hasMerchant = true;
        merchantX = npcX; merchantY = npcY;
        grid[npcY][npcX].SetType('M');
        grid[npcY][npcX].SetOccupied(true); // нельзя зайти на клетку торговца
    }
    void SpawnSecondNPC();
    bool IsNearSecondNPC() const;
    void SpawnDragon();
    bool IsDragonDefeated() const;
    bool HasDragon() const { return hasDragon; }
    int GetDragonX() const { return dragonX; }
    int GetDragonY() const { return dragonY; }
    void SetDragonDefeated(bool defeated) { dragonDefeated = defeated; }
    void ClearDragon() {
        if (hasDragon) {
            grid[dragonY][dragonX].SetType('.');
            grid[dragonY][dragonX].SetOccupied(false);
        }
        hasDragon = false;
        dragonX = -1; dragonY = -1;
    }
    bool SpawnEnemyAt(int x, int y) {
        if (x < 0 || y < 0 || x >= width || y >= height) return false;
        if (grid[y][x].IsOccupied()) return false;
        enemyX = x; enemyY = y; enemyPresent = true;
        grid[y][x].SetType('E');
        grid[y][x].SetOccupied(true);
        return true;
    }
    void ClearMainEnemy() {
        if (enemyPresent) {
            grid[enemyY][enemyX].SetType('.');
            grid[enemyY][enemyX].SetOccupied(false);
        }
        enemyPresent = false;
        enemyX = -1; enemyY = -1;
    }
    bool SpawnEnemy() {
        const int candidates[][2] = { {3,0}, {7,2}, {2,7}, {6,6} };
        for (auto &c : candidates) {
            if (SpawnEnemyAt(c[0], c[1])) {
                std::cout << "Main enemy spawned at (" << c[0] << "," << c[1] << ")" << std::endl;
                return true;
            }
        }
        std::cout << "Failed to spawn main enemy" << std::endl;
        return false;
    }
    // Additional lightweight enemies (positions only)
    bool SpawnExtraEnemy() {
        const int candidates[][2] = { {7,2}, {2,7}, {6,6}, {8,1}, {1,8} };
        for (auto &c : candidates) {
            int x = c[0], y = c[1];
            if (x < 0 || y < 0 || x >= width || y >= height) continue;
            if (grid[y][x].IsOccupied()) continue;
            grid[y][x].SetType('E');
            grid[y][x].SetOccupied(true);
            extraEnemies.push_back({x,y});
            std::cout << "Extra enemy spawned at (" << x << "," << y << ")" << std::endl;
            return true;
        }
        std::cout << "Failed to spawn extra enemy" << std::endl;
        return false;
    }
    void MoveExtraEnemies() {
        static const int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        for (auto &pos : extraEnemies) {
            int choice = Utils::RandomInt(0,3);
            int nx = pos.first + dirs[choice][0];
            int ny = pos.second + dirs[choice][1];
            if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            if (!grid[ny][nx].IsWalkable()) continue;
            if ((nx == npcX && ny == npcY) || (hasMerchant && nx == merchantX && ny == merchantY)) continue;
            // also avoid player and main enemy
            if ((nx == playerX && ny == playerY) || (enemyPresent && nx == enemyX && ny == enemyY)) continue;
            // avoid colliding with other extras
            bool occupiedByExtra = false; for (const auto &p2 : extraEnemies) { if (&p2 != &pos && p2.first == nx && p2.second == ny) { occupiedByExtra = true; break; } }
            if (occupiedByExtra) continue;
            grid[pos.second][pos.first].SetType('.');
            grid[pos.second][pos.first].SetOccupied(false);
            pos.first = nx; pos.second = ny;
            grid[ny][nx].SetType('E');
            grid[ny][nx].SetOccupied(true);
        }
    }
    // If an enemy is adjacent to player, return its position and remove it from extras (to engage)
    bool EngageAdjacentExtraEnemy(int &ex, int &ey) {
        for (size_t i = 0; i < extraEnemies.size(); ++i) {
            int x = extraEnemies[i].first, y = extraEnemies[i].second;
            if (std::max(std::abs(playerX - x), std::abs(playerY - y)) <= 1) {
                ex = x; ey = y;
                // clear from map; will be handled by main enemy slot
                grid[y][x].SetType('.');
                grid[y][x].SetOccupied(false);
                extraEnemies.erase(extraEnemies.begin() + i);
                return true;
            }
        }
        return false;
    }
private:
    int width, height;
    int playerX, playerY;
    int enemyX, enemyY;
    bool enemyPresent;
    int npcX, npcY;
    int merchantX, merchantY;
    bool hasMerchant;
    int secondNPCX, secondNPCY;
    bool hasSecondNPC;
    int dragonX, dragonY;
    bool hasDragon;
    bool dragonDefeated;
    std::vector<std::vector<MapTile>> grid;
    std::vector<std::pair<int,int>> extraEnemies;
};
