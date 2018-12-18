#ifndef MAP_H
#define MAP_H
#include <map>
#include "Room.h"
#include <string>
#define DEFAULT_ROOM_SIZE 100

class MAP
{
private:
	std::string questName;		//Name of Quest
	Room myRooms[DEFAULT_ROOM_SIZE];	//Rooms that make up the quest
	std::map<std::string, Room> rooms; //Room finder map by name
	int numRooms;
	Room entrance;
	Room exit;

	std::map<std::string, Monster> myMonsters;

public:
	MAP();
	MAP(std::string name);
	~MAP();
	
	void addRoom(std::string name);
	void addRoom(std::string name, std::string item_);
	void addRoom(std::string name, std::string item_, std::string key_);
	void addRoom(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east);
	void addRoom(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east, 
		std::string monsterName);
	void addRoom(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east,
		std::string up, std::string down);
	void addRoom(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east,
		std::string up, std::string down, std::string monsterName);

	void addMonster(std::string name, std::string type, int health, int attack);

	Room getRoom(std::string room);
	void setRoom(Room& rm);
	Room getEntrance();

	Room getExit();
	
	std::string getName();

	std::string listRoomNames();

	Room removeRoomKey(std::string room);

	void removeMonster(Room& rm);
};

#endif