#include "Hero.h"
#include <iostream>
#include <string>
#define DEFAULT_HEALTH 100

using namespace std;


Hero::Hero()
{
	health = DEFAULT_HEALTH;
	wpn = NULL;
	cur = NULL;
	addItem("WEAPON PUNCH 10");
}

Hero::Hero(string name)
{
	heroName = name;
	health = DEFAULT_HEALTH;
	wpn = NULL;
	cur = NULL;
	addItem("WEAPON PUNCH 10");
}

Hero::~Hero()
{
}

void Hero::setHeroName(string name)
{
	heroName = name;
}

string Hero::getHeroName()
{
	return heroName;
}

int Hero::getHealth()
{
	return health;
}

void Hero::takeDamage(int damage)
{
	health -= damage;
	if (health < 1)
		health = 0;
}

string Hero::getInventory()
{
	return inventory.str();
}

string Hero::getWeapons()
{
	string weapons;
	weapon* n = wpn;

	 while (n->nextWeapon != NULL)
	{
		weapons += n->weaponName + "\n";
		n = n->nextWeapon;
	}
	 weapons += n->weaponName + "\n";

	 return weapons;
	
}

string Hero::addItem(string thing)
{
	stringstream check(thing);
	string is;
	check >> is;
	if (is == "WEAPON")
	{
		check >> is;
		int damage;
		check >> damage;
		weapon* n = new weapon(is, damage);
		if (wpn != NULL)
		{
			cur = wpn;
			while (cur->nextWeapon != NULL)
			{
				cur = cur->nextWeapon;
			}
			cur->nextWeapon = n;
		}
		else
			wpn = n;

		return is;
	}
	else
	{
		inventory << thing << " ";
		return thing;
	}
}

void Hero::removeItem(string item_)
{
	string stuff = getInventory();
	inventory.str(std::string());
	stringstream strm(stuff);
	string thing;
	strm >> thing;
	do
	{
		if (item_ != thing)
			inventory << thing << " ";
	} while (strm >> thing);
}

string Hero::getHeroInfo()
{
	stringstream strm;
	strm << getHeroName() << "\n";
	strm << "HP: " << getHealth() << "\n";
	strm << "Inventory: \n Items: " << getInventory() << "\n";
	strm << " Weapons: " << getWeapons() << "\n\n";
	return strm.str();
}

Room Hero::getLocation()
{
	return location;
}

void Hero::setLocation(Room rm)
{
	location = rm;
}

string Hero::canDo()
{
	string res = "Search\nTake\nUse\nInventory\nInfo\n";
	return res;
}

string Hero::move(MAP dungeon, string command)
{
	if (command == "north")
	{
		if (location.getNorth() == "Wall")
			return "Wall";
		else
		{
			Room nextlocation = dungeon.getRoom(location.getNorth());
			if (nextlocation.getKey() == "")
				return location.getNorth();
			else
			{
				string need = nextlocation.getKey();
				return "Locked " + need;
			}
		}
	}
	if (command == "south")
	{
		if (location.getSouth() == "Wall")
			return "Wall";
		else
		{
			Room nextlocation = dungeon.getRoom(location.getSouth());
			if (nextlocation.getKey() == "")
				return location.getSouth();
			else
			{
				string need = nextlocation.getKey();
				return "Locked " + need;
			}
		}
	}
	if (command == "west")
	{
		if (location.getWest() == "Wall")
			return "Wall";
		else
		{
			Room nextlocation = dungeon.getRoom(location.getWest());
			if (nextlocation.getKey() == "")
				return location.getWest();
			else
			{
				string need = nextlocation.getKey();
				return "Locked " + need;
			}
		}
	}
	if (command == "east")
	{
		if (location.getEast() == "Wall")
			return "Wall";
		else
		{
			Room nextlocation = dungeon.getRoom(location.getEast());
			if (nextlocation.getKey() == "")
				return location.getEast();
			else
			{
				string need = nextlocation.getKey();
				return "Locked " + need;
			}
		}
	}
	if (command == "down")
	{
		if (location.getDown() == "Wall")
			return "Floor";
		else
		{
			Room nextlocation = dungeon.getRoom(location.getDown());
			if (nextlocation.getKey() == "")
				return location.getDown();
			else
			{
				string need = nextlocation.getKey();
				return "Locked " + need;
			}
		}
	}
	if (command == "up")
	{
		if (location.getUp() == "Wall")
			return "Ceiling";
		else
		{
			Room nextlocation = dungeon.getRoom(location.getUp());
			if (nextlocation.getKey() == "")
				return location.getUp();
			else
			{
				string need = nextlocation.getKey();
				return "Locked " + need;
			}
		}
	}
}


string Hero::attack(Monster& mon, string weapon_)
{
	weapon* n = wpn;
	while (n->nextWeapon != NULL)
	{
		if (n->weaponName == weapon_)
		{
			int damage = n->damage;
			mon.takeDamage(damage);
			cout << "You find your mark and deal " << damage << " points of damage.\n\n";
			if (mon.getHealth() == 0)
				return "killed";
			else
				return "alive";
		}
		n = n->nextWeapon;
	}

	int damage = n->damage;
	mon.takeDamage(damage);
	if (mon.getHealth() == 0)
		return "killed";
	else
		return "alive";
}

string Hero::search()
{
	if (location.getItem() != "")
		return "\nYou spot a " + location.getItem();
	else
		return "Nothing to take.";
}

string Hero::take()
{
	if (location.getItem() != "")
	{
		string thing = location.getItem();
		location.removeItem();
		thing = addItem(thing);
		return "DUNNuN NUUU! You got a " + thing;
	}
	else
		return "You reach out with hopeful hands, but come back empty.";
}

string Hero::use(MAP& dungeon, string& grab)
{
	
	int i = 0;
	while (grab[i])
	{
		grab[i] = toupper(grab[i]);
		i++;
	}
	string myStuff = getInventory();
	string stuff;
	stringstream strm(myStuff);
	strm >> stuff;
	do
	{
		if (stuff == grab)
		{
			string lock;
			string grabed = " " + grab;
			if (location.getNorth() != "Wall")
			{
				lock = dungeon.getRoom(location.getNorth()).getKey();
				if (lock == grab)
				{
					return dungeon.getRoom(location.getNorth()).getName();
				}
			}
			if (location.getSouth() != "Wall")
			{
				lock = dungeon.getRoom(location.getSouth()).getKey();
				if (lock == grab)
				{
					return dungeon.getRoom(location.getSouth()).getName();
				}
			}
			if (location.getWest() != "Wall")
			{
				lock = dungeon.getRoom(location.getWest()).getKey();
				if (lock == grab)
				{
					return dungeon.getRoom(location.getWest()).getName();
				}
			}
			if (location.getEast() != "Wall")
			{
				lock = dungeon.getRoom(location.getEast()).getKey();
				if (lock == grab)
				{
					return dungeon.getRoom(location.getEast()).getName();
				}
			}
			if (location.getUp() != "Wall")
			{
				lock = dungeon.getRoom(location.getUp()).getKey();
				if (lock == grab)
				{
					return dungeon.getRoom(location.getUp()).getName();
				}
			}
			if (location.getDown() != "Wall")
			{
				lock = dungeon.getRoom(location.getDown()).getKey();
				if (lock == grab)
				{
					return dungeon.getRoom(location.getDown()).getName();
				}
			}
			return "Unusable";
		}
	} while (strm >> stuff);
	return "doNotHave";
}

void Hero::clearWeapons()
{
	weapon* temp;
	weapon* n = wpn;
	while (n != NULL)
	{
		temp = n->nextWeapon;
		delete n;
		n = temp;
	}
}