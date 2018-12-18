#ifndef BATTLES_H
#define BATTLES_H
#include <string>
#include <iostream>

std::string battleTime(Hero& hero, Monster& monster)
{
	if (monster.getName() == "Troll")
	{
		cineBattleScene(hero.getHeroName(), monster.getName());
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	else
		std::cout << "You encounter a " << monster.getName() << "!\n\n";

	std::string code;
	std::string dead = "dead";
	std::string alive = "alive";
	bool first = true;
	while (hero.getHealth() != 0 || monster.getHealth() != 0)
	{
		std::cout << "What move will you use?\n";
		std::cout << hero.getWeapons();
		if (monster.getName() == "Troll")
		{
			if (first)
			{
				std::cout << "Dodge\nHide\nGuess its favorite color to show it that there are people who do still care.\n";
				std::cout << "(However, guessing will leave you vulnerable, guess wrong and you will die)\n\nCommand: ";
				first = false;
			}
			else
			{
				std::cout << "Dodge\nHide\nGuess\n\n";
			}
		}
		bool goodIn = false;
		std::string action;
		std::cin >> action;
		std::cin.ignore(10000, '\n');
		int i = 0;
		while (action[i])
		{
			action[i] = toupper(action[i]);
			i++;
		}
		std::stringstream attacks(hero.getWeapons());
		std::string weapon;
		attacks >> weapon;
		do
		{
			if (weapon == action)
			{
				goodIn = true;
				std::string outcome = hero.attack(monster, weapon);
				if (outcome == "killed")
				{
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n And with that final blow you slayed the " << monster.getName() << ".\n\n";
					system("pause");
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					return alive;
				}
				else//still alive and monster attacks
				{
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\nThe " << monster.getName() << " is now at " << monster.getHealth() << " HP.\n\n";
					hero.takeDamage(monster.getAttack());
					std::cout << "The " << monster.getName() << " dealt " << monster.getAttack() << " damage.\n";
					if (hero.getHealth() != 0)
					{
						std::cout << "Your health is now " << hero.getHealth() << " HP";
						std::cout << "\n\nYou've taken some damage but you can still win.\n\n";
					}
					else
					{
						std::cout << "\n\n\n\n\n\n\n\n\n\nIt seems you were no match for the " << monster.getName() << ".\n\n";
						return dead;
					}
				}
			}
		} while (attacks >> weapon);

		if (action == "DODGE")
		{
			goodIn = true;
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou dodge another blow but who knows how long your luck will last.\n\n";
		}
		if (action == "HIDE")
		{
			goodIn = true;
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou crouch behind a huge pile of something sticky and buy yourself\nsome more time.";
		}
		if (action == "GUESS")
		{
			goodIn = true;
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou bravely stand out and greet the " << monster.getName() << " with the best\nsmile you can muster.";
			std::cout << "The " << monster.getName() << " looks at you strangley as you slowly approach.\n\n";
			system("pause");
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nUsing your calm voice you say, \"Hey buddy, how about we be friends instead of kill eachother?\"\n\n";
			std::cout << "He just continues to stare at you.\n\n";
			std::cout << "Look, my name is " << hero.getHeroName() << ". What's yours?\n\n";
			std::cout << "...\n\n";
			std::cout << "Finally the " << monster.getName() << " speaks, \"If you want to be my friend\n then guess what my favorite color is.\n";
			std::cout << "Get it wrong and I'll eat you, guess right and I'll let you live.\n\n\n\n\n\n\n\n";
			std::cout << "What is your guess: ";
			std::string guess;
			std::cin >> guess;
			std::cin.ignore(10000, '\n');
			int j = 0;
			while (guess[j])
			{
				guess[j] = toupper(guess[j]);
				j++;
			}

			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			std::cout << "\"I guess... " << guess << "!\" You declare with confidence.\n\n\n\n\n";
			std::cout << "\n\n.....\n\n\n";
			system("pause");
			std::cout << "\n\n\n";
			if (guess == "GREEN")
			{
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\"How did you know?!\" The " << monster.getName() << " shouts with amazement.\n";
				std::cout << "\"Well, a deals a deal. You are free to go.\"\n\n\n\n\n\n";
				system("pause");
				return alive;
			}
			else
			{
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe " << monster.getName() << "'s eyes start to well up with tears.\nsniff sniff\n\n";
				system("pause");
				std::cout << "\n\n\"Oh thank goodness you guessed wrong. I haven't eaten in 5 days.\n\n";
				std::cout << "And with that " << hero.getHeroName() << " was no more.\n\n";
				return dead;

			}

		}
		if (!goodIn)
		{
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou stumble not knowing what your doing and the monster attacks.\n\n";
			hero.takeDamage(monster.getAttack());
			std::cout << "The " << monster.getName() << " dealt " << monster.getAttack() << " damage.\n";
			if (hero.getHealth() != 0)
			{
				std::cout << "Your health is now " << hero.getHealth() << "\n\n";
				std::cout << "You've taken some damage but you can still win.\n\n\n\n\n";
			}
			else
			{
				std::cout << "\nAnd it seems that little mistake cost you your life.\nYou are now dead.\n\n";
				return dead;
			}
		}
	}
}

#endif