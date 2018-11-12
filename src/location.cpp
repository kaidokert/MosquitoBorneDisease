/*
# Sub-module containing location functions
#
# This file is part of SMosMod.
#  Copyright (c) 2017-2018, Imperial College London
#  For licensing information, see the LICENSE file distributed with the SMosMod
#  software package.
*/

#include "location.hpp"

Location::Location(std::pair<double, double> coords) : coordinates(coords) {
  updateBlock();
}

void Location::updateBlock() {
  block = 0;
}
