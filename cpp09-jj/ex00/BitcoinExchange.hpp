#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;

		void processLine(const std::string& line);
		std::string trim(const std::string& str);
		bool isValidDate(const std::string& date);
		bool findExchangeRate(const std::string& date, double& rate)const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		bool processInputFile(const std::string& filename);

};

#endif
