#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>
#include <any>

class JSON {
protected:
    std::map<std::string, std::any> data;
    
    static bool isNumber(const std::string & );
public:
    static void Valid(const std::string&);
    static std::string T(const std::string&);
    JSON(std::map<std::string, std::any>);
    int count(const std::string&);
    static JSON parseFromString(const std::string&);
    static JSON parseFromStream(std::istream&);
    static JSON parseFromFile(const std::string&);

    template <typename T>
    T get(const std::string &key)
    {
        return std::any_cast<T>(data[key]);
    }

    class ParseException : virtual public std::runtime_error
    {
    public:
        explicit ParseException(const std::string &description) : std::runtime_error("Parsing error: " + description) {}
    };
};

#endif
