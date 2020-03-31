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


using namespace std;
char str[100];
vector <int> v;
vector <string> k;


 template<typename A, typename B>
 std::pair<B,A> flip_pair(const std::pair<A,B> &p)
 {   
     return std::pair<B,A>(p.second, p.first);
 }

 template<typename A, typename B>
 std::multimap<B,A> flip_map(const std::map<A,B> &src)
 {   
     std::multimap<B,A> dst;
     std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
                    flip_pair<A,B>);
     return dst;
 }


void Count_Word (FILE *f, vector <int> &v, vector <string> &k){
      map<string,int> counters;

      if ((f != NULL)){
         while(feof(f)==0){
               fgets(str,90,f);
               string stt(str);

               transform(stt.begin(),stt.end(),stt.begin(),::tolower);
               replace(stt.begin(),stt.end(),'`',' ');
               replace(stt.begin(),stt.end(),'\n',' ');
               replace(stt.begin(),stt.end(),'\t',' ');
               replace(stt.begin(),stt.end(),',',' ');
               replace(stt.begin(),stt.end(),'"',' ');
               replace(stt.begin(),stt.end(),'?',' ');
               replace(stt.begin(),stt.end(),'-',' ');
               replace(stt.begin(),stt.end(),'.',' ');
               replace(stt.begin(),stt.end(),'<',' ');
               replace(stt.begin(),stt.end(),'\n',' ');
               replace(stt.begin(),stt.end(),'>',' ');
               replace(stt.begin(),stt.end(),'@',' ');
               replace(stt.begin(),stt.end(),')',' ');
               replace(stt.begin(),stt.end(),'\t',' ');
               replace(stt.begin(),stt.end(),'(',' ');
               replace(stt.begin(),stt.end(),'!',' ');
               replace(stt.begin(),stt.end(),':',' ');
               replace(stt.begin(),stt.end(),'{',' ');
               replace(stt.begin(),stt.end(),'}',' ');
               replace(stt.begin(),stt.end(),'/',' ');
               boost::replace_all(stt," '"," ");
               boost::replace_all(stt,"' "," ");

               stringstream stream(stt);
               while(!stream.eof()){
                   string token;
                   stream >> token;
                   if(counters.count(token)==0)counters[token]=1;
                   else counters[token] += 1;
               }
          }

          std::multimap<int, std::string> dst = flip_map(counters);
          for (multimap<int,std::string>::reverse_iterator itt (dst.rbegin()); itt != dst.rend(); ++itt)
          {
               if(itt->second==""){
               }
               else
               {//cout << itt->second << ": "<<itt->first <<endl;
               v.push_back(itt->first);
               k.push_back(std::string(itt->second));
               }
         }
     }
 }