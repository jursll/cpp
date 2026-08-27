#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if(ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;

	if (!exchange.loadDatabase("data.csv"))
		return 1;

	if (!exchange.processInputFile(av[1]))
		return (1);
	return 0;
}

