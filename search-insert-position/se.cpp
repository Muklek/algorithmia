#include<iostream>
#include<vector>

//   complexity o(log n) -> binary search and insertion
//   space complexity o(1)

int searchInsert(std::vector<int>& numberList,int numberToCheck){
    int index{0};
    int low{0};
    int high{numberList.size()-1};
    while(low<=high){
        index=(low+high)/2;
        std::cout<<low<<std::endl;
        std::cout<<high<<std::endl;
        std::cout<<index<<std::endl;
        if(numberList[index]==numberToCheck){
            return index;
        }
        else{
            if(numberList[index-1] < numberToCheck && numberList[index+1] > numberToCheck){
                if(numberList[index] < numberToCheck){
                    return index+1;
                }
                if(numberList[index] > numberToCheck){
                    return index;
                }
            }
            else if(numberList[index] > numberToCheck){
                high=index-1;
            }
            else if(numberList[index] < numberToCheck){
                low=index+1;
            }
            else{
                return -99;
            }
        }
    }
}


int main(){
    std::vector<int> numbers{1,3,5,8};
    std::cout<<searchInsert(numbers,0)<<std::endl;
}
