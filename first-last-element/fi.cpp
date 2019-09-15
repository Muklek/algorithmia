#include<iostream>
#include<vector>


int localRange(std::vector<int>& numList,
           int index, int valToAdd, bool targetIndex=false){
   int numCheck{numList[index]};
   while(index >= 0 && index < numList.size()){
      std::cout<<index<<std::endl;
      if(numList[index] != numCheck){
         return index;
      }
      index += valToAdd;
   }
   return targetIndex ? index : -1;
}

std::vector<int> searchRange(std::vector<int>& numList, int target){
  size_t low{0},high{numList.size()-1},mid{0};
  while(low<=high){
     mid=(low+high)/2;
     if(numList[mid] == target){
        int minIndex{localRange(numList,mid,-1,true)+1};
        int maxIndex{localRange(numList,mid,+1,true)-1};
        return std::vector<int>{minIndex, maxIndex};
     }
     if(numList[mid] > target){
        high = localRange(numList, mid, -1);
        if(high == -1){
           break;
        }
     }
     if(numList[mid] < target){
        low = localRange(numList, mid, 1);
        if(low == -1){
           break;
        }
     }
  }
  return std::vector<int>{-1, -1};
}

int main(){
   std::vector<int> numbers_1{1,2,3,4,4,4,5,7,7,7,7,8,8,9,9,10};
   auto solution{searchRange(numbers_1, 9)};
   for(int number:solution){
      std::cout<<number;
      std::cout<<" ";
   }
   std::cout<<std::endl;
}
