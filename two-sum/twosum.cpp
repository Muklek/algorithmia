#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

// find two number such as the sum is equal to the example number
// naive approach:
//      brute-force the solution
//      complexity: O(n^2)
// efficient approach:
//      use hashmap to store valid values
//      complexity: 0(n)


std::vector<int> findPairs(const std::vector<int>& numberList, const int& numToEqual ){
    std::unordered_map<int, int> numberItems;
    for(const int number : numberList){
        const int subsOperation{numToEqual - number};
        if(numberItems.count(number) > 0){
            return std::vector<int>{number, numberItems.at(number)};
        }
        numberItems[subsOperation]=number;
    }
   
}


int main(){
    std::vector<int> numbers{1,2,3,4,5,6,7};
    const int exampleNum{5};
    const auto x = findPairs(numbers, 5);
    for(auto p : x){
        std::cout<<p<<std::endl;
    }
}
