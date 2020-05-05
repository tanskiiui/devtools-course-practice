// Copyright 2020 Sokova Anastasia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sokova_Anastasia_ComplexNumberTest, Can_Check_Equality) {
    // Act
    ComplexNumber x(8.0, 8.0);
    ComplexNumber y(8.0, 8.0);

    // Assert
    EXPECT_EQ(true, x == y);
}
TEST(Sokova_Anastasia_ComplexNumberTest, Complex_Number_Can_Create_If_Empty) {
    // Arrange
    double a = 0.0;
    double b = 0.0;
    ComplexNumber x(a, b);
    ComplexNumber y;

    // Assert
    EXPECT_EQ(x, y);
}
TEST(Sokova_Anastasia_ComplexNumberTest, Complex_Numbers_Sum) {
    // Arrange
    ComplexNumber x(4.0, -6.0);
    ComplexNumber y(-10.0, 7.0);
    ComplexNumber z;

    // Act
    z = x + y;

    // Assert
    EXPECT_EQ(-6.0, z.getRe());
    EXPECT_EQ(1.0, z.getIm());
}
