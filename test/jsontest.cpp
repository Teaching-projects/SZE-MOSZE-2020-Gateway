#include "../JSON.h"
#include "../Monster.h"
#include "../Hero.h"
#include "../Monster.cpp"
#include "../Hero.cpp"
#include <gtest/gtest.h>

TEST(ParserTest, Filetest)
{
    ASSERT_THROW(Parser::Fileparse("xy.json"), std::runtime_error);
    ASSERT_NO_THROW(Parser::Fileparse("../units/Eivar.json"));
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

TEST(HeroTest, Parse) 
{
    Hero hero = Hero::readJson("HeroParseTest.json");

    ASSERT_EQ(hero.getName(),"HTest");
    ASSERT_EQ(hero.getHp(),70);
    ASSERT_EQ(hero.getDmg(),20);
    ASSERT_EQ(hero.getCd(),float(0.8));
    ASSERT_EQ(hero.getLevel(),1);
    ASSERT_EQ(hero.getMaxHp(),70);
}

TEST(MonsterTest, Parse)
{
    Monster monster = Hero::readJson("MonsterParseTest.json");

    ASSERT_EQ(monster.getName(),"MTest");
    ASSERT_EQ(monster.getHp(),70);
    ASSERT_EQ(monster.getCd(),float(0.2));
    ASSERT_EQ(monster.getDmg(),10);
}

TEST(AttackTest, Attack) 
{
    Hero hero = Hero::readJson("HERO.json");
    Monster monster = Monster::readJson("MONSTER.json");

    monster.attack(hero);

    ASSERT_EQ(hero.getHp()-monster.getDmg(),960);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}