#include <iostream>	//std::cout, std::endl
#include <cctype>	//toupper()

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	int i = 1;
	while (i < ac)
	{
		int j = 0;
		while (av[i][j] != '\0')
		{
			std::cout << (char)std::toupper(av[i][j]);
			j++;
		}

		std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return 0;
}
