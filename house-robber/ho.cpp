#include<iostream>
#include<vector>
#include<algorithm>

int rob(std::vector<int>& houses){
    int firstWave{0}, secondWave{0};
    for(int i{0};i<houses.size();i++){
        if(i%2==0){
            firstWave+=houses[i];
        }
        else{
            secondWave+=houses[i];
        }
    }
    return std::max(firstWave, secondWave);
}




int main(){
    std::vector<int> numbers1{2,7,9,3,1};
    std::vector<int> numbers3{1,2};
    std::vector<int> numbers2{1,2,3,1};
    std::cout<<rob(numbers1)<<std::endl; //12
    std::cout<<rob(numbers2)<<std::endl; //4
    std::cout<<rob(numbers3)<<std::endl; //2
}
