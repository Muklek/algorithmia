#include<iostream>

// reverse number:
// 1234 to 4321
// approach: use maths!


const int reverse(int& numberToReverse){
    int rev;
    while(numberToReverse > 0){
        int lastDigit = numberToReverse % 10;
        rev = (rev * 10) + lastDigit;
        numberToReverse = numberToReverse / 10;
    }
    return rev;
}




int main(){
    int number{123450};
    std::cout<<reverse(number)<<std::endl;

}
