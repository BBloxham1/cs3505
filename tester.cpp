#include <iostream>
#include "node.h"
#include "string_set.h"

int main()
{
  
  cs3505::string_set new_set;

  new_set.add("dicks");
  //new_set.add("dart");

  std::string dicks = "dicks";

  std::cout << dicks.compare("fart") << std::endl; 
  return 0;
}
