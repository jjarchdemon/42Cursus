// ex04

// replace every occurance of s1 by s2 in a new file

#include <fstream>	//file operations
#include <iostream> //io operation
#include <string>	//string

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Format: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	// check if empty string
	if (s1.empty())
	{
		std::cerr << "empty string" << std::endl;
		return 1;
	}

	// open inputfile
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "error opening input file" << std::endl;
		return 1;
	}

	// create & open outputfile
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "error creating output file" << std::endl;
		inputFile.close();
		return 1;
	}

	// raed line by line and replace
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;

		while (true)
		{
			// Search for s1 starting from pos
			pos = line.find(s1, pos);
			// If not found, stop searching this line
			if (pos == std::string::npos)
				break;
			// erase s1, insert s2, increase pos
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line;
		// getline removes '\n', so add it back
		if (!inputFile.eof())
			outputFile << std::endl;
	}

	inputFile.close();
	outputFile.close();
	return 0;
}

// TODO: write tests