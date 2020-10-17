#include "../parser.hpp"
#include <gtest/gtest.h>

TEST(jsontest, wrong_input_test) {

  Parser test;

  ASSERT_THROW(test.fileparser("badmonster1.json"),std::invalid_argument);

};

TEST(jsontest, diff_test) {

  Parser test;

  Parser test2;

  test.fileparser("monster1.json");

  test2.fileparser("monster2.json");

  ASSERT_NE(test.readstring("name"),test2.readstring("name"));

  ASSERT_NE(test.readint("hp"),test2.readint("hp"));

  ASSERT_NE(test.readint("dmg"),test2.readint("dmg"));

};

TEST(jsontest,fileparser) {

  Parser test;

  test.fileparser("monster1.json");

  ASSERT_EQ(test.readstring("name"), "Igor");

  ASSERT_EQ(test.readint("hp"), 200);

  ASSERT_EQ(test.readint("dmg"), 40);

};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
