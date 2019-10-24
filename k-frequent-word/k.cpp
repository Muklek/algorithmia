#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

typedef std::string st;
typedef std::vector<st> vst;



bool sortByLength(st wordA, st wordB){
   return wordA.size() < wordB.size();
}


vst getMostFrequent(vst& stList, int const k){
   vst result;

   std::sort(stList.begin(), stList.end());
   std::sort(stList.begin(), stList.end(), sortByLength);
   

   for(int i{0}; i<stList.size(); i++){
      int reps{1};
      st const currWord{stList[i]};

      while(stList[i] == currWord){
         ++reps;
         ++i;
      }

      if(reps >= k){
         result.push_back(currWord);
      }
   }

   return result;
   
}


int main(){
   vst stList{"pro", "banana", "apple",
              "banana", "pro", "car", "lechuga",
              "lemon", "apple"};

   vst result{getMostFrequent(stList, 2)};

   for(auto x : result){
      std::cout<<x<<std::endl;
   }


}
