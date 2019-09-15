#include<iostream>
#include<algorithm>
#include<vector>


//  complexity O(n)
//  space complexity O(1)


int adjacentSum(std::vector<int>& numberList){
    int adSum{numberList[0]};
    int commSum{numberList[0]};
    for(int number : numberList){
        adSum = std::max(adSum+number, number);
        commSum = std::max(commSum,adSum);
    }
    return commSum;
}


int main(){
    std::vector<int> numbers{-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<adjacentSum(numbers)<<std::endl;
}
