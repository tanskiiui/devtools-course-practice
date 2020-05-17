// Copyright 2020 Okmyanskiy Andrey & Tanskii Yurii

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/stack_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class StackAppTest : public ::testing::Test {
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
    StackApp app_;
    string output_;
};

TEST_F(StackAppTest, Make_Help_Message) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a stack application\\..*");
}

TEST_F(StackAppTest, Do_Check_Arg_Is_Correct) {
    // Arrange
    vector<string> args = { "1", "2" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 1 argument.");
}

TEST_F(StackAppTest, Could_Provide_Wrong_Number_Format) {
    // Arrange
    vector<string> args = { "12ds3 34-1" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Wrong format!");
}

TEST_F(StackAppTest, Could_Insert_Positive_Intgers) {
    // Arrange
    vector<string> args = { "12 3 34 1 6" };

    // Act
    Act(args);

    // Assert
    Assert(" Stack: 6 1 34 3 12");
}

TEST_F(StackAppTest, Could_Insert_Negative_Intgers) {
    // Arrange
    vector<string> args = { "-3 -5 -8 -2" };

    // Act
    Act(args);

    // Assert
    Assert(" Stack: -2 -8 -5 -3");
}

TEST_F(StackAppTest, Could_Insert_Positive_Double_Num) {
    // Arrange
    vector<string> args = { "1.2 1.723 1.32 5.6" };

    // Act
    Act(args);

    // Assert
    Assert(" Stack: 5.6 1.32 1.723 1.2");
}
