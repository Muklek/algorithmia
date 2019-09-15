#include<iostream>
#include<vector>

#   complexity o(n)
#   space complexity(1)

void removeDuplicates(std::vector<int>& numberList){
    int i{0};
    for(int j{0};j<numberList.size();j++){
        if(numberList[i] != numberList[j]){
            i++;
        }
        else{
            numberList.erase(numberList.begin()+i);
            i++;
        }
    }
}


int main(){
    std::vector<int> numbers{1,1,2,3,4,4,5,5,5,6};
    removeDuplicates(numbers);
    for(auto number : numbers){
        std::cout<<number<<std::endl;
    }
}
