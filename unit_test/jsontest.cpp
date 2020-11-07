  
#include "../sources/JSON.h"
#include <gtest/gtest.h>

TEST(JsonTest, exist)
{
    JSON parsed = JSON::parseFromString("{\"name\":\"Kakarott\",\"hp\": 200}");
    ASSERT_EQ(parsed.count("name"), 1);
    ASSERT_EQ(parsed.count("hp"), 1);
    ASSERT_EQ(parsed.count("dmg"), 0);
}

TEST(JSONTest, badmonsterFile)
{
    ASSERT_THROW(JSON::parseFromFile("../unit_test/doesnotexist.json"), std::runtime_error);
}

TEST(JSONTest, existFile)
{
    ASSERT_NO_THROW(JSON::parseFromFile("../json_files/Dark_Wanderer.json"));
}
TEST(JSONTest, ValidMissingChars)
{
    ASSERT_THROW(JSON::parseFromString("    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\"  \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott,    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\"  200,    \"dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200    \"dmg\" : 90, \"attackcooldown\": 1.0  "), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200    dmg\" : 90, \"attackcooldown\": 1.0  }"), std::runtime_error);

    ASSERT_THROW(JSON::parseFromString("{    name : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 "), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\"  \"Kakarott\",    \"hp\" : 200,    \"dmg\"  90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\"  \"Kakarott\"    \"hp\" : 200    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown 1.0 }"), std::runtime_error);
    ASSERT_THROW(JSON::parseFromString("{    name\" : \"Kakarott\",    \"hp\"  200,    \"dmg\" : 90, \"attackcooldown 1.0 }"), std::runtime_error);
}

TEST(JSONTest, ValidPlusSpace)
{
    ASSERT_NO_THROW(JSON::parseFromString("{\"name\":\"Kakarott\",\"hp\": 200,\"dmg\":90, \"attackcooldown\": 1.0 }"));
    ASSERT_NO_THROW(JSON::parseFromString("{   \"name\"   :   \"Kakarott\"   ,    \"hp\"   : 200  ,    \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
    ASSERT_NO_THROW(JSON::parseFromString("{    \"name\" : \"Kakarott\",    \"hp\" : 200,    \"dmg\" : 90, \"attackcooldown\": 1.0 }"));
}
TEST(JSONTest, ValidMixedKeys)
{
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,   \"name\"   :   \"Kakarott\",        \"dmg\"   :    90  , \"attackcooldown\": 1.0   }"));
    ASSERT_NO_THROW(JSON::parseFromString("{  \"hp\"   : 200,       \"dmg\"   :    90,  \"name\"   :   \"Kakarott\" , \"attackcooldown\": 1.0  }"));
}