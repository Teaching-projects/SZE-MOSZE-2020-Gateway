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
 * \author Bitchka98
 * 
 * \version 3.0
 * 
 * \date 2020/12/08 08:45
*/
class Parser {
public:

    /**
     * \brief This checks if the given text is valid.
     * 
     * \param text
     * 
     * It finds the key points of the JSON and if it sees an error in their number or place it throws an exception.
    */
    static void Valid(const std::string &text);

    /**
     * \brief Finds the texts front and end, and removes the whitespaces.
     * 
     * \param text
     * 
     * Checks the text from the front to the end, and if it sees a whitespace, it removes it.
     * 
     * \return string
    */
    static std::string T(const std::string &text);

    /**
     * \brief This parses the read text, from the given input.
     * 
     * \param input
     * 
     * After it calls the Valid function, it puts the keys, and datas in the map and returns it.
     * 
     * \return mapData
    */
    static std::map<std::string, std::string> Stringparse(const std::string &input);

    /**
     * \brief This appends the curent line for the text.
     * 
     * \param stream
     * 
     * It appends the current line for the text and after that it returns the previous function with this text.
     * 
     * \return Stringparse(text)
    */
    static std::map<std::string, std::string> Streamparse(std::istream &stream);

    /**
     * \brief This parses the file, calling the streamparse.
     * 
     * \param filename
     * 
     * First it checks if the file is good. If its not, it throws and exception. Then it calls the Streamparse function for the read file, and then put it in a map called d, and then returns this d.
     * 
     * \return d
    */
    static std::map<std::string, std::string> Fileparse(const std::string &filename);
};

#endif
