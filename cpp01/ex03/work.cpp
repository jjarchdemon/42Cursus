
#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon() {}
	Weapon(std::string type) : type(type) {}
	~Weapon() {}

	const std::string &getType() const
	{
		return (this->type);
	}
	void setType(std::string type)
	{
		this->type = type;
	}
};

class HumanA
{
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}
	~HumanA() {}

	void attack()
	{
		std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
	}
};

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string name) : name(name), weapon(nullptr) {}
	~HumanB() {}

	void setWeapon(Weapon &weapon)
	{
		this->weapon = &weapon;
	}

	void attack()
	{
		if (weapon)
			std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
};

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}