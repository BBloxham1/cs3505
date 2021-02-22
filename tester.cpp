#include <iostream>
#include "node.h"
#include "string_set.h"

int main()
{
  
  cs3505::string_set new_set;

  new_set.add("dicks");
  std::cout << new_set.contains("dick");
  //new_set.add("dart");

  return 0;
}
