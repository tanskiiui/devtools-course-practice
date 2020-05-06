// Copyright 2020 Kukushkina Ksenia

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/statistics_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Statistics_app_test : public ::testing::Test {
 protected:
  void Act(vector<string> args_) {
    vector<const char*> options;

    options.push_back("appname");
    for (size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  Statistics_app app_;
  string output_;
};

TEST_F(Statistics_app_test, Do_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("This is a statistics application\\..*");
}

TEST_F(Statistics_app_test, Is_Checking_Number_Of_Arguments) {
  vector<string> args = { "1", "2" };

  Act(args);

  Assert("ERROR: Should be more than 2 arguments\\..*");
}
