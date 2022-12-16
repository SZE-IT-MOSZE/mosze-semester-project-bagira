#include <gtest/gtest.h>

#include "include/Option.h"
#include "include/Page.h"
#include "include/Character.h"

// Demonstrate some basic assertions

TEST(BasicAssertions, CheckOptionSize) {
  Option option("Első", 10, 13, 5);
  Option option2("Második", 5, 20, 6);
  std::vector<Option> options;
  options.push_back(option);
  options.push_back(option2);
  Page testPage(0, "Teszt Kérdés", options);
  // Expect page size to be 2
  EXPECT_EQ(testPage.getOptionSize(), 2);
}

TEST(BasicAssertions, CheckPageId) {
  Option option("Első", 10, 13, 5);
  std::vector<Option> options;
  options.push_back(option);
  Page testPage(19, "Teszt Kérdés", options);
  // Expect page size to be 2
  EXPECT_EQ(testPage.getPageId(), 19);
  EXPECT_NE(testPage.getPageId(), 1);
}

TEST(BasicAssertions, CheckIfAnswerIsEmpty) {
  Option option("Valami", 1, 20, 5);
  // Expect answer to be "Valami" and not to be null
  EXPECT_EQ(option.getAnswer(), "Valami");
  EXPECT_NE(option.getAnswer(), "");
}

TEST(BasicAssertions, CheckIfHpIsEmpty) {
  Option option("Valami", 1, 20, 5);
  // Expect Hp to be 1 and not to be null
  EXPECT_EQ(option.getHp(), 1);
  EXPECT_NE(option.getHp(), 0);
}

TEST(BasicAssertions, CheckIfMoraleIsEmpty) {
  Option option("Valami", 1, 20, 5);
  // Expect Morale to be 20 and not to be null
  EXPECT_EQ(option.getMorale(), 20);
  EXPECT_NE(option.getMorale(), 0);
}

TEST(BasicAssertions, CheckIfToPageIsEmpty) {
  Option option("Valami", 1, 20, 5);
  // Expect toPage to be 5 and not to be null
  EXPECT_EQ(option.getToPage(), 5);
  EXPECT_NE(option.getToPage(), 0);
}

TEST(BasicAssertions, CheckCorrectNavigation) {
  Option option("Első", 10, 13, 5);
  std::vector<Option> options;
  Page page(0, "Kérdés", options);
  EXPECT_EQ(option.getToPage(), 5);
  EXPECT_NE(option.getToPage(), 8);
}

TEST(BasicAssertions, CheckCorrectSetHP) {
  Character character(50, 2);
  character.setHp(55);
  EXPECT_EQ(character.getHp(), 55);
  EXPECT_NE(character.getHp(), 45);
}

TEST(BasicAssertions, CheckCorrectSetMorale) {
  Character character(50, 2);
  character.setMorale(15);
  EXPECT_EQ(character.getMorale(), 15);
  EXPECT_NE(character.getMorale(), 3);
}

TEST(BasicAssertions, CheckCorrectSetName) {
  Character character(50, 2);
  character.setName("Bagira");
  EXPECT_EQ(character.getName(), "Bagira");
  EXPECT_NE(character.getName(), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}