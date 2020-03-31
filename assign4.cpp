#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <boost/algorithm/string/replace.hpp>
#include <jsoncpp/json/json.h>
#include "assign4.h"

bool WriteToFile(const char* filename, const char* buffer, int len)
{
  FILE* r = fopen(filename, "wb");
  if (NULL == r)
    return false;
  size_t fileSize = fwrite(buffer, 1, len, r);
  fclose(r);
return true;
}

 int main(int argc, char **argv){
     FILE *f = fopen(argv[1], "r");
     map<string,int> counters;
     Json::Value jsonMap;

     Count_Word (f,v,k);
     for (int i=0; i<2706; i++){
        jsonMap[k[i]] = v[i];
     }
     Json::StyledWriter writer;
     std::string outputConfig = writer.write(jsonMap);
     std::cout << outputConfig << std::endl;
     bool result = WriteToFile("assign4.json", outputConfig.c_str(), outputConfig.length());

     fclose(f);
     return 0;
 }


