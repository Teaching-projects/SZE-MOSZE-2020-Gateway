#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Parser {
private:
  std::map<std::string, std::string> mymaps;
  std::map<std::string, int> mymapi;

public:
  void stringparser(const std::string &stringname);
  void fileparser(const std::string &filename);
  void ifstreamparser(std::ifstream &ifstream);
  std::string readstring(const std::string &key) {
    return mymaps[key];
  }
  int readint(const std::string &key) {
    return mymapi[key];
  }
};

#endif
