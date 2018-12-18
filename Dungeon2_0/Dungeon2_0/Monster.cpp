#include "Monster.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Monster::Monster()
{

}

Monster::Monster(string name, string type, int health, int attack)
{
	monsterName = name;
	monsterType = type;
	monsterHealth = health;
	monsterAttack = attack;
}


Monster::~Monster()
{
}

string Monster::getName()
{
	return monsterName;
}

string Monster::getType()
{
	return monsterType;
}

int Monster::getHealth()
{
	return monsterHealth;
}

void Monster::takeDamage(int damage)
{
	monsterHealth -= damage;
	if (monsterHealth < 1)
		monsterHealth = 0;
}

/*
string Monster::attack(Hero& hero)
{
	hero.takeDamage(monsterAttack);
	cout << monsterName << " dealt "<< monsterAttack + " damage.\n";
	if (hero.getHealth() != 0)
	{
		cout << "Your health is now " << hero.getHealth() << "\n\n\n";
		return "alive";
	}
	else
		return "dead";
}
*/

int Monster::getAttack()
{
	return monsterAttack;
}