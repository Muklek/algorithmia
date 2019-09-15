#include<vector>
#include<iostream>


bool isnonDecreasing(std::vector<int>& number){
    for(int i{0}; i<number.size()-1; i++){
        --number[i];
        if(number[i] < number[i+1]){
            return false;
        }
    }
    return true;
}


int main(){
    std::vector<int> numbers{3,3,2};
    std::cout<<isnonDecreasing(numbers)<<std::endl;
}
