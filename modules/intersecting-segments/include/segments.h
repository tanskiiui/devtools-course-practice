// Copyright 2020 Kukushkina Ksenia

#ifndef MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_
#define MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_

class Segment {
 public:
  Segment(double _x1, double _y1, double _x2, double _y2);
  double area(double x, double y);  // double oriented triangle area
  bool isIntersect(Segment* A);

 private:
  double x1;
  double y1;
  double x2;
  double y2;
};

#endif  // MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_
