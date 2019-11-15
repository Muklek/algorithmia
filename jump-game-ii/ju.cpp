#include<iostream>
#include<vector>

typedef std::vector<int> vi;

// complexity O(n)

bool finalIndex(vi& nums){
   int maxReach{nums[0]}, localReach{0}, lastIndex{0};
   
   for(int i{0}; i <= maxReach; ++i){
      if(maxReach >= nums.size()-1) return true;
      
      localReach = nums[i] + i;
      if(nums[i] == 1 && localReach > maxReach) maxReach += 1;
      else if(localReach > maxReach){
         maxReach += nums[i] - 1 - lastIndex;
         lastIndex = i;
      }
   }
   return false;
}


int main(){
  vi nums1{3,3,3,1,0,1};
  vi nums2{2,3,2,1,0,1};
  vi nums3{2,1,2,1,0,1};
  vi nums4{2,0};
  vi nums5{0};
  vi nums6{1,1,1,1,1,0};
  vi nums7{3,2,4,6,5,4,6,5,1,1,1,1,1,0,0};
  vi nums8{3,2,4,6,5,4,6,5,1,1,1,1,1,1,0};
  vi nums9{3,4,0,0,3,0};

  std::cout<<finalIndex(nums1)<<std::endl;
  std::cout<<finalIndex(nums2)<<std::endl;
  std::cout<<finalIndex(nums3)<<std::endl;
  std::cout<<finalIndex(nums4)<<std::endl;
  std::cout<<finalIndex(nums5)<<std::endl;
  std::cout<<finalIndex(nums6)<<std::endl;
  std::cout<<finalIndex(nums7)<<std::endl;
  std::cout<<finalIndex(nums8)<<std::endl;
  std::cout<<finalIndex(nums9)<<std::endl;
}
