#include <gtest/gtest.h>
#include "include/Option.h"
#include "include/Option.cpp"
#include "include/Page.cpp"
#include "include/Page.h"

// Demonstrate some basic assertions.
TEST(BasicAssertions, CheckIfEmpty) {
  Option option("", 1, 20);
  // Expect answer to be "Valami" and not to be null
  EXPECT_EQ(option.getAnswer(), "Valami");
  EXPECT_NE(option.getAnswer(), NULL);
}

TEST(BasicAssertions, CheckData) {
  Option option("Első", 10, 13);
   Option option2("Második", 5, 20);
  std::vector<Option> options;
  options.push_back(option);
  options.push_back(option2);
  Page testPage(0, "Teszt Kérdés", options);
  // Expect page size to be 2
  EXPECT_EQ(testPage.getOptionSize(), 2);
}