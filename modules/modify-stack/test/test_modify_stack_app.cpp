// Copyright 2020 Okmyanskiy Andrey

#include <gtest/gtest.h>

#include "include/modify_stack_app.h"

TEST(StackApp, StackAppFirstTest) {
    //Arrange
    int size = 25;

    // Act
    StackApp s(size);

    //Assert
    EXPECT_EQ(size, s.getA());
}
