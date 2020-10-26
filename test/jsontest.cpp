#include "../parser.hpp"
#include <gtest/gtest.h>

TEST(ParserTest, Filetest)
{
    ASSERT_THROW(Parser::Fileparse("xy.json"), std::runtime_error);
    ASSERT_NO_THROW(Parser::Fileparse("../unit/monster1.json"));
}
TEST(ParserTest, Stringparse)
{
    std::map<std::string, std::string> data = Parser::Stringparse("{    \"name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000}");
    ASSERT_EQ(data["name"], "Bicska");
    ASSERT_EQ(data["hp"], "45000");
    ASSERT_EQ(data["dmg"], "1000");
}
TEST(ParserTest, Valid)
{
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Parser::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_NO_THROW(Parser::Valid("{    \"name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000}"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}