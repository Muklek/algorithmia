#include<iostream>
#include<vector>
#include<algorithm>


int containerSize(std::vector<int>& wList){
    int container{0},left{0},right{wList.size()-1};
    while(left < right){
        int localContainer{((std::min(wList[left], wList[right])) * (right-left))};
        container = std::max(container, localContainer);
        if(wList[left] < wList[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return container;
}



int main(){
    std::vector<int> buckets{1,8,6,2,5,4,8,3,7};
    std::cout<<containerSize(buckets)<<std::endl;
}
