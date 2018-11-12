/*
# Sub-module containing non-parasite functions
#
# This file is part of SMosMod.
#  Copyright (c) 2017-2018, Imperial College London
#  For licensing information, see the LICENSE file distributed with the SMosMod
#  software package.
*/
#ifndef SRC_NONPARASITE_HPP_
#define SRC_NONPARASITE_HPP_

#include <utility>
#include "agent.hpp"
#include "location.hpp"

class NonParasite : public Agent {
 protected:
  Location location;

 public:
  // Constructors
  explicit NonParasite(Location ln);

  // Accessor
  Location getLocation() { return location; }
};

#endif  // SRC_NONPARASITE_HPP_
