// Copyright 2020 Vladislav Golubev

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#include <vector>

class Metrics {
 private:
  std::vector<float> fst;
  std::vector<float> sec;

 public:
  Metrics();
  Metrics(const Metrics&) = default;
  Metrics(const std::vector<float>& _fst, const std::vector<float>& _sec);

  std::vector<float> getFirst() const;
  std::vector<float> getSecond() const;

  void setFirst(const std::vector<float>& _fst);
  void setSecond(const std::vector<float>& _sec);

  double getL1();
  double getL2();
  double getL3();
  double getL4();
  double getLInf();
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
