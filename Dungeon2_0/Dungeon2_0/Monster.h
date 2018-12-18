#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <iostream>
#include <sstream>

class Monster
{
private:
	std::string monsterName;
	std::string monsterType;
	int monsterHealth;
	int monsterAttack;

public:
	Monster();

	Monster(std::string name, std::string type, int health, int attack);

	~Monster();

	std::string getName();
	std::string getType();
	int getHealth();
	void takeDamage(int damage);
	//std::string attack(Hero& hero);
	int getAttack();



};

#endif