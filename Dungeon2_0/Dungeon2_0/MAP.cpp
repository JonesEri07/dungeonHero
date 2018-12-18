#include "MAP.h"
#include <iostream>
#include <string>

using namespace std;

MAP::MAP() : numRooms(0) {}

MAP::MAP(std::string name)
{
	questName = name;
	numRooms = 0;
}


MAP::~MAP()
{

}

void MAP::addRoom(string name)
{
	int next = numRooms;				//save index for new room
	numRooms++;							//increas count for numRooms
	myRooms[next] = Room(name);		//add new room w/name
	rooms[name] = myRooms[next];		//add key to find new room
	if (numRooms == 1)
		entrance = myRooms[next];
	exit = myRooms[next];
}
void MAP::addRoom(std::string name, std::string item_)
{
	int next = numRooms;				//save index for new room
	numRooms++;							//increas count for numRooms
	myRooms[next] = Room(name, item_);		//add new room w/name
	rooms[name] = myRooms[next];		//add key to find new room
	if (numRooms == 1)
		entrance = myRooms[next];
	exit = myRooms[next];
}
void MAP::addRoom(std::string name, std::string item_, std::string key_)
{
	int next = numRooms;				//save index for new room
	numRooms++;							//increas count for numRooms
	myRooms[next] = Room(name, item_, key_);		//add new room w/name
	rooms[name] = myRooms[next];		//add key to find new room
	if (numRooms == 1)
		entrance = myRooms[next];
	exit = myRooms[next];
}
void MAP::addRoom(std::string name, std::string item_, std::string key_,
	std::string north, std::string south, std::string west, std::string east)
{
	int next = numRooms;				//save index for new room
	numRooms++;							//increas count for numRooms
	myRooms[next] = Room(name, item_, key_, north, south, west, east);		//add new room w/name
	rooms[name] = myRooms[next];		//add key to find new room
	if (numRooms == 1)
		entrance = myRooms[next];
	exit = myRooms[next];
}

void MAP::addRoom(std::string name, std::string item_, std::string key_,
	std::string north, std::string south, std::string west, std::string east, 
	string monsterName)
{
	Monster mon = myMonsters[monsterName];
	int next = numRooms;				//save index for new room
	numRooms++;							//increas count for numRooms
	myRooms[next] = Room(name, item_, key_, north, south, west, east, mon);		//add new room w/name
	rooms[name] = myRooms[next];		//add key to find new room
	if (numRooms == 1)
		entrance = myRooms[next];
	exit = myRooms[next];
}


void MAP::addRoom(std::string name, std::string item_, std::string key_,
	std::string north, std::string south, std::string west, std::string east,
	std::string up, std::string down)
{
	int next = numRooms;				//save index for new room
	numRooms++;							//increas count for numRooms
	myRooms[next] = Room(name, item_, key_, north, south, west, east, up, down);		//add new room w/name
	rooms[name] = myRooms[next];		//add key to find new room
	if (numRooms == 1)
		entrance = myRooms[next];
	exit = myRooms[next];
}

void MAP::addRoom(std::string name, std::string item_, std::string key_,
	std::string north, std::string south, std::string west, std::string east,
	std::string up, std::string down, string monsterName)
{
	Monster mon = myMonsters[monsterName];
	int next = numRooms;				//save index for new room
	numRooms++;							//increas count for numRooms
	myRooms[next] = Room(name, item_, key_, north, south, west, east, up, down, mon);		//add new room w/name
	rooms[name] = myRooms[next];		//add key to find new room
	if (numRooms == 1)
		entrance = myRooms[next];
	exit = myRooms[next];

}


void MAP::addMonster(std::string name, std::string type, int health, int attack)
{
	Monster newMonster(name, type, health, attack);
	myMonsters[name] = newMonster;
}



Room MAP::getRoom(string room)
{
	return rooms[room];
}

void MAP::setRoom(Room& rm)
{
	for (int i = 0; i < DEFAULT_ROOM_SIZE; i++)
	{
		if (myRooms[i] == rm)
		{
			rm.removeKey();
			myRooms[i] = rm;
			rooms[rm.getName()] = rm;
		}
	}
}

Room MAP::getEntrance()
{
	return entrance;
}

Room MAP::getExit()
{
	return exit;
}

string MAP::getName()
{
	return questName;
}

string MAP::listRoomNames()
{
	int n = 0;
	string line;
	while (n < numRooms)
	{
		line += myRooms[n].getName() + "\n";
		n++;
	}
	return line;
}


Room MAP::removeRoomKey(string room)
{
	rooms[room].removeKey();
	return rooms[room];
}

void MAP::removeMonster(Room& rm)
{
	for (int i = 0; i < DEFAULT_ROOM_SIZE; i++)
	{
		if (myRooms[i] == rm)
		{
			rm.noMoreMonster();
			myRooms[i] = rm;
			rooms[rm.getName()] = rm;
		}
	}
}