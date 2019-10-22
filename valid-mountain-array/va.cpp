#include<iostream>
#include<vector>

typedef std::vector<int> vi;

bool isMountain(vi numList){
   bool increasing{false}, decreasing{false};
   int index{0};
   for(int i{0}; i<numList.size()-1; i++){
      if(numList[i] < numList[i+1])
         increasing = true;
      else if(numList[i] > numList[i+1]){
         index = i;
         break;
      }
   }

   for(int i{index}; i<numList.size()-1; i++){
      if(numList[i] > numList[i+1]){
         decreasing = true;
      }
      else if(numList[i] < numList[i+1]){
         return false;
      }
   }
   return increasing && decreasing;
}



int main(){
   vi mountainA{0,3,2,1};         // true
   vi mountainB{0,1,2,3};         // false
   vi mountainC{3,2,1};           // false
   vi mountainD{1,2,2,3,4,3,2,1}; // true

   std::cout<<isMountain(mountainA)<<std::endl;
   std::cout<<isMountain(mountainB)<<std::endl;
   std::cout<<isMountain(mountainC)<<std::endl;
   std::cout<<isMountain(mountainD)<<std::endl;
}
