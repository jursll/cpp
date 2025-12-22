#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void myReplace(std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2)
{
	std::string line;
	while (std::getline(infile, line))
	{
		std::size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line;
		if (!infile.eof())
			outfile << '\n';
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 can't be empty" << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: can't open file \"" << filename << "\"" << std::endl;
		return 1;
	}

	std::string newFilename = filename + ".replace";
	std::ofstream outfile(newFilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: failed to create new output file" << std::endl;
		return 1;
	}

	myReplace(infile, outfile, s1, s2);

	infile.close();
	outfile.close();

	return 0;
}
