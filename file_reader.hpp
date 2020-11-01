#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include<fstream>

#include "table.hpp"

std::vector<std::string> split (const std::string &line, char delim);

table loadFromFile(std::string path);

#endif
