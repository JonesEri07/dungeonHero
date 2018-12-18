#ifndef HERO_H
#define HERO_H
#include <string>
#include <sstream>
#include "MAP.h"

class Hero
{
private:
	std::string heroName;
	int health;
	std::stringstream inventory;
	Room location;

	struct weapon 
	{
		std::string weaponName;
		int damage;
		weapon* nextWeapon;
		weapon(std::string name, int dmg) : weaponName(name), damage(dmg), nextWeapon(NULL) {}
	};
	weapon* wpn;
	weapon* cur;
	
public:
	Hero();
	Hero(std::string name);

	~Hero();

	//Info getters
	void setHeroName(std::string name);
	std::string getHeroName();

	int getHealth();
	void takeDamage(int damage);

	std::string getInventory();
	std::string getWeapons();
	std::string addItem(std::string thing);
	void removeItem(std::string item_);

	std::string getHeroInfo();

	Room getLocation();
	void setLocation(Room rm);

	std::string canDo();

	//Actions
	std::string move(MAP dungeon, std::string command);
	std::string attack(Monster& monster, std::string weapon_);
	std::string search();
	std::string take();
	std::string use(MAP& dungeon, std::string& grab);

	void clearWeapons();
};

#endif
