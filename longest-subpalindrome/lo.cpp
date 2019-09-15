#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int lengthSubPalindrome(std::string& line, int left, int right){
    while(left>=0 && right<line.size() && (line[left] == line[right])){
        left--;right++;
    }
    return right - left;
}


auto subPalindrome(std::string& line){
   int start{0},maxLength{0};
   for(int i{0};i<line.size();i++){
       int currentSubPal{lengthSubPalindrome(line, i, i)};
       if(currentSubPal > maxLength){
           maxLength = currentSubPal;
           start = (currentSubPal/2) - i - 1;
       }
   }
   return line.substr(start,maxLength-1);
}


int main(){
    std::string pal{"abacdfgdcaba"};
    std::cout<<subPalindrome(pal)<<std::endl;
}
