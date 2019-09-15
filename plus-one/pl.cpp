#include<iostream>
#include<vector>

void recursiveChange(std::vector<int>& numberList, int index){
    if(index != 0){
        if(numberList[index]==10){
            numberList[index]=0;
            recursiveChange(numberList, index-1);
        }
        else if(numberList[index]==9){
            numberList[index] += 0;
            recursiveChange(numberList, index-1);
        }
        else if(numberList[index]<9 && (numberList[index+1]==0)){
            numberList[index] +=1;
            recursiveChange(numberList, index-1);
        }
        else if(numberList[index+1] - numberList[index] >= 2){
            numberList[index] +=1;
            recursiveChange(numberList,index-1);
        }
    }
    else{
        numberList[index]+=1;
    }
}

void plusOne(std::vector<int>& numberList){
    numberList[numberList.size()-1] += 1;
    if(numberList[numberList.size()-1] == 10){
        recursiveChange(numberList, numberList.size()-1);
    }
}


int main(){
    std::vector<int> numbers1{2,3,4,5,6,7,8,9};
    std::vector<int> numbers2{8,9,9};
    plusOne(numbers1);
    plusOne(numbers2);

    for(int number : numbers1){
        std::cout<<number<<std::endl;
    }
    std::cout<<"--"<<std::endl;
    for(int number : numbers2){
        std::cout<<number<<std::endl;
    }

}
