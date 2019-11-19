#include<iostream>
#include<vector>
#include<unordered_set>

typedef std::string st;
typedef std::vector<st> vst;
typedef std::unordered_set<st> ust;

// complexity:
// space: O(word.length + dict.length)
// lookup time O(1)
// time complexity: O(n)

bool wordBreak(st& word, vst& fakeDict){
   ust realDict;
   for(st word : fakeDict) realDict.insert(std::move(word));
   
   st splittedWord{""};
   int validIndex;
   for(int i{0}; i<word.size(); i++){
      splittedWord += word[i];
      if(realDict.count(splittedWord) > 0){
         splittedWord = "";
         validIndex = i;
      }
   }
   return validIndex == word.size()-1;
}


int main(){
   st word1{"bananasapple"};
   vst dict1{"bananas", "apple"};
   
   st word2{"bananasapplex"};
   vst dict2{"bananas", "apple"};
   
   st word3{"b"};
   vst dict3{"bananas", "apple"};
   
   st word4{"catsandog"};
   vst dict4{"cats", "dog", "sand", "and", "cat"};
   
   st word5{"applepenapple"};
   vst dict5{"apple", "pen"};

   bool result1{wordBreak(word1, dict1)};
   bool result2{wordBreak(word2, dict2)};
   bool result3{wordBreak(word3, dict3)};
   bool result4{wordBreak(word4, dict4)};
   bool result5{wordBreak(word5, dict5)};

   std::cout<<result1<<std::endl; //true
   std::cout<<result2<<std::endl; //false
   std::cout<<result3<<std::endl; //false
   std::cout<<result4<<std::endl; //false
   std::cout<<result5<<std::endl; //true
}
