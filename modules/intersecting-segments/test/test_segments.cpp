// Copyright 2020 Kukushkina Ksenia

#include <gtest/gtest.h>

#include "include/segments.h"

TEST(Segment, can_create_segment) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(Segment(1, 2, 3, 4));
}

TEST(Segment, area_correctness) {
  // Arrange
  Segment A(2, 7, 10, 3);

  // Act & Assert
  ASSERT_EQ(24, abs(A.area(8, 7)));
}

TEST(Segment, area_sign) {
  // Arrange
  Segment A(1, 3, 7, 9);
  Segment A1(7, 9, 1, 3);

  // Act & Assert
  ASSERT_EQ(-1, A1.area(5, 5) / A.area(5, 5));
}

TEST(Segment, intersection_true) {
  // Arrange
  Segment A(2, 7, 10, 3);
  Segment B(8, 7, 5, 2);

  // Act & Assert
  ASSERT_EQ(true, A.isIntersect(&B));
}

TEST(Segment, intersection_false) {
  // Arrange
  Segment A(2, 7, 5, 2);
  Segment B(8, 7, 10, 3);

  // Act & Assert
  ASSERT_EQ(0, A.isIntersect(&B));
}

TEST(Segment, same_line_intersection_true) {
  // Arrange
  Segment A(1, 1, 4, 10);
  Segment B(3, 7, 2, 4);

  // Act & Assert
  ASSERT_EQ(true, A.isIntersect(&B));
}

TEST(Segment, same_line_intersection_false) {
  // Arrange
  Segment A(1, 1, 2, 4);
  Segment B(3, 7, 4, 10);

  // Act & Assert
  ASSERT_EQ(0, A.isIntersect(&B));
}

TEST(Segment, commutativity) {
  // Arrange
  Segment A(1, 3, 7, 8);
  Segment B(3, 9, 1, 1);

  // Act & Assert
  ASSERT_EQ(A.isIntersect(&B), B.isIntersect(&A));
}
