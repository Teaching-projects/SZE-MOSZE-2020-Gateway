#include "parser.hpp"

void Parser::fileparser(const std::string &filename) {
  std::ifstream file(filename);
  std::string key, data, line="";
  char c;
  if (file.is_open()) {
    while (file.get(c)) {
      if (!isspace(c)) {
        line += c;
      }
    }

    if (line[0] == '{') {
      int start = line.find_first_of("{,}")+1;
      int end = line.find_first_of("{,}",start);

      while (end != std::string::npos) {
        std::string subline;
        subline = line.substr(start,end-start);
        int kpont = subline.find(':');
        key = subline.substr(0,kpont);
        data = subline.substr(kpont+1);
        key = key.substr(1,key.size()-2);
        if (data[0] == '"' && data[data.size()-1] == '"'){
          mymaps[key] = data.substr(1,data.size()-2);
        }
        else {
          mymapi[key] = std::stoi(data);
        }
        start = end+1;
        end = line.find_first_of("{,}",start);
      }
    }

    file.close();
  }
  else {
    throw std::invalid_argument("Couldnt open the file");
  }
}

void Parser::stringparser(const std::string &stringname) {
  std::string key, data, line="";
  char c;

  for (int i = 0; i < stringname.size(); ++i) {
    if (!isspace(stringname[i])) {
      line += stringname[i];
    }
  }

  if (line[0] == '{') {
    int start = line.find_first_of("{,}")+1;
    int end = line.find_first_of("{,}",start);

    while (end != std::string::npos) {
      std::string subline;
      subline = line.substr(start,end-start);
      int kpont = subline.find(':');
      key = subline.substr(0,kpont);
      data = subline.substr(kpont+1);
      key = key.substr(1,key.size()-2);
      if (data[0] == '"' && data[data.size()-1] == '"'){
        mymaps[key] = data.substr(1,data.size()-2);
      }
      else {
        mymapi[key] = std::stoi(data);
      }
      start = end+1;
      end = line.find_first_of("{,}",start);
    }
  }
}

void Parser::ifstreamparser(std::ifstream &file) {
  std::string key, data, line="";
  char c;
  if (file.is_open()) {
    while (file.get(c)) {
      if (!isspace(c)) {
        line += c;
      }
    }

    if (line[0] == '{') {
      int start = line.find_first_of("{,}")+1;
      int end = line.find_first_of("{,}",start);

      while (end != std::string::npos) {
        std::string subline;
        subline = line.substr(start,end-start);
        int kpont = subline.find(':');
        key = subline.substr(0,kpont);
        data = subline.substr(kpont+1);
        key = key.substr(1,key.size()-2);
        if (data[0] == '"' && data[data.size()-1] == '"'){
          mymaps[key] = data.substr(1,data.size()-2);
        }
        else {
          mymapi[key] = std::stoi(data);
        }
        start = end+1;
        end = line.find_first_of("{,}",start);
      }
    }
  }
  else {
    throw std::invalid_argument("Couldnt open the file");
  }
}
