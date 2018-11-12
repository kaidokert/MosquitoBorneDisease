/*
# Sub-module containing location functions
#
# This file is part of SMosMod.
#  Copyright (c) 2017-2018, Imperial College London
#  For licensing information, see the LICENSE file distributed with the SMosMod
#  software package.
*/

#ifndef SRC_LOCATION_HPP_
#define SRC_LOCATION_HPP_

#include <utility>

class Location {
 private:
  std::pair<double, double> coordinates;
  unsigned int block;

  // Update simulation block
  void updateBlock();

 public:
  // Constructors
  explicit Location(std::pair<double, double> coords);

  // Accessor
  std::pair<double, double> getCoordinates() { return coordinates; }
};

#endif  // SRC_LOCATION_HPP_
