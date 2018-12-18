#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include <string>
#include <sstream>

int validInput(std::string& command)
{
	int i = 0;
	while (command[i])
	{
		command[i] = tolower(command[i]);
		i++;
	}
	
	if (command == "north" || command == "south" || command == "west" || command == "east" ||
		command == "up" || command == "down")
		return 1;
	if (command == "search" || command == "take" ||
		command == "use" || command == "inventory" || command == "info")
		return 2;
	else
		return 0;
}

#endif