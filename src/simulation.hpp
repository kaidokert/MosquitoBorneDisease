/*
# Sub-module containing simulation functions
#
# This file is part of SMosMod.
#  Copyright (c) 2017-2018, Imperial College London
#  For licensing information, see the LICENSE file distributed with the SMosMod
#  software package.
*/

#ifndef SRC_SIMULATION_HPP_
#define SRC_SIMULATION_HPP_

#include <iostream>
#include "world.hpp"

class Simulation{
 private:
   double t = 0.0;
   World world;

 public:
  // Constructors
  explicit Simulation(World wd);

  // Accessors
  double getTime() { return t; }
};

#endif  // SRC_SIMULATION_HPP_
