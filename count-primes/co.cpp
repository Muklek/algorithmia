#include<iostream>


int countPrimes(int number){
    int count{0};
    while(--number>0){
        if(number%2==0){
            count+=1;
        }
    }
    return count;

}

int main(){
    const int number{10};
    std::cout<<countPrimes(number)<<std::endl;
}
