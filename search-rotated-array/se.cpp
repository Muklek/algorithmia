#include<iostream>
#include<vector>
#include<ctime>

// rotated ascending order array
// algorithm: binary search
// partially select subarray where the possible value might be stored

typedef std::vector<int> vi;


int searchItem(vi& numberList, int item){
    std::cout<<std::endl;
    size_t low{0}, high{numberList.size()-1}, mid{0};
    if(numberList.size() == 0){
        return -1;
    }
    if(numberList.size() == 1){
        if(numberList[0] == item) return 0;
        return -1;
    }
    while(low<=high){
        mid=(low+high)/2;
        if(numberList[mid+1] - numberList[mid] != 1) mid++;
        if(numberList[mid] == item) return mid;
        if(numberList[low] == item) return low;
        if(numberList[high] == item) return high;

        if((numberList[low] <= item && numberList[mid-1] >= item)||
                (numberList[mid-1]==item || numberList[low]==item)){
            high = --mid;
        }
        else if((numberList[mid+1] <= item && numberList[high] >= item)||
                (numberList[mid+1]==item || numberList[high]==item)){
            low = ++mid;
        }
        else{
            break;
        }

    }
    return -1;
}


int main(){
    vi numbers{4,5,6,7,0,1,2};
    vi numbers2{4,5,6,7,8,1,2,3};
    vi numbers3{1,2,3,4,5};
    vi numbers4{7,0,1,2,3,4};
    vi numbers5{7,1,2};
    vi numbers6{7,1};
    vi numbers7{1,2,3,7,8,9,0};
    vi numbers8{1,2,3,7,8,9,10,11,12,13,0};
    std::cout<<searchItem(numbers, 1)<<std::endl; // valid
    std::cout<<searchItem(numbers, 0)<<std::endl; // valid
    std::cout<<searchItem(numbers, 5)<<std::endl; // valid
    std::cout<<searchItem(numbers2, 1)<<std::endl; // valid
    std::cout<<searchItem(numbers2, 4)<<std::endl; // valid
    std::cout<<searchItem(numbers2, 6)<<std::endl; // valid
    std::cout<<searchItem(numbers2, 2)<<std::endl; // valid
    std::cout<<searchItem(numbers2, 5)<<std::endl; // valid
    std::cout<<searchItem(numbers4, 1)<<std::endl; // valid
    std::cout<<searchItem(numbers5, 1)<<std::endl; // valid
    std::cout<<searchItem(numbers6, 1)<<std::endl; // valid
    std::cout<<searchItem(numbers7, 2)<<std::endl; // valid
    std::cout<<searchItem(numbers7, 9)<<std::endl; // valid
    std::cout<<searchItem(numbers7, 7)<<std::endl; // valid
    std::cout<<searchItem(numbers7, 3)<<std::endl; // valid
    std::cout<<searchItem(numbers3, 20)<<std::endl; // not valid
    std::cout<<searchItem(numbers5, 0)<<std::endl; // not valid
    std::cout<<searchItem(numbers4, 10)<<std::endl; // not valid
    std::cout<<searchItem(numbers6, 10)<<std::endl; // not valid
    std::cout<<searchItem(numbers7, 30)<<std::endl; // not valid
    std::cout<<searchItem(numbers8, 13)<<std::endl; // not valid
}
