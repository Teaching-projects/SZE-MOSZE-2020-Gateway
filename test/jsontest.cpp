#include "../parser.hpp"
#include <gtest/gtest.h>

TEST(jsontest, wrong_input_test) {

  Parser test;

  ASSERT_THROW(test.fileparser("badmonster1.json"),std::invalid_argument);

};

TEST(jsontest, string_diff_test) {

  Parser test;

  test.fileparser("monster1.json");

  ASSERT_NE(test.readstring("name"),"Rogi");

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
