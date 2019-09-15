#include<iostream>
#include<vector>
#include <sstream>
#include <iterator>

std::vector<std::vector<int>> pascalTriangle(int floors){
    std::vector<std::vector<int>> triangle;
    int currentFloors{1};
    while(currentFloors++<floors){
        if(triangle.size()==0){
            triangle.push_back(std::vector<int>{1});
        }
        std::vector<int> tempList;
        for(int i{0}; i<triangle[triangle.size()-1].size()+1;i++){
            if(i == 0){
                tempList.push_back(1);
            }
            else if(tempList.size() == triangle[triangle.size()-1].size()){
                tempList.push_back(1);
                break;
            }
            else{
                int computed{triangle[triangle.size()-1][i-1] + triangle[triangle.size()-1][i]};
                tempList.push_back(computed);
            }
        }
        triangle.push_back(tempList);
    }
    return triangle;
}


int main(){
    int length{5};
    std::cout<<pascalTriangle(5).size()<<std::endl;
    auto triangleResult{pascalTriangle(5)};
    for(auto list : triangleResult){
        for(auto innerList:list){
            std::cout<<innerList<<" ";
        }
        std::cout<<""<<std::endl;
    }
}
