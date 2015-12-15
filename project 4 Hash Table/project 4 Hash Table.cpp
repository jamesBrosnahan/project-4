// project 4 Hash Table.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "hash.h"

std::string commands[3] = { "insert", "find", "remove"};

int main()
{
	std::fstream file;
	file.open("DNAHashInput.txt", std::ios::in);
	std::fstream open;
	open.open("open.txt", std::ios::out);
	std::fstream closed;
	closed.open("closed.txt", std::ios::out);
	hash<std::string> table(10,10,true);
	std::string str;
	std::regex find("\\s*find\\s*");
	std::regex insert("\\s*insert\\s*");
	std::regex remove("\\s*remove\\s*");
	std::cmatch matches;
	if (file.is_open())
	{
		while (!file.eof())
		{
			str = "";
			std::getline(file, str);
			std::cout << std::regex_match(str.c_str(), remove) << std::endl;
			if (std::regex_match(str.c_str(), insert)) {//insert
				std::regex value("[^(insert)|\\s]\\s*");
				std::regex_match(str.c_str(), matches, value);
				auto start = std::chrono::system_clock::now();
				table.insert(matches.str(0));
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> diff = end - start;
				open << "Time to insert " << diff.count() << " s\n";
			}
			else if (std::regex_match(str.c_str(), find)) {//find
				std::regex value("[^(find)|\\s]\\s*");
				std::regex_match(str.c_str(), matches, value);
				auto start = std::chrono::system_clock::now();
				table.find(matches.str(0));
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> diff = end - start;
				open << "Time to find " << diff.count() << " s\n";
			}
			else if (std::regex_match(str.c_str(), remove)) {//remove
				std::regex value("[^(remove)|\\s]\\s*");
				std::regex_match(str.c_str(), matches, value);
				auto start = std::chrono::system_clock::now();
				table.remove(matches.str(0));
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> diff = end - start;
				open << "Time to remove " << diff.count() << " s\n";
			}
		}
	}
    return 0;
}

