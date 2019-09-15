#include<iostream>
#include<vector>
#include<algorithm>

typedef int i;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
using namespace std;


void getCombinations(vi& numList, vvi& resList, i index){
   if(index>=numList.size()){
      resList.push_back(numList);
      return;
   }
   for(int x{index}; x<numList.size();x++){
      std::cout<<x<<std::endl;
      if(index != x){
         swap(numList[index],numList[x]);
         getCombinations(numList,resList,index+1);
         swap(numList[index],numList[x]);
      }
   }
}

inline vvi permutations(vi numbers){
   vvi results;
   getCombinations(numbers,results,0);
   return results;
}


int main(){
   std::vector<int> numbers{1,2,3};
   auto resultList{permutations(numbers)};
   std::sort(resultList.begin(),resultList.end());
   for(auto x : resultList){
      for(auto y : x){
         std::cout<<y;
         std::cout<<" ";
      }
      std::cout<<std::endl;
   }
}
