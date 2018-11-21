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

#include "util/Vector.hpp"
using Coord2d = mbd::Vector<double, 2>;

class Location {
private:
  Coord2d coordinates;
  unsigned int block;

  // Update simulation block
  void updateBlock();

public:
  // Constructors
  explicit Location(Coord2d coords);

  const Coord2d &GetCoordinates() const;
};

#endif // SRC_LOCATION_HPP_
