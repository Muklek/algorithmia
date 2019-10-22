#include<iostream>
#include<vector>

typedef std::vector<int> vi;


bool canBeIncrement(vi& numList){
   int numToIncrement{0};
   int preVal{0};

   for(int i{0}; i<numList.size(); i++){
      if(preVal - numList[i] >= 1){
         ++numToIncrement;
      }
      preVal = numList[i];
   }

   return numToIncrement <= 1;
}


int main(){
   vi numList1{10,5,1};    // false
   vi numList2{10,5,7};    // true
   vi numList3{2,1,7,8,6}; // false
   vi numList4{2,5,7};     // true

   std::cout<<canBeIncrement(numList1)<<std::endl;
   std::cout<<canBeIncrement(numList2)<<std::endl;
   std::cout<<canBeIncrement(numList3)<<std::endl;
   std::cout<<canBeIncrement(numList4)<<std::endl;
}
