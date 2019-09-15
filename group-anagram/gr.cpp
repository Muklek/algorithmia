#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

typedef int i;
typedef std::string str;
typedef std::vector<str> vstr;
typedef std::vector<vstr> vvstr;
typedef std::unordered_map<str, vstr> m_strvstr;


vvstr convert(m_strvstr& comboDict){
   vvstr comboList;
   for(auto combo : comboDict){
      comboList.push_back(combo.second);
   }
   return comboList;
}

vvstr groupAnagrams(vstr& wordList){
   m_strvstr comboDict;
   vvstr comboGroups;
   for(str word : wordList){
      str orderedWord{word};
      std::sort(orderedWord.begin(),orderedWord.end());
      if(comboDict.count(orderedWord) > 0){
         comboDict.at(orderedWord).push_back(word);
      }
      else{
         vstr localCombo{word};
         comboDict[orderedWord] = localCombo;
      }
   }
   comboGroups = convert(comboDict);
   return comboGroups;
   
}


int main(){
   vstr words{"eat", "tea", "tan", "ate", "nat", "bat"};
   vvstr result{groupAnagrams(words)};
   for(auto x : result){
      for(auto y : x){
         std::cout<<y;
         std::cout<<" ";
      }
         std::cout<<std::endl;
   }
}
