#include<unordered_set>
#include<iostream>
#include<algorithm>
#include<cmath>

bool isHappy(int num){
    std::unordered_set<int> combinations;
    int currentSum{0}, localNum{num}, localVal{0};
    bool found{false};
    while(!found){
        localVal = localNum%10;
        currentSum += localVal*localVal;
        localNum = localNum/10;
        if(localNum == 0){
            if(currentSum == 1){
                found=true;
            }
            else{
                if(combinations.find(currentSum) != combinations.end()){
                    break;
                }
                else{
                    combinations.emplace(currentSum);
                    localNum = currentSum;
                    currentSum = 0;
                }
            }
        }
    }
    return found;
}


int main(){
    int number{19};
    std::cout<<isHappy(number)<<std::endl;

}
