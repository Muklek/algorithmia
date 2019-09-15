#include<iostream>
#include<vector>

inline int rSubsequence(std::vector<char>& charList){
   for(int i{0}; i<charList.size()-1; i++){
      if(charList[i] != 'R'){
         return i;
      }
   }
}

inline int bSubsequence(std::vector<char>& charList){
   for(int i{charList.size()-1}; i>=0; i--){
      if(charList[i] != 'B'){
         return i;
      }
   }
}

void swapRGB(std::vector<char>& charList, int& rIndex, int& bIndex, int cIndex){
   while(charList[cIndex] == 'R' || charList[cIndex] == 'B'){
      if(charList[cIndex] == 'R'){
         std::swap(charList[cIndex], charList[rIndex]);
         while(charList[++rIndex] == 'R'){};
      }
      if(charList[cIndex] == 'B'){
         std::swap(charList[bIndex], charList[cIndex]);
         while(charList[--bIndex] == 'B'){};
      }
   }
}

void reOrderRGB(std::vector<char>& chars){
   int front{rSubsequence(chars)},back{bSubsequence(chars)};
   for(int i{front}; i<=back; i++){
      if(chars[i] == 'R' && i>front){
         swapRGB(chars, front, back, i);
      }
      else if(chars[i] == 'B' && i<back){
         swapRGB(chars, front, back, i);
      }
   }
}

int main(){
   std::vector<char> charList{'R','G','G','G','R','B','G','B','B','R'};
   reOrderRGB(charList);
   for(char c : charList){
      std::cout<<c;
      std::cout<<" ";
   }
   std::cout<<std::endl;
}
