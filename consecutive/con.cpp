#include<iostream>
#include<deque>
#include<vector>
#include<numeric>

// add numbers consecutively such as:
// list = [1,2,3,4]
// output = [1, 3, 6, 9]
// 1+0 = 1, 1+2=3, 1+2+3=6, 2+3+4=9

// data-strucutre used: doble-ending queue

const std::vector<int> consecutive(std::vector<int>& itemList){
    std::deque<int> qList;
    std::vector<int> con;
    for(const int number : itemList){
        qList.push_back(number);
        if(qList.size() > 3){
            qList.pop_front();
        }
        const int queueSum = std::accumulate(qList.begin(),qList.end(),0);
        con.push_back(queueSum);
    }
    return con;
}

int main(){
    std::vector<int> numbers{1,2,3,4};
    const auto x = consecutive(numbers);
    for(const int i : x){
        std::cout<<i<<std::endl;
    }
}
