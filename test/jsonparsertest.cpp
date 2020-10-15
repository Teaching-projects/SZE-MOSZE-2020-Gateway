#include "parser.hpp"
#include <gtest/gtest.h>

TEST(jsonTest, fileParse) {
  std::string file ="units/monster1.json";
  std::map<std::string, std::string> ip;
  std::map<std::string, std::string> ep {
    {
      "name" : "Igor",
      "hp" : 200,
      "dmg" : 40
    }
  };

  ip = Parser::fileparser(file);
  ASSERT_EQ(ep.size(), ip.size());
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
