#include<iostream>
#include<vector>

typedef std::vector<int> vi;

bool finalIndex(vi& nums){
   int validState{static_cast<int>(nums.size())};
   int index{0}, jump{nums[index]};

   while(validState-- > 0 && index != nums.size()-1){
      if(jump == 0) return false;
      while(jump-- > 0) ++index;
      index = index%nums.size();
      jump = nums[index];
   }
   if(index == nums.size()-1) return true;
   else return false;
}

int main(){
   vi nums1{2,3,1,1,4}; // valid
   vi nums2{3,2,1,0,4}; // invalid
   vi nums3{3,1,2,4,4}; // valid
   vi nums4{3,1,3,4,4}; // invalid
   vi nums5{2,0}; // invalid
   vi nums6{0}; // valid


   bool result1{finalIndex(nums1)};
   bool result2{finalIndex(nums2)};
   bool result3{finalIndex(nums3)};
   bool result4{finalIndex(nums4)};
   bool result5{finalIndex(nums5)};
   bool result6{finalIndex(nums6)};

   std::cout<<result1<<std::endl;
   std::cout<<result2<<std::endl;
   std::cout<<result3<<std::endl;
   std::cout<<result4<<std::endl;
   std::cout<<result5<<std::endl;
   std::cout<<result6<<std::endl;
}
