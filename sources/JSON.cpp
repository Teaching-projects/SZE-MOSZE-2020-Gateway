#include "JSON.h"

JSON::JSON(std::map<std::string, std::any> data) : data(data)
{
}
void JSON::Valid(const std::string &text)
{
    int quote = 0;
    int j = 0;
    int start = text.find('{');
    int end = text.find('}');
    if (start == -1)
        throw std::runtime_error("Invalid Json");
    std::string tritext = text.substr(start, end - start + 1);
    int kpont = std::count(tritext.begin(), tritext.end(), ':');
    int dnumber = std::count(tritext.begin(), tritext.end(), ',');

    if ((tritext.find('{') != std::string::npos && tritext.find('}') != std::string::npos) && (kpont == (dnumber + 1)))
    {
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
int JSON::count(const std::string &key)
{
    return data.count(key);
}


JSON JSON::parseFromString(const std::string &input)
{
    std::string text = input;
    std::vector<std::string> data;
    std::map<std::string, std::any> mapData;

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
    return JSON(mapData);
}
JSON JSON::parseFromStream(std::istream &stream)
{
    std::string text, currentLine;

    while (getline(stream, currentLine))
    {
        text.append(currentLine);
    }
    return parseFromString(text);
}
JSON JSON::parseFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("file " + filename + " doesn't exist");

    return parseFromStream(file);
}
bool JSON::isNumber(const std::string &x)
{
    std::regex e("^[0-9.]*$");
    if (std::regex_match(x, e))
        return true;
    else
        return false;
}