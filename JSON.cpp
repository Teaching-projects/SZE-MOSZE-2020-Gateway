#include "JSON.h"


void Parser::Valid(const std::string &text)
{
    int start = text.find('{');
    int end = text.find('}');
    if (start == -1)
        throw std::runtime_error("Invalid Json");
    std::string tritext = text.substr(start, end - start + 1);
    int kpont = std::count(tritext.begin(), tritext.end(), ':');
    int dnumber = std::count(tritext.begin(), tritext.end(), ',');

    if ((tritext.find('{') != std::string::npos && tritext.find('}') != std::string::npos) && (kpont == (dnumber + 1)))
    {
        int quote = 0;
        int j = 0;
        tritext.erase(tritext.end() - 1);
        tritext.append(",}");
        for (int i = 0; i < kpont; i++)
        {
            do
            {
                if (tritext[j] == '\"')
                    quote++;
                j++;
            } while (tritext[j] != ':');
            if (tritext[j] == ':' && quote != 2)
            {

                throw std::runtime_error("Invalid Json");
            }

            quote = 0;

            do
            {
                if (tritext[j] == '\"')
                    quote++;
                j++;
            } while (tritext[j] != ',');
            if (!(tritext[j] == ',' && (quote == 0 || quote == 2)))
            {

                throw std::runtime_error("Invalid Json");
            }

            quote = 0;
        }
    }
    else
    {
        throw std::runtime_error("Invalid Json");
    }
}
std::string Parser::T(const std::string &text)
{
    auto start = text.begin();
    while (start != text.end() && std::isspace(*start))
    {
        start++;
    }

    auto end = text.end();
    do
    {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}
std::map<std::string, std::string> Parser::Stringparse(const std::string &input)
{
    std::string text = input;
    std::vector<std::string> data;
    std::map<std::string, std::string> mapData;

    Valid(input);

    text.push_back('\"');
    std::string chars = " :{},\r";
    for (size_t i = 0; i < chars.size(); i++)
    {
        text.erase(remove(text.begin(), text.end(), chars[i]), text.end());
    }
    text = std::regex_replace(text, std::regex("\"\""), "\"");
    text.erase(text.begin());

    size_t pos = 0;
    std::string token;
    while ((pos = text.find("\"")) != std::string::npos)
    {
        token = text.substr(0, pos);
        token = T(token);
        data.push_back(token);
        text.erase(0, pos + 1);
    }
    for (size_t i = 0; i < data.size() / 2; i++)
    {
        mapData[data[2 * i]] = data[2 * i + 1];
    }
    return mapData;
}
std::map<std::string, std::string> Parser::Streamparse(std::istream &stream)
{
    std::string text, currentLine;

    while (getline(stream, currentLine))
    {
        text.append(currentLine);
    }
    return Stringparse(text);
}
std::map<std::string, std::string> Parser::Fileparse(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("file " + filename + " doesn't exist");

    std::map<std::string, std::string> d = Streamparse(file);

    file.close();
    return d;
}
