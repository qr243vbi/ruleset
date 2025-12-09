#include <map>
#include <string>
#include "srslist.h"
#include <iostream>

int main(){
  for (auto pair : ruleSetMap){
//     std::string originalString = pair.second;
//     if (originalString.length() >= 4 && originalString.substr(originalString.length() - 4) == ".srs") {
//       originalString.replace(originalString.length() - 4, 4, ".json");
//     }
//     pair.second = originalString;
     std::cout << pair.first << std::endl <<pair.second << std::endl;
  }
  std::cout << "nekobox-adblocksingbox" << std::endl << 
    "https://raw.githubusercontent.com/217heidai/adblockfilters/main/rules/adblocksingbox.srs" << std::endl;
  std::cout << "" << std::endl << "" << std::endl;
}
