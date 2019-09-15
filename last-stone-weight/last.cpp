#include<iostream>
#include<vector>
#include<algorithm>

int lastStoneWeight(std::vector<int>& stoneList){
    while(stoneList.size() >= 1){
        if(stoneList.size() == 1){
            return stoneList[0];
        }
        std::sort(stoneList.begin(),stoneList.end());
        int fightResult{stoneList[stoneList.size()-1] - stoneList[stoneList.size()-2]};
        stoneList.pop_back();
        stoneList.pop_back();
        stoneList.push_back(fightResult);
        
    }
    return 0;
}


int main(){
    std::vector<int> numbers{2,7,4,1,8,1};
    const int result = lastStoneWeight(numbers);
    std::cout<<result<<std::endl;
}
