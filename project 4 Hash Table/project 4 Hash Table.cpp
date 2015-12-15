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
	hash<std::string> open_table(10,10,true);
	hash<std::string> closed_table(10, 10, false);
	char line[256];
	std::string str;
	std::regex find("\\s*find\\s*\\n");
	std::regex insert("\\s*insert\\s*\\n");
	std::regex remove("\\s*remove\\s*\\n");
	std::cmatch matches;
	hash<std::string>* hash_table = &open_table;
	if (file.is_open())
	{
		while (!file.eof())
		{
			str = "";
			file.getline(line, 256);
			str = line;
			//std::cout << line << std::endl;//std::regex_match(str.c_str(), remove)
			//std::cmatch matches;
			if (str.find("insert") != std::string::npos){//std::regex_match(str.c_str(), insert)) {//insert
				std::regex value("((A|T|C|G){4})*\\s?$");//[^(insert)|\\s]\\w*\\s*\\n
				std::regex_search(str.c_str(), matches, value);
				auto start = std::chrono::system_clock::now();
				std::cout << matches[0] << std::endl;
				hash_table->insert(matches.str(0));
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> diff = end - start;
				open << "Time to insert " << diff.count() << " s\n";
			}
			else if (str.find("find") != std::string::npos){//std::regex_match(str.c_str(), find)) {//find
				std::regex value("((A|T|C|G){4})*\\s?$");//"[^(find)|\\s]\\s*\\n"
				std::regex_search(str.c_str(), matches, value);
				auto start = std::chrono::system_clock::now();
				hash_table->find(matches.str(0));
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> diff = end - start;
				open << "Time to find " << diff.count() << " s\n";
			}
			else if (str.find("remove") != std::string::npos){//std::regex_match(str.c_str(), remove)) {//remove
				std::regex value("((A|T|C|G){4})*\\s?$");//"[^(remove)|\\s]\\s*\\n"
				std::regex_search(str.c_str(), matches, value);
				auto start = std::chrono::system_clock::now();
				hash_table->remove(matches.str(0));
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> diff = end - start;
				open << "Time to remove " << diff.count() << " s\n";
			}
		}
	}
    return 0;
}

