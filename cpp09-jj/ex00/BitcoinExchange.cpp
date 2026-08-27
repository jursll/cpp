#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if(!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::size_t comma = line.find(',');
		std::string date = line.substr(0, comma);
		std::string value = line.substr(comma +1);

		double rate;
		std::stringstream converter(value);
		converter >> rate;
		_database[date] = rate;
	}
	file.close();
	return (true);
}

bool BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}
	std::string line;
	while (true)
	{
		if (!std::getline(file, line))
		{
			std::cerr << "Error: empty file." << std::endl;
			return (false);
		}

		if (line.find_first_not_of(" \t\r") == std::string::npos)
			continue;

		break;
	}

	if (line != "date | value")
	{
		std::cerr << "Error: wrong header should be 'date | value'"
				<< std::endl;
		return (false);
	}
	while (std::getline(file, line))
	{
		if (line.find_first_not_of(" \t\r") == std::string::npos)
			continue;
		processLine(line);
	}
	file.close();
	return (true);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10)
		return (false);

	if (date[4] != '-' || date[7] != '-')
		return (false);

	std::size_t i = 0;
	while (i < date.size())
	{
		if (i != 4 && i != 7)
		{
			if (!std::isdigit(date[i]))
				return (false);
		}
		i++;
	}

	int year;
	int month;
	int day;

	std::stringstream yearConverter(date.substr(0, 4));
	yearConverter >> year;

	std::stringstream monthConverter(date.substr(5, 2));
	monthConverter >> month;

	std::stringstream dayConverter(date.substr(8, 2));
	dayConverter >> day;

	if (year < 1)
		return (false);

	if (month < 1 || month > 12)
		return (false);

	int daysInMonth[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
	{
		daysInMonth[1] = 29;
	}
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

void BitcoinExchange::processLine(const std::string& line)
{
	std::size_t separator = line.find('|');

	if (separator == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string date = line.substr(0, separator);
	std::string valueString = line.substr(separator + 1);

	date = trim(date);
	valueString = trim(valueString);
	if(!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	double value;
	char extra;
	std::stringstream converter(valueString);

	if (!(converter >> value) || (converter >> extra))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}

	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}
	double rate;

	if (!findExchangeRate(date, rate))
	{
		std::cerr << "Error: no exchange rate available for date => " << date << std::endl;
		return;
	}
	double result = value * rate;
	std::cout << date << " => " << value << " = " << result << std::endl;
}

std::string BitcoinExchange::trim(const std::string& str)
{
	std::size_t first = str.find_first_not_of(" \t\r");
	if (first == std::string::npos)
		return ("");

	std::size_t last = str.find_last_not_of(" \t\r");

	return (str.substr(first, last - first + 1));
}

bool BitcoinExchange::findExchangeRate(const std::string& date, double& rate) const
{
	if (_database.empty())
		return (false);

	std::map<std::string, double>::const_iterator it;
	it = _database.lower_bound(date);

	if (it == _database.end())
	{
		--it;
		rate = it->second;
		return (true);
	}

	if (it->first == date)
	{
		rate = it->second;
		return (true);
	}

	if (it == _database.begin())
		return (false);

	--it;
	rate = it->second;
	return (true);
}
