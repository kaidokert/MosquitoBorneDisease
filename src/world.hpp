#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

#include <iostream>

class World
{
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

#endif
