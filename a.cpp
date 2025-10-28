#include <map>
#include <string>
#include "srslist.h"
#include <iostream>

int main(){
  for (auto pair : ruleSetMap){
     std::cout << pair.first << std::endl <<pair.second << std::endl;
  }
  std::cout << "" << std::endl << "" << std::endl;
}
