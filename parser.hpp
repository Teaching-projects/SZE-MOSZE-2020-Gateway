#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>

class Parser {
private:
    static void Valid(const std::string &text);
    static std::string T(const std::string &text);

public:
    static std::map<std::string, std::string> Stringparse(const std::string &input);
    static std::map<std::string, std::string> Streamparse(std::istream &stream);
    static std::map<std::string, std::string> Fileparse(const std::string &filename);
};

#endif
