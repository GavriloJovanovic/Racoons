#include "file_reader.hpp"


std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

std::vector<std::string> split (const std::string &line, char delim) {
    std::vector<std::string> entries;
    std::stringstream strm(line);
    std::string tmp;
    while(std::getline(strm, tmp, delim)) {
        entries.push_back(trim(tmp));
    }
    return entries;
}



table loadFromFile(std::string path) {
    table result{};
    std::ifstream inputFile;
    inputFile.open(path);
    if(!inputFile.is_open()) {
        std::cout << "fajl ne postoji" << std::endl;
    }
    else {
        std::string line;
        std::getline(inputFile, line);
        std::vector<std::string> header = split(line, ',');
        result.push(header);
        while(std::getline(inputFile, line)) {
            std::vector<std::string> entries = split(line, ',');
            std::vector<std::pair<std::string, entry>> instance;
            for(unsigned i = 0; i<entries.size(); i++) {
                instance.push_back(std::make_pair(header[i], entry(trim(entries[i]))));
            }
            result.push_row(instance);
        }
    }
    return result;
}
