#include "../parser.hpp"
#include <gtest/gtest.h>

TEST(JsonTest, Filetest)
{
    ASSERT_THROW(Json::Fileparse("badmonster1.json"), std::runtime_error);
    ASSERT_NO_THROW(Json::Fileparse("../unit/monster1.json"));
}
TEST(JsonTest, Stringparse)
{
    std::map<std::string, std::string> data = Json::Stringparse("{    \"name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000}");
    ASSERT_EQ(data["name"], "Bicska");
    ASSERT_EQ(data["hp"], "45000");
    ASSERT_EQ(data["dmg"], "1000");
}
TEST(JsonTest, Valid)
{
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_THROW(Json::Valid("{    name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000 }"), std::runtime_error);
    ASSERT_NO_THROW(Json::Valid("{    \"name\" : \"Bicska\",    \"hp\" : 45000,    \"dmg\" : 1000}"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}