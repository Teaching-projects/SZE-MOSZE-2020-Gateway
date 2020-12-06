#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>

/**
 * \class Parser
 * 
 * \brief This is a class for parsing the datas.
 * 
 * This class includes the different type of parsers.
 * 
 * \author hmartin28
 * 
 * \version 3.0
 * 
 * \date 2020/12/06 12:09
*/
class Parser {
public:

    /**
     * \brief This checks if the given text is valid.
     * 
     * \param text
    */
    static void Valid(const std::string &text);

    /**
     * \brief Finds the texts front and end, and removes the whitespaces.
     * 
     * \param text
    */
    static std::string T(const std::string &text);

    /**
     * \brief This parses the read text, from the given input.
     * 
     * \param input
    */
    static std::map<std::string, std::string> Stringparse(const std::string &input);

    /**
     * \brief This appends the curent line for the text.
     * 
     * \param stream
    */
    static std::map<std::string, std::string> Streamparse(std::istream &stream);

    /**
     * \brief This parses the file, calling the streamparse.
     * 
     * \param filename
    */
    static std::map<std::string, std::string> Fileparse(const std::string &filename);
};

#endif
