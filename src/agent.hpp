#ifndef AGENT_HPP_INCLUDED
#define AGENT_HPP_INCLUDED

class Agent
{
private:
  double age;

public:
  // Constructors
  Agent();
  Agent(double a);

  // Accessors
  double getAge() {return age; };
};

#endif
