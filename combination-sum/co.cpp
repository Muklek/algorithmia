#include<iostream>
#include<vector>

typedef int i;
typedef std::vector<i> vi;
typedef std::vector<vi> vvi;


void localCombinations(vi& numList, vvi& numResult, vi& numCombos, i target, i index){
   if(target == 0){
      numResult.push_back(numCombos);
   }
   if((index < numList.size()) && (target >= numList[index])){
      i resultTarget{target - numList[index]};
      numCombos.push_back(numList[index]);
      localCombinations(numList, numResult, numCombos, resultTarget, index);
      numCombos.pop_back();
   }
   if((index+1 < numList.size()) && (target >= numList[index])){
      localCombinations(numList,numResult,numCombos,target,index+1);
   }
}


vvi findCombinations(vi& numbers, i target){
   vvi combinations;
   vi localCombos;
   localCombinations(numbers, combinations, localCombos, target, 0);
   return combinations;
}


int main(){
   vi number_combinations{2,3,6,7,8,9,10};
   auto result{findCombinations(number_combinations,20)};
   std::cout<<result.size()<<std::endl;
   for(auto x : result){
      for(auto y : x){
         std::cout<<y;
         std::cout<<" ";
      }
      std::cout<<std::endl;
   }
   std::cout<<std::endl;
}
