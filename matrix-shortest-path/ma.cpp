#include<vector>
#include<iostream>
#include<algorithm>

//  vertical minimum path
//  algo needs to traverse through every single node
//  if decisions are made based on each individual node
//  bug araises (decisions such as is a < b < c? )
//  Bug such as forcing a path with the end node higher weight


// solution: recursive approach
// computational expensive to process but forced path bug free

int traverse(std::vector<std::vector<int>> comb, int y, int x, int currSum){
    currSum += comb[y][x];
    if(y==comb.size()-1){
        return currSum;
    }
    else if(x==comb[0].size()-1){
        return std::min({
                traverse(comb, y+1, x, currSum),
                traverse(comb, y+1, x-1, currSum)});
    }
    else if(x == 0){
        return std::min({
                traverse(comb, y+1, x+1, currSum),
                traverse(comb, y+1, x, currSum)});
    }
    else if(x<comb[0].size()-1 && x!=0){
        return std::min({
                traverse(comb, y+1, x-1, currSum),
                traverse(comb, y+1, x, currSum),
                traverse(comb, y+1, x+1, currSum)});
    }
}

int shortestWeight(std::vector<std::vector<int>> comb){
    int currentSum{9999};
    for(int x{0}; x<comb[0].size(); x++){
        std::cout<<currentSum<<std::endl;
        int localSum{traverse(comb, 0, x, 0)};
        currentSum = std::min(currentSum, localSum);
    }
    return currentSum;
}



int main(){
    std::vector<std::vector<int>> m{
        {1,2,3},
        {40,30,10},
        {1,40,20}};
    int result{shortestWeight(m)};
    std::cout<<result<<std::endl;
}
