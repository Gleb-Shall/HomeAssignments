#pragma once
class Player; // forward declare

class Enemy {
public:
    Enemy();
    Enemy(int health, int attack);
    void Attack(Player& player);
    void Defend();
    void Think(Player& player);
    void TakeDamage(int dmg);
    void DropLoot();

    int GetHP() const;
    bool IsDead() const { return hp <= 0; }
    bool HasBuff() const;
    void SetMagical(bool magical) { isMagical = magical; }
    bool IsMagical() const { return isMagical; }
    void Reset(); // Reset enemy to initial state
private:
    int hp;
    int attackPower;
    bool defending;
    bool isMagical;
    bool hasBuff;
};
