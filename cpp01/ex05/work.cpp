
#include <iostream>
#include <string>

class Harl
{
private:
	void debug()
	{
		std::cout << "[DEBUG] I love extra bacon." << std::endl;
	}
	void info()
	{
		std::cout << "[INFO] I want extra bacon!" << std::endl;
	}
	void warning()
	{
		std::cout << "[WARNING] I NEED extra bacon!!" << std::endl;
	}
	void error()
	{
		std::cout << "[ERROR] CALL THE MANAGER!!!" << std::endl;
	}

public:
	Harl()
	{
	}
	~Harl()
	{
	}

	void complain(std::string level)
	{
		// array of levels
		std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		// array of corresponding function pointers
		void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

		for (int i = 0; i < 4; i++)
		{
			if (levels[i] == level)
				(this->*functions[i])();
		}
	}
};

int main(void)
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}

// TODO: tests + refactor