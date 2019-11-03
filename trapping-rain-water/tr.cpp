#include<iostream>
#include<vector>

typedef std::vector<int> vi;

int getVolume(const vi& nums){
   int front{0}, back{0};
   int trapped{0}, commulative{0};

   for(int i{0}; i<nums.size(); i++){
      if(i ==front){
         trapped += commulative;
         commulative = 0;

         int temp{++front};

         while(front < nums.size()){
            if(nums[front] >= nums[temp]){
               temp = front;
            }
            ++front;
         }

         front = temp;
         continue;
      }
      if(nums[i] > nums[back] && i <= front) back = i;
      if(front != back && i != front){
         int maxLevel = std::min(nums[back], nums[front]);
         commulative += std::abs(maxLevel - nums[i]);
      }
   }
   return trapped;
}


int main(){
   vi cubes_1{0,1,0,2,1,0,1,3,2,1,2,1}; // 6
   vi cubes_2{1,0,1,0,2,0,3,0};         // 4

   std::cout<<getVolume(cubes_1)<<std::endl;
   std::cout<<getVolume(cubes_2)<<std::endl;
}
