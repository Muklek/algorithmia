#include<iostream>
#include<vector>

// time:  O(n)
// space: O(1)

void rotate(std::vector<int>& numList, int rotations){
    int currentMoves{0};
    int tempValue{0}, value{numList[numList.size()-1]};
    int currentIndex{numList.size()-1}, posToMove{0};
    while(currentMoves++<numList.size()){
        posToMove = (currentIndex+rotations)%numList.size();
        tempValue = numList[posToMove];
        numList[posToMove] = value;
        value = tempValue;
        currentIndex = posToMove;
    }
}

int main(){
    std::vector<int> numbers{1,2,3,4,5,6,7};
    rotate(numbers,300);
    for(int number : numbers){
        std::cout<<number<<" ";
    }
    std::cout<<std::endl;
}
