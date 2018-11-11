/*
# Sub-module containing world functions
#
# This file is part of SMosMod.
#  Copyright (c) 2017-2018, Imperial College London
#  For licensing information, see the LICENSE file distributed with the SMosMod
#  software package.
*/

#ifndef SRC_WORLD_HPP_
#define SRC_WORLD_HPP_

#include <iostream>

class World{
 private:
  const double width;
  const double length;

 public:
  // Constructors
  World(double w, double l);

  // Accessors
  double getWidth() { return width; }
  double getHeight() { return length; }
  double getArea();
};

#endif  // SRC_WORLD_HPP_
